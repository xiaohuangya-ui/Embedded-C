#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define WEIGHT 3.0E-23
#define KQ 	950
#if 0
static void water(void)
{


	float num,sum;
	
	printf("Please input the weught of water\n:");
	scanf("%f",&num);	
	

	sum = num * KQ / WEIGHT;

	printf("The number of water:%e\n",sum);

	return ;

}
#endif

#if 0
static void areas(void)
{

	float a,b,c,s,area;

	printf("Please input three sides:");


	if (scanf("%f %f %f",&a,&b,&c) !=3)
	{

		printf("Invalid input!Please input correct number:\n");
		return ;
	}


	if (a+b>c && a+c>b && b+c>a)
	{
	s = 1.0/2* (a+b+c);
	area=sqrt(s*(s-a)*(s-b)*(s-c));
	
	printf("The areas is :%f\n",area);
	}

	else
	{
	printf("input is wrong!!!\n");
	}
	return ;
}
#endif


static void root(void)
{
	float a,b,c,sq,dlt,p,q;
	float x1,x2;

	printf("Please input:");
	if (scanf("%f %f %f",&a,&b,&c) != 3)
	{
		printf("Invald input!\n")	;
		return ;
	
	}
	
	dlt = b*b-4*a*c;


	if( dlt<0)
	{
	printf("No real root\n");
	}
	else

	{
	sq=sqrt(dlt);
	p=-b/2/a;
	q=sq/2/a;
	x1=p+q;
	x2=p-q;
	printf("x1=%f,x2=%f\n",x1,x2);
	
	}
return ;
}

int main()
{
//	water();
//	areas();
	root();


	exit(0);
}


















