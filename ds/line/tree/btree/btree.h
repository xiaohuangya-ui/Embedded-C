#ifndef _BTREE_H__
#define _BTREE_H__
#define L 1
#define R 2
#define FRONTEND 1
#define MIDDLE 2
#define BACKEND 3
#define LAYER 4
#define FPATH "/tmp/tree"
#include "sqlist.h"
#include "queue.h"

typedef int (*base_op)(const void *,const void *);
typedef void (*out_op)(const void *);

typedef struct tree_node
{
    void *data;
    struct tree_node *left;
    struct tree_node *right;
}treenode;


int tree_insert(treenode **,base_op ,const void *,int );

treenode * tree_find(treenode *,base_op ,const void *);

void tree_draw(treenode *,out_op ,int );

void tree_balance(treenode **);

int tree_delete(treenode **,base_op ,const void *,int);

void tree_travel(treenode *,out_op ,int );

void tree_destroy(treenode **);

int tree_save(treenode *,const char *,int );

treenode *tree_load(const char *,int);

#endif 
