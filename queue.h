#ifndef _QUEUE_H
#define _QUEUE_H

typedef struct {
    int value;
    int key;
} cell;

typedef enum {
    
} QUEUE_ERR;

void swap(cell *elem1, cell *elem2);

void show(cell *queue);

void siftUp(cell *queue, cell *elem, int elem_pos);

void siftDown(cell *queue, cell *elem, int elem_pos);

int findCellByValue(cell *queue, int elem_value);

void insert(cell* queue, int value, int key);

int extract_maximum(cell* queue);

void deleteByValue(cell* queue, int elem_value);

#endif