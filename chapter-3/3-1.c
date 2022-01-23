#include <math.h>

int binsearch(int x, int* v, int n) {
    // from Wikipedia, "binary search algorithm"
    int low = 0, high = n-1, mid;
    while (low != high) {
        mid = ceil((low + high) / 2.0);
        if (v[mid] > x) high = mid - 1;
        else low = mid; 
    }
    if (v[low] == x) return low;
    return -1;
}

#include <stdio.h>
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 3;
    printf("%d\n", binsearch(target, arr, 10));
}