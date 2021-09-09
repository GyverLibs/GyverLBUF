/*
    Линейный буфер для Arduino
    Документация: 
    GitHub: https://github.com/GyverLibs/GyverLBUF
    Возможности:
    - Хранит и даёт доступ к последним N записям
    - Может использоваться для:
        - Аппроксимации по последним N измерениям
        - Поиска разности между текущим и последним в буфере
    - Статический размер
    - Выбор типа данных
    
    AlexGyver, alex@alexgyver.ru
    https://alexgyver.ru/
    MIT License

    Версии:
    v1.0 - релиз
*/

#ifndef _GyverLBUF_h
#define _GyverLBUF_h
template < typename TYPE, int SIZE >
class GyverLBUF {
public:
    // добавить в буфер
    void write(TYPE val) {
        buffer[count % SIZE] = val;
        if (++count >= SIZE) count = 0;
    }
    
    // запись в буфер по номеру
    void write(int num, TYPE val) {
        buffer[(num + count) % SIZE] = val;
    }
    
    // чтение из буфера
    TYPE read(int num) {
        return buffer[(num + count) % SIZE];
    }
    
    // размер буфера
    int size() {
        return SIZE;
    }

private: 
    TYPE buffer[SIZE];
    int count = 0;
};
#endif