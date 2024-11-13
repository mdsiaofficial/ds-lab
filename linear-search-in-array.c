#include <stdio.h>

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 22; // Element to search
    
    printf("Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    int result = linearSearch(arr, n, x);
    if (result == -1)
        printf("\nElement %d not found", x);
    else
        printf("\nElement %d found at index %d", x, result);
    
    return 0;
}