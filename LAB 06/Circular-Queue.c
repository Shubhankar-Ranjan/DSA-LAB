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
    q->front=q->rear=0;
    q->Q=(int*) malloc(q->size*sizeof(int));
}

// Enqueue
void enqueue(struct Queue *q,int x)
{
    if((q->rear+1)%q->size==q->front)
        printf("Queue is full\n");
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}

// Dequeue
int dequeue(struct Queue *q)
{
    int x=-1;

    if(q->front==q->rear)
        printf("Queue is Empty\n");
    else
    {
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}

// Display
void display(struct Queue q)
{
    int i = q.front+1;
    do
    {
        printf("%d ",q.Q[i]);
        i=(i+1)%q.size;
    }while(i!=(q.rear+1)%q.size);
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

    display(q);

    printf("Deleted value is %d", dequeue(&q));
    printf("\n");
    printf("Deleted value is %d", dequeue(&q));
    printf("\n");

    display(q);

    enqueue(&q,20);
    enqueue(&q,10);

    display(q);


    return 0;
}