#include<stdio.h>
#include<stdlib.h>

#include "trie.h"

int main()
{
    FILE *fp = NULL;
    trinode *root =  NULL;
    char value[] = "liyujie";
    char *result = NULL;
    char ads[ADS_SIZE]={'\0'};
    char desc[DESC_SIZE]={'\0'};
    int state;

    fp = open_file(FPATH);
    if (fp==NULL)
        exit(0);
    while(1)
    {
        state = get_msg(fp,ads,desc);
        if (state==-1)
            break;
        msg_insert(&root,ads,desc);
       
    }
    result = msg_find(root,value);
    if (result!=NULL)
    {
        printf("%s\n",result);
    }
    else
    {
        printf("Can't find it!\n");
    }


    fclose(fp);
    



}
