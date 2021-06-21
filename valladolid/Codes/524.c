/* @JUDGE_ID: andrea 524 C "Brute Force" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <string.h>
#include <math.h>

int check_prime(int num)
{
	int temp, i;
	
	temp = sqrt(num);
	for (i = 2; i <= temp; i++) {
		if (num % i == 0) {
			return 0;
		}
	}

	return 1;
}

void find_prime_ring(char used_flag[], int num, int result[], int prev_pos)
{
	int i, temp;

	if (prev_pos + 1 == num && check_prime(result[prev_pos] + 1)) {
		for (i = 0; i < num - 1; i++) {
			printf("%d ", result[i]);
		}
		printf("%d\n", result[i]);

		return;
	}

	for (i = 1; i <= num; i++) {
		if (!used_flag[i] && check_prime(result[prev_pos] + i)) {
			used_flag[i] = 1;
			result[prev_pos + 1] = i;
			find_prime_ring(used_flag, num, result, prev_pos + 1);
			used_flag[i] = 0;
		}
	}
		
	return;
}

int main()
{
	int  num_cases, num;
	int  result[32];	
	char used_flag[32];

	num_cases = 0;
	while (scanf("%d\n", &num) != EOF) {
		num_cases++;
		memset(used_flag, 0x0, sizeof(char) * 32);

		if (num_cases > 1) {
			printf("\n");
		}
		printf("Case %d:\n", num_cases);

		result[0] = 1;
		used_flag[1] = 1;
		find_prime_ring(used_flag, num, result, 0); 
	}

	return 0;
}

/* @END_OF_SOURCE_CODE */
