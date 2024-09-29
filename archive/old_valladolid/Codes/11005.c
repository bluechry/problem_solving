/* @JUDGE_ID: andrea 11005 C "Brute Force" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <limits.h>

int calc_print_cost(int num, int base, int cost_table[])
{
	int cost;

	cost = 0;
	while (num > 0) {
		cost += cost_table[num % base];
		num /= base;
	}

	return cost;
}

int main()
{
	int cost_table[64];
	int num_cases, num_integers;
	int cost_record[64], min_cost, num;
	int count, i;

	count = 0;
	scanf("%d\n", &num_cases);
	while (num_cases-- > 0) {

		printf("Case %d:\n", ++count);

		for (i = 0; i < 36; i++) {
			scanf("%d", &cost_table[i]);
		}

		scanf("%d\n", &num_integers);

		while (num_integers-- > 0) {
		
			scanf("%d\n", &num);

			min_cost = INT_MAX;
			for (i = 2; i <= 36; i++) { 
				cost_record[i] = calc_print_cost(num, i, cost_table);
				if (cost_record[i] < min_cost) {
					min_cost = cost_record[i];	
				}
			}

			printf("Cheapest base(s) for number %d:", num);
			for (i = 2; i <= 36; i++) {
				if (cost_record[i] == min_cost) {
					printf(" %d", i);
				}
			}
			printf("\n");
		}
		
		if (num_cases != 0) {
			printf("\n");
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
