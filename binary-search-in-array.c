#include <stdio.h>

int binarySearch(int arr[], int low, int high, int x) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == x)
            return mid;
        
        if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {11, 12, 22, 25, 34, 64, 90}; // Array must be sorted
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 22; // Element to search
    
    printf("Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    int result = binarySearch(arr, 0, n-1, x);
    if (result == -1)
        printf("\nElement %d not found", x);
    else
        printf("\nElement %d found at index %d", x, result);
    
    return 0;
}