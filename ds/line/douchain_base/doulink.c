#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "doulink.h"


head_node *doulink_create(int initial)
{
    head_node *me = NULL;

    me = malloc(sizeof(*me));
    if(me==NULL)
        return NULL;
    
    me->datasize = initial;
    me->head.data = NULL;
    me->head.prev = &(me->head);
    me->head.next = &(me->head);
    return me;
}

int doulink_insert(head_node *me,const void *data,int mode)
{
    base_node *new_node=NULL;
    new_node = malloc(sizeof(*new_node));
    if(new_node==NULL)
    {
        return -1;
    }

    new_node->data = malloc(me->datasize);
    if(new_node->data==NULL)
    {
        free(new_node);
        return -2;
    }
    memcpy(new_node->data,data,me->datasize);
    if (mode==FRONTEND)
    {
        new_node->prev = &(me->head);
        new_node->next = me->head.next;
    }
        else if(mode==BACKEND)
        {
            new_node->prev = me->head.prev;
            new_node->next = &(me->head);
        }
            else
            {
                return -3;
            }

        new_node->prev->next = new_node;
        new_node->next->prev = new_node;
        return 0;
}



static base_node *linkfind(head_node *me,const void *key,link_cmp camp)
{   
    base_node *cur = NULL;
    for (cur=me->head.next;cur != &(me->head);cur=cur->next)
    {
        if(camp(key,cur->data)==0)
            break;
    }
    
    return cur; 
    
}

void *doulink_find(head_node *me ,const void *key ,link_cmp camp)
{       
        base_node *res = linkfind(me,key,camp);
        if(res== &(me->head))
            return NULL;
        return res->data;
}

void doulink_travel(head_node *me,link_op print_s)
{
    base_node *cur=NULL;

    for(cur = me->head.next;cur!=&(me->head);cur=cur->next)
    {
        print_s(cur->data);
    }
    
    printf("\n\n");
    return ;
}

int doulink_delete(head_node *me,const void *key,link_cmp cmp)
{


      base_node *res = linkfind(me,key,cmp);
      if(res==&(me->head))
          return -1;

       res->prev->next=res->next;
       res->next->prev=res->prev;
       free(res->data);
       free(res);
       return 0;

}

int doulink_fetch(head_node *me,const void *key,link_cmp cmp,void *data)
{
    base_node *res = linkfind(me,key,cmp);
    if (res==&(me->head))
    {
        return -1;
    }

    memcpy(data,res->data,me->datasize);
    res->prev->next=res->next;
    res->next->prev=res->prev;
    free(res->data);
    free(res);
    return 0;

}


void doulink_destroy(head_node *me)
{
    base_node *cur=me->head.next;
    base_node *nxt=NULL;
    while(cur != &(me->head))
    {
        nxt = cur->next;
        free(cur->data);
        cur->data= NULL;
        free(cur);
        cur=nxt;
    }

    free(me);
}



















