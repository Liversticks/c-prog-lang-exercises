void reverse(char * s) {
    char * end = s;
    if (*s) {
        while (*end) {
            end++;
        }
        end--;
        char temp;
        while (end > s) {
            temp = *s;
            *s = *end;
            *end = temp;
            s++;
            end--;
        }
    }
    
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char * a = malloc(sizeof(char) * 100);
    char * b = malloc(sizeof(char) * 100);
    char * c = malloc(sizeof(char) * 100);
    strcpy(a, "");
    strcpy(b, "1234");
    strcpy(c, "123456789");
    reverse(a);
    reverse(b);
    reverse(c);
    printf("%s %s %s\n", a, b, c);
    return 0;
}