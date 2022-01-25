#define swap(t, x, y) {\
t temp; \
temp = x; \
x = y; \
y = temp; \
}

#include <stdio.h>
int main() {
    int a = 10;
    int b = 5;
    swap(int, a, b);
    printf("%d %d\n", a, b);
    return 0;
}