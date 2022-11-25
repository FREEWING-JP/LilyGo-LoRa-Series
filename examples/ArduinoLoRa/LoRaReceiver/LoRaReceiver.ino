
#include <HTTPClient.h>
#include <WiFi.h>
#include <LoRa.h>
#include "boards.h"

int counter = 0;

// WiFi Internet Router
const char* ssid     = "WIFI_SSID";
const char* password = "WIFI_PASSWORD";

// LINE Messaging API
const char* line_channel_access_token = "LINE_CHANNEL_ACCESS_TOKEN";
const char* line_your_user_id = "LINE_YOUR_USER_ID";

void setup()
{
    initBoard();
    // When the power is turned on, a delay is required.
    delay(1500);

    Serial.println("LoRa Receiver");

    LoRa.setPins(RADIO_CS_PIN, RADIO_RST_PIN, RADIO_DI0_PIN);
    if (!LoRa.begin(LoRa_frequency)) {
        Serial.println("Starting LoRa failed!");
        while (1);
    }
    LoRa.setTxPower(13);             // TX Power: 13dBm, 20mW, ARIB STD-T108
    LoRa.setSignalBandwidth(125E3);  // Signal Bandwidth: defaults to 125E3
    LoRa.setSpreadingFactor(10);     // Spreading Factor: defaults to 7, 6 to 12
    LoRa.setCodingRate4(5);          // Coding Rate: defaults to 5, 5 to 8
    LoRa.enableCrc();

    Serial.println("WiFi Begin");
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(1000);
    }
    Serial.println("WiFi Connected");
}

void loop()
{
    // try to parse packet
    int packetSize = LoRa.parsePacket();
    if (packetSize) {
        // received a packet
        Serial.print("Received packet '");

        String recv = "";
        // read packet
        while (LoRa.available()) {
            recv += (char)LoRa.read();
        }

        Serial.println(recv);

        // print RSSI of packet
        Serial.print("' with RSSI ");
        Serial.println(LoRa.packetRssi());
#ifdef HAS_DISPLAY
        if (u8g2) {
            digitalWrite(BOARD_LED, LED_ON);
            u8g2->sleepOff();
            u8g2->clearBuffer();
            char buf[256];
            u8g2->drawStr(0, 12, "Received OK!");
            u8g2->drawStr(0, 26, recv.c_str());
            snprintf(buf, sizeof(buf), "RSSI:%i, %i", LoRa.packetRssi(), counter);
            u8g2->drawStr(0, 40, buf);
            snprintf(buf, sizeof(buf), "SNR:%.1f", LoRa.packetSnr());
            u8g2->drawStr(0, 56, buf);
            u8g2->sendBuffer();
            delay(500);
            digitalWrite(BOARD_LED, LED_OFF);
            u8g2->sleepOn();

            ++counter;
        }
#endif

      // LINE Messaging API
      HTTPClient httpClient;
      httpClient.begin("https://api.line.me/v2/bot/message/push");
      httpClient.addHeader("Content-Type", "application/json");

      char buf[256];
      sprintf(buf, "Bearer %s", line_channel_access_token);
      httpClient.addHeader("Authorization", buf);

      sprintf(buf, "{"
        "\"to\": \"%s\","
        "\"messages\":["
          "{"
            "\"type\":\"text\","
            "\"text\":\"%s%s\""
          "}"
        "]"
      "}", line_your_user_id, "郵便来た: ", recv);

      int status_code = httpClient.POST((uint8_t *)buf, strlen(buf));
      if (status_code == 200)
      {
        Serial.print("OK");
      }
      else
      {
        Serial.printf("ERR %d", status_code);
      }
      httpClient.end();
    }
}
