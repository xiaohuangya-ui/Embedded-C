#include<stdio.h>
#include<stdlib.h>

#include "trie.h"

int main()
{
    FILE *fp = NULL;
    trinode *root =  NULL;
    char word[ADS_SIZE]={'\0'};

    fp = open_file(FPATH);
    if (fp==NULL)
        exit(0);
    while(get_word(fp,word)==0)
    {
        msg_insert(&root,word);
       
    }
    
    printf("Word frequency statistics:\n");
    print_all_word_freq(root,word,0);

    fclose(fp);
    return 0;

}
