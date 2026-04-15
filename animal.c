#include<stdio.h>
#include<stdlib.h>


static void animal(void)
{
	int animal;

	printf("Please input letter:");
	animal = getchar();

	
	switch(animal)
	{
		case 'A':
		case 'a':
			printf("Ant");
			break;
		case 'B':
		case 'b':
			printf("Butterfly");
			break;
		case 'C':
		case 'c':
			printf("Cobra");
			break;
		case 'd':
		case 'D':
			printf("Donkey");
			break;
		default:
			break;
	
	
	}




}





int main()

{
	animal();
	exit(0);
}


















