#include "libmath.h"

double log(double x) {
    if (x <= 0) {
        return -1.0 / 0.0; 
    }

    double y = (x - 1) / (x + 1);
    double y2 = y * y;
    double result = 0.0;
    double num = y;
    double denom = 1;

    for (int i = 0; i < 100; i++) {
        result += num / denom;
        num *= y2;
        denom += 2;
    }

    return 2 * result;
}

