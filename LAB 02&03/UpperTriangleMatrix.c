#include<stdio.h>
#include<stdio.h>
void Scan(int A[][10], int m);
void UpperTriangleMatrix(int A[][10], int m);
void Print(int A[][10], int m);
int main(){
    int A[10][10], m;

    printf("Enter rows and column for a square matrix A: ");
    scanf("%d",&m);


    Scan(A, m);

    Print(A, m);

    UpperTriangleMatrix(A, m);

    return 0;
}
void Scan(int A[][10],int m){
    int i, j;
    printf("\n Enter elements of matrix A: \n");
    for(i=0; i< m; i++){
        for(j=0; j< m; j++){
            printf("Enter element at A%d%d: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

}

void Print(int A[][10], int m){
    int i, j;
    printf("\n Output Matrix: \n");
    for(i=0; i<m; i++){
        for(j=0; j<m; j++){
            printf("%d  ",A[i][j]);
        }
        printf("\n");
    }
}

void UpperTriangleMatrix(int A[][10], int m){
    int i,j,flag;
    for (i = 1; i < m; i++){
		for (j = 0; j < i; j++){
			if (A[i][j] != 0){
				flag = 0;

            }else{
				flag = 1;

            }

        }

    }
	if (flag == 1)
		printf("Upper Triangular Matrix");
	else
		printf("Not an Upper Triangular Matrix");
}
