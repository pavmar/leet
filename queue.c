#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct elem
{
    int val;
    struct elem *next;
    struct elem *prev;
} elem_t;

typedef struct queue 
{
    elem_t *head;
    elem_t *tail;
} q_t;

void enqueue(int val, q_t *q)
{
    elem_t *elem;
    
    elem = malloc(sizeof(elem_t));
    elem->val = val;
    elem->next = NULL;
    elem->prev = NULL;
    if (!q->head && !q->tail)
    {
      q->head = elem;
      q->tail = elem;
      return;
    }
    elem->next = q->head;
    q->head->prev = elem;
    q->head = elem;

}
void dequeue(q_t *q)
{
    elem_t *tmp;
    if (q->tail)
    {
        tmp = q->tail;
        if (tmp->prev)
            q->tail = tmp->prev;
	else{
	   q->tail = NULL;
	   q->head = NULL;
	}
        free(tmp);
    }
}

void printFront(q_t *q)
{
    if(q->tail)
       printf("%d\n", q->tail->val);
}

int main() {
    
    q_t myQ;
    myQ.tail = NULL;
    myQ.head = NULL;
    int q;
    scanf("%d", &q);  // Read number of queries

    for (int i = 0; i < q; i++) {
        int query_type, value;
        int read = scanf("%d", &query_type);  // Read query type

        if (query_type == 1) {
            // Read value for enqueue
            read = scanf("%d", &value);
            // Process enqueue here
            enqueue(value, &myQ);
        } else if (query_type == 2) {
            // Process dequeue here
            dequeue(&myQ);
        } else if (query_type == 3) {
            // Process print front here
            printFront(&myQ);
        } else {
            printf("Invalid query type\n");
        }
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    return 0;
}

