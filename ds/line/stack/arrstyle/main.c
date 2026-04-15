#include<stdio.h>
#include<stdlib.h>

#include "doustack.h"


int main()
{
    stacknode *head=NULL;
    datatype arr[]={12,54,0,89,55};
    int i;
    datatype top,tmp;
    head = doustack_create();
    if(head==NULL)
        printf("Create failed!\n");
    
    for (i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    {
        doustack_push(head,&arr[i]);
    }
    doustack_travel(head);
   
    printf("\n");

    doustack_top(head,&top);
    printf("TOP:%d\n",top);

    while(doustack_pop(head,&tmp)==0)
        printf("POP:%d\n",tmp);

    doustack_destroy(head);

    return 0;

}

