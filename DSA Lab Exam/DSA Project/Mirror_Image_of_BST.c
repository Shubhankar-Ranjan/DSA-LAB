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

//Inorder Traversal of a Binary Search Tree
void Inorder(struct Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}

// Mirror Image of a Binary Search Tree
void Mirror(struct Node* p)
{
    if (p == NULL)
        return;
    else {
        struct Node* temp;
 
        // do the subtrees
        Mirror(p->lchild);
        Mirror(p->rchild);
 
        // swap the pointers into this node 
        temp = p->lchild;
        p->lchild = p->rchild;
        p->rchild = temp;
    }
}

// Main function
int main()
{
    printf("\nLet's Create a new Binary Search Tree:-\n\n");
    Create();

    printf("\nInorder Traversal\n");
    Inorder(root);
    printf("\n");

    printf("\nThe Mirror Image of a same Binary Search Tree:-\n");
    Mirror(root);
    printf("\nInorder Traversal\n");
    Inorder(root);
    printf("\n\n");

    return 0;
}   