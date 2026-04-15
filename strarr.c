#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#if 0
static void test(void)
{

	char str[128];
	int i;
	gets(str);

	for(i=0;i<128;i++)
	{
		printf("%c\n",str[i]);

	}

return ;
}
#endif



static void cotarr(void)
{
	char txt[256];
	int count=0;
	int i,flag=0;
//input
	printf("Please input your txt:");
	gets(txt);

//handle
	for(i=0;txt[i]!='\0';i++)
	{
		if(txt[i]==' ')
		{
		
		flag=0;
		
		}
		else//not " " is letter 
			if(flag == 0) //letter in first or middle:=0 is first or is middls
			{
			count++;
			flag=1;

			}	

	}
//output
	printf("The number is:%d\n",count);
	return ;

}

int main()
{
//	test();
	cotarr();


	exit(0);
}





















