#ifndef _QUEUE_H__
#define _QUEUE_H__

#include "sqlist.h"

typedef headnode queue;

queue *qu_create(int,int);

int qu_enter(queue *,const void *);

int qu_travel(queue *,list_op);

int qu_leave(queue *,void *);

int qu_cmp(queue *,base_op);

int qu_isempty(queue *);

void qu_destroy(queue *);

#endif
