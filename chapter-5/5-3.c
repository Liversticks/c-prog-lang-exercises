void strcat(char * s, char * t) {
    // alternative: s += strlen(s);
    while (*s) {
        s++;
    }
    while (*s++ = *t++) {
        ;
    }
    *s = '\0';
}

#include <stdlib.h>
#include <stdio.h>

int main() {
    char * a = "test";
    char * b = malloc(100 * sizeof(char));
    char * temp = b;
    for (int i = 0; i < 100; i++) {
        *temp = '\0';
        temp += 1;
    }
    strcat(b, a);
    printf("%s\n", b);
    free(b);
    return 0;
}