#include<stdio.h>
#include<stdlib.h>

#include "queue.h"

int main()
{
    datatype arr[17]={47, 92, 88, 23, 74, 39, 61, 5, 81, 32, 77, 18, 99,42, 65,77};


    int i;

    qunode *queue =NULL;
    queue = queue_create();
    datatype  temp;
    if(queue==NULL)
        return -1;

    for (i=0;i<MAXSIZE-1;i++)
    {
        if (queue_enter(queue,&arr[i]))
            return -2;


    }

    queue_travel(queue);
    printf("\n\n");
    queue_leave(queue,&temp);
    printf("%2d\n",temp);
    queue_destroy(queue);
    return 0;
}
