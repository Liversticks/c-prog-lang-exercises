#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

#define MAXOP 100

#define NUMBER '0'

int getch(void);
void ungetch(int);
int getop(char *);
void push(double);
double pop(void);
void init(void);
void destroy(void);

// For future expansion, type should be an enum (decouples operators from representation in input)

int main() {
    int type;
    double op2;
    char s[MAXOP];
    double recent = 0;

    double variables[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
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
            case '^':
                op2 = pop();
                push(pow(pop(), op2));
                break;
            // e ^ x
            case '#':
                push(exp(pop()));
                break;
            // ln(x)
            case '@':
                op2 = pop();
                if (op2 > 0) {
                    push(log(op2));
                }
                else {
                    printf("Error: cannot take logarithm of a non-positive value.\n");
                }
                break;
            case 'R':
                push(recent);
                break;
            /*
            case 'a':
            case 'b':
            case 'c':
            case 'd':
            case 'e':
            case 'f':
            case 'g':
            case 'h':
            case 'i':
            case 'j':
            case 'k':
            case 'l':
            case 'm':
            case 'n':
            case 'o':
            case 'p':
            case 'q':
            case 'r':
            case 's':
            case 't':
            case 'u':
            case 'v':
            case 'w':
            case 'x':
            case 'y':
            case 'z':
                push();
                break;
            */
            case '\n':
                recent = pop();
                printf("\t%.8g\n", recent);
                break;
            default:
                printf("Error: unrecognized command (%s)\n", s);
                break;
        }
    }
    return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void peek_stack() {
    printf("Stack top: %g.\n", val[sp]);
}

void duplicate_top() {
    if (sp < MAXVAL) {
        double temp = val[sp++];
        val[sp] = temp;
    }
    else {
        printf("Error: stack full, cannot duplicate top element.\n");
    }
}

void swap_top() {
    if (sp < MAXVAL && sp > 0) {
        double temp = val[sp];
        val[sp] = val[sp-1];
        val[sp-1] = temp;
    }
}

void clear_stack() {
    sp = 0;
}

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