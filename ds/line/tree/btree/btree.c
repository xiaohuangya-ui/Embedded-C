#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "btree.h"

#define NAMESIZE 32
typedef struct stu_node
{
    int id;
    char name[NAMESIZE];
    int chinese;
    int math;

}stunode;
int tree_insert(treenode **me,base_op id_cmp,const void *data,int datasize)
{
    treenode *new_node = NULL;
    int res;
    if (*me == NULL)
    {   
        new_node = malloc(sizeof(*new_node));
        if (new_node == NULL)
            return -1;

        new_node->data = malloc(datasize);
        if(new_node->data==NULL)
        {
            free(new_node);
            return -2;
        }
        
        memcpy(new_node->data,data,datasize);
        new_node->left = NULL;
        new_node->right = NULL;
        *me = new_node;
        return 0;
    }
    res = id_cmp(data,(*me)->data);
    if (res>0)
    {
        return tree_insert(&(*me)->right,id_cmp,data,datasize);
    }
    else if (res<0)
    {   
        return tree_insert(&(*me)->left,id_cmp,data,datasize);
    }
    else
    {
        return -3;
    }
}

treenode *tree_find(treenode *me,base_op id_cmp,const void *ref)
{

    int res;
    if (me==NULL)
        return NULL;
    res = id_cmp(ref,me->data);
    if (res==0)
        return me;
    else if(res>0)
        return tree_find(me->right,id_cmp,ref);
    else
        return tree_find(me->left,id_cmp,ref);


}

static void draw(treenode *me,out_op print_t,int lay)
{
    int i;
    if (me==NULL)
        return ;

    draw(me->right,print_t,lay+1);
    for (i=1;i<lay+1;i++)
        printf("    *");
    print_t(me->data);
    draw(me->left,print_t,lay+1);
    return ;
}

void tree_draw(treenode *me,out_op out,int lay)
{
    draw(me,out,lay);
}


static int get_num(treenode *me)
{
    if (me==NULL)
        return 0;
    
    return get_num(me->left) + 1 + get_num(me->right);
}

static treenode *get_min(treenode *me)
{
    if(me->left == NULL)
        return me;
    return get_min(me->left);

}

static void turn_left(treenode **me)
{
    treenode *old_root = *me;
    treenode *new_root = (*me)->right;

    old_root->right = new_root->left;
    new_root->left = old_root;

    *me = new_root;
    
    return ;

}
static treenode *get_max(treenode *me)
{
    if (me->right == NULL)
        return me;
    return get_max(me->right);


}

static void turn_right(treenode **me)
{
    treenode *old_root = *me;
    treenode *new_root = old_root->left;
    
    old_root->left = new_root->right;

    new_root->right = old_root;

    *me = new_root;
    return ;

}

void tree_balance(treenode **me)
{

    int dif = 0;


    if (*me==NULL)
        return ;
    
    
    while(1)
    {
        dif = get_num((*me)->left)-get_num((*me)->right);
    
        if (dif>=-1 && dif<=1)
        {
            break;
        }
        else if (dif < -1)
        {
            turn_left(me);
        }
        else
        {
            turn_right(me);
        }

    }

    tree_balance(&(*me)->left);

    tree_balance(&(*me)->right);
        
    return ;
}

int tree_delete(treenode **me,base_op id_cmp,const void *ref,int mode)
{
    treenode **cur = me;
    treenode *tmp =NULL;
    int res = 0;
    while (*cur!=NULL &&id_cmp(ref,(*cur)->data)!= 0) 
    {
        if (id_cmp(ref,(*cur)->data) >0)
            cur = &(*cur)->right;
        else if (id_cmp(ref,(*cur)->data) <0)
            cur = &(*cur)->left;

    }

    if ((*cur)==NULL)
        return -1;
    tmp = *cur;
    switch (mode)
    {
        case L:
        {
            if (tmp->left == NULL)
            {
                *cur = tmp->right;
            }
            else 
            {   
                *cur = tmp->left;
                get_max(*cur)->right = tmp->right;
            }
            break;
        }
        case R:
        {

            if (tmp->right == NULL)
            {
                *cur = tmp->left;
            }
            else 
            {   
                *cur = tmp->right;
                get_min(*cur)->left = tmp->left;
            }
            break;
        }
        default:
            break;


    }

    free(tmp->data);
    free(tmp);

    return 0;

}


void tree_travel(treenode *me,out_op opt,int mode)
{
    int res = 0;
    queue *store = NULL;
    treenode *cur = me;
    treenode *l,*r;
    if (me==NULL)
        return ;
    switch(mode)
    {
        case FRONTEND:
            {
                opt(me->data);
                tree_travel(me->left,opt,mode);
                tree_travel(me->right,opt,mode);
                break;
            }
        case MIDDLE:
            {
                tree_travel(me->left,opt,mode);
                opt(me->data);
                tree_travel(me->right,opt,mode);
                break;
            }
        case BACKEND:
            {

                tree_travel(me->left,opt,mode);
                tree_travel(me->right,opt,mode);
                opt(me->data);
                break;
            }
        case LAYER:
            {   
                store = qu_create(sizeof(treenode *));
                if(store==NULL)
                    return ;

                qu_enter(store,&me);

                while(!qu_isempty(store))
                {
                    res = qu_leave(store,&cur);
                    
                    if (res!=0)
                        break;

                    opt(cur->data);

                    if (cur->left != NULL)
                    {   
                        l = cur->left;
                        qu_enter(store,&l);
                    }
                    if (cur->right != NULL)
                    {
                        r = cur->right;
                        qu_enter(store,&r);
                    }
                }
                qu_destroy(store);

                break;
            }
        default:
            break;   

}
}

static int always_match(const void *ref,const void *data)
{

    return 0;
}
void tree_destroy(treenode **me)
{   
    if(me == NULL || *me == NULL )
        return ;
    tree_destroy(&(*me)->left);
    tree_destroy(&(*me)->right);

    free((*me)->data);
    free(*me);

    *me = NULL;
}

static int save_(treenode *me,FILE *file,int datasize)
{
    stunode *s=NULL;
    fputc('(',file);

    if (me == NULL)
    {
        fputc(')',file);
        return 0;
    }
    s = (stunode *)me->data;
    fprintf(file,"%2d %5s %2d %2d",s->id,s->name,s->chinese,s->math);

    save_(me->left,file,datasize);
    save_(me->right,file,datasize);
    fputc(')',file);
    return 0;
}


int tree_save(treenode *me,const char *path,int datasize)
{
    FILE *fp = NULL;

    fp = fopen(path,"wb");
    if (fp == NULL)
        return -1;

    save_(me,fp,datasize);
    fclose(fp);
    return 0;


}


treenode *load_(FILE *file,int datasize)
{
    int ch = 0;
    stunode *s = NULL;
    treenode *new_node = NULL;
    
    while((ch = getc(file))!='(' && ch !=EOF);
    if (ch==EOF)
        return NULL;
    ch = getc(file);
    if (ch==')')
        return NULL;
    else
    {
        ungetc(ch,file);
    }

    new_node = malloc(sizeof(*new_node));
    if(new_node == NULL)
        return NULL;

    new_node->data = malloc(datasize);
    s = (stunode *)new_node->data;
    if(fscanf(file,"%d %s %d %d",&s->id,s->name,&s->chinese,&s->math)!=4)
    {
        free(new_node->data);
        free(new_node);
        return NULL;
    }

    new_node->left = load_(file,datasize);
    new_node->right = load_(file,datasize);

    while((ch = getc(file))!=')'&&ch!=EOF);
    
    return new_node;
    

        

}

treenode *tree_load(const char *path,int datasize)
{
    treenode *res = NULL;
    FILE *fp = NULL;

    fp = fopen(path,"rb");
    if(fp==NULL)
        return NULL;
    res = load_(fp,datasize);

    fclose(fp);
    
    return res;


}









