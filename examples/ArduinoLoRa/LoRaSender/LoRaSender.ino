#include <LoRa.h>
#include "boards.h"

int counter = 0;

void setup()
{
    initBoard();
    // When the power is turned on, a delay is required.
    delay(1500);

    Serial.println("LoRa Sender");
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
}

void loop()
{
    Serial.print("Sending packet: ");
    Serial.println(counter);

    // send packet
    LoRa.beginPacket();
    LoRa.print("hello ");
    LoRa.print(counter);
    LoRa.endPacket();

#ifdef HAS_DISPLAY
    if (u8g2) {
        char buf[256];
        u8g2->clearBuffer();
        u8g2->drawStr(0, 12, "Transmitting: OK!");
        snprintf(buf, sizeof(buf), "Sending: %d", counter);
        u8g2->drawStr(0, 30, buf);
        u8g2->sendBuffer();
    }
#endif
    counter++;
    delay(5000);
}
