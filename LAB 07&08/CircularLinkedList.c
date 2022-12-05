 #include<stdio.h>
#include<stdlib.h>

// creating a node
struct Node
{
    int data;
    struct Node *next;
}*head;

// Display the linked list
void Display(struct Node *p)
{
    do
    {
        printf("%d ", p->data);
        p=p->next;
    }while(p != head);
}

// Insert a new node at the beginning of the list
void Insert_First(struct Node *p, int x)
{
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    if(head==NULL)
    {
        head = t;
        head->next = head;
    }
    else
    {
        while(p->next!=head)
            p = p->next;
        p->next = t;
        t->next = head;
        head = t;
    }
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
    while(p->next!=head)
        p = p->next;
    p->next = t;
    t->next = head;
}

// Delete first node form the list
void Delete_First(struct Node *p)
{
    struct Node *t;
    while(p->next != head) 
        p = p->next;
    if(head==p)
    {
        free(head);
        head = NULL;
    }
    else
    {
        p->next = head->next;
        free(head);
        head = p->next;
    }
} 

// Delete middle node form the list
void Delete_Middle(struct Node *p, int index)
{
    struct Node *t;
    for (int i = 0; i < index - 2; i++)
        p = p->next;
    t = p->next;
    p->next = t->next;
    free(t);
}

// Delete last node form the list
void Delete_Last(struct Node *p)
{
    struct Node *t;
    while(p->next != head)
    {
        t = p;
        p = p->next;
    } 
    t->next = p->next;
    free(p);
}

int main()
{
    Insert_First(head, 2); Display(head); printf("\n");
    Insert_First(head,3); Display(head); printf("\n");
    Insert_Middle(head,1,1); Display(head); printf("\n");
    Insert_Last(head,5); Display(head); printf("\n");
    Delete_First(head); Display(head); printf("\n");
    Delete_Middle(head,2); Display(head); printf("\n");
    Delete_Last(head);
    Display(head);
    return 0;
}