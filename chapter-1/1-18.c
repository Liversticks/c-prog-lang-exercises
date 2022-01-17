#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* getline() {
    int c, currentSize = 1, len = 0;
    bool hasExtraWhitespace = true;
    char * ret = malloc(currentSize * sizeof(int));
    while ((c=getchar()) != EOF) {
        if (hasExtraWhitespace && (c == ' ' || c == '\t')) {
            continue;
        }
        if (c == ' ' || c == '\t') {
            hasExtraWhitespace = true;
        } else {
            hasExtraWhitespace = false;
        }
        //allocate more space if needed
        if (len - 2 > currentSize) {
            currentSize *= 2;
            ret = realloc(ret, currentSize * sizeof(int));
        }
        ret[len] = c;
        len++;
        if (c == '\n') {
            break;
        }
    }
    ret = realloc(ret, (len+1)*sizeof(int));
    ret[len] = '\0';
    return ret;
}

bool isNotEmptyLine(char * s) {
    return s[0] != '\n';
}

int main() {
    int len;
    int max = 0;
    char* s = NULL;
    while ((s = getline()) != NULL && strlen(s) > 0)  {
        if (isNotEmptyLine(s)) {
            printf("%s\n", s);
        }
        free(s);
    }
    if (s != NULL) {
        free(s);
    }
    return 0;
}