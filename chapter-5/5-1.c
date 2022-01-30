#include <ctype.h>
#include <stdio.h>

int getint(int* pn) {
    int c, sign;
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
    for (*pn = 0; isdigit(c); c = getchar()) {
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;
    if (c != EOF) {
        ungetc(c, stdin);
    }
    return 0;
}

int main() {
    int a = 45;
    getint(&a);
    printf("\n%d\n", a);
    return 0;
}