#include <string.h>

void lower(char* str) {
    // assumption: ASCII only
    for (int i = 0; i < strlen(str); i++) {
        str[i] = (str[i] >= 'A' && str[i] <= 'Z') ? str[i] + 32 : str[i];
    }
}

#include <stdio.h>
int main() {
    char test[] = "ABCDEFG";
    lower(test);
    printf("%s\n", test);
}