int rightrot(int x, int n) {
    int shift = n % (sizeof(int) * 8);
    int shifted = x >> shift;
    int rotated = x << (sizeof(int) * 8 - shift);
    return shifted | rotated;
}

#include <stdio.h>
int main() {
    int x = 0x12345678;
    int n = 4;
    printf("%d\n", rightrot(x, n));
    return 0;
}