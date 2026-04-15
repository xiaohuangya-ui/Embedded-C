#include<stdio.h>
#include<stdlib.h>

#include "queue.h"
#include "stack.h"

#define NR_BALL 27

static int print_s(const void *data)
{

    const int *out=data;
    printf("%2d ",*out);
    return 0;

}

static int neibor_cmp(const void *value1,const void *value2)
{
    const int *bef = value1;
    const int *beh = value2;

    if (*bef < *beh)
        return 0;
    else
        return -1;
}

static int state_check(queue *me,base_op neibor_cmp)
{
    
    return qu_cmp(me,neibor_cmp);

}


int main()
{  
    int i;
    int qu_tmp;
    int st_tmp;
    int time=0;
    queue *qu = NULL;
    stack *st_min = NULL;
    stack *st_fivmin = NULL;
    stack *st_hour = NULL;

    qu = qu_create(sizeof(int),NR_BALL);
    if(qu==NULL)
        exit(0);

    st_min = stack_create(sizeof(int),4);
    if(st_min==NULL)
        exit(0);

    st_fivmin = stack_create(sizeof(int),11);
    if(st_fivmin==NULL)
        exit(0);

    st_hour = stack_create(sizeof(int),11);
    if(st_hour==NULL)
        exit(0);

    for (i=1;i<=NR_BALL;i++)
    {
        qu_enter(qu,&i);
    }
    qu_travel(qu,print_s);
    
    
    while (1)
    {
        qu_leave(qu,&qu_tmp);
        time++;

        if (!stack_isfull(st_min))
        {
            stack_push(st_min,&qu_tmp);
        }
        else
        {
            while(!stack_isempty(st_min))
            {
                stack_pop(st_min,&st_tmp);
                qu_enter(qu,&st_tmp);
            }
            
            if(!stack_isfull(st_fivmin))
            {
                stack_push(st_fivmin,&qu_tmp);
            }
            else
            {
                while(!stack_isempty(st_fivmin))
                {
                    stack_pop(st_fivmin,&st_tmp);
                    qu_enter(qu,&st_tmp);

                }

                if (!stack_isfull(st_hour))
                {

                    stack_push(st_hour,&qu_tmp);

                }

                else
                {
                    while (!stack_isempty(st_hour))
                    {
                        stack_pop(st_hour,&st_tmp);
                        qu_enter(qu,&st_tmp);

                    }
                    
                    qu_enter(qu,&qu_tmp);
                    if(!state_check(qu,neibor_cmp))
                        break;
                }

            
            }


        }
    
    }

        
    printf("\n\n");
    printf("Total time: %2d\n",time);
    qu_destroy(qu);
    stack_destroy(st_min);
    stack_destroy(st_fivmin);
    stack_destroy(st_hour);



    return 0;
}
