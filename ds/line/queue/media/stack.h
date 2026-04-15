#ifndef _STACK_H__
#define _STACK_H__

#include "sqlist.h"

typedef headnode stack;

stack *stack_create(int,int);

int stack_isempty(stack *);

int stack_isfull(stack *);

int stack_travel(stack *,list_op);

int stack_push(stack *,const void *);

int stack_pop(stack *,void *);

void stack_destroy(stack *);

#endif
