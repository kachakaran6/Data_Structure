#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*link;
}*start;

void addatend(int item){
    struct node*first,*newnode;
    if(start == NULL){
        first = (struct node*)malloc(sizeof(struct node));
        first->data = item;
        first->link = NULL;
        start = first;
    }else{
        first = start;
        while(first->link!=NULL)
        first = first->link;
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = item;
        newnode->link = NULL;
        first->link=newnode;
    }
}

void addatbeg(int item){
    struct node*first;

    first = (struct node* )malloc(sizeof(struct node));
    first->data = item;
    first->link = start;
    start = first;
}

void addafter(int loc,int item){
    struct node *newnode,*temp;
    int i;
    temp = start;
    for(i=0;i<loc-1;i++){
        temp = temp->link;
        if(temp == NULL){
            printf("\nThere are less than %d element in list",loc);
            return;
        }
    }
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->link = temp->link;
    temp->link = newnode;
}

void deletenode(int item){
    struct node *old,*temp;
    temp = start;
    while(temp!=NULL){
        if(temp->data == item){
            if(temp == start){
                start = temp ->link;
            }else{
                old->link = temp->link;
                free(temp);
                return;
            }
        }else{
            old = temp;
            temp = temp -> link;
        }
    }
    printf("\n\nElement %d not found",item);
            return;
}

void display(){
    struct node *temp = start;
    printf("\n\tINFO\tLINK\n");
    while(temp !=NULL){
        printf("\t%d",temp->data);
        printf("\t%u\n",temp->link);
        temp = temp->link;
    }
}

void main(){
    int loc,item,choice;

    do{
        printf("\nEnter 1 for Create Linklist :");
        printf("\nEnter 2 for Insert node at Begining of Link list : ");
        printf("\nEnter 3 for Insert Node at After Specified Location :");
        printf("\nEnter 4 for Delete Node :");
        printf("\nEnter 5 for Display LinkList :");
        printf("\nEnter 6 for EXIT :");
         printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
            printf("\nEnter Item :");
            scanf("%d",&item);
            addatend(item);
            break;


            case 2:
            printf("\nEnter Item :");
            scanf("%d",&item);
            addatbeg(item);
            break;

            case 3:
            printf("\nEnter the location where you want to insert Node: ");
            scanf("%d",&loc);
            printf("\nEnter item : ");
            scanf("%d",&item);
            addafter(loc,item);
            break;

            case 4:
            printf("\nEnter Item which you have to Delete: ");
            scanf("%d",&item);
            deletenode(item);
            break;

            case 5:
            display();
            break;

            case 6:
            break;
        }
    }while(choice !=6);
    // getch();
}




