// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
    uint16_t constValue = value;
    while (n > 1) {
        value *= constValue;
        n--;
    }
    return value;
}

uint64_t fact(uint16_t n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n*fact(n-1);
    }
}

double calcItem(double x, uint16_t n) {
    return pown(x, n)/fact(n);
}

double expn(double x, uint16_t count) {
    double value = 1.0;
    for (uint64_t i = 1; i <= count; i++) {
        value += calcItem(x, i);
    }
    return value;
}

double sinn(double x, uint16_t count) {
    double value = x;
    for (int i = 2; i <= count; ++i) {
        value += pown(-1, i-1)*calcItem(x, i * 2 - 1);
    }
    return value;
}

double cosn(double x, uint16_t count) {
    double value = 1.0;
    for (int i = 2; i <= count; ++i) {
        value += pown(-1, i-1) * calcItem(x, i * 2-2);
    }
    return value;
}
