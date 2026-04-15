#include<stdio.h>
#include<stdlib.h>
#include "sqlist.h"
int main()
{

    sqlist *list=NULL;
    sqlist *list1=NULL;
    sqlist *list2=NULL;
    datatype arr[]={11,23,5,65,12,87,98};
    datatype arr1[]={12,35,65,42,3.8,56,99};
    datatype arr2[]={86,12,24,65,43,35,56,7};
    int i,err,k,ser,length;
    int count1,count2,err1,err2;
    datatype j;
    datatype number=12;
    datatype change=100;
//list
    list = sqlist_create();
    if (list==NULL)
    {
        fprintf(stderr,"sqlist_create() failed!\n");
        exit(0);
    }

    for(i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    {
        if ((err=sqlist_insert(list,0,&arr[i]))!=0)
        {
            if (err==-1)
            {
                
                fprintf(stderr,"The arr is full.\n");
            }
            else if (err==-2)
            {
                fprintf(stderr,"The pos you want to insert is wrong.\n");
            }
                else
                {
                    fprintf(stderr,"Error!\n");
                }
                

        }
    }


    sqlist_display(list);
    
    sqlist_delete(list,1);
    sqlist_display(list);
    
    j=sqlist_findnum(list,1);
    printf("%d \n",j);
    
    k=sqlist_findarr(list,&number);
    printf("%d \n",k);

    sqlist_modify(list,3,&change);
    sqlist_display(list);

    length=sqlist_getnum(list);
    printf("%d \n",length);


    sqlist_setempty(list);
    ser=sqlist_isempty(list);    
    printf("%d \n",ser);

    sqlist_destory(list);
    




//list1    
    sqlist_create1(&list1);

    if (list1==NULL)
    {
        fprintf(stderr,"sqlist_create() failed!\n");
        exit(0);
    }


    for(count1=0;count1<sizeof(arr1)/sizeof(arr1[0]);count1++)
    {
        if ((err1=sqlist_insert(list1,0,&arr1[count1]))!=0)
        {
            if (err1==-1)
            {
                
                fprintf(stderr,"The arr is full.\n");
            }
            else if (err1==-2)
            {
                fprintf(stderr,"The pos you want to insert is wrong.\n");
            }
                else
                {
                    fprintf(stderr,"Error!\n");
                }
                

        }
    }



    sqlist_display(list1);
    


//list2
    sqlist_create1(&list2);

    if (list2==NULL)
    {
        fprintf(stderr,"sqlist_create() failed!\n");
        exit(0);
    }
    
    for(count2=0;count2<sizeof(arr2)/sizeof(arr2[0]);count2++)
    {
        if ((err2=sqlist_insert(list2,0,&arr2[count2]))!=0)
        {
            if (err2==-1)
            {
                
                fprintf(stderr,"The arr is full.\n");
            }
            else if (err2==-2)
            {
                fprintf(stderr,"The pos you want to insert is wrong.\n");
            }
                else
                {
                    fprintf(stderr,"Error!\n");
                }
                

        }
    }




    sqlist_display(list2);

//union 
    sqlist_union(list1,list2);
    sqlist_display(list1);
    

    sqlist_destory(list1);
    sqlist_destory(list2);

    return 0;

}



















