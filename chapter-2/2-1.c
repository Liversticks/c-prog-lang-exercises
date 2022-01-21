#include <limits.h>
#include <float.h>
#include <stdio.h>

int main() {
    printf("Size of char: %lu\n", sizeof(char));
    printf("Size of short: %lu\n", sizeof(short));
    printf("Size of int: %lu\n", sizeof(int));
    printf("Size of long: %lu\n", sizeof(long));
    printf("Size of long long: %lu\n", sizeof(long long));
    printf("Size of float: %lu\n", sizeof(float));
    printf("Size of double: %lu\n", sizeof(double));
    printf("Size of long double: %lu\n", sizeof(long double));
    
    printf("Smallest signed char: %d\n", CHAR_MIN);
    printf("Largest signed char: %d\n", CHAR_MAX);
    printf("Largest unsigned char: %d\n", UCHAR_MAX);

    printf("Smallest signed short: %d\n", SHRT_MIN);
    printf("Largest signed short: %d\n", SHRT_MAX);
    printf("Largest unsigned short: %d\n", USHRT_MAX);

    printf("Smallest signed integer: %d\n", INT_MIN);
    printf("Largest signed integer: %d\n", INT_MAX);
    printf("Largest unsigned integer: %u\n", UINT_MAX);

    printf("Smallest signed long: %ld\n", LONG_MIN);
    printf("Largest signed long: %ld\n", LONG_MAX);
    printf("Largest unsigned long: %lu\n", ULONG_MAX);

    printf("Smallest signed long long: %lld\n", LLONG_MIN);
    printf("Largest signed long long: %lld\n", LLONG_MAX);
    printf("Largest unsigned long long: %llu\n", ULLONG_MAX);

    printf("Smallest float: %f\n", FLT_MIN);
    printf("Largest float: %f\n", FLT_MAX);

    printf("Smallest double-precision float: %lf\n", DBL_MIN);
    printf("Largest double-precision float: %lf\n", DBL_MAX);

    printf("Smallest long double: %Lf\n", LDBL_MIN);
    printf("Largest long double: %Lf\n", LDBL_MAX);

    return 0;
}