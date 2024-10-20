#include "PB_Telbot.h"

PB_TelBot::PB_TelBot(String token, String chat) {
  botToken = token;
  chatID = chat;
}

void PB_TelBot::connectWiFi(const char* ssid, const char* password) {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("Connected to WiFi");
}

void PB_TelBot::sendMessage(String message) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String serverPath = "https://api.telegram.org/bot" + botToken + "/sendMessage?chat_id=" + chatID + "&text=" + message;
    http.begin(serverPath.c_str());

    int httpResponseCode = http.GET();

    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println(response);
    } else {
      Serial.print("Error on sending message: ");
      Serial.println(httpResponseCode);
    }
    http.end();
  }
}

void PB_TelBot::sendPhoto(String filePath) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String serverPath = "https://api.telegram.org/bot" + botToken + "/sendPhoto";
    
    http.begin(serverPath);
    http.addHeader("Content-Type", "multipart/form-data");

    String boundary = "----WebKitFormBoundary7MA4YWxkTrZu0gW";
    String body = "--" + boundary + "\r\n";
    body += "Content-Disposition: form-data; name=\"chat_id\"\r\n\r\n";
    body += chatID + "\r\n";
    body += "--" + boundary + "\r\n";
    body += "Content-Disposition: form-data; name=\"photo\"; filename=\"" + filePath + "\"\r\n";
    body += "Content-Type: image/jpeg\r\n\r\n";  // เปลี่ยนตามประเภทของไฟล์
    body += "--" + boundary + "--\r\n";

    http.addHeader("Content-Type", "multipart/form-data; boundary=" + boundary);
    int httpResponseCode = http.POST(body);

    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println(response);
    } else {
      Serial.print("Error on sending photo: ");
      Serial.println(httpResponseCode);
    }
    http.end();
  }
}

void PB_TelBot::sendFile(String filePath) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String serverPath = "https://api.telegram.org/bot" + botToken + "/sendDocument";

    http.begin(serverPath);
    http.addHeader("Content-Type", "multipart/form-data");

    String boundary = "----WebKitFormBoundary7MA4YWxkTrZu0gW";
    String body = "--" + boundary + "\r\n";
    body += "Content-Disposition: form-data; name=\"chat_id\"\r\n\r\n";
    body += chatID + "\r\n";
    body += "--" + boundary + "\r\n";
    body += "Content-Disposition: form-data; name=\"document\"; filename=\"" + filePath + "\"\r\n";
    body += "Content-Type: application/pdf\r\n\r\n";  // เปลี่ยนตามประเภทของไฟล์
    body += "--" + boundary + "--\r\n";

    http.addHeader("Content-Type", "multipart/form-data; boundary=" + boundary);
    int httpResponseCode = http.POST(body);

    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println(response);
    } else {
      Serial.print("Error on sending document: ");
      Serial.println(httpResponseCode);
    }
    http.end();
  }
}