/* @JUDGE_ID: andrea 10812 C "Arithmatic" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

int main()
{
	int num_cases;
	int sum, diff;
	int score_win, score_lose; 

	scanf("%d\n", &num_cases);
	while (num_cases-- > 0) {
		scanf("%d %d\n", &sum, &diff);

		score_win = (sum + diff) / 2;
		score_lose = sum - score_win;

		if (score_win < 0 || score_lose < 0 || (score_win - score_lose) != diff) {
			printf("impossible\n");
		}
		else {
			printf("%d %d\n", score_win, score_lose);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
