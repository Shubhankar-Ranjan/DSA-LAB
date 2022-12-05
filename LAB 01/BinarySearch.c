#include<stdio.h>
void Scan(int A[], int m);
void Print(int A[], int m);
int BinarySearch(int A[], int m);
int main(){
    int A[100],m;

    printf("Enter the size of an array: ");
    scanf("%d",&m);

    Scan(A,m);
    Print(A,m);
    BinarySearch(A,m);

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

int BinarySearch(int A[], int m){
    int search;
    printf("\nEnter the element you want to search: ");
    scanf("%d", &search);
    int l = 0;
    int r = m - 1;
    while(l <= r){
        int mid = (l + r) / 2;
        if(search == A[mid]){
            printf("Element is present in the array at position %d\n", mid);
            return mid;
        }else if(search < A[mid]){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    printf("Element is not present in the array");
    return -1;
}
