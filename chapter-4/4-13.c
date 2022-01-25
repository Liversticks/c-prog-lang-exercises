#include <string.h>

void reverseRec(char * s, int len) {
    if (len < 2) return;
    char temp = s[0];
    s[0] = s[len-1];
    s[len - 1] = temp;
    reverseRec(s+1, len-2);
}

void reverse(char * s) {
    reverseRec(s, strlen(s));    
}

#include <stdio.h>
int main() {
    char a[] = "abcdefg";
    reverse(a);
    printf("%s\n", a);
    return 0;
}