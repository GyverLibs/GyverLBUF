#pragma once
#include <inttypes.h>
#include <stddef.h>

template <typename T, size_t SIZE, typename Ti = uint16_t>
class GyverLBUF {
   public:
    // добавить в буфер
    void write(T val) {
        buffer[head] = val;
        head = (head + 1 >= SIZE) ? 0 : (head + 1);
    }

    // запись в буфер по номеру
    void write(size_t n, T val) {
        get(n) = val;
    }

    // чтение из буфера
    T read(size_t n) {
        return buffer[_i(n)];
    }

    // чтение из буфера
    T& get(size_t n) {
        return buffer[_i(n)];
    }

    // чтение из буфера
    T& operator[](size_t n) {
        return get(n);
    }

    // размер буфера
    size_t size() {
        return SIZE;
    }

   private:
    T buffer[SIZE] = {};
    Ti head = 0;

    inline size_t _i(size_t num) {
        size_t i = num + head;
        return i >= SIZE ? i - SIZE : i;
    }
};