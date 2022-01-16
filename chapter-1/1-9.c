#include <stdio.h>
#include <stdbool.h>

void main() {
    bool is_repeated_space = false;
    int c;
    while ((c = getchar()) != EOF) {
        if (c == ' ' && is_repeated_space) {
            continue;
        }
        else if (c == ' ') {
            is_repeated_space = true;
            putchar(c);
        }
        else {
            is_repeated_space = false;
            putchar(c);
        }
    }
}