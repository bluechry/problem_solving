/* @JUDGE_ID: andrea 440 C "Simulation" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

/*@
 * Definitions of Queue Data Structures
 */
#define MAX_ITEM	1024

typedef struct int_queue {
	int front;
	int rear;
	int num_elems;
	int max_elems;

	int elem[MAX_ITEM];
} Queue;


/*@
 * Definitions of External Functions
 */
int Queue_Init(Queue* , int );

int Queue_Final(Queue* );

int Queue_Insert(Queue* , int );

int Queue_Delete(Queue* );


/*@
 * Implementation of External Functions
 */
int Queue_Init(Queue* q, int max_elems)
{
	if (max_elems > MAX_ITEM) {
		printf("Extend MAX_ITEM size.\n");

		return -1;
	}

	q->front = q->rear = 0;
	q->num_elems = 0;
	q->max_elems = max_elems;

	return 0;	
}

int Queue_Final(Queue* q)
{
	q->front = q->rear = 0;
	q->num_elems = 0;
	q->max_elems = 0;

	return 0;
}

int Queue_Insert(Queue* q, int elem)
{
	if (q->front == q->rear && q->num_elems > 0) {
		return -1;
	}

	q->elem[q->rear] = elem;
	q->rear = (q->rear + 1) % q->max_elems;
	q->num_elems++;

	return 0; 
}

int Queue_Delete(Queue* q)
{
	int ret_value;

	if (q->front == q->rear && q->num_elems == 0) {
		return -1;
	}

	ret_value = q->elem[q->front];
	q->front = (q->front + 1) % q->max_elems;
	q->num_elems--;

	return ret_value;
}

void Queue_Print(Queue* q)
{
	int i, front;

	printf("Queue:");

	for (front = q->front, i = q->num_elems; i > 0; i--) {
		printf(" %d", q->elem[front]);
		front = (front + 1) % q->max_elems;
	}
	printf("\n");

	return;
}

int run_josephus(int n, int m)
{
	Queue 	q;
	int 	i, elem;

	Queue_Init(&q, 256);

	for (i = 1; i <= n; i++) {
		Queue_Insert(&q, i);
	}

	while (q.num_elems != 1) {

		Queue_Delete(&q);
		
		for (i = 1; i < m; i++) {
			elem = Queue_Delete(&q);
			Queue_Insert(&q, elem);		
		}
	}

	return Queue_Delete(&q);
}

int main()
{
	int 	n, m;
	Queue 	q;

	while (scanf("%d\n", &n) != EOF && n != 0) {

		for (m = 1; ; m++) {
			
			if (run_josephus(n, m) == 2) {
				printf("%d\n", m);
				break;
			}
		}	
	
	}

	return 0;
}

/* @END_OF_SOURCE_CODE */
