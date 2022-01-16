#include <stdio.h>

void main() {
    float f, c;
    int low, high, step;

    low = 0;
    high = 300;
    step = 20;

    c = low;
    printf("%3s %6s\n", "C", "F");
    while (c <= high) {
        f = (9.0 / 5.0) * c + 32;
        printf("%3.0f %6.1f\n", c, f);
        c += step;
    }
}