#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "doulink.h"

headnode *doulink_create(int datasize)
{
    headnode *me=NULL;
    me=malloc(sizeof(*me));
    if(me==NULL)
        return NULL;

    me->datasize = datasize;
    me->head.prev= &me->head;
    me->head.next= &me->head;
    return me;  

}

int doulink_insert(headnode *me,const void *data,int mode)
{
    basenode *child = NULL;
    child=malloc(sizeof(*child)+(me->datasize)-1);
    if(child==NULL)
        return -1;

    memcpy(child->data,data,me->datasize);
    if (mode == FRONTEND)
    {
        child->prev=&me->head;
        child->next=me->head.next;
    }
        else if(mode==BACKEND)
        {
            child->prev = me->head.prev;
            child->next = &me->head;

        }
            else
            {
                free(child);
                return -2;
            }
        child->prev->next=child;
        child->next->prev=child;
        return 0;
    
}

void doulink_travel(headnode *me,link_opt print_s)
{
    basenode *cur=NULL;

    for (cur=me->head.next;cur!=&me->head;cur=cur->next)
    {
        print_s(cur->data);
    }

}

basenode *addfind(headnode *me,const void *ref,opt id_cmp)
{
    int res;
    basenode *cur=NULL;
    for (cur=me->head.next;cur!=&me->head;cur=cur->next)
    {
        res = id_cmp(ref,cur->data);
        if (res==0)
            return cur;
    }
    return NULL;
}


int doulink_find(headnode *me,const void *ref,opt id_cmp,void *resdata)
{
    basenode *res=NULL;
    res = addfind(me,ref,id_cmp);
    if (res==NULL)
        return -1;
    resdata = res;
    return 0;


}
int doulink_delete(headnode *me,const void *ref,opt id_cmp)
{
    basenode *result=NULL;

    result=addfind(me,ref,id_cmp);

    if (result ==NULL)
        return -1;
    result->next->prev = result->prev;
    result->prev->next = result->next;
    free(result);
    result = NULL;
    return 0;

}

int doulink_fetch(headnode *me,const void *ref,opt id_cmp,void *data)
{
    basenode *res = NULL;
    res = addfind(me,ref,id_cmp);

    if (res==NULL)
        return -1;
    res->prev->next=res->next;
    res->next->prev=res->prev;
    memcpy(data,res->data,me->datasize);
    return 0;
}

void doulink_destroy(headnode *me)
{
    basenode *cur = NULL;
    basenode *nxt = NULL;
    for (cur=me->head.next;cur!=&me->head;cur=nxt)
    {
        nxt=cur->next;
        free(cur);
    }
    free(me);
    me=NULL;
    return ;
}

