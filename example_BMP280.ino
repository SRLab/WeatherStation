// На основе примеров Arduino IDE 2.0
// 
// Примеры по учебным курсам
//
// Bishkek 2023

// Подключение библиотеки для работы с датчиком
#include <Adafruit_BMP280.h>

// Объявление объекта для работы с датчиком
Adafruit_BMP280 bmp; // Подключение через I2C

void setup() {
// Инициализация последовательного порта
Serial.begin(74880);
while ( !Serial ) delay(100); // Ожидание завершения инициализации порта
// Вывод информации о начале работы скетча
Serial.println(F("BMP280 test"));
unsigned status;
// Инициализация датчика с определенным адресом 0x76
status = bmp.begin(0x76);
// Проверка статуса инициализации датчика
if (!status) {
Serial.println(F("Ошибка подключения к датчику BMP280");
while (1) delay(10);
}

}

void loop() {
// Вывод на экран температуры в градусах Цельсия
Serial.print(F("Temperature = "));
Serial.print(bmp.readTemperature());
Serial.println(" *C");

// Вывод на экран атмосферного давления в Паскалях
Serial.print(F("Pressure = "));
Serial.print(bmp.readPressure());
Serial.println(" Pa");

// Вывод на экран примерной высоты над уровнем моря
Serial.print(F("Approx altitude = "));
Serial.print(bmp.readAltitude(1013.25)); /* Корректировка под местный прогноз! */
Serial.println(" m");

// Пустая строка для удобства чтения информации
Serial.println();
// Задержка 2 секунды между измерениями
delay(2000);

