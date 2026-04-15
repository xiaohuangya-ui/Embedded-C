#ifndef _DOULINK_H__
#define _DOULINK_H__
#define NAMESIZE 1024

#define FRONTEND 1
#define BACKEND 2
typedef struct node_bs
{
    void *data;
    struct node_bs *prev;
    struct node_bs *next;

}base_node;

typedef struct node_hd
{
    int datasize;
    struct node_bs head;

}head_node;

typedef struct node_stu
{
    int id;
    char name[NAMESIZE];
    int chinese;
    int math;

}stunode;

typedef void (*link_op)(const void *);

typedef int (*link_cmp)(const void *,const void *);

head_node *doulink_create(int);

int doulink_insert(head_node *,const void *,int );

void doulink_travel(head_node *,link_op );

void *doulink_find(head_node *,const void *,link_cmp );

int doulink_delete(head_node *,const void *,link_cmp );

int doulink_fetch(head_node *,const void *,link_cmp ,void *);

void doulink_destroy(head_node *);





#endif
