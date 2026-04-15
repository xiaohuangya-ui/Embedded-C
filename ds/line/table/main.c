#include<stdio.h>
#include<stdlib.h>

#include "list.h"

int main()
{
    datatype arr[]={11,23,43,5,78,56};
    datatype arr1[]={45,23,65,87,79,88,21,77};
    datatype arr2[8]={0};
    datatype value1,value2,value3=87,value4=78;
    int i,j,k,num;
    talist *list,*list1;
    list=list_create();
    list1=list_create();

    for (i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    {
        list_insert_at(list,0,&arr[i]);
    }

    list_display(list);
    list_find_num(list,3,&value1);
    printf("I find it:%d\n",value1);
    
    j=list_find_val(list,&value4);
    printf("in positon : %d\n",j);

    

    for (i=0;i<sizeof(arr1)/sizeof(arr1[0]);i++)
    {
        list_order_insert(list1,&arr1[i]);
    }
    list_display(list1);
#if 0    
    list_delete_at(list1,3,&value2);

    printf("delete %d\n",value2);
    list_display(list1);

    list_delete_num(list1,&value3);
    list_display(list1);
#endif

    for (i=0;i<sizeof(arr1)/sizeof(arr1[0]);i++)
    {
        list_delete_at(list1,0,&arr2[i]);
        list_display(list1);
    }    
    
    k=list_isempty(list1);
    printf("result:%d\n",k);
    
    list_destroy(list);
    list_destroy(list1);

    return 0;



    

}
