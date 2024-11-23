#include <stdio.h>
#include <stdlib.h>
#define max 10

int push(int stack[max], int *top, int *data)
{
  if (*top == max)
  {
    return -1;
  }
  else
  {
    *top = *top + 1;
    stack[*top] = *data;
    return 1;
  }
}
int pop(int stack[max], int *top, int *data)
{
  if (*top == -1)
  {
    return -1;
  }
  else
  {
    *data = stack[*top];
    *top = *top - 1;
    return 1;
  }
}
int display(int stack[max], int *top)
{
  printf("\nStack: ");
  for(int i=0; i<*top; i++){
    printf("%d ", stack[i]);
  }
}
int main()
{
  int stack[max], data, top = -1, op, n;
  do
  {
    printf("\n----------------------\n");
    printf("\nStack Operations\n");
    printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
    printf("\n----------------------\n");
    printf("Enter option: ");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
      printf("Enter data: ");
      scanf("%d", &data);
      n = push(stack, &top, &data);
      if (n == -1)
        printf("Stack overflow");
      else
        printf("data (%d) pushed successfully.", data);
      break;

    case 2:
      n = pop(stack, &top, &data);
      if (n == -1)
        printf("Stack underflow");
      else
        printf("data (%d) popped successfully.", data);
      break;

    case 3:
      display(stack, &top);
      break;

    case 4:
      exit(0);

    default:
      printf("Invalid option selected.\n\npress any key to contitue...");
      getchar();
    }

  } while (1);
  return 0;
}
