#include <stdio.h>
#define MAX_SIZE 100

void insertElement(int arr[], int* n, int element, int position) {
    if (*n >= MAX_SIZE) {
        printf("Array is full\n");
        return;
    }
    
    if (position > *n || position < 0) {
        printf("Invalid position\n");
        return;
    }
    
    // Shift elements to right
    for (int i = *n; i > position; i--)
        arr[i] = arr[i-1];
        
    arr[position] = element;
    (*n)++;
}

int main() {
    int arr[MAX_SIZE] = {1, 2, 3, 4, 5};
    int n = 5; // Current size of array
    
    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    int element = 10, position = 2;
    insertElement(arr, &n, element, position);
    
    printf("\nArray after insertion: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    return 0;
}