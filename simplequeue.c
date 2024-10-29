#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<stdlib.h>
#define MAX 10
int arr[MAX];
int front = -1, rear = -1;

void addqueue(int item)
{
    if (rear == MAX - 1)
    {
        printf("Queue is full\n");
        return;
    }
    arr[++rear] = item;

    if (front == -1)
        front = 0;
}
int dequeue()
{
    int data;

    if (front == -1) 
    {
        printf("Queue is empty\n");
        return 0;
    }
    data = arr[front];
    arr[front] = 0;
    if (front == rear)
        front = rear = -1;
    else
    {
        front++;
    }
    return data;
}

void display()
{
    printf("\n\t\t\tinformation in Queue\n\n");
    if (rear == -1)
    {
        printf("\t\t|");
        for (int i = 0; i < MAX; i++)
            printf("  |");
        printf("\n\n");
    }
    else
    {
        printf("\t\t|");
        for (int i = 0; i <= rear; i++) 
            printf("%d  |", arr[i]);
        printf("\n\n");
    }
}
void main()
{
    int item;
    int ch;
    
    do
    {
        printf("\n\t\tPress 1 for insert item into Queue");
        printf("\n\t\tPress 2 for Delete item from Queue");
        printf("\n\t\tPress 3 for Display Data of Queue");
        printf("\n\t\tPress 4 for EXIT");
        printf("\n\t\t Enter Your Choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter item to insert : ");
            scanf(" %d", &item); 
            addqueue(item);
            break;
        case 2:
            item = dequeue(); 
            printf("\nitem %d is Deleted\n", item);
            break;
        case 3:
            display();
            break;
        case 4:
           exit(0);
  break;
        default:
            printf("Invalid choice\n");
        }
    }while(ch !=4);
    // getch();

}









