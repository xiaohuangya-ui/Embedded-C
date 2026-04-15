#include<stdio.h>
#include<stdlib.h>


#define M 2
#define N 3
#define K 4

#if 0
static void exchange(void)
{

	int i,j;
	int arr1[M][N]={{1,2,3},{4,5,6}};
	int arr2[N][M]={0};
//origin
	for (i=0;i<M;i++)
	{
		for (j=0;j<N;j++)
		{
		
			printf("%2d",arr1[i][j]);

		}
		
	printf("\n");
	}


//handle
	for (i=0;i<M;i++)
	{
		for (j=0;j<N;j++)
		{
		
			arr2[j][i]=arr1[i][j];
		}
		
	
	}
//output
	for (i=0;i<N;i++)
	{
		for (j=0;j<M;j++)
		{
		
			printf("%2d",arr2[i][j]);

		}
		
	printf("\n");
	}
	return ;
}

#endif



#if 0
static void max(void)
{
	int i,j;
	int row,col;
	int maxone;
//input
	int arr[M][N]={{89,652,744},{123,5465,9987}};

	for (i=0;i<M;i++)
	{
		for (j=0;j<N;j++)
		{
		
			printf("%6d",arr[i][j]);

		}
		
	printf("\n");
	}
//handle
	maxone = arr[0][0];
	for(i=0;i<M;i++)
	{
	
		for(j=0;j<N;j++)
		{
		
			if(arr[i][j]>maxone)
			{
			
				maxone=arr[i][j];
				row=i;
				col=j;
			}
		
		
		}
	
	
	}
//output
	printf("maxinum=%d\n",maxone);
	printf("row=%d\n",row);
	printf("col=%d\n",col);
	return ;
}
#endif

#if 0
static void sum(void)
{
	int i,j;

//input
	int arr[M+1][N+1]={{1,2,3},{4,5,6}};

	for (i=0;i<M+1;i++)
	{
		for (j=0;j<N+1;j++)
		{
		
			printf("%6d",arr[i][j]);

		}
		
	printf("\n");
	}
printf("\n");
//handle
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
			{
			
				arr[M][N]+=arr[i][j];
				arr[i][N]+=arr[i][j];
				arr[M][j]+=arr[i][j];
			
			}
	
	}

	for (i=0;i<M+1;i++)
	{
		for (j=0;j<N+1;j++)
		{
		
			printf("%6d",arr[i][j]);

		}
		
	printf("\n");
	}
	return ;
}

#endif

static void multiple(void)
{
	int i,j,k;
//input
	int arr1[M][N]={{1,2,3},{4,5,6}};
	int arr2[N][K]={{1,4,6,9},{2,5,6,3},{3,6,7,1}};
	int arrsum[M][K]={0};
printf("arr1:\n");
	for (i=0;i<M;i++)
	{
		for (j=0;j<N;j++)
		{
		
			printf("%6d",arr1[i][j]);

		}
		
	printf("\n");
	}

printf("\n");

printf("arr2:\n");
	for (i=0;i<N;i++)
	{
		for (j=0;j<K;j++)
		{
		
			printf("%6d",arr2[i][j]);

		}
		
	printf("\n");
	}
printf("\n");


//handle
	for(i=0;i<M;i++)
	{
	
		for(j=0;j<K;j++)
		{
		
			for(k=0;k<N;k++)
			{
			
				arrsum[i][j]+=arr1[i][k]*arr2[k][j];
			
			}
		
		
		}	
	
	
	}

//output
printf("The result is:\n");
	for (i=0;i<M;i++)
	{
		for (j=0;j<K;j++)
		{
		
			printf("%6d",arrsum[i][j]);

		}
		
	printf("\n");
	}
	return ;
}



int main()
{
//	exchange();
//	max();
//	sum();
	multiple();
	exit(0);
}































