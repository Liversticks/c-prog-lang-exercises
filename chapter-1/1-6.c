#include <stdio.h>

void main() {
    // Can use CTRL+D on the shell to signal end-of-transmission
    printf("%d\n", getchar() != EOF);
}