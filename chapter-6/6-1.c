#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

struct key {
    char* word;
    int count;
};

typedef struct key key;

key keytab[] = {
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    "do", 0,
    "double", 0,
    "else", 0,
    "enum", 0,
    "extern", 0,
    "float", 0,
    "for", 0,
    "goto", 0,
    "if", 0,
    "int", 0,
    "long", 0,
    "register", 0,
    "return", 0,
    "short", 0,
    "signed", 0,
    "sizeof", 0,
    "static", 0,
    "struct", 0,
    "switch", 0,
    "typedef", 0,
    "union", 0,
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0
};

#define NKEYS sizeof(keytab)/sizeof(key)

#define MAXWORD 100

int getword(char*, int);
int bsearch(char*, key*, int);

int main() {
    int n;
    char word[MAXWORD];

    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            if ((n = bsearch(word, keytab, NKEYS)) >= 0) {
                keytab[n].count++;
            }
        }
    }
    for (n = 0; n < NKEYS; n++) {
        if (keytab[n].count > 0) {
            printf("%4d %s\n", keytab[n].count, keytab[n].word);
        }
    }
    return 0;
}

int bsearch(char* word, key tab[], int n) {
    int cond;
    int low = 0, high = n-1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if ((cond = strcmp(word, tab[mid].word)) < 0) {
            high = mid - 1;
        }
        else if (cond > 0) {
            low = mid + 1;
        }
        else {
            return mid;
        }
    }
    return -1;
}

int getword(char* word, int lim) {
    int c, getch(void);
    void ungetch(int);
    char* w = word;

    while (isspace(c = getch())) {
        ;
    }
    if (c != EOF) {
        *w++ = c;
    }
    // find comments
    if (c == '/') {
        c = getch();
        if (c == '/') {
            while ((c = getch()) != '\n') {
                ;
            }
            *w = '\0';
            return '/';
        }
        else if (c == '*') {
            bool commentEnd = false;
            while (!commentEnd) {
                c = getch();
                if (c == '*') {
                    if ((c = getch()) == '/') {
                        commentEnd = true;
                    }
                    else {
                        ungetch(c);
                    }
                }
            }
            *w = '\0';
            return '/';
        }
    }
    // find string literals
    if (c == '\"') {
        while((c = getch()) != '\"' && c != '\n') {
            ;
        }
        *w = '\0';
        return '\"';
    }
    // find preprocessor statements
    bool canContinue = isalpha(c) || c == '_' || c == '\'' || c == '#';
    if (!canContinue) {
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++) {
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];
}
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch() {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    }
    else {
        buf[bufp++] = c;
    }
}
