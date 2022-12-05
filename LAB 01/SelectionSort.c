#include<stdio.h>
void Scan(int A[], int m);
void Print(int A[], int m);
void SelectionSort(int A[], int m);
void Switch(int *a, int *b);

int main(){
    int A[100],m;

    printf("Enter the size of an array: ");
    scanf("%d",&m);

    Scan(A,m);
    Print(A,m);
    SelectionSort(A,m);

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

void SelectionSort(int A[], int m){
    for(int i = 0; i < m-1; i++){
        int min = i;
        for(int j = i + 1; j < m; j++){
            if(A[j] < A[min]){
                min = j;
            }
        }
        if(min != i){
            Switch(&A[i], &A[min]);
        }
    }
    printf("\nAfter Selection Sorting\n");
    Print(A,m);
}

void Switch(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
