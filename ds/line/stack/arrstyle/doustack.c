#include<stdio.h>
#include<stdlib.h>

#include "doustack.h"


stacknode *doustack_create()
{
    stacknode *me = NULL;
    me = malloc(sizeof(*me));
    if(me==NULL)
        return NULL;
   
    me->top=-1;
    return me;


}

int stack_isempty(stacknode *me)
{
    return (me->top==-1);
}


int doustack_push(stacknode *me,const datatype *data)
{
    if (me->top == DATASIZE-1)
        return -1;
    me->data[++me->top] = *data;
    return 0;

}

int doustack_pop(stacknode *me,datatype *data)
{
    if (stack_isempty(me))
        return -1;
    *data = me->data[me->top--];
    return 0;

}

int doustack_top(stacknode *me,datatype *data)
{
    if(stack_isempty(me))
        return -1;
    *data = me->data[me->top];
    return 0;
}

void doustack_travel(stacknode *me)
{
    int i;
    if(stack_isempty(me))
        return ;
    
    for (i=0;i<=me->top;i++)
        printf(" %2d ",me->data[i]);
    return ;
}

void doustack_destroy(stacknode *me)
{
    free(me);
    return ;
}


