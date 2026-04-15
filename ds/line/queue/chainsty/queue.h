#ifndef _QUEUE_H__
#define _QUEUE_H__

#include "sqlist.h"

typedef headnode queue;

queue *qu_create(int);

int qu_enter(queue *,const void *);

int qu_leave(queue *,void *);

int qu_isempty(queue *);

void qu_destroy(queue *);

#endif
