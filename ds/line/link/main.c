#include<stdio.h>
#include<stdlib.h>

#include "nohead_link.h"

#define LENGTH 10 


int main()
{
    stunode *link=NULL;
    sconode data;
    sconode value;
    int i;

    for(i=0;i<LENGTH;i++)
    {
        
        data.id = i;
        snprintf(data.name,NAMESIZE,"stu%d",i);
        data.chinese = rand() % 100;
        data.math = rand() % 100;
        link_insert(&link,&data);
        
    }

    link_display(link);

    link_find(&link,3,&value);
    printf("value\n%d %s %d %d\n\n",value.id,value.name,value.chinese,
            value.math);

    link_delete(&link);
    link_display(link);

    link_destroy(link);

    return 0;
}
































