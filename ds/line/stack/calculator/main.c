#include <stdio.h>
#include <stdlib.h>
#include "cacul.h"

int main() 
{
    stack *snum = NULL;
    stack *sopt = NULL;

    char express[32] = "1+2*3-(6+2)/4";

    int i=0;
    int value = 0;
    int flag = 0;
    int result = 0;
    int op;
    int op_char;

    snum = stack_create(sizeof(int));
    sopt = stack_create(sizeof(int));

    while(express[i]!='\0')
    {
        if ((express[i]>='0') && (express[i]<='9'))
        {

            value = value *10 + (express[i] - '0');
            flag=1;
        }
        else
        {
            if(flag==1)
            {
                stack_push(snum,&value);
                flag = 0;
                value =0;
            }
            if (express[i]=='(')
            {
                op_char = express[i];
                stack_push(sopt,&op_char);
            }

            else if (express[i]==')')
            {
                
                deal_bracket(snum,sopt);
            }
            else
            {
                op_char = express[i]; 
                deal_op(snum,sopt,&op_char);

            }
             
        }
        i++;
    }
    if (flag == 1)
    {
        stack_push(snum,&value);
    }

    while (!stack_isempty(sopt))
    {

        stack_pop(sopt,&op);
        if(op!='(')
        {
            compute(snum,&op);
        }
    }

    if (stack_pop(snum,&result)==0)
    {
        printf("Result = %d\n",result);
    }
    else
    {
        printf("caculation failed!\n");
    }
        

    stack_destroy(snum);
    stack_destroy(sopt);

    return 0;
}
