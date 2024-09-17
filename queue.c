#include <stdio.h>
#include <stdlib.h>

#define MAX 10

char arr[MAX];
int front = -1, rear = -1;

void enque(char data) {
    if (rear == MAX - 1) {
        printf("\nQueue is Full");
        return;
    }
    arr[++rear] = data;

    if (front == -1) {
        front = 0;
    }
}

void deque() {
    if (front == -1) {
        printf("\nQueue is Empty");
        return;
    }
    char data = arr[front];
    arr[front] = ' ';
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

void display() {
    int i;
    if (front == -1) {
        printf("\nQueue is Empty");
        return;
    }
    
    for (i = front; i <= rear; i++) {
        printf("\narr[%d] = %c", i, arr[i]);
    }
}

int main() {
    int num;
    char c;

    while (1) {
        printf("\nEnter the operation:");
        printf("\n0 to exit");
        printf("\n1 to enque");
        printf("\n2 to deque");
        printf("\n3 to display\n");
        scanf("%d", &num);
        
        // Clear newline character left in buffer
        while (getchar() != '\n');

        switch (num) {
            case 1:
                printf("\nEnter character to enque: ");
                scanf("%c", &c);
                enque(c);
                break;
            case 2:
                deque();
                break;
            case 3:
                display();
                break;
            case 0:
                exit(0);
            default:
                printf("\nInvalid option");
        }
    }

    return 0;
}