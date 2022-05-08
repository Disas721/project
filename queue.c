#include <queue.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int MAXSIZE = 10;
int size = 0;

void swap(cell *elem1, cell *elem2) {
    cell temp = *elem1;
    *elem1 = *elem2;
    *elem2 = temp;
}

void show(cell *queue) 
{
    printf("-----\nQueue: ");
    for (int i = 0; i < size; i++)
        printf("%d ", queue[i].value);
    printf("\n");

    printf("Size: %d\n-----\n", size);
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

    printf("Element not found...\n");

    return -1;
}

void insert(cell* queue, int value, int key) 
{
    cell elem = {value, key};

    if (size + 1 > MAXSIZE)
        printf("Queue is full...\n");

    queue[size++] = elem;

    siftUp(queue, &queue[size - 1], size);

    printf("> Element by key '%d' with value '%d' added to the queue.\n", elem.key, elem.value);
}

int extract_maximum(cell* queue) 
{
    if (size == 0) {
        printf("Error: Queue is empty...\n");
        return -1;
    }

    int value = queue[0].value;
    if (size == 1) {
        size--;
        return value;
    }

    cell *pnt_max = &queue[0];
    cell *pnt_last_elem = &queue[size - 1];
    swap(pnt_max, pnt_last_elem);
    siftDown(queue, pnt_max, 1);

    size--;

    return value;
}

void deleteByValue(cell* queue, int elem_value) 
{
    if (size == 0) {
        printf("Error: Queue is empty...\n");
        return;
    }
    if (size == 1) {
        --size;
        return;
    }

    int elem_pos = findCellByValue(queue, elem_value);
    if (elem_pos == -1) return;

    cell *pnt_elem = &queue[elem_pos - 1];
    swap(pnt_elem, &queue[--size]);

    if (elem_pos == 1)
        siftDown(queue, pnt_elem, elem_pos);
    else if (pnt_elem[elem_pos / 2 - 1].key < pnt_elem -> key)
        siftUp(queue, pnt_elem, elem_pos);
    else
        siftDown(queue, pnt_elem, elem_pos);

    printf("> Element with value '%d' has been removed from the queue.\n", elem_value);
    return;
}

