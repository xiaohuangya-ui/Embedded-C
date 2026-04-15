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
    int maxsize;
    int count;
    struct base_node head;

}headnode;

typedef int (*base_op)(const void *,const void*);

typedef int (*list_op)(const void *);

headnode *sqlist_create(int,int);

int sqlist_isempty(headnode *);

int sqlist_isfull(headnode *);

int sqlist_travel(headnode *,list_op);

int sqlist_insert(headnode *,const void *,int );

int sqlist_fetch(headnode *,const void *,base_op ,void *);

int sqlist_cmp(headnode *,base_op );

void sqlist_destroy(headnode *);
    
#endif
