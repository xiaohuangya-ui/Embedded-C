#include<stdio.h>
#include<stdlib.h>

#include "list.h"


talist *list_create()
{
    talist *me=NULL;

    me = malloc(sizeof(*me));

    if (me==NULL)
    {
        return NULL;
    }
    else
    {
        
        me->next=NULL;
        return me;
    }

}


int list_find_num(talist *me,int i,datatype *value)
{
    talist *p = me->next,*q;
    int j=0;

    if(i<0)
    {
        
        return -1;
    }

    while(j<i && p!=NULL)
    {
        p=p->next;
        j++;
    }
    
    if (p)
    {
        *value=p->data;
        return 0;
    }
    else
        return -2;
    

}


int list_find_val(talist *me,datatype *data)
{
    talist *p=me;
    int i=0;
    
    while(p->next!=NULL)
    {
        if (p->next->data==*data)
        {
            return i;
        }
        else
        {   
            p=p->next;
            i++;
        }
    }
    return -1;

}

int list_order_insert(talist *me,datatype *data)
{
    talist *p=me,*q;

    while(p->next && p->next->data > *data)
        p=p->next;
        
    q=malloc(sizeof(*q));
    if (q==NULL)
    {
        return -1;
    }
    q->data=*data;
    q->next=p->next;
    p->next=q;

    return 0;

}



int list_insert_at(talist *me,int i,datatype *data)
{
    talist *p=me,*q;
    int j;

    if (i<0)
    {
        return -1;
    }

    for (j=0;j<i && p;j++)
    {
        p=p->next;

    }
    
    if (p==NULL)
    {
        return -2;
    }
    else
    {
        q=malloc(sizeof(*q));
        if(q==NULL)
        {return -3;}
        q->data=*data;
        q->next=p->next;
        p->next=q;
        return 0;
    }
}

void list_display(talist *me)
{

    talist *p=me->next;

    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }

    printf("\n");

}

int list_delete_at(talist *me,int i,datatype *data)
{
    talist *p=me,*q;

    int j;

    for (j=0;p->next && j<i;j++)
    {

        p=p->next;

    }

    if(p->next==NULL)
    {
        return -1;
    }
    else
    {
        q=p->next;
        *data=q->data;
        p->next=q->next;
        free(q);
        q=NULL;
        return 0;
    }

                

}

int list_delete_num(talist *me,datatype *data)
{
    talist *p=me,*q;

    while(p && p->next->data!=*data)
    {
        p=p->next;
    }
    if (p->next==NULL)
    {   
        return -1;
    }
    else
    {
        q=p->next;
        p->next=q->next;
        free(q);
        q=NULL;
        return 0;
        
    }

}

int list_isempty(talist *me)
{
    if(me->next==NULL)
    {   
        return 0;
    }

    return -1;

}

void list_destroy(talist *me)
{
    talist *cur=me;
    talist *nxt=NULL;

    while(cur!=NULL)
    {
        nxt=cur->next;
        free(cur);
        cur=nxt;
        return ;
    }

}

