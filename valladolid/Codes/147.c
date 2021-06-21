/* @JUDGE_ID: andrea 147 C "Dynamic Programming" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

#define NUM_COIN 	11
#define MAX_VALUE 	6200	

int 		 	   coin[NUM_COIN] = {1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};
unsigned long long num_way[MAX_VALUE];

void calculate_num_way()
{
	int i, j;

	num_way[0] = 1LU;
	for (i = 0; i < NUM_COIN; i++) {
		for (j = coin[i]; j <= MAX_VALUE; j++) {
			num_way[j] += num_way[j - coin[i]]; 
		} 
	}

	return;
}

int main()
{
	double f_value;
	int	   i_value;
	
	calculate_num_way();

	while (scanf("%lf\n", &f_value) != EOF && f_value != 0.00f) {
		i_value = (int)(f_value * 100 + 0.5) / 5;
		printf("%6.2lf%17llu\n", f_value, num_way[i_value]);	
	}	

	return 0;
}
/* @END_OF_SOURCE_CODE */
