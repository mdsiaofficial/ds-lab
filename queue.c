#include <stdio.h>
#include <stdlib.h>
#define max 10

int enqueue(int queue[max], int *data, int *front, int *rear) {
    if (*rear == max - 1) {
        return -1;  // Queue Overflow
    } else {
        if (*front == -1) {
            *front = 0;
        }
        *rear = *rear + 1;
        queue[*rear] = *data;
        return 1;
    }
}

int dequeue(int queue[max], int *data, int *front, int *rear) {
    if (*front == -1 || *front > *rear) {
        return -1;  // Queue Underflow
    } else {
        *data = queue[*front];
        *front = *front + 1;
        if (*front > *rear) {  // Reset front and rear when the queue becomes empty
            *front = -1;
            *rear = -1;
        }
        return 1;
    }
}

int display(int queue[max], int *front, int *rear) {
    if (*front == -1 || *front > *rear) {
        printf("\nQueue is empty. Press any key to continue...");
        getchar();
    } else {
        printf("\nQueue is: \n");
        for (int i = *front; i <= *rear; i++) {
            printf("%d\n", queue[i]);
        }
        printf("\nPress any key to continue...");
        getchar();
    }
}

int main() {
    int queue[max], data, front = -1, rear = -1, option, n;
    do {
        printf("\n\t*** Queue Menu ***\t");
        printf("\n\t 1. Enqueue");
        printf("\n\t 2. Dequeue");
        printf("\n\t 3. Display");
        printf("\n\t 4. Exit");
        printf("\n\t Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\n\t Enter the data: ");
                scanf("%d", &data);
                n = enqueue(queue, &data, &front, &rear);
                if (n == -1) {
                    printf("\n\t Queue Overflow");
                } else {
                    printf("\n\t Data (%d) inserted successfully", data);
                }
                break;

            case 2:
                n = dequeue(queue, &data, &front, &rear);
                if (n == -1) {
                    printf("\n\t Queue Underflow");
                } else {
                    printf("\n\t Data (%d) deleted successfully", data);
                }
                break;

            case 3:
                display(queue, &front, &rear);
                break;

            case 4:
                exit(0);

            default:
                printf("\n\t Invalid option, press any key to continue...");
                getchar();
        }
    } while (1);
    return 0;
}

