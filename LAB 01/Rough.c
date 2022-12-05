#include <stdio.h>
#include <stdlib.h>

void print_arr(int *arr, int arr_size)
{
	int i = 0;
	for ( ; i < arr_size-1; i++ )
	{
		printf("%d, ", *(arr+i));
	}
	printf("%d\n", *(arr+i));
}

void swap( int *arr, int index1, int index2 )
{
	int temp = *(arr+index1);
	*(arr+index1) = *(arr+index2);
	*(arr+index2) = temp;
}

int main(void)
{
	int arr_size = 10;
	int arr = (int)malloc(sizeof(int)*arr_size);

	for ( int i = 0; i < arr_size; i++ ){
		scanf("%d", (arr+i));}

	for ( int i = 0; i < arr_size-1; i++ )
	{
		for ( int j = 0; j < arr_size-i-1; j++ )
		{
			if (*(arr+j) > *(arr+j+1)){
				swap(arr, j, j+1);}
		}
		print_arr(arr, arr_size);
	}
}