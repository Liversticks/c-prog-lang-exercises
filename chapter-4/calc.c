#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAXOP 100

#define NUMBER '0'

int getch(void);
void ungetch(int);
int getop(char *);
void push(double);
double pop(void);
void init(void);
void destroy(void);

int main() {
    int type;
    double op2;
    char s[MAXOP];
    init();

    while ((type = getop(s)) != EOF) {
        switch(type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0) {
                    push(pop() / op2);
                }
                else {
                    printf("Error: division by 0.\n");
                }
                break;
            case '%':
                op2 = pop();
                push((long)pop() % (long)op2);
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("Error: unrecognized command (%s)\n", s);
                break;
        }
    }
    destroy();
    return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f) {
    if (sp < MAXVAL) {
        val[sp++] = f;
    }
    else {
        printf("Error: stack full, cannot push %g.\n", f);
    }
}

double pop(void) {
    if (sp > 0) {
        //printf("%f\n", val[sp-1]);
        return val[--sp];
    }
    else {
        printf("Error: stack empty.\n");
        return 0.0;
    }
}

char * line;
int linePos = 0;

char * getline_nonlib(void);

void init() {
    line = getline_nonlib();
}

void destroy() {
    free(line);
}

int getop(char* s) {
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t') {
        ;
    }
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-') {
        return c; // not a number
    }
    // peek at next
    int next = getch();
    ungetch(next);
    if (c == '-' && !isdigit(next)) {
        return c;
    }
    bool isNegative = false;
    if (c == '-') {
        s[0] = '-';
        isNegative = true;
    }
    i = 0;
    if (isNegative || isdigit(c)) {
        while (isdigit(s[++i] = c = getch())) {
            ;
        }
    }
    if (c == '.') {
        while (isdigit(s[++i] = c = getch())) {
            ;
        }
    }
    s[i] = '\0';
    if (c != EOF) {
        ungetch(c);
    }
    return NUMBER;
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