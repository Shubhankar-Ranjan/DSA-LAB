#include<stdio.h>
void Scan(int A[], int m);
void Print(int A[], int m);
void Switch(int *a, int *b);
void BubbleSort(int A[], int m);

int main(){
    int A[100],m;

    printf("Enter the size of an array: ");
    scanf("%d",&m);

    Scan(A,m);
    Print(A,m);
    BubbleSort(A,m);

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

void Switch(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int A[], int m){
    for(int i = 0; i < m - 1; i++){
        int flag = 0;
        for (int j = 0; j < m-1-i; j++){
            if(A[j] > A[j+1]){
                Switch(&A[j], &A[j+1]);
                flag = 1;
            }
        }
        if(flag == 0){
            break;
        }
    }
    printf("\nAfter Bubble Sorting\n");
    Print(A, m);
}