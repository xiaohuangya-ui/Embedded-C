#include<stdio.h>
#include<stdlib.h>

#include "queue.h"

qunode *queue_create()
{
    qunode *me = NULL;
    me = malloc(sizeof(*me));
    if (me==NULL)
        return NULL;

    me->head=0;
    me->tail=0;
    return me;

}

int que_isfull(qunode *me)
{
    return ((me->tail+1)%MAXSIZE == me->head);

    
}

int que_isempty(qunode *me)
{

    return (me->head==me->tail);
}

int queue_enter(qunode *me,datatype *data)
{

    if (que_isfull(me))
        return -1;
    me->tail = (me->tail+1)%MAXSIZE;
    me->data[me->tail] = *data;
    return 0;
}

int queue_leave(qunode *me,datatype *result)
{
    if (que_isempty(me))
        return -1;
    me->head = (me->head+1)%MAXSIZE;
    *result=me->data[me->head];
    return 0;
}

void queue_travel(qunode *me)
{
    int tmp = (me->head+1)%MAXSIZE;
    while(tmp != (me->tail+1)%MAXSIZE)
    {
        printf("%2d ",me->data[tmp]);
        tmp=(tmp+1)%MAXSIZE;
    }

    return ;

}

void queue_destroy(qunode *me)
{
    free(me);
    return ;
}
