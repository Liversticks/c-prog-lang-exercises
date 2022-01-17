#include <stdio.h>

int getline(char line[], int lim) {
    int c, i, max = 0;
    for (i = 0; (c=getchar()) != EOF; i++) {
        if (c == '\n') {
            line[i] = c;
            break;
        }
        if (i < lim) {
            line[i] = c;
        }
        max++;
    }
    i = i >= lim ? lim-1 : i;
    line[i] = '\0';
    return max;
}

void copy(char* to, char* from) {
    int i = 0;
    while((to[i] = from[i]) != '\0') {
        i++;
    }
}

int main() {
    int len;
    int max = 0;
    const int MAX = 10;
    char line[MAX];
    char longest[MAX];
    while ((len = getline(line, MAX)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) printf("Length: %d, %s\n", max, longest);
    return 0;
}