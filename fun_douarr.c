#include<stdio.h>
#include<stdlib.h>

#define M 3
#define N 4


#if 0
void sum(int *p,int n)
{
	int i;
	int sum=0;
	for(i=0;i<n;i++)
	{
		sum+=p[i];
		printf("%p--->%2d \n",&p[i],p[i]);
	
	}
	printf("sum=%d\n",sum);
	return ;
}

#endif

void find(int (*q)[N],int n)
{
	int i;
	for(i=0;i<N;i++)
	{
		printf("%4d",*(*(q+n)+i));
		
	}
	printf("\n");	
	return ;
}


int main()
{

	int arr[M][N]={{1,2,3,9},{4,5,6,54},{23,56,78,34}};
//	int *p = *arr;
	int (*q)[N]=arr;
	int num;
	int i,j;

	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%4d",arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	printf("PLease the row(0 or 1 or 2):\n");
//	sum(p,M*N);
	if(scanf("%d",&num)==1)
	{
		find(q,num);
	}
	return 0;

}






















