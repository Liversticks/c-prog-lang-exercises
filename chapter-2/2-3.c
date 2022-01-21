#include <string.h>

int htoi(char* s) {
    // only positive values
    int ret = 0;
    long long int power = 1;
    for (int i = strlen(s) - 1; i >= 0; i--) {
        if (s[i] >= '0' && s[i] <= '9') {
            ret += (s[i] - '0') * power; 
        }
        else if (s[i] >= 'a' && s[i] <= 'f') {
            ret += (s[i] - 'a' + 10) * power;
        }
        else if (s[i] >= 'A' && s[i] <= 'F') {
            ret += (s[i] - 'A' + 10) * power;
        }
        else if (s[i] == 'x' || s[i] == 'X') {
            if (s[i-1] == '0') {
                return ret;
            }
        }
        // printf("%d\n", ret);
        power *= 16;
    }
    return ret;
}

#include <stdio.h>
int main() {
    printf("%d\n", htoi("512345"));
}