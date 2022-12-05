#include<stdio.h>
#include<stdlib.h>

// creating a node
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

// Display the linked list
void Display(struct Node *p)
{
    while(p)
    {
        printf("%d ", p->data);
        p=p->next;
    }
}

// Insert a new node at the beginning of the list
void Insert_First(struct Node *p, int x)
{
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->prev = NULL;
    t->next = first;
    if(first)
        first->prev = t;
    first = t;
}

// Insert a new node in the middle of the list
void Insert_Middle(struct Node *p, int index, int x)
{
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    for(int i=0; i<index-1; i++)
        p=p->next;
    t->prev=p;
    t->next = p->next;
    p->next->prev=t;
    p->next = t;
}

// Insert a new node at the last of the list
void Insert_Last(struct Node *p, int x)
{
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    while(p->next)
        p=p->next;
    t->prev = p;
    t->next = p->next;
    p->next = t;
}

// Delete first node form the list
void Delete_First(struct Node *p)
{
    first = first->next;
    if(first)
        first->prev = NULL;
    free(p);
} 

// Delete middle node form the list
void Delete_Middle(struct Node *p, int index)
{
    for (int i = 0; i < index - 1; i++)
        p = p->next;
    p->prev->next = p->next;
    p->next->prev = p->prev;
    free(p);
}

// Delete last node form the list
void Delete_Last(struct Node *p)
{
    while(p->next)
        p = p->next;
    p->prev->next=p->next;
    free(p);
}

int main()
{
    Insert_First(first, 2); Display(first); printf("\n");
    Insert_First(first,3); Display(first); printf("\n");
    Insert_Middle(first,1,1); Display(first); printf("\n");
    Insert_Last(first,5); Display(first); printf("\n");
    Delete_First(first); Display(first); printf("\n");
    Delete_Middle(first,2); Display(first); printf("\n");
    Delete_Last(first);
    Display(first);
    return 0;
}
