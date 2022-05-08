#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

const int MAXSIZE = 10;

int main() 
{
    cell (*queue) = (cell*)malloc(sizeof(cell) * MAXSIZE);

    printf("add_1\n");
    insert(queue, 10, 10);
    show(queue);

    printf("add_2\n");
    insert(queue, 4, 4);
    show(queue);

    printf("add_3\n");
    insert(queue, 9, 9);
    show(queue);

    printf("add_4\n");
    insert(queue, 3, 3);
    show(queue);

    printf("add_5\n");
    insert(queue, 2, 2);
    show(queue);

    printf("add_6\n");
    insert(queue, 8, 8);
    show(queue);

    printf("delete_1\n");
    deleteByValue(queue, 9);
    show(queue);

    printf("extract_max_1");
    printf("max = %d\n", extract_maximum(queue));
    show(queue);

    return 0;
}