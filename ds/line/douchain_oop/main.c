#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "doulink.h"

#define NAMESIZE 1024
#define NUMBER 45


typedef struct stuinf
{
    int id;
    char name[NAMESIZE];
    int chinese;
    int math;
}stunode;


void print_s(const void *data)
{
    const stunode *cur=data;
    printf("%2d %5s %2d %2d\n",cur->id,cur->name,cur->chinese,cur->math);
    return ;
}

int id_cmp(const void *ref,const void *data)
{
    const int *r=ref;
    const stunode *d=data;
    
    return *r-d->id;

}


int main()
{
    int i;
    stunode *data1=NULL;
    int value1=25;
    int value2=19;
    headnode *head = NULL;
    stunode student;

    head = doulink_create(sizeof(student));
    if (head == NULL)
        return -1;
    for (i=0;i<NUMBER;i++)
    {
        student.id = i;
        snprintf(student.name,NAMESIZE,"student%d",i);
        student.chinese=rand()%100;
        student.math=rand()%100;
        head->insert(head,&student,BACKEND);
    }

    head->travel(head,print_s);
    printf("\n\n");

    head->delete(head,&value1,id_cmp);
    head->travel(head,print_s);
    printf("\n\n");
    
    data1=malloc(sizeof(*data1));
    if(data1==NULL)
        return -1;
    head->fetch(head,&value2,id_cmp,data1);
    print_s(data1);
    printf("\n\n");

    head->travel(head,print_s);

    doulink_destroy(head);
    
    return 0;


}

