#ifndef _QUEUE_H__
#define _QUEUE_H__

#define MAXSIZE 17

typedef int datatype;

typedef struct base_node
{
    datatype data[MAXSIZE];
    datatype head;
    datatype tail;

}qunode;

qunode *queue_create();

int que_isfull(qunode *);

int que_isempty(qunode *);

int queue_enter(qunode *,datatype *);

int queue_leave(qunode *,datatype *);

void queue_travel(qunode *);

void queue_destroy(qunode *);


#endif
