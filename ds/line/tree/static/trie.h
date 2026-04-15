#ifndef _TRIE_H__
#define _TRIE_H__

#define ADS_SIZE 256
#define TMP_SIZE 512

#define FPATH   "message"

typedef struct tri_node
{
    struct tri_node *ads[26];
    int count;

}trinode;


FILE *open_file(const char *);

int get_word(FILE *,char *);

trinode *trinode_create(void);

int msg_insert(trinode **,char *);

int msg_get_count(trinode *,char *);

int print_all_word_freq(trinode *,char *,int);
#endif
