#include<stdio.h>
void Scan(int A[][10], int B[][10], int m, int n, int p, int q);
void multiplyMatrices(int A[][10], int B[][10], int multiplyMatrix[][10], int m, int n, int p, int q);
void Print(int multiplyMatrix[][10], int m, int q);
int main(){
    int A[10][10], B[10][10], multiplyMatrix[10][10], m, n, p, q;

    printf("Enter rows and column for matrix A: ");
    scanf("%d %d",&m, &n);

    printf("Enter columns and rows for matrix B: ");
    scanf("%d %d",&p, &q);

    while (n != p){
		printf("Error! column of first matrix not equal to row of second.\n");
        
        printf("Enter rows and column for matrix A: ");
        scanf("%d %d",&m, &n);

        printf("Enter columns and rows for matrix B: ");
        scanf("%d %d",&p, &q);
    }

    Scan(A, B, m, n, p, q);

    multiplyMatrices(A, B,multiplyMatrix, m, n, p, q);

    Print(multiplyMatrix, m, q);

    return 0;
}
void Scan(int A[][10], int B[][10], int m, int n, int p, int q){
    int i, j;
    printf("\n Enter elements of matrix A: \n");
    for(i=0; i< m; i++){
        for(j=0; j< n; j++){
            printf("Enter element at A%d%d: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    printf("\n Enter elements of matrix B: \n");
    for(i=0; i< p; i++){
        for(j=0; j< q; j++){
            printf("Enter element at B%d%d:", i, j);
            scanf("%d", &B[i][j]);
        }
    }
}

void Print(int multiplyMatrix[][10], int m, int q){
    int i, j;
    printf("\n Output Matrix: \n");
    for(i=0; i<m; i++){
        for(j=0; j<q; j++){
            printf("%d  ",multiplyMatrix[i][j]);
            if (j == q-1)
            printf("\n\n");
        }
    }
}

void multiplyMatrices(int A[][10], int B[][10], int multiplyMatrix[][10], int m, int n, int p, int q){
    int i, j, k;
    for(i = 0; i < m; i++)
	{
		for(j = 0; j < q; j++)
		{
			multiplyMatrix[i][j] = 0;
		}
	}

    for(i=0; i<m; i++){
        for(j=0; j<q; j++){
            for(k=0; k<n; k++){
                multiplyMatrix[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}