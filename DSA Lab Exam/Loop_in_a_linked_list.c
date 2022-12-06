#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(i=1; i<n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void display(struct Node *p){
    while(p!=NULL)
    {
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}

void isLoop(struct Node *f)
{
    struct Node *p,*q; 
    p=q=f;

    do
    {
        p=p->next;
        q=q->next;
        q=q?q->next:q;
    }while(p && q && p!=q);
    if(p==q){ 
        printf("Loop Exist\n");
    }
    else{
        printf("Loop does not exist\n");
    }
}

int main(){

    //linked list without loop
    printf("\nLinked List without a loop\n");
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    display(first);
    isLoop(first);

    // Linked List with loop
    printf("\n\nLinked List with a loop\n");
    int B[] = {10, 20, 30, 40, 50};
    create(B, 5);
    struct Node *t1, *t2;
    t1 = first->next->next;
    t2 = first->next->next->next->next;
    t2->next = t1;
    isLoop(first);
    // display(first); 

    return 0;
}