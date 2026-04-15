#include<stdio.h>
#include<stdlib.h>

#define LEN 10


#if 0
static void exchange1(int arr[],int length)
{

	int i = 0,j = length-1;
	int tem;
	int k;


	while(i<j)
	{
	
		tem=arr[j];
		arr[j] = arr[i];
		arr[i] = tem;
		i++;
		j--;
	}

	for (k=0;k<length;k++)
	{
		printf("%d ",arr[k]);
	
	}
	printf("\n");
	return ;

}	
#endif


#if 0
static void exchange2(int arr[],int length)
{

	int tem;
	int i,j,k;


	for(i=0,j=length-1;i<j;i++,j--)
	{
	
		tem=arr[j];
		arr[j] = arr[i];
		arr[i] = tem;
	}

	for (k=0;k<length;k++)
	{
		printf("%d ",arr[k]);
	
	}
	printf("\n");
	return ;

}	
#endif

#if 0
static void fibonacci(void)
{
	int i,j; 
	int fib[LEN]={1,1};
	for(i=2;i<sizeof(fib)/sizeof(fib[0]);i++)
	{
	
		fib[i] = fib[i-1] + fib[i-2];
	}

	for (j=0;j<sizeof(fib)/sizeof(fib[0]);j++)
	{
		printf("%d ",fib[j]);
	
	
	}
	printf("\n");


	exchange1(fib,sizeof(fib)/sizeof(fib[0]));
	exchange2(fib,sizeof(fib)/sizeof(fib[0]));
	return ;
}

#endif


#if 0
static void sort1(void)
{
	int i,j,tem,k;
	int arr[LEN]={11,34,8,87,66,54,11,34,98,6};

//original

	for (k=0;k<sizeof(arr)/sizeof(arr[0]);k++)
	{
	
	printf("%d ",arr[k]);
	
	}
	printf("\n");

	
//sort
	for (i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		for (j=0;j<(sizeof(arr)/sizeof(arr[0]))-1-i;j++)
		{
			if (arr[j]>arr[j+1])
			{
				tem = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = tem;

			}
			
		}
	
	}


	
//output
	for (k=0;k<sizeof(arr)/sizeof(arr[0]);k++)
	{
	
	printf("%d ",arr[k]);
	
	}
	printf("\n");
	return ;
}
#endif


#if 0
static void sort2(void)

{
	int i,j,k,tem,tem1;
	int arr[LEN]={11,79,8,87,66,54,68,34,98,6};

	
//original
	for (k=0;k<sizeof(arr)/sizeof(arr[0]);k++)
	{
	
	printf("%d ",arr[k]);
	
	}
	printf("\n");
//sort
	

	for (i=0;i<sizeof(arr)/sizeof(arr[0])-1;i++)
	{	
		
		tem = i;
		for (j=i+1;j<sizeof(arr)/sizeof(arr[0]);j++)
		{
			if(arr[j]<arr[tem])
			{
				tem=j;
			}
		}
		if(i!=tem)
		{
		
			tem1 = arr[tem];
			arr[tem] = arr[i];
			arr[i] = tem1;
		
		}

//output
	for (k=0;k<sizeof(arr)/sizeof(arr[0]);k++)
	{
	
	printf("%d ",arr[k]);
	
	}
	printf("\n");
	}

	return ;
}

#endif

//delete method

#if 0
static void prime(void)
{
	int i,j,k;
	char arr[1001]={0};

	for (i=2;i<1001;i++)
	{
		if(arr[i]==0)
		{
			for(j=2*i;j<1001;j+=i)
			{	
				
				arr[j] = -1;
			}
		
		}
	
	}
	for (k=2;k<1001;k++)
	{
		if(arr[k]==0)
		{
		printf("%d ",k);
		}
	}
	printf("\n");

	return ;

}
#endif

#if 0

static void convert(void)
{
	int num;
	int base;
	int i;
	int arr[128];
//input
	printf("Please input the number:");
	scanf("%d",&num);

	printf("Please input base:");
	scanf("%d",&base);

//handle
	
	for (i=0;num != 0;i++)
	{

		arr[i] = num%base;
		num = num/base;
	
	}
//output
	for (i--;i>=0;i--)
	{
		if(arr[i]>=10)
		{
			printf("%c",arr[i]-10 + 'A');
		}
		
		else
		{
			printf("%d",arr[i]);
		}
	}
	printf("\n");

	return ;
}	


#endif



int main()
{

//	fibonac1i();
//	sort1();
//	sort2();
//	prime();
//	convert();
	exit(0);
}







































