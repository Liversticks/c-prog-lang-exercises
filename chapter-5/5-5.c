#include <stddef.h>

void strncpy(char * s, char * t, size_t n) {
    for (size_t x = 0; x < n && (*s++ = *t++); x++) {
        ;
    }
}

void strncat(char * s, char * t, size_t n) {
    // alternative: s += strlen(s);
    while (*s) {
        s++;
    }
    size_t x = 0;
    while ((*s++ = *t++) && x < n) {
        x++;
    }
    *s = '\0';
}

int strncmp(char * s, char * t, size_t n) {
    for (size_t x = 0; x < n && (*s == *t); x++, s++, t++) {
        if (*s == '\0') {
            return 0;
        }
    }
    return *s - *t;
}

#include <stdio.h>
#include <stdlib.h>

int main() {
    char * a = "abcd";
    char * b = "abcdeftest";
    char * c = malloc(sizeof(char) * 100);
    for (int i = 0; i < 100; i++) {
        c[i] = '\0';
    }
    printf("%d\n", strncmp(a, b, 3));
    strncpy(c, b, 6);
    strncat(c, b, 10);
    printf("%s\n", c);
    free(c);
    return 0;
}