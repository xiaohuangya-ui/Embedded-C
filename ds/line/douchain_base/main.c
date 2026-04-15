#include<stdio.h>
#include<stdlib.h>

#include "doulink.h"

#define NUMBER 45
static void print_s(const void *data)
{
    const stunode *r = data;
    
    printf("%2d %5s %2d %2d\n",r->id,r->name,r->chinese,r->math);
}


static int id_cmp(const void *key,const void *record)
{
    const int *k = key;
    const stunode *r = record;

    return (*k-r->id);
    
    
}

int main()
{
    int initial=sizeof(stunode);
    int i,value1,value2;
    int value3=27;
    int num=99;

    stunode *data=NULL;
    stunode *rcdata=NULL;
    stunode tem;
    head_node *head =NULL;
    head=doulink_create(initial);
    for (i=0;i<NUMBER;i++)
    {
        tem.id=i;
        snprintf(tem.name,NAMESIZE,"stu%d",i);
        tem.chinese = rand() % 100;
        tem.math = rand() % 100;
        doulink_insert(head,&tem,BACKEND);
    }

    doulink_travel(head,print_s);

    data = doulink_find(head,&num,id_cmp);
    if (data ==NULL)
    {
        printf("Can't find this data!\n");
    }
    else
        
    {
        printf("%2d %5s %2d %2d\n\n",data->id,data->name,data->chinese,data->math);
    }

    value1 = doulink_delete(head,&num,id_cmp);
    if(value1==-1)
    {

        printf("Can't find it!\n");
    }
    else
    {   
        doulink_travel(head,print_s);
    }
    rcdata=malloc(sizeof(*rcdata));
    value2 = doulink_fetch(head,&value3,id_cmp,rcdata);
    if(value2==-1)
    {
        printf("search faild!\n");
    }
    else
    {
        printf("%2d %5s %2d %2d\n",rcdata->id,rcdata->name,rcdata->chinese,rcdata->math);
    }
    free(rcdata);

    doulink_destroy(head);
    return 0;

}
