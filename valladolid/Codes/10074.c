/* @JUDGE_ID: andrea 10074 C "Dynamic Programming" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <string.h>

#define MAX 128

int main()
{
	int M, N, num;
	int array[MAX][MAX];
	int sum_array[MAX];
	int i, j, k;
	int sum, max_sum;

	while (scanf("%d %d\n", &M, &N) != EOF) {
		
		if (M == 0 && N == 0) {
			break;
		}

		/* input processing */
		for (i = 0; i < M; i++) {
			for (j = 0; j < N; j++) {
				scanf("%d", &num);
				array[i][j] = (num == 1) ? -9999 : 1;
			}
		}

		/* find a maximum sum */
		max_sum = 0;
		for (i = 0; i < M; i++) {
			memset(&sum_array[0], 0x0, sizeof(int) * MAX);

			for (j = i; j < M; j++) {
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
