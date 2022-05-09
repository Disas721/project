#ifndef _QUEUE_H
#define _QUEUE_H

typedef struct {
    int value;
    int key;
} cell;

typedef enum {
    EMPTY,
    FULL,
    NOTEXIST,
    INVARG, 
    SUCCESS,
    MALLOC
} QUEUE_ERR;

cell *init_queue(int size, QUEUE_ERR *err);

void swap(cell *elem1, cell *elem2);

void show(cell *queue, QUEUE_ERR *err);

void siftUp(cell *queue, cell *elem, int elem_pos);

void siftDown(cell *queue, cell *elem, int elem_pos);

int findCellByValue(cell *queue, int elem_value);

void insert(cell* queue, int value, int key, QUEUE_ERR *err);

void Remove_Queue(cell *queue, QUEUE_ERR *err);

int extract_maximum(cell* queue, QUEUE_ERR *err);

void deleteByValue(cell* queue, int elem_value, QUEUE_ERR *err);

#endif