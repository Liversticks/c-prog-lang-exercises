#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void* a, const void* b) {
    return strcoll((char*)a, (char*)b);
}

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

char** readlines(size_t* nlines_out) {
    size_t nlines = 0, currentSize = 1, len = 0;
    char ** lineptr = malloc(currentSize * sizeof(char*));
    char * p;
    for (size_t i = 0; (p = getline()) != NULL && strlen(p) > 1; i++) {
        if (i >= currentSize) {
            currentSize *= 2;
            lineptr = realloc(lineptr, currentSize * sizeof(char*));
        }
        lineptr[nlines++] = p;
    }
    lineptr = realloc(lineptr, nlines * sizeof(char*));
    *nlines_out = nlines;
    return lineptr;
}

void writelines(char** lineptr, size_t lines) {
    for (size_t i; i < lines; i++) {
        printf("%s", lineptr[i]);
    }
}

void freelines(char** lineptr, size_t lines) {
    for (size_t i = 0; i < lines; i++) {
        free(lineptr[i]);
    }
    free(lineptr);
}

int main() {
    size_t lines = 0;
    char** lineptr = readlines(&lines);
    qsort(lineptr, lines, sizeof(char*), compare);
    writelines(lineptr, lines);
    freelines(lineptr, lines);
    return 0;
}