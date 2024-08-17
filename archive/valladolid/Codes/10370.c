/* @JUDGE_ID: andrea 10370 C "Arithmatic" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

int main()
{
	int C, N;
	int score[1024];
	int i, count;
	double avr;

	scanf("%d\n", &C);
	while (C-- > 0) {
		scanf("%d ", &N);

		for (avr = 0, i = 0; i < N; i++) {
			scanf("%d\n", &score[i]);
			avr += score[i];
		}

		avr = avr / N;
	
		for (count = 0, i = 0; i < N; i++) {
			if (score[i] > avr) count++;
		}

		printf("%.3lf%\n", (double)count / N * 100);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
