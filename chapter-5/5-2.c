#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

int getfloat(double* pd) {
    int c, sign;
    double power;
    bool negexp = false;
    while (isspace(c = getchar())) {
        ;
    }
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetc(c, stdin);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getchar();
    }
    if (!isdigit(c)) {
        ungetc(c, stdin);
        return 0;   
    }
    for (*pd = 0; isdigit(c); c = getchar()) {
        *pd = 10 * *pd + (c - '0');
    }

    if (c == '.') {
        c = getchar();
    }
    for (power = 1.0; isdigit(c); c = getchar()) {
        *pd = 10.0 * *pd + (c - '0');
        power *= 10;
    }
    if (c == 'e' || c == 'E') {
        c = getchar();
    }
    if (c == '-') {
        negexp = true;
        c = getchar();
    }
    int exp;
    for (exp = 0; isdigit(c); c = getchar()) {
        exp = 10 * exp + (c - '0');
    }
    power *= pow(10, exp * (negexp ? 1 : -1));
    *pd = sign * *pd / power;

    if (c != EOF) {
        ungetc(c, stdin);
    }
    return 0;
}

int main() {
    double a = 1.0;
    getfloat(&a);
    printf("%g\n", a);
    return 0;
}