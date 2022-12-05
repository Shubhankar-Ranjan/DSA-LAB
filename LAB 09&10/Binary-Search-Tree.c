#include<stdio.h>
#include<stdlib.h>

// creating a node for tree
struct Node 
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root = NULL;

// menu option used in creating a binary search tree
char menu()
{
    char c;
    printf("Do you want to enter more value Y or N: ");
	scanf("%s", &c);

    return (c);
}

// Creating a Binary Search Tree 
void Create()
{
    struct Node *t = root;
	int x,z;
	
    struct Node *r, *p;
	printf("Enter Value of the root node: ");
	scanf("%d", &x);
	
	p = (struct Node *)malloc(sizeof(struct Node));
    p->data = x;
    p->lchild=p -> rchild=NULL;
    root = p;
	
    char choice = '\0';
	choice = menu();
    do
    {
        if(choice=='y'|| choice=='Y')
        {
            p = root;
            printf("Enter Value in the node: ");
            scanf("%d", &z);
            while(p)
            {
                r =p;
                if(z < p->data)
                    p = p->lchild;
                else if(z > p->data) 
                    p = p->rchild;
                else
                {
                    printf("This value already exist!\n");
                    choice = menu();
                }
            }
            p = (struct Node *)malloc(sizeof(struct Node));
            p->data = z;
            p->lchild=p->rchild=NULL;

            if(z < r->data)
                r->lchild = p;
           else
                r->rchild = p;
        }
        else if(choice == 'n' || choice == 'N')
            return;
        else 
            printf("Please enter a Valid Choice!\n");
        
        choice= menu();
    } while(choice=='y'|| choice=='Y');
}
 
// Insertion in a binary search tree
void Insert()
{
    struct Node *t = root;
    struct Node *r, *p;
    int value;

    if(root == NULL)
    {
        printf("Firstly you need to create a tree!\n\n");
        return;
    }

    printf("\nWhich value you want to insert: ");
    scanf("%d", &value);
    while(t)
    {
        r = t;
        if(value < t->data)
            t = t->lchild;
        else if(value > t->data) 
            t = t->rchild;
        else
            return;
    }
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = value;
    p->lchild=p->rchild=NULL;

    if(value < r->data)
        r->lchild = p;
    else
        r->rchild = p;
}

//Preorder Traversal
void Preorder(struct Node *p)
{
    if(p)
    {
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

//Inorder Traversal
void Inorder(struct Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}

//Postorder Traversal
void Postorder(struct Node *p)
{
    if(p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ", p->data);
    }
}

// Searching in a Binary Search Tree
void Search()
{
    int value;
    printf("\nEnter the value you want to search: ");
    scanf("%d", &value);
    struct Node *t = root;

    while(t)
    { 
        if(value==t->data)
        {
            printf("\nElement %d is present in the tree\n", value);
            return;
        }
        else if(value<t->data)
            t = t->lchild;
        else
            t = t->rchild;
    }
    printf("\nElement is not present in the tree\n");  
}

// Height of a Binary Search Tree
int Height(struct Node *p)
{
    int x,y;
    if(p==NULL) return 0;
    x = Height(p->lchild);
    y= Height(p->rchild);
    return x>y?x+1:y+1;
}

// Inorder Predecessor : Rightmost child of a lchild subtree
struct Node *InPre(struct Node *p)
{
    while(p && p->rchild!=NULL)
        p = p->rchild;
    return p;
}

// Inorder Sucessor : Leftmost child of a right subtree
struct Node *InSucc(struct Node *p)
{
    while(p && p->lchild!=NULL)
        p = p->lchild;
    return p;
}

// Deletion in a Binary Search Tree
struct Node *Delete(struct Node *p, int value)
{
    struct Node *q;

    if(p==NULL)
        return NULL;
    if(p->lchild==NULL && p->rchild==NULL)
    {
        if(p==root)
            root = NULL;
        free(p);
        return NULL;
    }

    if (value < p->data)
        p->lchild = Delete(p->lchild, value);
    else if(value > p->data)
        p->rchild = Delete(p->rchild, value);
    else
    {
        if(Height(p->lchild) > Height(p->rchild))
        {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild=Delete(p->lchild,q->data); 
        }
        else
        {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild=Delete(p->rchild,q->data);
        }
    }
    return p;
}

// find minimum in a Binary Search tree
void Minimum()
{
    struct Node *p = root;

    while (p->lchild)
    {
        p = p->lchild;
    }
    printf("\n%d is the minimum value\n", p->data);
}

// search largest in a binary search tree which is less than equal to N
void Maximum_for_N()
{
    int N;
    printf("\nEnter N: ");
    scanf("%d", &N);

    struct Node *p = root, *r;

    while(p)
    {
        r = p;
        if(N > p->data)
            p = p->rchild;
        else if (N < p->data)
            p = p->lchild;
        else
        {
            printf("%d is the maximum value", p->data);
            return;
        }    
    }
    printf("%d is the maximum value\n", r->data);
}

// Main function
int main()
{
    Insert();
    Create();
    Insert();

    printf("\nInorder Traversal\n");
    Inorder(root);
    printf("\n");

    printf("\nPreorder Traversal\n");
    Preorder(root);
    printf("\n");

    printf("\nPostorder Traversal\n");
    Postorder(root);
    printf("\n");

    Search();

    int value;
    printf("\nEnter Value you want to delete: ");
    scanf("%d",&value);
    Delete(root, value);

    printf("\nInorder Traversal\n");
    Inorder(root);
    printf("\n");

    Minimum();

    Maximum_for_N();

    return 0;
}