#include "PB_TelBot.h"

PB_TelBot::PB_TelBot(String token, String chat_id) {
    botToken = token;
    chatId = chat_id;
    baseURL = "https://api.telegram.org/bot" + botToken;
}

bool PB_TelBot::sendMessage(String message) {
    String url = baseURL + "/sendMessage?chat_id=" + chatId + "&text=" + message;
    HTTPClient http;
    http.begin(url);
    int httpCode = http.GET();
    http.end();
    return (httpCode == 200);
}

bool PB_TelBot::sendImage(String filePath) {
    String url = baseURL + "/sendPhoto";
    HTTPClient http;
    http.begin(url);
    http.addHeader("Content-Type", "multipart/form-data");
    http.addHeader("chat_id", chatId);
    http.addHeader("photo", filePath);
    
    int httpCode = http.POST("");
    http.end();
    return (httpCode == 200);
}

bool PB_TelBot::sendFile(String filePath) {
    String url = baseURL + "/sendDocument";
    HTTPClient http;
    http.begin(url);
    http.addHeader("Content-Type", "multipart/form-data");
    http.addHeader("chat_id", chatId);
    http.addHeader("document", filePath);
    
    int httpCode = http.POST("");
    http.end();
    return (httpCode == 200);
}

bool PB_TelBot::sendFileFromURL(String url) {
    String apiURL = baseURL + "/sendDocument?chat_id=" + chatId + "&document=" + url;
    HTTPClient http;
    http.begin(apiURL);
    int httpCode = http.GET();
    http.end();
    return (httpCode == 200);
}