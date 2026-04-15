#ifndef _DOULINK_H__
#define _DOULINK_H__
#define FRONTEND 1
#define BACKEND 2

struct head_st;

typedef struct node_st
{
    struct node_st *prev;
    struct node_st *next;
    char data[1];

}basenode;

typedef void (*link_opt)(const void *);

typedef int (*opt)(const void *,const void *);

typedef struct node_st *(*base_opt)(struct head_st*,const void *,opt );

typedef struct head_st
{
    int datasize;
    struct node_st head;
    
    int (*insert)(struct head_st *,const void *,int );

    void (*travel)(struct head_st *,link_opt );

    int (*find)(struct head_st *,const void *,opt ,void *);

    int (*delete)(struct head_st *,const void *,opt);

    int (*fetch)(struct head_st *,const void *,opt,void *);

}headnode;



headnode *doulink_create(int);

void doulink_destroy(struct head_st *);

#endif
