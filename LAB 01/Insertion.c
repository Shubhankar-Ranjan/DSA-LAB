#include<stdio.h>
void Scan(int A[], int m);
void Print(int A[], int m);
void Insert(int A[], int m);

int main(){
    int A[100],m;

    printf("Enter the size of an array: ");
    scanf("%d",&m);

    Scan(A,m);
    Print(A,m);
    Insert(A,m);

    return 0;
}


void Scan(int A[], int m){
    int i,j;
    printf("Enter the elements of an array: \n");
    for(i = 0; i < m; i++){
        printf("Enter element at %d position: ", i);
        scanf("%d", &A[i]);
    }
}

void Print(int A[], int m){
    int i, j;
    printf("\n Output array: ");
    for(i = 0; i < m; i++){
        printf("%d ", A[i]);
    }
}

void Insert(int A[], int m){
    int  pos, num;

    printf("\nEnter data you want to insert: ");
    scanf("%d",&num);
    printf("Enter position at which data to be inserted: ");
    scanf("%d",&pos);
    if(pos<=0 || pos>m+1){
        printf("Invalid position\n");
    } else{
        for(int i=m-1; i>=pos; i--){
            A[i+1]= A[i];
        }
        A[pos] = num;
        m++;
    }
    printf("\nAfter Inserting new element\n")
    Print(A,m);
}
