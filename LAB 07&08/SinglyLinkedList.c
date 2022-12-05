#include<stdio.h>
#include<stdlib.h>

// creating a node
struct Node
{
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
    t->next = first;
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
    t->next = p->next;
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
    t->next = NULL;
    p->next = t;
}

// Delete first node form the list
void Delete_First(struct Node *p)
{
    struct Node *t = NULL;
    t = first;
    first = first->next;
    free(t);
} 

// Delete middle node form the list
void Delete_Middle(struct Node *p, int index)
{
    struct Node *t = NULL;
    for (int i = 0; i < index - 1; i++)
    {
        t = p;
        p = p->next;
    }
    t->next = p->next;
    free(p);
}

// Delete last node form the list
void Delete_Last(struct Node *p)
{
    struct Node *t = NULL;
    while(p->next)
    {
        t=p;
        p = p->next;
    }
    t->next = p->next;
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
