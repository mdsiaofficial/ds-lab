#include <stdio.h>
#define max 10


void swap (int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubble_sort(int arr[], int n){
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(arr[j]>arr[j+1]) {
        swap(&arr[j], &arr[j+1]);
      }
    }
  }
}

void selection_sort(int arr[], int n){
  for(int i=0; i<n; i++){
    int min = i;
    for(int j=i+1; j<n; j++){
      if(arr[j] < arr[min]) min=j;
    }
    if(min!=i) swap(&arr[i], &arr[min]);
  }
}

void insertion_sort(int arr[], int n){
  for(int i=1; i<n; i++){
    int key = arr[i];
    int j=i-1;
    while(j>=0 && arr[j]>key){
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = key;
  }
}

int linear_search(int arr[], int n, int target){
  for(int i=0; i<n; i++){
    if(arr[i]==target) return i;
  }
  return -1;
}

int binary_search(int arr[], int n, int target){
  int low=0, high = n-1;
  while(low<=high){
    int mid = (low+high)/2;
    if(arr[mid] == target) return mid;
    else if(arr[mid]>target) high = mid-1;
    else low = mid+1;
  }
}

int main (){
  int arr[] = {7,38,2,4,1,13,2,14,53,32,4,7};
  int n = sizeof(arr)/sizeof(arr[0]);

  printf("\nOriginal array: \n");
  for(int i=0; i<n; i++) {
    printf("%d ", arr[i]);
  }

  // bubble_sort(arr, n);
  // selection_sort(arr, n);
  insertion_sort(arr, n);


  printf("\n\n");
  printf("\nsorted array: \n");
  for(int i=0; i<n; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n\n");

  // int inx = linear_search(arr, n, 14);
  // if(inx >=0){
  //   printf("\nlinear search of 14: %d\n", inx);
  // }else{
  //   printf("\nlinear search of 14: not found\n");
  // }
  
  printf("\n\n");

  int inx = binary_search(arr, n, 14);
  if(inx >=0){
    printf("\nbinary search of 14: %d\n", inx);
  }else{
    printf("\nbinary search of 14: not found\n");
  }
}
