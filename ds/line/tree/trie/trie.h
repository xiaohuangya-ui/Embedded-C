#ifndef _TRIE_H__
#define _TRIE_H__

#define DESC_SIZE 256
#define ADS_SIZE 256
#define TMP_SIZE 512

#define FPATH   "message"

typedef struct tri_node
{
    struct tri_node *ads[26];
    char desc[DESC_SIZE];

}trinode;


FILE *open_file(const char *);

int get_msg(FILE *,char *,char *);

trinode *trinode_create(void);

int msg_insert(trinode **,char *,char *);

char *msg_find(trinode *,char *);


#endif
