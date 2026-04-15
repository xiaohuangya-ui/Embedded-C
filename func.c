#include<stdio.h>
#include<stdlib.h>


int min(int a,int b,int c)
{
	int tem;
	tem=a<b?a:b;
	return c<tem?c:tem; 
}

int max(int a,int b,int c)
{
	int tem;
	tem=a>b?a:b;
	return c>tem?c:tem; 
}


int dist(int a,int b,int c)
{

	return max(a,b,c)-min(a,b,c);
}



int main()
{
	int i,j,k;
	int res;
	printf("Please input three(eg:1 2 3):");
	if(scanf("%d %d %d",&i,&j,&k)==3)
	{	res=dist(i,j,k);
	
		printf("(i=%2d j=%2d k=%2d) the largest dist is %2d\n",i,j,k,res);
	}
	return 0;
}






















