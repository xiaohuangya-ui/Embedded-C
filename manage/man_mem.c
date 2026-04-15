#include<stdio.h>
#include<stdlib.h>

#define SIZE 20
#define NUM 5


#if 0
int test2()
{
	int *p;
	int i;
	p=calloc(NUM,sizeof(int));
	if(p==NULL)
	{
		printf("malloc() error\n");
		return -1;
	}
	else
	{
	for (i=0;i<NUM;i++)
	{
		printf("Please input number:");
		scanf("%d",p+i);
	}
	for (i=0;i<NUM;i++)
	{
	
		printf("%p---->%4d\n",p+i,p[i]);
	
	}
	printf("\n\n");
	free(p);
	printf("%p\n",p);	
	p=NULL;
	return 0;
	}

}
#endif

#if 0
int test1(void)
{

	int *p;
	
	
	p=malloc(sizeof(int)*5);
	if(p==NULL)
	{
		printf("malloc() error\n");
		return -1;
	}
	else
	{
	*p=100;
	printf("%p--->%d\n",p,*p);
	free(p);
	p=NULL;
	int q;
	q=128;

	printf("%p--->%d\n",&q,q);
	printf("%p\n",p);
	

	return 0;
	}
}

#endif
int test3(void)
{
	int *p,*temp;
	int i;
		
	p=calloc(NUM,sizeof(int));

	
	if(p==NULL)
	{
	
		printf("malloc() error!\n");
		return -1;
	}
	else
	{	
		for (i=0;i<NUM;i++)
		{
			printf("Please input number(%d):",NUM);
			if(scanf("%d",p+i)!=1)
				break;
		
		}


		for (i=0;i<NUM;i++)
		{
	
			printf("%p---->%4d\n",p+i,p[i]);
	
		}
	}
	printf("\n\n");
//change
	temp=realloc(p,2*NUM*sizeof(int));

	if(temp!=NULL)
	{
		p=temp;
		for (i=0;i<2*NUM;i++)
		{
			printf("Please input number(%d):",2*NUM);
			if(scanf("%d",p+i)!=1)
				break;
		}
		for (i=0;i<2*NUM;i++)
		{
	
			printf("%p---->%4d\n",p+i,p[i]);
	
		}
		printf("\n\n");
		free(p);
		printf("%p\n",p);
		p=NULL;
		return 0;
	}
	else
	{
		printf("recalloc() error!\n");
		return -1;
	}

}

	

int main()
{

//	test1();
//	test2();
	test3();
	return 0;
}





































































