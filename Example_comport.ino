// На основе примеров Arduino IDE 2.0
// 
// Примеры по учебным курсам
//
// Bishkek 2023

void setup()
{
  Serial.begin(9600);    // подключаем монитор порта
  Serial.print("Start"); // выводим текст на монитор 1 раз
}


void loop()
{
  Serial.println("Hello!"); // выводим текст 1 раз в секунду
  delay(1000);            // задержка в 1 секунду
}
