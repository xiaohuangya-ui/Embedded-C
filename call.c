#include<stdio.h>
#include<stdlib.h>


//void print_hello(void);

#if 0

void exchange_print(int a,int b)
{
	int tem;

	printf("i=%d,j=%d\n",a,b);
	tem = a;
	a=b;
	b=tem;
	printf("i=%d,j=%d\n",a,b);
	
	return ;
}

#endif
void exchange(int *p,int *q)
{
	int tem;

	tem = *q;
	*q = *p;
	*p = tem;


	return ;
}
int main()
{
	int i=6,j=98;

	printf("i=%d,j=%d\n",i,j);
//	exchange_print(i,j);
	exchange(&i,&j);	
	printf("i=%d,j=%d\n",i,j);
	

	return 0 ;
}

#if 0
void print_hello(void)
{

	printf("hello world\n");
	return ;
}
#endif


























