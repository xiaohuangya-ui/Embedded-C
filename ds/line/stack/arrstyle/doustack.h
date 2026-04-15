#ifndef _DOUSTACK_H__
#define _DOUSTACK_H__

#define DATASIZE 1024

typedef int datatype;


typedef struct node_st
{
    datatype data[DATASIZE];
    int top;

}stacknode;


stacknode *doustack_create();

int stack_isempty(stacknode *);

int doustack_push(stacknode *,const datatype *);

int doustack_pop(stacknode *,datatype *);

int doustack_top(stacknode *,datatype *);

void doustack_travel(stacknode *);

void doustack_destroy(stacknode *);




#endif
