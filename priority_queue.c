#include <stdio.h>

#define SIZE 5

struct PriorityQueue {
    int data;
    int priority;
};

struct PriorityQueue pq[SIZE];
int front = -1, rear = -1;

// Check if the priority queue is full
int isFull() {
    return (rear == SIZE - 1);
}

// Check if the priority queue is empty
int isEmpty() {
    return (front == -1);
}

// Insert an element into the priority queue
void insert(int element, int priority) {
    if (isFull()) {
        printf("\nPriority Queue is full!\n");
        return;
    }
    if (isEmpty()) {
        front = 0;
        rear = 0;
        pq[rear].data = element;
        pq[rear].priority = priority;
    } else {
        int i;
        for (i = rear; i >= front && pq[i].priority > priority; i--) {
            pq[i + 1] = pq[i];
        }
        pq[i + 1].data = element;
        pq[i + 1].priority = priority;
        rear++;
    }
    printf("\nInserted %d with priority %d\n", element, priority);
}

// Delete an element with the highest priority
void delete() {
    if (isEmpty()) {
        printf("\nPriority Queue is empty!\n");
        return;
    }
    printf("\nDeleted element %d with priority %d\n", pq[front].data, pq[front].priority);
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front++;
    }
}

// Display the priority queue
void display() {
    if (isEmpty()) {
        printf("\nPriority Queue is empty!\n");
        return;
    }
    printf("\nPriority Queue elements are:\n");
    for (int i = front; i <= rear; i++) {
        printf("Element: %d, Priority: %d\n", pq[i].data, pq[i].priority);
    }
}

int main() {
    int choice, element, priority;
    while (1) {
        printf("\nPriority Queue Operations:");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display Queue");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the element to insert: ");
                scanf("%d", &element);
                printf("\nEnter the priority of the element: ");
                scanf("%d", &priority);
                insert(element, priority);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nExiting program.\n");
                return 0;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
}