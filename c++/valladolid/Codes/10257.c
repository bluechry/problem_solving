/* @JUDGE_ID: andrea 10257 C "Simple Iteration" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

int main()
{
	int s, p, y, j, sum;
	int S, P, Y;


	while (scanf("%d %d %d %d\n", &s, &p, &y, &j) != EOF) {

		/*
		 * calculate S, Y, P temporarily
		 */
		sum = 12 + j;

		S = (2 * s + p + sum) / 3;

		Y = S - y;

		P = p + Y;


		/*
		 * adjust S, Y, P
		 */
		while (sum != S + Y + P) {
			
			/* check ++S */
			++S;
			if (S - P <= s + 1 && S - Y <= y + 1) {
				continue;
			}
			else {
				--S;
			}

			/* check ++P */
			++P;
			if (S - P <= s + 1 && P - Y <= p + 1) {
				continue;
			}
			else {
				--P;	
			}

			/* check ++Y */
			++Y;
			if (S - Y <= y + 1 && P - Y <= p + 1) {
				continue;
			}
			else {
				--Y;
			}
		}

		printf("%d %d %d\n", S, P, Y);
	}	 

	return 0;		
}

/* @END_OF_SOURCE_CODE */
