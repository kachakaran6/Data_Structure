#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>
#define MAX 10
char arr[MAX];
int front =-1, rear =-1;

void addqueue(char item){
    if(rear == MAX-1){
        printf("Queue is Full\n");
        return;
    }
    arr[++rear]=item;

    if(front == -1)
    front = 0;
}
char dequeue(){
    char data;

    if(front == -1){
        printf("Queue is empty\n");
        return 0;
    }
    data = arr[front];
    arr[front] = 0;
    if(front == rear)
    front = rear =-1;
    else{
        front++;
    }
    return data;
}

void display(){
    printf("\n\t\t\tinformation in Queue\n\n");
    if(rear == -1){
        printf("\t\t|");
        for(int i=0; i<MAX;i++)
        printf(" |");
        printf("\n\n");
    }else{
        printf("\t\t|");
        for(int i =0;i<= front; i++)
        printf("%c |", arr[i]);
        printf("\n\n");
    }
}

void main(){
    char item;
    int ch;
    // clrscr();
    do{
        printf("\n\t\tPress 1 for insert item ino Queue");
        printf("\n\t\tPress 2 for Delete item from Queue");
        printf("\n\t\tPress 3 for Display Queue");
        printf("\n\t\tPress 4 for Exit");
        printf("\n\t\tEnter your choice: ");
        scanf("%d", &ch);

        switch(ch){
            case 1:
            printf("\nEnter item to insert : ");
            scanf("%c",&item);
            addqueue(item);
            break;

            case 2:
            item = dequeue();
            printf("\nitem %c is Deleted\n",item);
            break;

            case 3:
            display();
            break;

            case 4:
            exit(0);

            default:
            printf("Invalid Choice\n");
        }
    }while (ch !=4);
    getch();
}
