// На основе примеров Arduino IDE 2.0
// 
// Примеры по учебным курсам
//
// Bishkek 2023

#include "DHT.h"         // подключаем библиотеку DHT

#define DHTPIN 0         // указываем пин, к которому подключен датчик
#define DHTTYPE DHT22    // указываем тип датчика

DHT dht(DHTPIN, DHTTYPE); // создаем объект dht для работы с датчиком

void setup() {
  Serial.begin(74880);    // открываем последовательный порт для вывода данных
  Serial.println(F("DHT22 test!")); // выводим сообщение о начале тестирования


  dht.begin();            // инициализируем датчик
}

void loop() {
  delay(2000);            // задержка 2 секунды

  float h = dht.readHumidity();    // считываем влажность
  float t = dht.readTemperature(); // считываем температуру

  if (isnan(h) || isnan(t) ) {     // если полученные данные некорректны
    Serial.println(F("Failed to read from DHT sensor!")); // выводим сообщение об ошибке
    return;                         // выходим из функции loop()
  }

  float hic = dht.computeHeatIndex(t, h, false); // вычисляем индекс теплового дискомфорта

  Serial.print(F("Humidity: "));    // выводим сообщение о влажности
  Serial.print(h);                  // выводим значение влажности
  Serial.print(F("%  Temperature: ")); // выводим сообщение о температуре
  Serial.print(t);                  // выводим значение температуры в градусах Цельсия
  Serial.print(F("°C "));           // выводим символ градусов Цельсия
  Serial.print(F("°F  Heat index: ")); // выводим сообщение об индексе теплового дискомфорта
  Serial.print(hic);                // выводим значение индекса теплового дискомфорта в градусах Цельсия
  Serial.println(F("°C "));         // выводим символ градусов Цельсия и переводим строку
}
