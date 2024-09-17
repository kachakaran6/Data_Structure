#include <stdio.h>

#define SIZE 5

int deque[SIZE];
int front = -1, rear = -1;

// Check if the deque is full
int isFull() {
    return ((front == 0 && rear == SIZE - 1) || (front == rear + 1));
}

// Check if the deque is empty
int isEmpty() {
    return (front == -1);
}

// Insert at the front
void insertFront(int element) {
    if (isFull()) {
        printf("\nDeque is full!\n");
        return;
    }
    if (front == -1) {  // Empty deque
        front = 0;
        rear = 0;
    } else if (front == 0) {
        front = SIZE - 1;
    } else {
        front = front - 1;
    }
    deque[front] = element;
    printf("\nInserted %d at front\n", element);
}

// Insert at the rear
void insertRear(int element) {
    if (isFull()) {
        printf("\nDeque is full!\n");
        return;
    }
    if (front == -1) {  // Empty deque
        front = 0;
        rear = 0;
    } else if (rear == SIZE - 1) {
        rear = 0;
    } else {
        rear = rear + 1;
    }
    deque[rear] = element;
    printf("\nInserted %d at rear\n", element);
}

// Delete from the front
void deleteFront() {
    if (isEmpty()) {
        printf("\nDeque is empty!\n");
        return;
    }
    printf("\nDeleted %d from front\n", deque[front]);
    if (front == rear) {  // Deque has only one element
        front = -1;
        rear = -1;
    } else if (front == SIZE - 1) {
        front = 0;
    } else {
        front = front + 1;
    }
}

// Delete from the rear
void deleteRear() {
    if (isEmpty()) {
        printf("\nDeque is empty!\n");
        return;
    }
    printf("\nDeleted %d from rear\n", deque[rear]);
    if (front == rear) {  // Deque has only one element
        front = -1;
        rear = -1;
    } else if (rear == 0) {
        rear = SIZE - 1;
    } else {
        rear = rear - 1;
    }
}

// Display the deque
void display() {
    if (isEmpty()) {
        printf("\nDeque is empty!\n");
        return;
    }
    printf("\nDeque elements are: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\nFront: %d, Rear: %d\n", front, rear);
}

int main() {
    int choice, element;
    while (1) {
        printf("\nDeque Operations:");
        printf("\n1. Insert at Front");
        printf("\n2. Insert at Rear");
        printf("\n3. Delete from Front");
        printf("\n4. Delete from Rear");
        printf("\n5. Display Deque");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the element to insert at front: ");
                scanf("%d", &element);
                insertFront(element);
                break;
            case 2:
                printf("\nEnter the element to insert at rear: ");
                scanf("%d", &element);
                insertRear(element);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("\nExiting program.\n");
                return 0;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
}