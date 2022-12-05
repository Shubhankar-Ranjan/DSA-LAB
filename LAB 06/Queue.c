#include<stdio.h>
#include<stdlib.h>

// making structure of queue 
struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

// creating a queue
void create(struct Queue *q)
{
    printf("Enter Size: ");
    scanf("%d", &q->size);
    q->front=q->rear=-1;
    q->Q=(int*) malloc(q->size*sizeof(int));
}

// Enqueue
void enqueue(struct Queue *q,int x)
{
    if(q->rear==q->size-1)
        printf("Queue is full\n");
    else
    {
        q->rear++;
        q->Q[q->rear]=x;
    }
}

// Dequeue
int dequeue(struct Queue *q)
{
    int x=-1;

    if(q->front==q->rear)
        printf("Queue is empty\n");
    else
    {
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}

// Display
void Display(struct Queue q)
{
    printf("Elements in the Queue: ");
    for(int i=q.front+1;i<=q.rear;i++)
        printf("%d ",q.Q[i]);
    printf("\n");    
}

int main()
{
    struct Queue q;
    create(&q);

    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);

    Display(q);

    printf("Deleted value is %d\n", dequeue(&q));

    Display(q);


    return 0;
}