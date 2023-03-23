// На основе примеров Arduino IDE 2.0
// 
// Примеры по учебным курсам
//
// Bishkek 2023

#include <ESP8266WiFi.h>


// Параметры сети - здесь нужно указать SSID и пароль своей Wi-Fi сети
const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";

WiFiServer server(80); // Создание экземпляра сервера на порту 80

int connectionCount = 0; // Счетчик подключений

void setup() {
  Serial.begin(9600); // Настройка последовательного порта для вывода отладочной информации

  WiFi.mode(WIFI_STA); // Установка режима клиента Wi-Fi
  WiFi.begin(ssid, password); // Подключение к сети Wi-Fi

  // Ожидание подключения к сети Wi-Fi
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000); // Задержка 1 секунда
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi"); // Отладочный вывод
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP()); // Вывод IP-адреса ESP8266
  // Примечание: WiFi.localIP() возвращает объект типа IPAddress, 
  // который может быть преобразован в строку для вывода на веб-странице

  server.begin(); // Запуск сервера
}

void loop() {
  // Ожидание подключения клиента к серверу
  WiFiClient client = server.available();

  if (client) { // Если клиент подключился
    Serial.println("New client connected"); // Отладочный вывод

    connectionCount++; // Увеличение счетчика подключений
    Serial.print("Connections count: ");
    Serial.println(connectionCount); // Отладочный вывод

    // Отправка HTTP-заголовка клиенту
    client.println("HTTP/1.1 200 OK"); 
    client.println("Content-Type: text/html");
    client.println();

    // Вывод информации на веб-страницу
    client.println("<html><body style='background-color: blue; color: white;'>");
    client.print("<h1>MAC address: ");
    client.print(WiFi.macAddress()); // Вывод MAC-адреса ESP8266
    client.println("</h1>");
    client.print("<h1>IP address: ");
    client.print(WiFi.localIP()); // Вывод IP-адреса ESP8266
    client.println("</h1>");
    client.print("<h1>Connections count: ");
    client.print(connectionCount); // Вывод счетчика подключений
    client.println("</h1>");
    client.println("</body></html>");

    client.stop(); // Закрытие соединения с клиентом
    Serial.println("Client disconnected"); // Отладочный вывод
  }
}
