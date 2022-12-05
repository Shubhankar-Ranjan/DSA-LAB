#include<stdio.h>
void Scan(int A[], int m);
void Print(int A[], int m);
void Delete(int A[], int m);

int main(){
    int A[100],m;

    printf("Enter the size of an array: ");
    scanf("%d",&m);

    Scan(A,m);
    Print(A,m);
    Delete(A,m);

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

void Delete(int A[], int m){
    int pos;

    printf("\nFrom which position you want to delete: ");
    scanf("%d",&pos);
    if(pos<0 || pos>m-1){
        printf("\nInvalid position\n");
    }else{
        for(int i=pos; i<m-1; i++){
            A[i] = A[i+1];
        }
        m--;
    }
    printf("\nAfter deleting an element");
    Print(A,m);
}
