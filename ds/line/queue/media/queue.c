#include<stdio.h>
#include<stdlib.h>

#include "queue.h"
#define BACKEND 2

typedef int (*base_op)(const void *,const void *);

queue *qu_create(int datasize,int maxsize)
{
    return sqlist_create(datasize,maxsize);
}

int qu_travel(queue *me,list_op opt)
{
    return sqlist_travel(me,opt);
}

int qu_enter(queue *me,const void *data)
{
    return sqlist_insert(me,data,BACKEND);
}

int always_match(const void *ref,const void *data)
{

    return 0;
}

int qu_leave(queue *me,void *result)
{
    return sqlist_fetch(me,(void *)0,always_match,result);
    
}

int qu_cmp(queue *me,base_op cmp)
{
    return sqlist_cmp(me,cmp);

}

int qu_isempty(queue *me)
{
    return sqlist_isempty(me); 
}

void qu_destroy(queue *me)
{
    sqlist_destroy(me);
    return ;
}



