#include <stdio.h>

double fahrenheitToCelsius(int f) {
    return 5.0 * (f-32) / 9.0;
}

int main() {
    for (int f = 0; f <= 300; f += 20) {
        printf("%3d %5.1f\n", f, fahrenheitToCelsius(f));
    }
    return 0;
}