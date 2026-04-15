#ifndef _JOSE_H__
#define _JOSE_H__

typedef struct node_st
{
    int data;
    struct node_st *next;

}josenode;

josenode *link_create(int *);

josenode *link_insert(josenode **,int *);

void link_display(josenode *);

void jose_kill(josenode ** ,int );
 
void  link_destroy(josenode*);

#endif
