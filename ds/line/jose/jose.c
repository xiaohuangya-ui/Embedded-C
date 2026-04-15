#include<stdio.h>
#include<stdlib.h>

#include "jose.h"

josenode *link_create(int *data)
{
    josenode *me=NULL;
    me = malloc(sizeof(*me));
    if(me== NULL)
        return NULL;
    me->data = *data;
    me->next = me;
    return me;

}

josenode *link_insert(josenode **cur,int *data)
{
    josenode *new_node=NULL;
    
    new_node = malloc(sizeof(*new_node));
    if(new_node == NULL)
    {
        return NULL;
    }
    
    new_node->data = *data;
    new_node->next = (*cur)->next;
    (*cur)->next = new_node;
    return new_node;
    
}


void link_display(josenode *me)
{

    josenode *cur=me;

    while(cur->next!=me)
    {
        printf(" %d ",cur->data);
        cur=cur->next;
    }
    printf(" %d ",cur->data);
    printf("\n");
    return ;
}

void jose_kill(josenode **me,int n)
{
    josenode *pre = *me;
    josenode *cur = *me;
    josenode *tem = NULL;
    int i;
    
    while(cur != cur->next)
    {
        for (i=1;i<n;i++)
        {
            pre=cur;
            cur = cur->next;
        }
        
        printf(" %d ",cur->data);
        pre->next = cur->next;
        tem = cur;
        cur=cur->next;
        free(tem);
        tem =NULL;
    }
    printf("\n");

    return ;
}


void link_destory(josenode *me)
{
    josenode *cur = me->next;
    josenode *temp = NULL;
    while(cur!=me)
    {
        temp = cur;
        cur = cur->next;
        free(temp);
        temp = NULL;

    }
    free(me);
    me = NULL;
    return ;
}
