/* @JUDGE_ID: andrea 694 C "Simulation" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

int main()
{
	int 		A, L;
	int 		num_terms, num_case;
	long long 	temp;

	num_case = 0;
	while (scanf("%d %d\n", &A, &L) != EOF) {
		if (A < 0 && L < 0) break;

		temp = A;
		num_terms = 1;
		while (temp != 1) {
			temp = (temp & 0x1) ? (temp * 3 + 1) : (temp / 2);
			if (temp > L) break;
			num_terms++;
		}

		printf("Case %d: A = %d, limit = %d, number of terms = %d\n", ++num_case, A, L, num_terms);	
	} 

	return 0;
}
/* @END_OF_SOURCE_CODE */
