/* @JUDGE_ID: andrea 108 C "Dynamic Programming" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <string.h>

#define MAX 128

int main()
{
	int N;
	int array[MAX][MAX];
	int sum_array[MAX];
	int i, j, k;
	int sum, max_sum;

	while (scanf("%d\n", &N) != EOF) {

		/* input processing */
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				scanf("%d", &array[i][j]);
			}
		}

		/* find a maximum sum */
		max_sum = array[0][0];
		for (i = 0; i < N; i++) {
			memset(&sum_array[0], 0x0, sizeof(int) * MAX);

			for (j = i; j < N; j++) {
				sum_array[0] += array[j][0];	
				sum = sum_array[0];
				max_sum = (sum > max_sum) ? sum : max_sum;

				for (k = 1; k < N; k++) {
				
					sum_array[k] += array[j][k];
	
					if (sum < 0) {
						sum = sum_array[k]; 
					}
					else {
						sum += sum_array[k];
					}

					max_sum = (sum > max_sum) ? sum : max_sum;
				} 	
			}
		}

		printf("%d\n", max_sum);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
