/* @JUDGE_ID: andrea 10041 C "Number Theory" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void* op1, const void* op2)
{
	int* l;
	int* r;

	l = (int*) op1;
	r = (int*) op2;

	return *l - *r;
}

int main()
{
	int num_cases;
	int num_elems, elems[30000];
	int median, distance;
	int i, temp;

	scanf("%d\n", &num_cases);
	while (num_cases-- > 0) {

		scanf("%d\n", &num_elems);
		for (i = 0; i < num_elems; i++) {
			scanf("%d", &elems[i]);
		}

		qsort(&elems[0], num_elems, sizeof(int), compare);

		temp = num_elems / 2;
		median = (num_elems & 0x1) ? elems[temp] : (elems[temp] + elems[temp - 1]) / 2;

		distance = 0;
		for (i = 0; i < num_elems; i++) {
			distance += abs(elems[i] - median);
		} 

		printf("%d\n", distance);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
