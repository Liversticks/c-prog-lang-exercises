// Adapt the calculator program from chapter 4
// IMPORTANT: Depending on the shell, certain operators may need to be escaped

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

enum calcType {
    NUMBER,
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION,
    MODULUS,
    POWER,
    ERROR,
    END
};

typedef enum calcType calcType;

calcType getop(char *);
void push(double);
double pop(void);

int main(int argc, char** argv) {
    calcType type;
    double op2;

    for (int i = 1; i <= argc; i++) {
        type = getop(argv[i]);
        switch(type) {
            case NUMBER:
                push(atof(argv[i]));
                break;
            case ADDITION:
                push(pop() + pop());
                break;
            case MULTIPLICATION:
                push(pop() * pop());
                break;
            case SUBTRACTION:
                op2 = pop();
                push(pop() - op2);
                break;
            case DIVISION:
                op2 = pop();
                if (op2 != 0.0) {
                    push(pop() / op2);
                }
                else {
                    puts("Error: division by 0.");
                }
                break;
            case MODULUS:
                op2 = pop();
                push((long)pop() % (long)op2);
                break;
            case POWER:
                op2 = pop();
                push(pow(pop(), op2));
                break;
            case END:
                printf("\t%.8g\n", pop());
                return 0;
            default:
                puts("Unrecognized option.");
                return 1;
        }
    }    
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
        puts("Error: stack empty.");
        return 0.0;
    }
}

calcType parseNumber(char * s, int start) {
    if (s[start] == '.') {
        start++;
    }
    while (s[start]) {
        if (!isdigit(s[start]) && s[start] != '.') {
            return ERROR;
        }
        start++;
    }
    if (s[start] == '.') {
        start++;
    }
    while (s[start]) {
        if (!isdigit(s[start])) {
            return ERROR;
        }
        start++;
    }
    return NUMBER;
}

calcType getop(char* s) {
    int j = 0;

    if (s == NULL) {
        return END;
    }
    if (isdigit(s[j]) || s[j] == '.') {
        return parseNumber(s, j);
    }
    else if (s[j] == '+') {
        return ADDITION;
    }
    else if (s[j] == '*') {
        return MULTIPLICATION;
    }
    else if (s[j] == '/') {
        return DIVISION;
    }
    else if (s[j] == '%') {
        return MODULUS;
    }
    else if (s[j] == '^') {
        return POWER;
    }
    else if (s[j] == '-') {
        j++;
        if (!(s[j])) {
            return SUBTRACTION;
        }
        else {
            return parseNumber(s, j);
        }
    }
    return ERROR;
}