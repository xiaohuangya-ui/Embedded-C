#include<stdio.h>
#include<stdlib.h>

#include "cacul.h"


int get_pre(int *op)
{
    int pre;

    switch (*op)
    {
        case '(':
            pre=0;
            break;
        case '+':
        case '-':
            pre=1;
            break;
        case '*':
        case '/':
            pre=2;
            break;
        default:
            return -1;


    }
    
    return pre;

}

int compute(stack *num,int *op)
{
    int value1,value2,res;

    stack_pop(num,&value2);

    stack_pop(num,&value1);

    switch (*op)
    {
        case '+':
            res = value1 + value2;
            break;

        case '-':
            res = value1 - value2;
            break;

        case '*':
            res = value1 * value2;
            break;

        case '/':
            res = value1 / value2;
            break;
    }

    stack_push(num,&res);
    
    return 0;
    

}


int deal_bracket(stack *num,stack *opt)
{
    int old_op;

    while(!stack_isempty(opt))
    {
        stack_pop(opt,&old_op);
        if (old_op=='(')
            break;
        compute(num,&old_op);
    }
    
    return 0;

}

int deal_op(stack *snum,stack *sopt,void *op)
{
    int old_opt;
    int current_opt =*(int *)op;
    while (!stack_isempty(sopt))
    {
   
        stack_top(sopt,&old_opt);

        if (old_opt =='(')
            break;
    
        if (get_pre(&old_opt)>=get_pre(&current_opt))
        {
            stack_pop(sopt,&old_opt);
            compute(snum,&old_opt);

        }

        else 
        {
            break;
        }
    }
            stack_push(sopt,&current_opt);
            return 0;
}


