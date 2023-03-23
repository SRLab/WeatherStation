// На основе примеров Arduino IDE 2.0
// 
// Примеры по учебным курсам
//
// Bishkek 2023

#include <ESP8266WiFi.h>

const char* ssid = "myAP";       // имя точки доступа
const char* password = "mypassword";   // пароль для точки доступа
IPAddress local_IP(192, 168, 4, 22);   // IP-адрес точки доступа
IPAddress gateway(192, 168, 4, 9);     // IP-адрес шлюза
IPAddress subnet(255, 255, 255, 0);    // маска подсети

void setup() {
  Serial.begin(115200);
  WiFi.softAP(ssid, password);  // создание точки доступа
  WiFi.softAPConfig(local_IP, gateway, subnet);  // настройка сети
  Serial.println("Access Point created");
  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP()); // вывод IP-адреса точки доступа
}

void loop() {
  // пустой цикл
}
