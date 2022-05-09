#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

const int MAXSIZE = 10;

int main() 
{   
    cell *queue = NULL;
	QUEUE_ERR err;

	queue = init_queue(-1, &err);
	if (err != INVARG)
		fprintf(stdout, "Test_1.1\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_1.1\t->\tPASSED\n");

	queue = init_queue(MAXSIZE, &err);
	if (queue == NULL)
		fprintf(stdout, "Test_1.2\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_1.2\t->\tPASSED\n");
    
    show(queue, &err);
    
    insert(queue, -1, 2, &err);
    if (err != INVARG)
        fprintf(stdout, "Test_2.1\t->\tFAILED\n");
    else
        fprintf(stdout, "Test_2.1\t->\tPASSED\n");

    insert(queue, 2, 0, &err);
    if (err != INVARG)
        fprintf(stdout, "Test_2.2\t->\tFAILED\n");
    else
        fprintf(stdout, "Test_2.2\t->\tPASSED\n");

    show(queue, &err);
    
    int i;
    for(i = 0; i <= MAXSIZE; i++) {
        insert(queue, i, i, &err);
    }
    if (err != SUCCESS)
        fprintf(stdout, "Test_3.1\t->\tFAILED\n");
    else
        fprintf(stdout, "Test_3.1\t->\tPASSED\n");

    insert(queue, 11, 11, &err);
    if (err != FULL)
        fprintf(stdout, "Test_3.2\t->\tFAILED\n");
    else
        fprintf(stdout, "Test_3.2\t->\tPASSED\n");

    show(queue, &err);

    return 0;
}