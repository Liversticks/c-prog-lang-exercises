#include <stdio.h>

void main() {
    for (int f = 300; f >= 0; f -= 20) {
        printf("%3d %6.1f\n", f, (5.0/9.0)*(f-32));
    }
}