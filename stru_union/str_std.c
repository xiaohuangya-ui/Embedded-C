#include<stdio.h>
#include<stdlib.h>
#define NAMESIZE 128

struct name
{
	char first[NAMESIZE];
	char last[NAMESIZE];

};


struct info_std
{
	int id;
	float value;
	char class;
	struct name full_name;


};

void printf_info(struct info_std *p,const struct info_std *q)
{

	*p=*q;
	printf("%4d %2f %4c %6s %6s\n",
		p->id,
     		p->value,
		p->class,
		p->full_name.first,
		p->full_name.last);
	return ;
}

int main()
{
	struct info_std info_temp;
	struct info_std info;
	printf("Please enter the relevant information:");
	scanf("%d%f %c%s%s",
		&info_temp.id,
     		&info_temp.value,
		&info_temp.class,
		info_temp.full_name.first,
		info_temp.full_name.last);
	printf_info(&info,&info_temp);	

	return 0;
}




















