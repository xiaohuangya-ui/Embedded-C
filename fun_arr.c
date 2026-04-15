#include<stdio.h>
#include<stdlib.h>

#define N 6

void testarr(int *p,int *q,int n)
{
	int i;
	for (i=0;i<n;i++)
	{	printf("%p--->%d\n",&p[i],p[i]);

		printf("%p--->%d\n",&q[i],q[i]);

	}
	return ;
}

int main()
{
	int arr[N] = {1,3,5,2,7,9};
	int *p = arr;


	testarr(arr,p,N);


	return 0;
}	



























