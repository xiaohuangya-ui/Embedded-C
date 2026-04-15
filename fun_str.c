#include<stdio.h>
#include<stdlib.h>
#include<string.h>



#if 0
char *mystrcpy(char *dest,const char *src)
{
	int i;
	char *res=dest;
	if (dest!=NULL && src!=NULL)
	{
	
		for(i=0;src[i]!='\0';i++)
		{
	
			dest[i]=src[i];
	
		}
		dest[i] = '\0';
		return res;
	}
	else
		return NULL;
}
#endif

#if 0
char *mystrcpy(char *dest,const char *src)
{
	char *res=dest;
	if(dest!=NULL&&src!=NULL)
	{
	
		while((*dest++=*src++)!='\0');
		//*dest='\0';
		return res;
	
	}
	else
	{
	
	return NULL;
	}


}
#endif


char *mystrncpy(char *dest,const char *src,size_t n)
{
	char *res=dest;
	size_t i=0;
	if(dest!=NULL && src!=NULL)
	{
	
		for(;i<n && src[i]!='\0';i++)
		{
		
			dest[i]=src[i];
		}

		for (;i<n;i++)
		{
			dest[i]='\0';
		}
		return res;
	}
	else
	{
		return NULL;
	}


}


int main()
{
	char str[]="hello world";
	char str1[128];
	int n;
	printf("Please enter the number of characters that need to be cpoied:");
	if(scanf("%d",&n)==1)
//	mystrcpy(str1,str);
	{	if(n<0||n>127)
		{
			printf("INPUT ERROR,please input 0-127:\n");
			return -1;
		}
		else
		{	
			mystrncpy(str1,str,n);
			str1[n]='\0';
			puts(str1);
		}
	}
	return 0;
}






















