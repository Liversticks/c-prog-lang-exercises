#include <stdbool.h>

bool strend(char * s, char * t) {
    // alternative: s += strlen(s);
    char * sstart = s;
    char * tstart = t;
    while (*s) {
        s++;
    }
    while (*t) {
        t++;
    }
    while (s != sstart && t != tstart) {
        if (*s != *t) {
            return false;
        }
        s--;
        t--;
    }
    if (t != tstart) {
        return false;
    }
    return true;
}

#include <stdio.h>

int main() {
    char * a = "test";
    char * b = "abcdeftest";
    bool ab = strend(b, a);
    bool ba = strend(a, b);
    printf("%d %d\n", ab, ba);
    return 0;
}