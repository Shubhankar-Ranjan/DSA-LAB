#include<stdio.h>
void Scan(int A[][10], int m, int n);
void Transpose(int A[][10], int b[][10], int m, int n);
void Print(int B[][10], int m, int n);
int main(){
    int A[10][10], B[10][10], m, n;

    printf("Enter rows and column for matrix A: ");
    scanf("%d %d",&m, &n);

    Scan(A, m, n);

    Transpose(A,B, m, n);

    Print(B, m, n);

    return 0;
}
void Scan(int A[][10], int m, int n){
    int i, j;
    printf("\n Enter elements of matrix: \n");
    for(i=0; i< m; i++){
        for(j=0; j< n; j++){
            printf("Enter element at A%d%d: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
}


void Transpose(int A[][10], int B[][10], int m, int n){
    int i,j;

    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            B[j][i] = A[i][j];
        }
    }
}

void Print(int B[][10], int m, int n){
    int i, j;
    printf("\n Output Matrix: \n");
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            printf("%d  ",B[i][j]);
        }
        printf("\n");
    }
}