#ifndef PB_TELBOT_H
#define PB_TELBOT_H

#ifdef ESP32
  #include <WiFi.h>
  #include <HTTPClient.h>
#elif defined(ESP8266)
  #include <ESP8266WiFi.h>
  #include <ESP8266HTTPClient.h>
#endif

class PB_TelBot {
  private:
    String botToken;
    String chatID;

  public:
    PB_TelBot(String token, String chat);
    void connectWiFi(const char* ssid, const char* password);
    void sendMessage(String message);
    void sendPhoto(String filePath);
    void sendFile(String filePath);
};

#endif