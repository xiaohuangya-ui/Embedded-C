#include<stdio.h>
#include<stdlib.h>

#include "poly.h"


paranode *link_create()
{

    paranode *me = NULL;

    me = malloc(sizeof(*me));
    if(me == NULL)

        return NULL;
    
    me->data.coef;
    me->next=NULL;
    return me;

}


int link_order_insert(paranode *me,int arr[2])
{
    paranode *cur=me;
    paranode *temp=NULL;
    
    while(cur->next && cur->next->data.index < arr[1])
    { 
        cur=cur->next;
    }
        temp=malloc(sizeof(*temp));
        if (temp==NULL)
            return -1; 
        temp->data.coef=arr[0];
        temp->data.index=arr[1];
        temp->next = cur->next;
        cur->next=temp;
        return 0;


}


void link_display(paranode *me)
{
    paranode *cur=NULL;

    
    for (cur=me->next;cur!=NULL;cur=cur->next)
    {
        printf(" (%d %d) ",cur->data.coef,cur->data.index);
        
    }

    printf("\n");
    return ;
}


paranode *link_merge(paranode **target,paranode **control)
{
    paranode *pos=(*target)->next;
    paranode *neg=(*control)->next;
    paranode *opt=(*target);
    paranode *temp;


    while (pos!= NULL && neg!= NULL)
    {
        if (pos->data.index < neg->data.index)
        {
            opt->next=pos;
            opt = opt->next;
            pos = pos->next;
        
        }
            else if (pos->data.index > neg->data.index)
            {
                opt->next=neg;
                opt = opt->next;
                neg=neg->next;
        
            }
                else if(pos->data.index==neg->data.index)
                {
                    pos->data.coef = pos->data.coef + 
                                            neg->data.coef;
                    if (pos->data.coef==0)
                    {
                        temp=pos;
                        pos=pos->next;
                        free(temp);
                        temp=neg;
                        neg=neg->next;
                        free(temp);
                    }
                    else
                    {
                        opt->next = pos;
                        opt=opt->next;
                        pos=pos->next;
                        temp=neg;
                        neg=neg->next;
                        free(temp);
                    }
                }
    }
    
    if (pos==NULL)
    {
        opt->next = neg;
    }
    else if (neg==NULL)
    {

        opt->next=pos;
    }
    free(*control);
    control = NULL;
    return *target;

}


int link_destroy(paranode *me)
{
    paranode *cur = me;
    paranode *nxt =NULL;

    if (me == NULL)
        return -1;
    
    while(cur!=NULL)
    {
        nxt = cur->next;
        free(cur);
        cur=nxt;

    }
    return 0;
}
