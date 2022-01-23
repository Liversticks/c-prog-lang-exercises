int invert(int x, int p, int n) {
    // p is 0-indexed

    // zero affected bits in x
    // get the left side
    int xleft = x & (~0 << (sizeof(int) * 8 - p));
    // get the right side
    int xright = x & (~0u >> (p + n));
    //printf("%d\n", xleft);
    //printf("%d\n", xright);
    int xunch = xleft | xright;
    //printf("%d\n", x);

    int xch = ~x;

    if ((p + n) < sizeof(int) * 8) {
        xch = xch >> (sizeof(int) * 8 - (p + n));
        xch = xch << (sizeof(int) * 8 - (p + n) + p);
        xch = xch >> p;
    }
    else {
        xch = (xch << p) >> p;
    }

    return xch | xunch;
}

#include <stdio.h>
int main() {
    int x = 0x2E6B;
    int p = 20;
    int n = 4;
    printf("%d\n", invert(x, p, n));
}