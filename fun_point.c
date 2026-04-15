#include<stdio.h>
#include<stdlib.h>

int sub(int a,int b)
{

	return a-b;
}


int plu(int a,int b)
{
	return a+b;

}

int main()
{
	int a=5,b=3;
	int (*p[2]) (int,int);
	int res;
	p[0]=plu;
	p[1]=sub;
	res = p[0](a,b)-p[1](a,b);
	printf("result=%d\n",res);
	return 0;
}



































