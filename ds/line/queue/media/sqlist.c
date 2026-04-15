#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "sqlist.h"

#define FRONTEND 1
#define BACKEND 2
headnode *sqlist_create(int initial,int max)
{
    headnode *me = NULL;
    me=malloc(sizeof*(me));
    if(me==NULL)
        return NULL;
    me->datasize = initial;
    me->count = 0;
    me->maxsize = max;
    me->head.prev=&me->head;
    me->head.next=&me->head;
    return me;

}

int sqlist_isempty(headnode *me)
{
    return (me->head.next==&me->head);

}

int sqlist_isfull(headnode *me)
{

   if (me->count == me->maxsize )
       return 1;
   return 0;

}

int sqlist_insert(headnode *me,const void *data,int mode)
{
    basenode *new_node = NULL;
    
    if (me->count==me->maxsize)
        return -4;

    new_node = malloc(sizeof(*new_node));
    if(new_node==NULL)
        return -1;
    new_node->data=malloc(me->datasize);
    if(new_node->data==NULL)
    {
        free(new_node);
        return -2;
    }
    memcpy(new_node->data,data,me->datasize);
    if (mode==FRONTEND)
    {
        new_node->prev=&me->head;
        new_node->next=me->head.next;
    }
        else if(mode == BACKEND)
        {
            new_node->prev=me->head.prev;
            new_node->next=&me->head;
        }
            else
            {
                free(new_node);
                new_node=NULL;
                return -3;
            }
        new_node->prev->next=new_node;
        new_node->next->prev=new_node;
        me->count++;
        return 0;
}


int sqlist_travel(headnode *me,list_op opt)
{

    basenode *cur = NULL;
    if (sqlist_isempty(me))
        return -1;
    for (cur = me->head.next;cur!=&me->head;cur=cur->next)
    {
        
        opt(cur->data);
    
    }
    

}



basenode *find_ele(headnode *me,const void *ref,base_op cmp)
{
        basenode *cur =NULL;
        int res=0;
        for(cur=me->head.next;cur!=&me->head;cur=cur->next)
        {
            res = cmp(ref,cur->data);
            if (res==0)
                return cur;
        }

        return NULL;

}


int sqlist_fetch(headnode *me,const void *ref,base_op cmp,void *data)
{
    basenode *res=NULL;

    res = find_ele(me,ref,cmp);
    if(res==NULL)
        return -1;
    memcpy(data,res->data,me->datasize);
    
    res->prev->next=res->next;
    res->next->prev=res->prev;
    free(res->data);
    free(res);
    res=NULL;
    me->count--;
    return 0;
}

int sqlist_cmp(headnode *me,ele_op cmp)
{
    basenode *cur = NULL;
    
    for (cur=me->head.next;cur != me->head.prev;cur=cur->next)
    {
        if (cmp(cur->data,cur->next->data))
            return -1;

    }

    return 0;

}


void sqlist_destroy(headnode *me)
{

    basenode *cur = NULL;
    basenode *tmp = NULL;

    for(cur=me->head.next;cur!=&me->head;cur=tmp)
    {
        tmp=cur->next;
        free(cur->data);
        free(cur);
    }
    free(me);
    return ;
}
    
