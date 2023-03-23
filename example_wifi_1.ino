// На основе примеров Arduino IDE 2.0
// 
// Примеры по учебным курсам
//
// Bishkek 2023

#include <ESP8266WiFi.h> // Подключаем библиотеку для работы с модулем ESP8266 и WiFi

const char* ssid = "  "; // Имя WiFi-сети, к которой будет подключаться модуль (необходимо заполнить)
const char* password =  "  "; // Пароль WiFi-сети (необходимо заполнить)

void setup() {
  Serial.begin(74880); // Инициализируем последовательный порт

  WiFi.begin(ssid, password); // Подключаемся к WiFi-сети с использованием переменных ssid и password

  while (WiFi.status() != WL_CONNECTED) { // Цикл, пока модуль не подключится к WiFi
    delay(1000); // Задержка в 1 секунду
    Serial.println("Connecting to WiFi."); // Выводим сообщение о подключении к WiFi
  }

  Serial.print("IP address: "); // Выводим сообщение о IP-адресе модуля
  Serial.println(WiFi.localIP()); // Выводим IP-адрес модуля

  Serial.print("Hostname: "); // Выводим сообщение об имени хоста модуля
  Serial.println(WiFi.getHostname()); // Выводим имя хоста модуля

  Serial.print("ESP Mac Address: "); // Выводим сообщение о MAC-адресе модуля
  Serial.println(WiFi.macAddress()); // Выводим MAC-адрес модуля
}

void loop() {
  delay(100000); // Задержка в 100 000 миллисекунд (100 секунд)
}
