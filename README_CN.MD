<h1 align = "center">🌟LilyGo LoRa Series🌟</h1>

## **[English](./README.MD) | 中文**

## 快速开始:

1. 将 `libdeps` 目录中所有文件夹复制到`~/Arduino/libraries`目录内,Windons用户放在 `"我的文档/Arduino/libraries"`
2. 打开对应的示例
3. `T-Beam`用户可以选择`TTGO T-Beam`,`lora32(T3)`用户可以选择`ESP32 Dev Module`,`T-Motion` 用户选择 `Nucleo_l073RZ`
4. 在端口中选择板子的端口
5. 除了GPS 目录外的其他示例，请在`utilities.h` 中上方根据你的板子型号取消注释,否则编译将报错误
6. 上传

## Product 📷

| Product                   | Product Link                    | Schematic                                              | Corresponding example macro definition                    |
| :-----------------------: | :-----------------------------: | :----------------------------------------------------: | :-------------------------------------------------------: |
| [T-Beam SX1278/76][1-4]   | [AliExpress][1]                 | [TBeamV0.7][1-1] / [TBeamV1.0][1-2] / [TBeamV1.1][1-3] | LILYGO_TBeam_V0_7 / LILYGO_TBeam_V1_0 / LILYGO_TBeam_V1_1 |
| [T-Beam SX1262][1-4]      | [AliExpress][2]                 | [TBeamV0.7][1-1] / [TBeamV1.0][1-2] / [TBeamV1.1][1-3] | LILYGO_TBeam_V0_7 / LILYGO_TBeam_V1_0 / LILYGO_TBeam_V1_1 |
| [LoRa32 V1.0 SX1276][3-1] | [AliExpress][3]                 | ❌                                                    | LILYGO_T3_V1_0                                             |
| [LoRa32 V1.0 SX1278][3-1] | [AliExpress][4]                 | ❌                                                    | LILYGO_T3_V1_0                                             |
| [LoRa32 V1.3 SX1276][5-2] | [AliExpress][5]                 | [LoRa32 V1.3][5-1]                                     | LILYGO_T3_V1_3                                            |
| [LoRa32 V2.0][6-2]        | [AliExpress][6]                 | [LoRa32 V2.0][6-1]                                     | LILYGO_T3_V1_3                                            |
| [LoRa32 V2.1 & 1.6][7-4]  | [AliExpress][7-1]/[Amazon][7-2] | [LoRa32 V2.1_1.6][7-3]                                 | LILYGO_T3_V1_6                                            |
| [T-Motion S76G][8-2]      | [AliExpress][8]                 | [T-Motion][8-1]                                        | LILYGO_T3_V1_6                                            |
| [LoRa32 V1.8 2.4G][9-2]   | [lilygo.cc][9]                  | [LoRa32 V1.8 2.4G][9-1]                                | LILYGO_T3_V1_8                                            |

[1]: https://pt.aliexpress.com/item/32967228739.html "T-Beam SX1278/76"
[1-1]: schematic/LilyGo_TBeam_V0.7.pdf
[1-2]: schematic/LilyGo_TBeam_V1.0.pdf
[1-3]: schematic/LilyGo_TBeam_V1.1.pdf
[1-4]: assets/image/t-beam_v1.1_pinmap.jpg
[2]: https://pt.aliexpress.com/item/4001287221970.html "T-Beam SX1262"
[3]: https://pt.aliexpress.com/item/32842155838.html "LoRa32 V1.0 SX1276"
[3-1]: assets/image/lora32_v1.0_pinmap.jpg
[4]: https://pt.aliexpress.com/item/32842155838.html "LoRa32 V1.0 SX1278"
[5]: https://pt.aliexpress.com/item/4000628100802.html "LoRa32 V1.3 SX1276"
[5-1]: schematic/T3_V1.3.pdf
[5-2]: assets/image/lora32_v1.3_pinmap.jpg
[6]: https://pt.aliexpress.com/item/32847443952.html "LoRa32 V2.0"
[6-1]: schematic/T3_V2.0.pdf
[6-2]: assets/image/lora32_v2.0_pinmap.jpg
[7-1]: https://pt.aliexpress.com/item/32872078587.html "AliExpress"
[7-2]: https://www.amazon.com/dp/B09SHRWVNB?ref=myi_title_dp "Amazon"
[7-3]: schematic/T3_V1.6.pdf
[7-4]: assets/image/lora32_v1.6.1_pinmap.jpg
[8]: https://www.aliexpress.com/item/4000571051141.html "T-Motion S76G"
[8-1]: schematic/T-Motion.pdf
[8-2]: assets/image/t-motion_v1.0_pinmap.jpg
[9]: https://www.lilygo.cc/products/lora-v1-8-esp32 "LoRa32 V1.8 2.4G"
[9-1]: schematic/T3_V1.8.pdf
[9-2]: assets/image/lora32_v1.8_pinmap.jpg

## 示例描述

```
examples
├─ArduinoLoRa                                   # Just only support SX1276/SX1278 radio module
│  ├─LoRaReceiver
│  └─LoRaSender
├─GPS                                           # T-Beam GPS demo examples
│  ├─Example1_BasicNMEARead
│  ├─Example2_NMEAParsing
│  ├─Example3_FactoryDefaultsviaSerial
│  ├─TinyGPS_Example
│  └─TinyGPS_KitchenSink
├─OLED                                          # OLED demo examples
│  ├─SSD1306SimpleDemo
│  └─SSD1306UiDemo
├─RadioLibExamples                              # RadioLib examples,Support SX1276/78/62/80
│  ├─SX1262
│  │  ├─SX1262_Receive_Interrupt
│  │  └─SX1262_Transmit_Interrupt
│  ├─SX1268
│  │  ├─SX1268_Receive_Interrupt
│  │  └─SX1268_Transmit_Interrupt
│  ├─SX1276
│  │  ├─SX1276_Receive_Interrupt
│  │  └─SX1276_Transmit_Interrupt
│  ├─SX1278
│  │  ├─SX1278_Receive
│  │  ├─SX1278_Receive_Interrupt
│  │  ├─SX1278_Transmit
│  │  └─SX1278_Transmit_Interrupt
│  ├─SX1280
│  │  ├─SX128x_Receive_Interrupt
│  │  └─SX128x_Transmit_Interrupt
│  └─TBeamAllFunction                           # T-Beam all function example
├─SleepTest
└─TTN                                           # OTAA method Join TTN example
    └─TTN_OTTA

```

## LoRa 型号分辨

分辨LoRa的型号只需要查看板子上的贴纸,
433MHz则是SX1278，
868MHz则是SX1276，
如果标签写的是SX1262则是SX1262

## 常见问题

1. GPS没有数据输出，[参考GPS恢复出厂](firmware/NMEA_Reset/README.MD)


## 引脚映射

- See [utilities.h](examples/ArduinoLoRa/LoRaReceiver/utilities.h)

## 应用

- [T-Beam SoftRF](https://github.com/lyusupov/SoftRF)
- [T-Beam Paxcounter](https://github.com/cyberman54/ESP32-Paxcounter)
- [T-Beam Meshtastic](https://github.com/meshtastic/Meshtastic-device)

## TTN

接入TTN(The Things Network)使用请参考 [LilyGo_LoRa_Series_Quick_Start](./docs/zh/LilyGo_LoRa_Series_Quick_Start_On_TTN_zh.md)

## 数据手册

- [AXP192](http://www.x-powers.com/en.php/Info/product_detail/article_id/29)
- [SX1262](https://www.semtech.com/products/wireless-rf/lora-transceivers/sx1262)
- [SX1278](https://www.semtech.com/products/wireless-rf/lora-transceivers/sx1278)
- [SX1276](https://www.semtech.com/products/wireless-rf/lora-transceivers/sx1276)
- [GSP NEO-6/NEO-8](https://www.u-blox.com/en/product/neo-6-series)
- [GPS Air530]()


## 注意事项

1. LoRa设置输出功率后需要设置最低电流。设置sx1262如下 :

```
    // digitalWrite(LoRa_Busy, LOW);
    // set output power to 10 dBm (accepted range is -17 - 22 dBm)
    if (radio.setOutputPower(22) == RADIOLIB_ERR_INVALID_OUTPUT_POWER) {
        Serial.println(F("Selected output power is invalid for this module!"));
        while (true);
    }


    // set over current protection limit to 80 mA (accepted range is 45 - 240 mA)
    // NOTE: set value to 0 to disable overcurrent protection
    if (radio.setCurrentLimit(80) == RADIOLIB_ERR_INVALID_CURRENT_LIMIT) {
        Serial.println(F("Selected current limit is invalid for this module!"));
        while (true);
    }
```
