#ifndef _CACUL_H__
#define _CACUL_H__

#include "stack.h"

typedef char datatype;

int get_pre(int *);

int deal_bracket(stack *,stack *);

int deal_op(stack *,stack *,void *);

int compute(stack *,int *);

#endif
