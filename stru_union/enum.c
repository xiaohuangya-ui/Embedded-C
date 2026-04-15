#include<stdio.h>
#include<stdlib.h>

enum color
{
	RED,
	GREEN=100,
	BLUE
};
void print_info()
{
	enum color colorone;
	int i;
	printf("Please input serial number:");
	if(scanf("%d",&i)==1)
	{	
	colorone = (enum color)i;
	switch(colorone)
	{
		case RED:
			printf("RED\n");
			break;
		case GREEN:
			printf("GREEN\n");
			break;
		case BLUE:
			printf("BLUE\n");
			break;
		default:
			printf("Invalid input\n");
			break;
	}
	}
	return ;
}

int main()
{

	print_info();
	return 0;
}

































