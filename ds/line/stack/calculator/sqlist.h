#ifndef _SQLIST_H__
#define _SQLIST_H__

typedef struct base_node
{
    struct base_node *prev;
    struct base_node *next;
    void *data;

}basenode;

typedef struct head_node
{
    int datasize;
    struct base_node head;

}headnode;

typedef int (*base_op)(const void *,const void*);

headnode *sqlist_create(int);

int sqlist_isempty(headnode *);

int sqlist_insert(headnode *,const void *,int );

int sqlist_find(headnode *,const void *,base_op ,void *); 

int sqlist_fetch(headnode *,const void *,base_op ,void *);

void sqlist_destroy(headnode *);
    
#endif
