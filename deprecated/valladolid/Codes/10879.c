/* @JUDGE_ID: andrea 10879 C "Simple Iteration" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

int main()
{
	int num_cases;
	int count, turn, num;
	int i;
	
	scanf("%d\n", &num_cases);
	for (count = 1; count <= num_cases; count++) {
		scanf("%d\n", &num);
		printf("Case #%d: %d", count, num);
		for (turn = 0, i = 2; i < num && turn < 2; i++) {
			if (num % i == 0) {
				printf(" = %d * %d", i, num / i);
				++turn;
			}
		}
		printf("\n");
	}	

	return 0;
}
/* @END_OF_SOURCE_CODE */
