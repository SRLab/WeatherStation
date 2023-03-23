// На основе примеров Arduino IDE 2.0
// 
// Примеры по учебным курсам
//
// Bishkek 2023

#include <ESP8266WiFi.h> // Подключаем библиотеку для работы с модулем ESP8266 и WiFi

void setup()
{
    Serial.begin(115200); // Инициализируем последовательный порт со скоростью 115200 бод
    WiFi.mode(WIFI_STA); // Устанавливаем модуль в режим клиента (станция)
    WiFi.disconnect(); // Отключиться от текущей WiFi-сети (если были подключены)
}

void loop()
{
    int n = WiFi.scanNetworks(); // Сканируем доступные WiFi-сети и записываем количество найденных в переменную n


    if (n == 0) {
        Serial.println("no networks found"); // Если не найдено ни одной сети, выводим сообщение об этом
    } else {
        Serial.print(n);
        Serial.println(" networks found"); // Если найдены сети, выводим их количество
        for (int i = 0; i < n; ++i) { // Цикл для вывода списка сетей и их названий
            Serial.print(i + 1);
            Serial.print(": ");
            Serial.println(WiFi.SSID(i));
        }
    }
    Serial.println("");
    delay(5000); // Задержка в 5 секунд перед повторным сканированием сетей
}
