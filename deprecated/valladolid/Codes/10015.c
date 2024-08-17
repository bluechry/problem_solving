/* @JUDGE_ID: andrea 10015 C "Simulation" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <math.h>


/*@
 * Definitions of External Functions 
 */
int  check_prime(int );
void find_primes(int , int[] , int* );

/*
 * Implementations of External Functions 
 */
int check_prime(int num)
{
    int temp, i;

    if (num < 2)
        return 0;

    temp = sqrt(num);

    for (i = 2; i <= temp; i++) {
        if (num % i == 0)  
            return 0;
    }   

    return 1;
}

void find_primes(int upper_bound, int primes[], int* num_primes)
{
    int i, j;
    int count, temp;

    count = 0;

    for (i = 2; i <= upper_bound; i++) {

        temp = sqrt(i);

        for (j = 0; j < count && primes[j] <= temp; j++) {
            if (i % primes[j] == 0)  
                break;
        }   
    
        if (j == count || primes[j] > temp) 
            primes[count++] = i;
    }   

    *num_primes = count;

    return;
}

/*@
 * Definitions of Queue Data Structures
 */
#define MAX_ITEM	8192	

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

	Queue_Init(&q, 4096);

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

int run_josephus_cousin(int n, int primes[])
{
	Queue	q;
	int		i, j, elem;

	Queue_Init(&q, 4096);

	for (i = 1; i <= n; i++) {
		Queue_Insert(&q, i);
	}

	for (i = 0; i < n - 1; i++) {

		for (j = 0; j < primes[i] - 1; j++) {
			elem = Queue_Delete(&q);
			Queue_Insert(&q, elem);
		}

		Queue_Delete(&q);
	}

	return Queue_Delete(&q);	
}

int main()
{
	int primes[4096], num_primes;
	int num, result;


	/* pre-calculate prime numbers */
	find_primes(1 << 15, primes, &num_primes);

	/* run josephus' cousin */
	while (scanf("%d\n", &num) != EOF && num != 0) {
		result = run_josephus_cousin(num, primes);

		printf("%d\n", result);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
