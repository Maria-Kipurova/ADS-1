// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
    if (value < 2) {
        return false;
    }
    for (int i = 2; i <= value / 2; i++) {
        if (value % i == 0) {
            return false;
        }
    }
    return true;
}


uint64_t nPrime(uint64_t n) {
    if (n == 1) {
        return 2;
    }
    uint64_t count = 1;
    uint64_t num = 3;
    while (count < n) {
        bool isPrime = true;
        for (uint64_t i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            count++;
        }
        num += 2;
    }
    return num - 2;
}

uint64_t nextPrime(uint64_t value) {
    uint64_t num = value + 1;
    while (!checkPrime(num)) {
        num++;
    }
    return num;
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t sum = 0;
    for (uint64_t num = 2; num < hbound; num++) {
        if (checkPrime(num)) {
            sum += num;
        }
    }
    return sum;
}
