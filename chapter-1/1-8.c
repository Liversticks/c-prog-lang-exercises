#include <stdio.h>

void main() {
    long spaces = 0, tabs = 0, lines = 1;
    int c;

    while((c = getchar()) != EOF) {
        if (c == ' ') {
            spaces++;
        }
        else if (c == '\t') {
            tabs++;
        }
        else if (c == '\n') {
            lines++;
        }
    }
    printf("\nSpaces: %ld, Tabs: %ld, Lines: %ld\n", spaces, tabs, lines);
}