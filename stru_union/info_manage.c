#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#define NAMESIZE 128

struct ret_info
{
	int record[128];
	int count;
	
};

struct birth_info
{

	int year;
	int month;
	int day;

};


struct stu_info
{
	float id;
	char name[NAMESIZE];
	struct birth_info birthday;
	char class;
	int chinese;
	int math;
	
};

int input_info(struct stu_info *student)
{
	int i,n; 
	
//input	
	printf("Please input thr number of students:");

	if(scanf("%d",&n)==1)

	{	
		while(getchar()!='\n');
		for (i=0;i<n;i++)
		{	printf("Please input the %d student information:\n",i+1);
			if(scanf("%f%s%d%d%d %c%d%d",
				&student[i].id,
				student[i].name,
				&student[i].birthday.year,
				&student[i].birthday.month,
				&student[i].birthday.day,
				&student[i].class,
				&student[i].chinese,
				&student[i].math)==8)
			
			{	
				printf("Entry completed,next!\n");
			}
			else
			{
			printf("ENTER ERROR!\n");
			break;
			}
		}
		
		return n; 
	}
	else
	{	printf("INPUT ENTER!\n");
		return -1;
	}
}

void show_all(struct stu_info *student,int number)
{
	int i;

	for (i=0;i<number;i++)
	{
			
		printf("%5f %6s %6d %6d %6d %3c %6d %6d\n",
			student[i].id,
			student[i].name,
			student[i].birthday.year,
			student[i].birthday.month,
			student[i].birthday.day,
			student[i].class,
			student[i].chinese,
			student[i].math);
	}	


	return ;
}

int show_one(struct stu_info *student,int number)
{
	int j;
	printf("Please enter the student number:");
	if(scanf("%d",&j)==1)
	{
			
		printf("%.5f %6s %6d %6d %6d %3c %6d %6d\n",
			student[j-1].id,
			student[j-1].name,
			student[j-1].birthday.year,
			student[j-1].birthday.month,
			student[j-1].birthday.day,
			student[j-1].class,
			student[j-1].chinese,
			student[j-1].math);
		return 0;
	}
	else
	{
		printf("ENTER ERROR!");
		return -1;
	}	

}


int search_info(struct stu_info *student,int number)
{
	int mode;


	printf("Please input the search pattern:\n0-show all\n1-display separately\n");
	if(scanf("%d",&mode)==1)
	{
		switch (mode)
		{
		
			case 0:
				show_all(student,number);
				break;
			case 1:
				show_one(student,number);
				break;
			default:
				printf("ENTER ERROR!");
				break;
		}
		return 0;
	
	
	}
	else
	{
	
		printf("INPUT ERROR!\n");
		return -1;
	}
}


int edit_info(struct stu_info *student,int number)
{

	char newname[NAMESIZE];
	int num;
	printf("Please input serial number and newname:");
	
	scanf("%d%*c%s",&num,newname);
	
	if(num>0 && num<=number)
	{
	
		strcpy(student[num-1].name,newname);
	
		return 0;
	}
	else
	{
		printf("Invalid index!\n");	
		return -1;
	}
}


struct ret_info menu(struct stu_info *student,int *number)
{
	struct ret_info ret_menu={{0},0};
	int *p=ret_menu.record;
	int choice;
	int res;
	do
	{
		printf("0-input information\n1-search for information\n2-edit information\n");
		printf("Please enter your choice(0-2),enter q or Q exit:\n");
		res=scanf("%d",&choice);
		p[ret_menu.count]=choice;
		ret_menu.count++;
		if (res==1  && (choice == 0 || choice==1 || choice==2 ))
		{
			switch (choice)
			{
				case 0:
					*number = input_info(student);
					printf("Successfully saved %d students.\n",*number);
			break;
				case 1:
					search_info(student,*number);
					break;
				case 2:
					edit_info(student,*number);
					break;
				default:
					break;
			
			
			}
	
		}
		else
		{	printf("ENTRE ERROR!\n");
			break;
		}
		sleep(1);
	}while(choice!='q' && choice!='Q');
	
	return ret_menu; 
	

}


int main()
{	
	struct stu_info student[128];
	struct ret_info rec_info;
	int number=0,i=0;
	printf("Please start this operation according tothe menu prompts(Enter a non-numeric input exit)\n");
	sleep(1);
	rec_info = menu(student,&number);

	for(;i<rec_info.count;i++)
	{
		printf("[%d]\n",rec_info.record[i]);
	}

	return 0;
}





















