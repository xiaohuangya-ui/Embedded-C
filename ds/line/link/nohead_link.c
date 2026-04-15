#include<stdio.h>
#include<stdlib.h>
#include "nohead_link.h"



int link_insert(stunode **me,sconode *data)
{
    stunode *new_node=NULL;
    new_node = malloc(sizeof(*new_node));


    if(new_node==NULL)
    {
        return -1;
    }

    new_node->data = *data;
    new_node->next = *me;
    *me = new_node;
    return 0;

}

int link_delete(stunode **me)
{

    stunode *temp=NULL;
    temp = *me;
    *me = (*me)->next;
    free(temp);
    temp = NULL;
    return 0;

}

void link_display(stunode *me)
{
    stunode *cur=NULL;

    for (cur = me;cur!=NULL;cur=cur->next)
    {
        printf("%d %s %d %d\n",cur->data.id,cur->data.name,
                                cur->data.chinese,cur->data.math);

    }

    return ;
}


int link_find(stunode **me,int i,sconode *data)
{
    stunode *cur=*me;
    stunode *nxt=NULL;
    
    while(cur != NULL)
    {
        if (cur->data.id == i)
        {
          *data = cur->data;
          return 0;
        }
        nxt=cur->next;
        cur = nxt;
    }

    return -1;

}

int link_destroy(stunode *me)
{
    stunode *cur=me;
    stunode *nxt=NULL;

    while(cur != NULL)
    {
        nxt=cur->next;
        free(cur);
        cur = nxt;
    }
    
    return 0;

}



