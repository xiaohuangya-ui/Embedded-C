#include<stdio.h>
#include<stdlib.h>

#include "poly.h"



int main()
{

    int tag[][2]={{2,0},{5,3},{8,5},{9,6},{-10,8}};
    int con[][2]={{3,1},{7,6},{5,2},{6,5},{1,7}};
    int i,j;

    paranode *poly1;
    paranode *poly2;
    paranode *poly_merge;

    poly1=link_create();
    poly2=link_create();

    for (i=0;i<sizeof(tag)/sizeof(tag[0]);i++)
    {
        link_order_insert(poly1,tag[i]);  

    }

    for (j=0;j<sizeof(con)/sizeof(con[0]);j++)
    {
        link_order_insert(poly2,con[j]);
    }

    link_display(poly1);
    link_display(poly2);


    poly_merge = link_merge(&poly1,&poly2);
    link_display(poly_merge);
    
    link_destroy(poly1);
    return 0;
}





























