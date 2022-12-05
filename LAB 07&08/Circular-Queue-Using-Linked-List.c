#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*front=NULL,*rear=NULL;

// Enqueue
void enqueue(int x)
{
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if(t==NULL)
        printf("Queue is Full!\n");
    else
    {
        if((front==NULL) && (rear==NULL))
        {
            front = rear = t;
            rear->next = front;
        }
        else
        {
            rear->next = t;
            rear = t;
            t->next = front;
        }
    }
}

// Dequeue
void dequeue()
{
    struct Node *t;
    t = front;
    if((front==NULL) && (rear==NULL))
        printf("Queue is Empty!\n");
    else if((front==rear))
    {
        front = rear = NULL;
        free(t);
    }
    else
    {
        front = front->next;
        rear->next = front;
        free(t);
    }
}

// Display
void display()
{
    struct Node *t;
    t = front;
    if((front==NULL) && (rear==NULL))
        printf("Queue is Empty!\n");
    else
    {
        do
        {
            printf("%d ",t->data);
            t=t->next;
        }while(t != front);
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    display(front); printf("\n");

    dequeue();

    enqueue(10);

    display(front);

    return 0;
}