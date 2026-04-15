#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "trie.h"



FILE *open_file(const char *path)
{
    FILE *fp = NULL;

    fp = fopen(path,"r");

    if(fp == NULL)
        return NULL;

    return fp;

}

int get_word(FILE *fp,char *word)
{
    int c;
    int i = 0;

    while((c = fgetc(fp))!=EOF && !isalpha(c));

    if (c==EOF)
        return -1;

    do
    {
        if(i<ADS_SIZE-1)
        {
            word[i++]=tolower(c);
        }
    }while((c=fgetc(fp))!=EOF && isalpha(c));

    word[i]='\0';
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
    new_node->count=0;
    return new_node;
}


int msg_insert(trinode **me,char *ads)
{
    if(*me == NULL)
    {
        *me = trinode_create();
    }

    if (*ads=='\0')
    {
        (*me)->count++;
        return 0;
    }
    
    return msg_insert(&(*me)->ads[*ads-'a'],ads+1);


}

int msg_get_count(trinode *root,char *ele)
{
    if (root==NULL)
        return 0;

    if (*ele=='\0')
        return root->count;

    return msg_get_count(root->ads[*ele-'a'],ele+1);

}


int print_all_word_freq(trinode *root,char *path,int level)
{

    int i;
    if (root==NULL)
        return -1;
    if(root->count>0)
    {
        path[level]= '\0';
        printf("%s: %d\n",path,root->count);
        
    }

    for(i=0;i<26;i++)
    {
        if (root->ads[i]!=NULL)
        {
            path[level] = i+'a';
            print_all_word_freq(root->ads[i],path,level+1);
        }


    }
    return 0;

}























