#include <stdio.h>

void main() {
    //assumption: only ASCII chars
    int charset[128];
    for (int i = 0; i < 128; i++) {
        charset[i] = 0;
    }
    int c;
    while ((c = getchar()) != EOF) {
        charset[c]++;
    }
    for (int i = 0; i < 128; i++) {
        if (charset[i] != 0) {
            printf("%c: %d\n", i, charset[i]);
        }
    }
}