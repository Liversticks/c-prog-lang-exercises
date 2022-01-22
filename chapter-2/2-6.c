//#include <stdio.h>
int setbits(int x, int p, int n, int y) {
    // p is 0-indexed

    // get the rightmost n bits of y
    // assumption: 8 bits/byte
    int ymask = ~0u >> (sizeof(int) * 8 - n);
    //printf("%d\n", ymask);
    y = y & ymask;
    //printf("%d\n", y);

    // transform mask to correct position
    if (p < (sizeof(int) * 8 - n)) {
        // left shift
        y = y << ((sizeof(int) * 8 - n) - p);
    }
    else if (p > (sizeof(int) * 8 - n)) {
        // right shift
        y = y >> (p - (sizeof(int) * 8 - n));
    }
    // y is in the correct position, do nothing
    //printf("%d\n", y);

    // zero affected bits in x
    // get the left side
    int xleft = x & (~0 << (sizeof(int) * 8 - p));
    // get the right side
    int xright = x & (~0u >> (p + n));
    //printf("%d\n", xleft);
    //printf("%d\n", xright);
    x = xleft | xright;
    //printf("%d\n", x);

    // transform mask to align with position p of x (note: will overflow if n + p >= |x|)
    return x | y;
}

#include <stdio.h>
int main() {
    int x = 74;
    int y = 2;
    int p = 26;
    int n = 2;
    printf("%d\n", setbits(x, p, n, y));
    return 0;
}