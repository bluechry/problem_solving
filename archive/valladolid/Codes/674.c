/* @JUDGE_ID: andrea 674 C "Dynamic Programming" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

#define NUM_COIN 	5
#define MAX_VALUE 	8192


int 		 coin[NUM_COIN] = {1, 5, 10, 25, 50};
unsigned int num_way[MAX_VALUE];

void calculate_num_way()
{
	int i, j;

	num_way[0] = 1;
	for (i = 0; i < NUM_COIN; i++) {
		for (j = coin[i]; j <= MAX_VALUE; j++) {
			num_way[j] += num_way[j - coin[i]]; 		
		} 
	}

	return;
}

int main()
{
	int  value;

	calculate_num_way();

	while (scanf("%d\n", &value) != EOF) {
		printf("%u\n", num_way[value]);	
	}	

	return 0;
}
/* @END_OF_SOURCE_CODE */
