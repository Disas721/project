#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

const int MAXSIZE1 = 10;

int main() 
{   
    cell *queue = NULL;
	QUEUE_ERR err;

	queue = init_queue(-1, &err);
	if (err != INVARG)
		fprintf(stdout, "Test_1.1\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_1.1\t->\tPASSED\n");

	queue = init_queue(MAXSIZE1, &err);
	if (queue == NULL)
		fprintf(stdout, "Test_1.2\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_1.2\t->\tPASSED\n");
    
    show(queue, &err);

    insert(NULL, 2, 2, &err);
    if (err != INVARG)
        fprintf(stdout, "Test_2.2\t->\tFAILED\n");
    else
        fprintf(stdout, "Test_2.2\t->\tPASSED\n");
    
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
    
    int i;
    for(i = 0; i <= MAXSIZE1; i++) {
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
    if (err != SUCCESS)
        fprintf(stdout, "Test_4.1\t->\tFAILED\n");
    else
        fprintf(stdout, "Test_4.1\t->\tPASSED\n");
    
    show(NULL, &err);
    if (err != INVARG)
        fprintf(stdout, "Test_4.2\t->\tFAILED\n");
    else
        fprintf(stdout, "Test_4.2\t->\tPASSED\n");

    extract_maximum(NULL, &err);
    if (err != INVARG)
        fprintf(stdout, "Test_5.1\t->\tFAILED\n");
    else
        fprintf(stdout, "Test_5.1\t->\tPASSED\n");

    for(i = 1; i<= MAXSIZE1; i++) { 
        printf("extract_max_%d", i);
        printf("max = %d\n", extract_maximum(queue, &err));
    }
    if (err != SUCCESS)
            fprintf(stdout, "Test_5.2\t->\tFAILED\n");
        else
            fprintf(stdout, "Test_5.2\t->\tPASSED\n");

    extract_maximum(queue, &err);
    if (err != EMPTY)
        fprintf(stdout, "Test_5.3\t->\tFAILED\n");
    else
        fprintf(stdout, "Test_5.3\t->\tPASSED\n");
    show(queue, &err);

    for(i = 1; i <= MAXSIZE1; i++) {
        insert(queue, i, i, &err);
    }
    show(queue, &err);

    deleteByValue(NULL, 4, &err);
    if (err != INVARG)
        fprintf(stdout, "Test_6.1\t->\tFAILED\n");
    else
        fprintf(stdout, "Test_6.1\t->\tPASSED\n");
    
    show(queue, &err);

    deleteByValue(queue, 20, &err);
    if (err != NOTEXIST)
        fprintf(stdout, "Test_6.2\t->\tFAILED\n");
    else
        fprintf(stdout, "Test_6.2\t->\tPASSED\n");

    for (i = 1; i <= MAXSIZE1; i++) {
        deleteByValue(queue, i, &err);
    }
    if (err != SUCCESS)
        fprintf(stdout, "Test_6.3\t->\tFAILED\n");
    else
        fprintf(stdout, "Test_6.3\t->\tPASSED\n");

    deleteByValue(queue, 1, &err);
    if (err != EMPTY)
        fprintf(stdout, "Test_6.4\t->\tFAILED\n");
    else
        fprintf(stdout, "Test_6.4\t->\tPASSED\n");

    for(i = 1; i <= MAXSIZE1; i++) {
        insert(queue, i, i, &err);
    }
    show(queue, &err);

    Remove_Queue(NULL, &err);
    if (err != INVARG)
        fprintf(stdout, "Test_7.1\t->\tFAILED\n");
    else
        fprintf(stdout, "Test_7.1\t->\tPASSED\n");

    Remove_Queue(queue, &err);
    if (err != SUCCESS)
        fprintf(stdout, "Test_7.2\t->\tFAILED\n");
    else
        fprintf(stdout, "Test_7.2\t->\tPASSED\n");

    show(queue, &err);

    return 0;
}