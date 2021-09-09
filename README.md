![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)
![author](https://img.shields.io/badge/author-AlexGyver-informational.svg)
# GyverLBUF
Линейный буфер для Arduino
- Хранит и даёт доступ к последним N записям
- Может использоваться для:
    - Аппроксимации по последним N измерениям
    - Поиска разности между текущим и последним в буфере
- Статический размер
- Выбор типа данных

### Совместимость
Совместима со всеми Arduino платформами (используются Arduino-функции)

## Содержание
- [Установка](#install)
- [Инициализация](#init)
- [Использование](#usage)
- [Пример](#example)
- [Версии](#versions)
- [Баги и обратная связь](#feedback)

<a id="install"></a>
## Установка
- **БИБЛИОТЕКА ПОКА ЧТО НЕДОСТУПНА В МЕНЕДЖЕРЕ БИБЛИОТЕК**
- Библиотеку можно найти по названию **GyverLBUF** и установить через менеджер библиотек в:
    - Arduino IDE
    - Arduino IDE v2
    - PlatformIO
- [Скачать библиотеку](https://github.com/GyverLibs/GyverLBUF/archive/refs/heads/main.zip) .zip архивом для ручной установки:
    - Распаковать и положить в *C:\Program Files (x86)\Arduino\libraries* (Windows x64)
    - Распаковать и положить в *C:\Program Files\Arduino\libraries* (Windows x32)
    - Распаковать и положить в *Документы/Arduino/libraries/*
    - (Arduino IDE) автоматическая установка из .zip: *Скетч/Подключить библиотеку/Добавить .ZIP библиотеку…* и указать скачанный архив
- Читай более подробную инструкцию по установке библиотек [здесь](https://alexgyver.ru/arduino-first/#%D0%A3%D1%81%D1%82%D0%B0%D0%BD%D0%BE%D0%B2%D0%BA%D0%B0_%D0%B1%D0%B8%D0%B1%D0%BB%D0%B8%D0%BE%D1%82%D0%B5%D0%BA)

<a id="init"></a>
## Инициализация
```cpp
GyverLBUF<тип данных, размер буфера> buf;
// тип данных: любой. byte/int/float...
// размер буфера: код выполняется быстрее при размере буфера, кратном степени двойки (2, 4, 8, 16, 32...)
```

<a id="usage"></a>
## Использование
```cpp
// TYPE - указанный при инициализации тип данных
void write(TYPE newVal);        // добавить в буфер
void write(int num, TYPE val);  // запись в буфер по номеру num
TYPE read(int num);             // чтение из буфера
int size();                     // размер буфера
```

<a id="example"></a>
## Пример
Остальные примеры смотри в **examples**!
```cpp
#include <GyverLBUF.h>
GyverLBUF<int, 8> buf;
// тип данных: любой. byte/int/float...
// размер буфера: код выполняется быстрее при
// размере буфера, кратном степени двойки (2, 4, 8, 16, 32...)

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 12; i++) {
    buf.write(i);
    for (int j = 0; j < 8; j++) {
      Serial.print(buf.read(j));
      Serial.print(',');
    }
    Serial.println();
  }

  /*
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,1,
    0,0,0,0,0,0,1,2,
    0,0,0,0,0,1,2,3,
    0,0,0,0,1,2,3,4,
    0,0,0,1,2,3,4,5,
    0,0,1,2,3,4,5,6,
    0,1,2,3,4,5,6,7,
    1,2,3,4,5,6,7,8,
    2,3,4,5,6,7,8,9,
    3,4,5,6,7,8,9,10,
    4,5,6,7,8,9,10,11,
  */
}

void loop() {
}
```

<a id="versions"></a>
## Версии
- v1.0

<a id="feedback"></a>
## Баги и обратная связь
При нахождении багов создавайте **Issue**, а лучше сразу пишите на почту [alex@alexgyver.ru](mailto:alex@alexgyver.ru)  
Библиотека открыта для доработки и ваших **Pull Request**'ов!