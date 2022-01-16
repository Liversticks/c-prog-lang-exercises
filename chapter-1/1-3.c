#include <stdio.h>

void main() {
    float f, c;
    int low, high, step;

    low = 0;
    high = 300;
    step = 20;

    f = low;
    printf("%3s %6s\n", "F", "C");
    while (f <= high) {
        c = (5.0 / 9.0) * (f - 32);
        printf("%3.0f %6.1f\n", f, c);
        f += step;
    }
}