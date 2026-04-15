#include<stdio.h>
#include<stdlib.h>

#include "stack.h"
#define FRONTEND 1

stack *stack_create(int initial,int maxsize)
{
    return sqlist_create(initial,maxsize);
    
}

int stack_isempty(stack *me)
{
    return sqlist_isempty(me);

}

int stack_isfull(stack *me)
{

    return sqlist_isfull(me);
}

int stack_travel(stack *me,list_op opt)
{
    return sqlist_travel(me,opt);
    
}

int stack_push(stack *me,const void *data)
{
    
    return sqlist_insert(me,data,FRONTEND);
    
}

static int always_match(const void *ref,const void *data)
{
    return 0;
}

int stack_pop(stack *me,void *data)
{
    return sqlist_fetch(me,(void *)0,always_match,data);
}


void stack_destroy(stack *me)
{

    sqlist_destroy(me);
}



