/* @JUDGE_ID: andrea 696 C "arithmatic" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

int main()
{
	int n, m, orig_n, orig_m;
	int num_knight, temp;

	while (scanf("%d %d\n", &n, &m) != EOF && n != 0 || m != 0) {
		orig_n = n; 
		orig_m = m;

		if (n > m) {
			n ^= m, m ^= n, n ^= m;
		}	
	
		switch (n) {
		case 1:
			num_knight = m;
			break;
		case 2:
			num_knight = (m / 4) * 4;
			num_knight = (m % 4 > 2) ? num_knight + 4 : num_knight + (m % 4) * 2;
			break;
		default:
			num_knight = (n / 2) * m;
			num_knight = (n % 2 == 1) ? num_knight + (m - 1) / 2 + 1 : num_knight;
			break;
		} 

		printf("%d knights may be placed on a %d row %d column board.\n", num_knight, orig_n, orig_m);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
