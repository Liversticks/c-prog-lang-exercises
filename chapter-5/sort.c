#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

char** readlines(size_t * nlines_out);
void writelines(char* lineptr[], size_t nlines);
void freelines(char** lineptr, size_t nlines);

void my_qsort(void * lineptr[], int left, int right, bool increasing, int (*comp)(void*, void*));
int numcmp(char*, char*);
int foldcmp(char*, char*);

int main(int argc, char** argv) {
    bool numeric = false;
    bool increasing = true;
    bool fold = false;

    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            if (argv[i][0] == '-') {
                switch (argv[i][1]) {
                    case 'n':
                        numeric = true;
                        break;
                    case 'r':
                        increasing = false;
                        break;
                    case 'f':
                        fold = true;
                        break;
                }
            }
        }
    }
    size_t nlines = 0;
    char** lineptr = readlines(&nlines);
    // numeric will override fold if both are specified
    my_qsort((void**)lineptr, 0, nlines-1, increasing, (int (*)(void*, void*))(numeric ? numcmp : (fold ? foldcmp : strcmp)));
    writelines(lineptr, nlines);
    freelines(lineptr, nlines);
    return 0;

}

void my_qsort(void* v[], int left, int right, bool increasing, int (*comp)(void*, void*)) {
    void swap(void *v[], int, int);

    if (left >= right) {
        return;
    }
    swap(v, left, (left + right)/2);
    int last = left;
    for (int i = left+1; i <= right; i++) {
        if (increasing) {
            if ((*comp)(v[i], v[left]) < 0) {
                swap(v, ++last, i);
            }
        }
        else {
            if ((*comp)(v[i], v[left]) > 0) {
                swap(v, ++last, i);
            }
        }
    }
    swap(v, left, last);
    my_qsort(v, left, last-1, increasing, comp);
    my_qsort(v, last+1, right, increasing, comp);
}

#include <ctype.h>
int foldcmp(char * s1, char * s2) {
    char * s1_temp = malloc(sizeof(char) * strlen(s1) + 1);
    memset(s1_temp, 0, strlen(s1)+1);
    char * s2_temp = malloc(sizeof(char) * strlen(s2) + 1);
    memset(s2_temp, 0, strlen(s2)+1);
    for (size_t i = 0; i < strlen(s1); i++) {
        s1_temp[i] = tolower(s1[i]); 
    }
    for (size_t i = 0; i < strlen(s2); i++) {
        s2_temp[i] = tolower(s2[i]);
    }
    int ret = strcmp(s1_temp, s2_temp);
    free(s1_temp);
    free(s2_temp);
    return ret;
}

int numcmp(char * s1, char * s2) {
    double v1 = atof(s1);
    double v2 = atof(s2);
    if (v1 < v2) {
        return -1;
    }
    else if (v1 > v2) {
        return 1;
    }
    return 0;
}

void swap(void* v[], int i, int j) {
    void * temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
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
    for (size_t i = 0; i < lines; i++) {
        printf("%s", lineptr[i]);
    }
}

void freelines(char** lineptr, size_t lines) {
    for (size_t i = 0; i < lines; i++) {
        free(lineptr[i]);
    }
    free(lineptr);
}