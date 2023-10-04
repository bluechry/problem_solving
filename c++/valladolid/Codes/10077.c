/* @JUDGE_ID: andrea 10077 C "Binary Search" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

typedef struct {
	int	m;
	int n;
} Fraction;

#define COMP_FRAC(x, y) ((x).m * (y).n - (y).m * (x).n)

void find_fraction(Fraction value)
{
	Fraction left  = {0, 1}; 
	Fraction mid   = {1, 1};
	Fraction right = {1, 0};
	int		 result;

	while ((result = COMP_FRAC(value, mid)) != 0) {
		if (result < 0) {
			putchar('L');

			right = mid;
			mid.m = left.m + mid.m;
			mid.n = left.n + mid.n;
			left  = left;	
		}
		else {
			putchar('R');

			left  = mid;
			mid.m = mid.m + right.m;
			mid.n = mid.n + right.n;
			right = right;
		}
	}

	putchar('\n');
	
	return;
}

int main()
{
	Fraction input;	

	while (scanf("%d %d\n", &(input.m), &(input.n)) != EOF) {

		if (input.m == 1 && input.n == 1) {
			break;
		}

		find_fraction(input);
	}

	return 0;		
}

/* @END_OF_SOURCE_CODE */
