#ifndef _NOHEAD_LINK_H__
#define _NOHEAD_LINK_H__

#define NAMESIZE 1024

typedef struct score_info
{
        
    int id;
    char name[NAMESIZE];
    int chinese;
    int math;

}sconode;

typedef struct node_st
{
    struct score_info data;
    struct node_st *next;

}stunode;



int link_insert(stunode **,sconode *);

int link_delete(stunode **);

void link_display(stunode *);

int link_find(stunode **,int i,sconode *);

int link_destroy(stunode *);


#endif




