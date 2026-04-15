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
    const int *d=data;
    
    if (*r-*d==0)
        return 0;

}


int main()
{
    int i;
    stunode *data1;
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
        doulink_insert(head,&student,BACKEND);
    }

    doulink_travel(head,print_s);
    printf("\n\n");


    doulink_delete(head,&value1,id_cmp);
    doulink_travel(head,print_s);
    printf("\n\n");

    doulink_fetch(head,&value2,id_cmp,data1);
    print_s(data1);
    printf("\n\n");

    doulink_travel(head,print_s);

    doulink_destroy(head);
    
    return 0;


}

