/* @JUDGE_ID: andrea 344 C "Simulation" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void countRomanDigit(int n, int* num_i, int* num_v, int* num_x, int* num_l, int* num_c)
{
	/* Count the number of roman digits */
	while (n > 0) {
		if (n >= 100) {
			++*num_c;
			n -= 100;
		}
		else if (n >= 90) {
			++*num_c;
			++*num_x;
			n -= 90;
		}
		else if (n >= 50) {
			++*num_l;
			n -= 50;
		}
		else if (n >= 40) {
			++*num_l;
			++*num_x;
			n -= 40;
		}
		else if (n >= 10) {
			++*num_x;
			n -= 10;
		}
		else if (n >= 9) {
			++*num_x;
			++*num_i;
			n -= 9;
		}
		else if (n >= 5) {
			++*num_v;
			n -= 5;
		}
		else if (n >= 4) {
			++*num_v;
			++*num_i;
			n -= 4;
		}
		else if (n >= 1) {
			++*num_i;
			n -= 1;
		}
	}

	return;
}


int main()
{
	int n;
	int num_i, num_v, num_x, num_l, num_c;
	int	i;

	while (scanf("%d\n", &n) != EOF && n != 0) {

		num_i = num_v = num_x = num_l = num_c = 0;

		for (i = 1; i <= n; i++) {
			countRomanDigit(i, &num_i, &num_v, &num_x, &num_l, &num_c);	
		}
	
		printf("%d: %d i, %d v, %d x, %d l, %d c\n", n, num_i, num_v, num_x, num_l, num_c);	
	}	


	return 0;
}
/* @END_OF_SOURCE_CODE */
