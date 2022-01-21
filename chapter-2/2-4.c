#include <stdlib.h>
#include <string.h>

void squeeze(char* s1, char* s2) {
    // on my machine, sizeof(char) = 1 byte --> support 128 positive characters (0-127)
    // additionally, this ignores case (a and A are treated as separate characters)
    int vector[4] = {0, 0, 0, 0};
    int vectorIndex, position;
    unsigned int flag;
    for (int i = 0; i < strlen(s2); i++) {
        vectorIndex = s2[i] / 32;
        position = s2[i] % 32;
        flag = 1;
        flag = flag << position;
        vector[vectorIndex] = vector[vectorIndex] | flag;
    }
    int j = 0;
    for (int i = 0; i < strlen(s1); i++) {
        vectorIndex = s1[i] / 32;
        position = s1[i] % 32;
        flag = 1;
        flag = flag << position;
        if (!(vector[vectorIndex] & flag)) {
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
}

#include <stdio.h>
int main() {
    char* s2 = "test";
    char s1[] = "abcdefghijklmnopqrstuvwxyz";
    squeeze(s1, s2);
    printf("%s\n", s1);
    
    return 0;
}
