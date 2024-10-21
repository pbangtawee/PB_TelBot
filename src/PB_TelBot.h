#ifndef PB_TELBOT_H
#define PB_TELBOT_H

#include <WiFi.h>
#include <HTTPClient.h>

class PB_TelBot {
  private:
    String botToken;
    String chatId;
    String baseURL;
    
  public:
    PB_TelBot(String token, String chat_id);
    bool sendMessage(String message);
    bool sendImage(String filePath);
    bool sendFile(String filePath);
    bool sendFileFromURL(String url);
};

#endif