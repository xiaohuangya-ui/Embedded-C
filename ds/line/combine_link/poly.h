#ifndef _POLY_H__
#define _POLY_H__

typedef struct numnode
{
    int coef;
    int index;

}numnode;

typedef struct node_st
{
    struct numnode data;
    struct node_st *next;

}paranode;


paranode *link_create();

int link_order_insert(paranode *,int arr[2]);

void link_display(paranode *);

paranode *link_merge(paranode **,paranode **);

int link_destroy(paranode *);


#endif
