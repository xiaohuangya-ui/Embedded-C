#ifndef _DOULINK_H__
#define _DOULINK_H__
#define FRONTEND 1
#define BACKEND 2

typedef void headnode;


typedef void (*link_opt)(const void *);

typedef void *(*base_opt)(headnode *,const void *);

typedef int (*opt)(const void *,const void *);

headnode *doulink_create(int);

int doulink_insert(headnode *,const void *,int );

void doulink_travel(headnode *,link_opt );

int doulink_find(headnode *,const void *,opt ,void *);

int doulink_delete(headnode *,const void *,opt);

int doulink_fetch(headnode *,const void *,opt,void *);

void doulink_destroy(headnode *);

#endif
