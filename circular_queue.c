#include <stdio.h>

#define SIZE 5

int items[SIZE];
int front = -1, rear = -1;

// check if the queue is full
int isFull() {
  if ((front == (rear + 1) % SIZE) || (front == 0 && rear == SIZE - 1)) return 1;
  return 0;
}

// check if the queue is empty
int isEmpty() {
  if (front == -1) return 1;
  return 0;
}

// adding an element
void enQueue(int element) {
  if (isFull())
    printf("\n Queue is full!! \n");
  else {
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    items[rear] = element;
    printf("\n Inserted -> %d", element);
  }
}

// removing an element
int deQueue() {
  int element;
  if (isEmpty()) {
    printf("\n Queue is empty !! \n");
    return (-1);
  } else {
    element = items[front];
    if (front == rear) {
      front = -1;
      rear = -1;
    } 
    else {
      front = (front + 1) % SIZE;
    }
    printf("\n Deleted element -> %d \n", element);
    return (element);
  }
}

// display the queue
void display() {
  int i;
  if (isEmpty())
    printf(" \n Empty Queue\n");
  else {
    printf("\n Front -> %d ", front);
    printf("\n Items -> ");
    for (i = front; i != rear; i = (i + 1) % SIZE) {
      printf("%d ", items[i]);
    }
    printf("%d ", items[i]);
    printf("\n Rear -> %d \n", rear);
  }
}

int main() {
  int choice, element;

  while (1) {
    printf("\nQueue Operations:");
    printf("\n1. Enqueue");
    printf("\n2. Dequeue");
    printf("\n3. Display Queue");
    printf("\n4. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("\nEnter element to enqueue: ");
        scanf("%d", &element);
        enQueue(element);
        break;

      case 2:
        deQueue();
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