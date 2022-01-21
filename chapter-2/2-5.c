#include <stdlib.h>
#include <string.h>

int any(char* s1, char* s2) {
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
    for (int i = 0; i < strlen(s1); i++) {
        vectorIndex = s1[i] / 32;
        position = s1[i] % 32;
        flag = 1;
        flag = flag << position;
        if (vector[vectorIndex] & flag) {
            return i;
        }
    }
    return -1;
}

#include <stdio.h>
int main() {
    char* s2 = "test";
    char s1[] = "abcdefghijklmnopqrstuvwxyz";
    printf("%d\n", any(s1, s2));
    
    return 0;
}
