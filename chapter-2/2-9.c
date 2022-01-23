int bitcount(unsigned int x) {
    // If x is odd, x-1 is x except the last bit is set to 0. x & x-1 = x-1 which is now even (so the rightmost 1 bit is gone)
    // if x is even, x-1 is x except the rightmost 0 bits of x are set to 1. As x ends with 1 000... and x-1 ends with 0 111...
    // x &= (x-1) will result in x ending in all 0s.

    if (x == 0) return 0;
    int count = 1;
    while ((x &= (x-1)) != 0) {
        count++;
    }
    return count;
}

#include <stdio.h>
int main() {
    unsigned int x = 15;
    printf("%d\n", bitcount(x));
    return 0;
}