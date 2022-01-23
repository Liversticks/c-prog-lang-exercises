#include <string.h>

void escape(char* s, char* t) {
    int tcount = 0;
    for (int i = 0; i < strlen(s); i++) {
        switch(s[i]) {
            case '\a': {
                t[tcount] = '\\';
                t[++tcount] = 'a';
                break; 
            }
            case '\b': {
                t[tcount] = '\\';
                t[++tcount] = 'b';
                break;
            }
            case '\e': {
                t[tcount] = '\\';
                t[++tcount] = 'e';
                break;
            }
            case '\f': {
                t[tcount] = '\\';
                t[++tcount] = 'f';
                break;
            }
            case '\n': {
                t[tcount] = '\\';
                t[++tcount] = 'n';
                break;
            }
            case '\r': {
                t[tcount] = '\\';
                t[++tcount] = 'r';
                break;
            }
            case '\t': {
                t[tcount] = '\\';
                t[++tcount] = 't';
                break;
            }
            case '\v': {
                t[tcount] = '\\';
                t[++tcount] = 'v';
                break;
            }
            case '\\': {
                t[tcount] = '\\';
                t[++tcount] = '\\';
                break;
            }
            case '\'': {
                t[tcount] = '\\';
                t[++tcount] = '\'';
                break;
            }
            case '\"': {
                t[tcount] = '\\';
                t[++tcount] = '\"';
                break;
            }
            case '\?': {
                t[tcount] = '\\';
                t[++tcount] = '\?';
                break;
            }
            default: {
                t[tcount] = s[i];
                break;
            }
        }  
        tcount++;
    }
    t[tcount] = '\0';
}

void unescape(char* s, char* t) {
    int scount = 0, tcount = 0;
    while (s[scount] != '\0') {
        if (s[scount] == '\\') {
            switch (s[++scount]) {
                case 'a': {
                    t[tcount] = '\a';
                    break;
                }
                case 'b': {
                    t[tcount] = '\b';
                    break;
                }
                case 'e': {
                    t[tcount] = '\e';
                    break;
                }
                case 'f': {
                    t[tcount] = '\f';
                    break;
                }
                case 'n': {
                    t[tcount] = '\n';
                    break;
                }
                case 'r': {
                    t[tcount] = '\r';
                    break;
                }
                case 't': {
                    t[tcount] = '\t';
                    break;
                }
                case 'v': {
                    t[tcount] = '\\';
                    break;
                }
                case '\\': {
                    t[tcount] = '\\';
                    break;
                }
                case '\'': {
                    t[tcount] = '\'';
                    break;
                }
                case '\"': {
                    t[tcount] = '\"';
                    break;
                }
                case '\?': {
                    t[tcount] = '\?';
                    break;
                }
            }
        }
        else {
            t[tcount] = s[scount];
        }
        scount++;
        tcount++;
    }
    t[tcount] = '\0';
}

#include <stdio.h>
#include <stdlib.h>
int main() {
    char s[100] = "abcdef\nasd\tds\n";
    char* r = malloc(100 * sizeof(char));
    char* t = malloc(100 * sizeof(char));
    escape(s, r);
    unescape(r, t);
    printf("%s\n", r);
    printf("%s\n", t);
    free(r);
    free(t);
    return 0;
}