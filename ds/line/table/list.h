#ifndef _LIST_H__
#define _LIST_H__

typedef int datatype;


typedef struct node
{
    datatype data;
    struct node *next;

}talist;


talist *list_create();

int list_find_num(talist *,int i,datatype *);

int list_find_val(talist *,datatype *);

int list_order_insert(talist *,datatype *);

int list_insert_at(talist *,int i,datatype *);

void list_display(talist *);

int list_delete_at(talist *,int i,datatype *);

int list_delete_num(talist *,datatype *);

int list_isempty(talist *);

void list_destroy(talist *);







#endif
