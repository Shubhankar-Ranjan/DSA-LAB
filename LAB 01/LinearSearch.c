#include<stdio.h>
void Scan(int A[], int m);
void Print(int A[], int m);
void LinearSearch(int A[], int m);

int main(){
    int A[100],m;

    printf("Enter the size of an array: ");
    scanf("%d",&m);

    Scan(A,m);
    Print(A,m);
    LinearSearch(A,m);

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

void LinearSearch(int A[], int m){
    int search;

    printf("\nEnter the element you wish to search: \n");
    scanf("%d",&search);

    for(int i=0; i<m; i++){
        if(A[i]==search){
            printf("Element found at position: %d\n", i);
            break;
        }
        else if (A[i]==m){
            printf("Element not found");
        }
    }
}

void Print(int A[], int m){
    int i, j;
    printf("\n Output array: ");
    for(i = 0; i < m; i++){
        printf("%d ", A[i]);
    }
}
