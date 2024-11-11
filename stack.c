#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define max 10

int push(int stack[max], int *data, int *top);
int pop(int stack[max], int *data, int *top);
int display(int stack[max], int *data, int *top);




int main(){
  int stack[max], data, top=-1, option, n;
  do{
    printf("\n\t*** Stack menu***\t");
    printf("\n\t 1. Push");
    printf("\n\t 2. Pop");
    printf("\n\t 3. Display");
    printf("\n\t 4. Exit");
    printf("\n\t Enter your option: ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
      printf("\n\t Enter the data: ");
      scanf("%d", &data);
      n=push(stack, &data, &top);
      if(n==-1){
        printf("\n\t Stack Overflow");
      }else{
        printf("\n\t Data (%d)) inserted successfully", data);
      }
      break;
    
    case 2:
      n=pop(stack, &data, &top);
      if(n==-1){
        printf("\n\t Stack Underflow");
      }else{
        printf("\n\t Data (%d) deleted successfully", data);
      }
      break;
    
    case 3:
      display(stack, &data, &top);
      break;
    
    case 4:
      exit(0);
    
    default:
      printf("\n\t Invalid option, press any key to continue...");
      getch();
    }
  }while(1);
  return 0;

}

int push(int stack[max], int *data, int *top){
  if(*top==max){
    return (-1);
  }else{
    *top = *top +1 ;
    stack[*top]=*data;
    return (1);
  }
}
int pop(int stack[max], int *data, int *top){
  if(*top==-1){
    return (-1);
  }else{
    *data = stack[*top];
    *top = *top - 1 ;
    return (1);
  }
}
int display(int stack[max], int *data, int *top){
  if(*top==-1){
    printf("\nStack is empty. Press any key to continue...");
    getch();
  }else{
    printf("\nStack is: \n");
    for(int i=*top; i>=0; i--){

      printf("%d\n", stack[i]);
    }
    printf("\nPress any key to continue...");
    getch();

  }
}