#include<stdio.h>
#include<stdlib.h>

#include "jose.h"
#define NUMBER 8
int main()
{
    
    int i,n=3;
    int start=1;
    josenode *link=NULL;
    josenode *new_node = NULL;
    link = link_create(&start);
    new_node = link;
    for(i=2;i<=NUMBER;i++)
    {
        new_node=link_insert(&new_node,&i);
    }
    link_display(link);
    jose_kill(&link,n);


    return 0;
}
