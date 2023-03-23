// На основе примеров Arduino IDE 2.0
//
// Примеры по учебным курсам
//
// Bishkek 2023

#include <Adafruit_BMP280.h>  // Подключение библиотеки BMP280
#include "DHT.h"              // подключаем библиотеку DHT

// Создаем определения
#define DHTPIN 0       // указываем пин, к которому подключен датчик
#define DHTTYPE DHT22  // указываем тип датчика

// Объявление объектов для работы с датчиками
Adafruit_BMP280 bmp;       // Создаем объект с подключение через I2C
DHT dht(DHTPIN, DHTTYPE);  // создаем объект dht для работы с датчиком

void setup() {

  Serial.begin(74880);         // Инициализация последовательного порта
  while (!Serial) delay(100);  // Ожидание завершения инициализации порта

  Serial.println(F("BMP280 test"));  // Вывод информации о начале работы скетча
  unsigned status;

  status = bmp.begin(0x76);  // Инициализация датчика с определенным адресом 0x76
  // Проверка статуса инициализации датчика
  if (!status) {
    Serial.println(F("Ошибка подключения к датчику BMP280"));
    while (1) delay(10);
  }
  dht.begin();  // инициализируем датчик DHT22
}

void loop() {
  // Работа с датчиком DHT22
  float h = dht.readHumidity();                            // считываем влажность
  float t = dht.readTemperature();                         // считываем температуру
  if (isnan(h) || isnan(t)) {                              // если полученные данные некорректны
    Serial.println(F("Failed to read from DHT sensor!"));  // выводим сообщение об ошибке
    return;                                                // выходим из функции loop()
  }

  float hic = dht.computeHeatIndex(t, h, false);  // вычисляем индекс теплового дискомфорта

  Serial.print(F("Temperature inside= "));  // Вывод на экран температуры в градусах Цельсия
  Serial.print(bmp.readTemperature());
  Serial.println(" °C");

  Serial.print(F("Pressure = "));  // Вывод на экран атмосферного давления в Паскалях
  Serial.print(bmp.readPressure());
  Serial.println(" Pa");

  Serial.print(F("Approx altitude = "));    // Вывод на экран примерной высоты над уровнем моря
  Serial.print(bmp.readAltitude(1013.25));  // Вычисление примерной высоты над уровнем моря
  Serial.println(" m");

  Serial.print(F("Humidity: "));  // выводим сообщение о влажности
  Serial.print(h);                // выводим значение влажности
  Serial.println(F("%"));         // выводим  обозначение влажностит

  Serial.print(F("Temperature outsid: "));  // выводим сообщение о температуре
  Serial.print(t);                          // выводим значение температуры в градусах Цельсия
  Serial.println(F("°C "));                 // выводим символ градусов Цельсия
  Serial.print(F("Heat index: "));          // выводим сообщение об индексе теплового дискомфорта
  Serial.print(hic);                        // выводим значение индекса теплового дискомфорта в градусах Цельсия
  Serial.println(F("°C "));                 // выводим символ градусов Цельсия и переводим строку

  Serial.println();  // Пустая строка для удобства чтения информации

  delay(5000);  // Задержка 5 секунды между измерениями
}