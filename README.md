# PB_TelBot Library

PB_TelBot is a lightweight library for ESP32 that allows easy interaction with Telegram bots. With this library, you can send messages, images, and files from your ESP32 directly to a Telegram chat. You can also send files from a URL.

## Features
- Send text messages to a Telegram chat
- Send images and files stored on ESP32 (e.g., SPIFFS or SD card)
- Send files from URLs

## Requirements
- ESP32 board
- Telegram bot token and chat ID
- Libraries:
  - WiFi.h (for WiFi connection)
  - HTTPClient.h (for sending HTTP requests)

## Installation
1. Download the PB_TelBot library from this repository.
2. Place the library in the `libraries` folder of your Arduino environment:
    - On Windows: `Documents/Arduino/libraries/`
    - On macOS: `~/Documents/Arduino/libraries/`
    - On Linux: `~/Arduino/libraries/`
3. Restart the Arduino IDE.
4. Include the library in your sketch by adding:

```cpp
#include <PB_TelBot.h>