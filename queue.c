#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int MAXSIZE = 10;
int size = 0;

cell *init_queue(int ssize, QUEUE_ERR *err)
{
    if (ssize <= 0) {
		fprintf(stderr, "Invalid argument: size\n");
		if (err != NULL)
			*err = INVARG;
		return NULL;
	}
    
    cell (*queue) = (cell*)malloc(sizeof(cell) * ssize);
	if (queue == NULL) {
		fprintf(stderr, "Not enough memory\n");
		if (err != NULL)
			*err = MALLOC;
		return NULL;
	}

    *err = SUCCESS;
    return queue;
}

void Remove_Queue(cell *queue, QUEUE_ERR *err) {

    if (queue == NULL) {
        fprintf(stderr, "Invalid argument: queue\n");
        if(err != NULL) {
            *err = INVARG;
        }
        return;
    }
    
    size = 0;
    free(queue);
    *err = SUCCESS;
}

void swap(cell *elem1, cell *elem2) {
    cell temp = *elem1;
    *elem1 = *elem2;
    *elem2 = temp;
}

void show(cell *queue, QUEUE_ERR *err) 
{
    if (queue == NULL) {
		fprintf(stderr, "Invalid argument: queue\n");
		if (err != NULL)
			*err = INVARG;
		return;
	}

    if (size == 0) { 
        printf("Queue is empty");
    } else { 
        printf("-----\nQueue: ");
        for (int i = 0; i < size; i++)
            printf("%d ", queue[i].value);
        printf("\n");
    }
    printf("Size: %d\n-----\n", size);
    
    *err = SUCCESS;
}

void siftUp(cell *queue, cell *elem, int elem_pos) 
{
    
    if (elem_pos == 1) return;

    int parent_pos = elem_pos / 2;
    cell *parent = &queue[parent_pos - 1];
    if ((parent -> key) < (elem -> key)) {
        swap(elem, parent);
        siftUp(queue, parent, parent_pos);
    }

    return;
}

void siftDown(cell *queue, cell *elem, int elem_pos) 
{
    cell *max_cell;
    int max_pos, max_key = queue[elem_pos - 1].key;

    if (elem_pos * 2 <= size && queue[elem_pos * 2 - 1].key > max_key) {
        max_pos = elem_pos * 2;
        max_cell = &queue[max_pos - 1];
        max_key = max_cell -> value;
    }
    if (elem_pos * 2 + 1 <= size && queue[elem_pos * 2].key > max_key) {
        max_pos = elem_pos * 2 + 1;
        max_cell = &queue[max_pos - 1];
        max_key = max_cell -> value;
    }
    
    if (queue[elem_pos - 1].key != max_key) {
        swap(elem, max_cell);
        siftDown(queue, elem, max_pos);
    }

    return;
}

int findCellByValue(cell *queue, int elem_value) 
{
    for (int i = 1; i <= size; i++) {
        if (queue[i - 1].value == elem_value)
            return i;
    }

    return -1;
}

void insert(cell* queue, int value, int key, QUEUE_ERR *err) 
{
    if (queue == NULL) {
		fprintf(stderr, "Invalid argument: queue\n");
		if (err != NULL)
			*err = INVARG;
		return;
	}

    if (value <= 0) {
		fprintf(stderr, "Invalid argument: value\n");
		if (err != NULL)
			*err = INVARG;
		return;
	}

    if (key <= 0) {
		fprintf(stderr, "Invalid argument: key\n");
		if (err != NULL)
			*err = INVARG;
		return;
	}

    cell elem = {value, key};

    if (size + 1 > MAXSIZE) {
        fprintf(stderr, "Queue is full\n");
		if (err != NULL)
			*err = FULL;
		return;
    }

    queue[size++] = elem;

    siftUp(queue, &queue[size - 1], size);

    printf("> Element by key '%d' with value '%d' added to the queue.\n", elem.key, elem.value);

    *err = SUCCESS;
}


int extract_maximum(cell* queue, QUEUE_ERR *err) 
{
    if (queue == NULL) {
		fprintf(stderr, "Invalid argument: queue\n");
		if (err != NULL)
			*err = INVARG;
		return -1;
	}

    if (size == 0) {
        fprintf(stderr, "Queue is empty\n");
        *err = EMPTY;
        return -1;
    }

    int value = queue[0].value;
    if (size == 1) {
        size--;
        return value;
    }

    cell *pnt_max = &queue[0];
    cell *pnt_last_elem = &queue[--size];
    swap(pnt_max, pnt_last_elem);
    siftDown(queue, pnt_max, 1);
    
    *err = SUCCESS;

    return value;
}

void deleteByValue(cell* queue, int elem_value, QUEUE_ERR *err) 
{
    if (queue == NULL) {
		fprintf(stderr, "Invalid argument: queue\n");
		if (err != NULL)
			*err = INVARG;
		return;
	}

    if (size == 0) {
        fprintf(stderr, "Queue is empty\n");
        *err = EMPTY;
        return;
    }
    if (size == 1) {
        --size;
        return;
    }

    int elem_pos = findCellByValue(queue, elem_value);
    if (elem_pos == -1) {
        fprintf(stderr, "Element not exist\n");
        *err = NOTEXIST;
        return;
    }

    cell *pnt_elem = &queue[elem_pos - 1];
    swap(pnt_elem, &queue[--size]);

    siftDown(queue, pnt_elem, elem_pos);
    siftUp(queue, pnt_elem, elem_pos);

    printf("> Element with value '%d' has been removed from the queue.\n", elem_value);

    *err = SUCCESS;

    return;
}

