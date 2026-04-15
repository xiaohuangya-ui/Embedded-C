#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "trie.h"



FILE *open_file(const char *path)
{
    FILE *fp = NULL;

    fp = fopen(path,"r");

    if(fp == NULL)
        return NULL;

    return fp;

}

int get_msg(FILE *fp,char *ads,char *desc)
{
    char tmp[TMP_SIZE] = {'\0'};
    
    char *res = NULL;

    int i,j;
    res = fgets(tmp,TMP_SIZE,fp);

    if (res== NULL)
        return -1;
    
    for(i=0;i<ADS_SIZE-1 && res[i]!=':' &&res[i]!='\0';i++)
    {
        ads[i]=res[i];
    }
    ads[i]='\0';
    
    if (res[i]==':')
    {
        i++;
    }
    for(j=0;j<DESC_SIZE-1 && res[i]!='\0';j++,i++)
    {
        desc[j]=res[i];
    }
    desc[j]='\0';

    return 0;    
}

trinode *trinode_create(void)
{
    trinode *new_node = NULL;
    int i;

    new_node = malloc(sizeof(*new_node));
    if(new_node==NULL)
        return NULL;
    for(i=0;i<26;i++)
    {
        new_node->ads[i]=NULL;
    }
    new_node->desc[0] ='\0';
    return new_node;
}


int msg_insert(trinode **me,char *ads,char *desc)
{
    if(*me == NULL)
    {
        *me = trinode_create();
    }

    if (*ads=='\0')
    {
        strncpy((*me)->desc,desc,DESC_SIZE-1);
        return 0;
    }
    
    return msg_insert(&(*me)->ads[*ads-'a'],ads+1,desc);


}

char *msg_find(trinode *root,char *ele)
{
    if (root==NULL)
        return NULL;

    if (*ele=='\0')
        return root->desc;

    return msg_find(root->ads[*ele-'a'],ele+1);
    

}
