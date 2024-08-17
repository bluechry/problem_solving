/* @JUDGE_ID: andrea 10137 C "Simple Iteration" */
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_STUDENT	1000

int compare(const void* arg1, const void* arg2)
{
	int val1, val2;

	val1 = *(int* )arg1;
	val2 = *(int* )arg2;
	
	return (val2 - val1);
}

int main()
{
	int		n_student;
	int		i;
	int 	temp, money_total, money_exchange;
	int		money_already_paid[MAX_STUDENT];
	int 	money_should_paid[MAX_STUDENT];
	int		avg, rest;
	double 	money;

	while (scanf("%d", &n_student) == 1 && n_student != 0) {
		for (money_total = 0, i = 0; i < n_student; i++) {
			scanf("%lf", &money);
			temp = (int)(money * 100 + 0.5);
			money_already_paid[i] = temp;
			money_total += temp;
		}
		
		qsort((void* )money_already_paid, (size_t)n_student, sizeof(int), compare);

		avg = money_total / n_student;
		for (i = 0; i < n_student; i++) {
			money_should_paid[i] = avg;
		}

		rest = money_total % n_student;
		for (i = 0; i < rest; i++) {
			money_should_paid[i]++;
		}
	
		for (money_exchange = 0, i = 0; i < n_student; i++) {
			money_exchange += abs(money_already_paid[i] - money_should_paid[i]);
		}
		money_exchange /= 2;
		/*	The following code also give right answer.
		for (money_exchange = 0, i = 0; i < n_student; i++) {
			if (money_already_paid[i] > avg) {
				money_exchange += (money_already_paid[i] - money_should_paid[i]);
			}
		}		
		*/

		printf("$%.2lf\n", money_exchange / 100.0);	
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
