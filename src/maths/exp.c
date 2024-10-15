#include "libmath.h"

double exp(double x) {
    double sum = 1.0;
    double term = 1.0;

    for (int n = 1; n < 100; n++) {
        term *= x / n;
        sum += term;

        if (term < 1e-15) {
            break;
        }
    }

    return sum;
}



