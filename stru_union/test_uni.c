#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

struct digit
{
	uint16_t a;
	uint16_t b;

};


union unostd
{
	uint32_t x;
	struct digit y;
};


int diaplay(union unostd *p)
{

	int i;
	for (i=0;i<2;i++)
	{	
		printf("adress:%p---->low position:%x\n",&((p+i)->y.a),(p+i)->y.a);
	
		printf("adress:%p---->high position:%x\n",&((p+i)->y.b),(p+i)->y.b);
	}
	printf("\n\n");
	return 0;
}



int sum(union unostd *p)
{
	
	uint16_t sum =0;
	int j=0;
	for(j=0;j<2;j++)
	{		
		sum=(p+j)->y.a+(p+j)->y.b;
		printf("The sum of the high place and the low place is %x---->daress:%p\n",sum,&sum);
		sum=0;
	}
	return 0;
}


int sum2(uint32_t q)
{

	uint16_t sum=0x0000;
	uint16_t low;
	uint16_t high;

	high = q>>16;
	low = q & 0xFFFF;

	printf("high = %x\n",high);
	printf("low = %x\n",low);
	sum = high+low;
	printf("sum = %x\n",sum);
	return 0;
}

int main()
{
	union unostd test[2];
	uint32_t simp=0x11223344;
	test[0].x = 0x11223344;
	test[1].x = 0x55667788;
	diaplay(test);
	sum(test);
	sum2(simp);
	return 0;
}















































































