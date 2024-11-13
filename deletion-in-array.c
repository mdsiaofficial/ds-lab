#include <stdio.h>

void deleteElement(int arr[], int* n, int position) {
    if (position >= *n || position < 0) {
        printf("Invalid position\n");
        return;
    }
    
    // Shift elements to left
    for (int i = position; i < *n - 1; i++)
        arr[i] = arr[i+1];
        
    (*n)--;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5; // Current size of array
    
    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    int position = 2;
    deleteElement(arr, &n, position);
    
    printf("\nArray after deletion: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    return 0;
}