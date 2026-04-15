#include <stdio.h>
#include <stdlib.h>

#include "btree.h"
#define NAMESIZE 32

typedef struct stu_node
{
    int id;
    char name[NAMESIZE];
    int chinese;
    int math;

}stunode;

int id_cmp(const void *ref,const void *data)
{
    const int *r = ref;
    const stunode *d = data;
    return (*r - d->id);
}

int id_insert(const void *ref,const void *data)
{
    const stunode *r = ref;
    const stunode *d = data;
    return (r->id - d->id);
}


void print_t(const void *data)
{
    const stunode *out = data;
    printf("%2d %5s %2d %2d\n",out->id,out->name,out->chinese,out->math);
    return ;
    
}


int main()
{
    int i;
    int lay = 0;
    int test = 5;
    stunode tmp;
    treenode *result = NULL;
    int check=3;
    treenode *root = NULL;
    int arr[10] = {1,5,2,3,7,8,9,4,6,10};
    treenode *load_root = NULL;

    for (i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    {
        tmp.id = arr[i];
        snprintf(tmp.name,NAMESIZE,"stu%2d",arr[i]);
        tmp.chinese = rand()%100;
        tmp.math = rand()%100;

        tree_insert(&root,id_insert,&tmp,sizeof(tmp));
    
    }
    result = tree_find(root,id_cmp,&check);
    if (result == NULL)
        printf("Can't find it!\n");
    else
        print_t(result->data);

    tree_draw(root,print_t,lay);

    printf("\n\n");
    
    tree_balance(&root);
    tree_draw(root,print_t,lay);

    printf("\n\n");
    tree_delete(&root,id_cmp,&test,R);
    tree_draw(root,print_t,lay);
    
    tree_travel(root,print_t,LAYER);
    

    tree_save(root,FPATH,sizeof(stunode));
    printf("\n\n");
    load_root = tree_load(FPATH,sizeof(stunode));
    if (load_root == NULL) 
    {
        printf("Error: tree_load failed! File might be empty or corrupted.\n");
    } 
    else 
    {
        printf("Load Success! Drawing tree:\n");
        tree_draw(load_root, print_t, lay);
    }

    tree_destroy(&root);
    return 0;
}
