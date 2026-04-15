#include<stdio.h>
#include<stdlib.h>

/*
#define INT int
typedef int INT;

INT i--->int i;

#define IP int *   
IP p,q;--->int *p,q;


typedef int *IP;
IP p,q--->int *p,*q


typeof int ARR[6];
ARR a---> int a[6]


*/
/*
 *
 typedef int FUNC(int);--->int(int) FUNC
 FUNC F--->int F(int);
 *
 typeof int *FUNC(int);--->int*(int) FUNC
 FUNC G--->int *G(int);
 *
 typedef int *(*FUNC)(int);--->int *(*)(int)
 FUNC H--->int *(*H)(int);
 *
 */
#if 0
struct node_st
{
	int i;
	int j;

};

typedef struct 
{
	int a;
	int b;

} STD,*STDP;


typedef struct node_st NODE;
typedef struct node_st *NODEP;

int test2(void)
{

	STD x;
	STDP q;
	q=&x;
	x.a=66;
	x.b=77;
	printf("%p--->%4d %p--->%4d\n",&x.a,x.a,&x.b,x.b);

	q->a=88;
	q->b=99;
	printf("%p--->%4d %p--->%4d\n",&(q->a),x.a,&(q->b),x.b);

	return 0;

}	


int test1(void)
{
	NODE a;//struct node_st a;
	NODEP p=&a;//struct node_st *p;
	a.i=15;
	a.j=255;
	printf("%4d %4d\n",a.i,a.j);
	
	p->i=16;
	p->j=256;
	printf("%4d %4d\n",a.i,a.j);
	return 0;
}
#endif



int main()
{
//	test1();

//	test2();
	return 0;
}

























