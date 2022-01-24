#include <string.h>
int strrindex(const char * s, const char * t) {
    int i, j, k;
    for (i = strlen(s) - 1; i >= 0; i--) {
        for (j = i, k = 0; j < strlen(s) && t[k] != '\0' && s[j] == t[k]; j++, k++) {
            ;
        }
        if (k > 0 && t[k] == '\0') {
            return i;
        }
    }
    return -1;
}

#include <stdio.h>

int main() {
    char a[] = "testtesttesttest";
    char b[] = "test";
    char c[] = "bruh";
    printf("%d\n", strrindex(a, b));
    printf("%d\n", strrindex(a, c));
    return 0;
}