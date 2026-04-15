#include<stdio.h>
#include<stdlib.h>

#include "stack.h"
#define NAMESIZE 1024
#define NUMBER 17
typedef struct stu_node
{
    int id;
    char name[NAMESIZE];
    int chinese;
    int math;
}stunode;

void print_s(void *data)
{
    stunode *out = data;
    printf("%2d %5s %2d %2d\n",out->id,out->name,out->chinese,out->math);
    return ;
}

int main()
{
    headnode *head = NULL;
    stunode member;
    int i,res;
    stunode data;

    head = stack_create(sizeof(member));
    if(head==NULL)
    {
        printf("Create failed!\n");
        return -1;
    }
    

    for (i=0;i<NUMBER;i++)
    {
        member.id=i;
        snprintf(member.name,NAMESIZE,"stu%2d",i);
        member.chinese=rand()%100;
        member.math=rand()%100;
        if(stack_push(head,&member))
            exit(0);
    }

    
    while (1)
    {
        res = stack_pop(head,&data);
    
        if(res!=0)
            break;
        print_s(&data);
    
    }

    stack_destroy(head);

    return 0;
}
