#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* getline() {
    int c, currentSize = 1, len = 0;
    char * ret = malloc(currentSize * sizeof(int));
    for (int i = 0; (c=getchar()) != EOF; i++) {
        //allocate more space if needed
        if (i - 2 > currentSize) {
            currentSize *= 2;
            ret = realloc(ret, currentSize * sizeof(int));
        }
        ret[i] = c;
        len++;
        if (c == '\n') {
            break;
        }
    }
    ret = realloc(ret, (len+1)*sizeof(int));
    ret[len] = '\0';
    return ret;
}

void reverse(char * s) {
    int temp;
    int workingLen = strlen(s) - 2; // account for \n at end of line
    for (int i = 0; i <= workingLen/2; i++) {
        temp = s[i];
        s[i] = s[workingLen - i];
        s[workingLen - i] = temp;
    }
}

int main() {
    int len;
    int max = 0;
    char* s = NULL;
    while ((s = getline()) != NULL && strlen(s) > 0)  {
        reverse(s);
        printf("%s\n", s);
        free(s);
    }
    if (s != NULL) {
        free(s);
    }
    return 0;
}