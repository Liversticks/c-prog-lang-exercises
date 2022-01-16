#include <stdio.h>
#include <stdbool.h>

void main() {
    // 1-9, 10+
    int lengths[10];
    for (int i = 0; i < 10; i++) {
        lengths[i] = 0;
    }
    bool inWord = false;
    int c;
    int length = 0;

    while ((c = getchar()) != EOF) {
        if (inWord && ((c == ' ' || c == '\t' || c == '\n'))) {
            inWord = false;
            if (length >= 10) {
                lengths[9]++;
            }
            else {
                lengths[length-1]++;
            }
            length = 0;
        }
        else if ((c != ' ') && (c != '\t') && (c != '\n')) {
            inWord = true;
            length++;
        }
    }

    for (int i = 0; i < 9; i++) {
        if (lengths[i] != 0) {
            printf("Length %d: %d\n", i+1, lengths[i]);
        }
    }
    if (lengths[9] != 0) {
        printf("Length 10+: %d\n", lengths[9]);
    }
    
}