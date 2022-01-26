#include <stdbool.h>

int positiveRemainder(int dividend, int divisor) {
    if (dividend >= 0) {
        return dividend % divisor;
    }
    else {
        return ((dividend / divisor) * divisor) - dividend;
    }
}

int itoa(int n, char* s) {
    bool isNegative = n < 0;
    int index = 0;
    if (isNegative) {
        s[index] = '-';
        s++;
    }
    if (n / 10) {
        index += itoa(((isNegative) ? (n / -10) : (n / 10)), s);
    }
    s[index] = (positiveRemainder(n, 10) + '0');
    return index+1;
}

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

int main() {
    char * s = malloc(100 * sizeof(char));
    memset(s, 0, 100 * sizeof(char));
    int n = INT_MIN;
    itoa(n, s);
    printf("%s\n", s);
    //printf("%d %d\n", INT_MIN / -10, INT_MIN % 10);
    free(s);
    return 0;
}