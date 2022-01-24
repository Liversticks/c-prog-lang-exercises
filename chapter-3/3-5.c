#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

int positiveRemainder(int dividend, int divisor) {
    if (dividend >= 0) {
        return dividend % divisor;
    }
    else {
        return ((dividend / divisor) * divisor) - dividend;
    }
}

void reverse(char * s) {
    int temp;
    int workingLen = strlen(s) - 1;
    for (int i = 0; i <= workingLen/2; i++) {
        temp = s[i];
        s[i] = s[workingLen - i];
        s[workingLen - i] = temp;
    }
}

void reverseInt(int * s, int len) {
    int temp;
    for (int i = 0; i <= len/2; i++) {
        temp = s[i];
        s[i] = s[len - i];
        s[len - i] = temp;
    }
}

void itoa(int n, char* s) {
    int i = 0;
    bool sign = n < 0;
    do {
        s[i++] = positiveRemainder(n, 10) + '0';
    } while ((n /= 10) != 0);
    if (sign) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

char toHex[16] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
};

void toHexStr(int * digits, int len, char * s) {
    int i = 0;
    if (digits[i] == '-') s[i++] = '-';
    for (; i < len; i++) {
        s[i] = toHex[digits[i]];
    }
    s[i] = '\0';
}

void toArbStr(int * digits, int len, char * s) {
    int i = 0;
    if (digits[i] == '-') s[i++] = '-';
    for (int dc = 0; dc < len; dc++) {
        char a[11] = {0,0,0,0,0,0,0,0,0,0,0};
        itoa(digits[dc], a);
        for (int j = 0; j < strlen(a); j++) {
            s[i++] = a[j];
        }
        if (dc + 1 < len) {
            s[i++] = ',';
        }
        
    }
    s[i] = '\0';
}

// only works on positive numbers (because logs are used to calculate the length of the number)
void itob(int n, char * s, int b) {
    // extra 1 for possible - sign
    bool sign = n < 0;
    int length = floor(log(n) / log(b)) + 1 + (sign ? 1 : 0);
    int * digits = malloc(sizeof(int) * length);
    int i = 0;
    do {
        digits[i++] = positiveRemainder(n, b);
    } while((n /= b) != 0);
    if (sign) {
        digits[i++] = '-';
    }
    reverseInt(digits, length-1);
    if (b <= 16) {
        toHexStr(digits, length, s);
    }
    else {
        toArbStr(digits, length, s);
    }
    free(digits);
}

#include <stdio.h>
#include <limits.h>
int main() {
    int a = INT_MAX;
    char * s = malloc(sizeof(char) * 100);
    itob(a, s, 16);
    printf("%s\n", s);
    itob(a, s, 64);
    printf("%s\n", s);
    itob(a, s, 10);
    printf("%s\n", s);
    free(s);
    return 0;
}