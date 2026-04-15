#include<stdio.h>
#include<stdlib.h>


int main(int argc, char *argv[])
{
	int i;
	printf("%d\n",argc);
	for (i=0;argv[i]!=NULL;i++)
	{
		printf("%s\n",argv[i]);
	}

	return 0;
}







































