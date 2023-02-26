#pragma once
#include "stdafx.h"

template<typename T>
class CRandom {
public:
    static T Get(T min = -50, T max = 50, T precision = 2) {
        if (is_same_v<T, int>)
            return GetRandomInt(min, max);
        else if (is_same_v<T, size_t>)
            return GetRandomInt(0, max);
        else if (is_same_v<T, double>)
            return GetRandomDouble(min, max, precision);
    }

    static double GetPrecisionScale(T precision) {
        return pow(10, precision + 2);
    }
    
    static int GetRandomInt(T min, T max) {
        return (rand() % (int)((max + 1.) - min)) + min;
    }

    static double GetRandomDouble(T min, T max, T precision) {      
        return (min)+(((rand() % (int)(GetPrecisionScale(precision))) / (GetPrecisionScale(precision))) * ((max)-(min)));
    }

private:
    CRandom() = delete;
    CRandom(const CRandom&) = delete;
    CRandom& operator=(const CRandom&) = delete;
};