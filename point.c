#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#if 0
static void test(void)
{
	int i = 123456;
	int *p = &i;


	printf("%p---->%d\n",&i,i);
	printf("%p---->%p\n",&p,p);

	return ;
}

#endif

#if 0
static void test1(void)
{
	int i = 256;
	int *p = &i;
	int **q = &p;

//handle
	printf("%p--->%d\n",&i,i);
	printf("%p--->%p\n",&p,p);
	printf("%p--->%p\n",&q,q);

	i = 255;
	printf("change by i directly:i = %d<---%p\n",i,&i);
	
	
	*p = 63;
	printf("change by p indirectly:*p = %d<---%p\n",i,&*p);

	**q = 15;
	printf("change by q indirectly:**q = %d<---%p\n",i,&**q);
//handle
	printf("by i:%d\nby p:%d\nby q:%d\n",i,*p,**q);


	return ;
}

#endif

#if 0
static void test2(void)
{
	int *p = NULL;
	printf("%p",p);

	return ;
}
#endif

#if 0
static void test3(void)
{

	int arr[3]={1,2,3};
	int *p=arr;
	int i;


	for(i=0;i<3;i++)
	{
	printf("%p--->%d\n",&arr[i],arr[i]);
	printf("\n\n");
	}

	for(i=0;i<3;i++)
	{
	printf("%p--->%d\n",arr+i,*(arr+i));
	printf("\n\n");
	}

	for(i=0;i<3;i++)
	{
	printf("%p--->%d\n",p+i,*(p+i));
	printf("\n\n");
	}
	return ;
}

#endif
#if 0

static void test4(void)
{
	int a[2][3]={{1,2},{2,4}};
	int i,j;
	int (*p)[3]=a;

//	printf("size of a:%ld\n",sizeof(a));
//	printf("size of *a:%ld\n",sizeof(*a));

/*	for (i=0;i<2;i++)
	{	
	
		printf("%p\n",a+i);

	}	

	
	for (j=0;j<3;j++)
	{	
	
		printf("%p\n",*a+j);

	}	
	

	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
		
			printf("%p--->%d\n",&a[i][j],a[i][j]);
		}
	}		
	printf("\n\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
		
			printf("%p--->%d\n",*(p+i)+j,*((*p+i)+j));
		}
	}		
*/


	return ;
}
#endif
#if 0
static void test5(void)
{

	char str[]="I love China!";
	char *p=str;

	puts(str);
	printf("\n\n");

	puts(p);
	
	return;
}

#endif

#if 0
static void test5(void)
{

	char str[] = "hello";
	char str1[] = "funny";
	char *p=str1;
	char *q = "liyujie";
	puts(str);
	printf("\n");
	
	strcpy(str,"world");
	puts(str);
	
	printf("\n");
	puts(str1);

	p = "no funny";
	puts(p);
	printf("\n");

	puts(q);
	printf("\n");

	q = "very good!";
	puts(p);
	printf("\n");

	return ;
}

#endif
#if 0
static void test6(void)
{

	 const int a=100;
	 int *p = &a;

	 p=101;
	 printf("a=%d",*p);


	return ;
}
#endif
#if 0
static void test7(void)
{
	int a=1,b=2,c=3;
	int *arr[3];
	int i; 

	arr[0]=&a;
	arr[1]=&b;
	arr[2]=&c;

	for (i=0;i<3;i++)
	{
	
	printf("%p--->%d\n",arr[i],*arr[i]);
	
	
	}
	return ;
}
#endif
int main()
{

//	test();
//	test1();
//	test2();
//	test3();
//	test4();
//	test5();
//	test6();
//	test7();
	exit(0);
}


























