#include <stdio.h>
#include <stdbool.h>

void main() {
    bool inWord = false;
    int c;

    while ((c = getchar()) != EOF) {
        if (inWord && ((c == ' ' || c == '\t' || c == '\n'))) {
            inWord = false;
            putchar('\n');
        }
        else {
            putchar(c);
            inWord = true;
        }
    }

}