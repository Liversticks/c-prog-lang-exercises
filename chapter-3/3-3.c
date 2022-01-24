#include <string.h>

void expand(char* s1, char* s2) {
    // expand a-z into abc...xyz
    int s1c, s2c = 0, start, end;
    for (s1c = 0; s1c < strlen(s1); s1c++) {
        if ((s1c == 0 || s1c == strlen(s1) - 1) && s1[s1c] == '-') {
            s2[s2c] = '-';
            s2c++;
        }
        else {
            if ((s1[s1c] >= 'A' && s1[s1c] <= 'Z') || (s1[s1c] >= 'a' && s1[s1c] <= 'z') || (s1[s1c] >= '0' && s1[s1c] <= '9')) {
                // try and parse entire range
                if (s1[s1c+1] == '-' && ((s1c + 2) < strlen(s1))) {
                    if ((s1[s1c+2] > s1[s1c]) && (((s1[s1c] >= 'A' && s1[s1c] <= 'Z') && (s1[s1c+2] >= 'A' && s1[s1c+2] <= 'Z')) || ((s1[s1c] >= 'a' && s1[s1c] <= 'z') && (s1[s1c+2] >= 'a' && s1[s1c+2] <= 'z')) || ((s1[s1c] >= '0' && s1[s1c] <= '9') && (s1[s1c+2] >= '0' && s1[s1c] <= '9')))) {
                        for (char low = s1[s1c]; low <= s1[s1c+2]; low++) {
                            s2[s2c++] = low;
                        }
                        s1c += 2;
                    }
                    else {
                        //copy block of 3 characters
                        s2[s2c] = s1[s1c];
                        s2[++s2c] = s1[++s1c];
                        s2[++s2c] = s1[++s1c];
                        s2c++;
                    }
                }
                else {
                    s2[s2c] = s1[s1c];
                    s2c++;
                }
            }
            else {
                s2[s2c] = s1[s1c];
                s2c++;
            }
        }
    }
    s2[s2c] = '\0';
}

#include <stdio.h>
#include <stdlib.h>

int main() {
    char s1[] = "a-";
    char s2[] = "aaaaabvc";
    char s3[] = "-a-";
    char s4[] = "sd3a-ffds";
    char s5[] = "ADA-Gasd3";
    char s6[] = "235-8sdf";
    char s7[] = "asda-9a";
    char s8[] = "dfgkjM-A";
    char s9[] = "asd--asd";
    char * test = malloc(100 * sizeof(char));
    expand(s1, test);
    printf("%s\n", test);
    expand(s2, test);
    printf("%s\n", test);
    expand(s3, test);
    printf("%s\n", test);
    expand(s4, test);
    printf("%s\n", test);
    expand(s5, test);
    printf("%s\n", test);
    expand(s6, test);
    printf("%s\n", test);
    expand(s7, test);
    printf("%s\n", test);
    expand(s8, test);
    printf("%s\n", test);
    expand(s9, test);
    printf("%s\n", test);
    free(test);
    return 0;
}