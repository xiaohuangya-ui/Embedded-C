#include<stdio.h>
#include<stdlib.h>

#include "stack.h"
#define FRONTEND 1

stack *stack_create(int initial)
{
    return sqlist_create(initial);
    
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



