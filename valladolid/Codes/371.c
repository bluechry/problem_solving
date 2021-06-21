/* @JUDGE_ID: andrea 371 C "Simulation" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

int main()
{
	long L, H;
	long V, S;
	long len, temp, i;

	while (scanf("%ld %ld\n", &L, &H) != EOF) {

		if (L == 0 && H == 0) {
			break;
		}

		if (L > H) {
			L ^= H;
			H ^= L;
			L ^= H;
		}

		S = -1;	
		for (i = L; i <= H; i++) {

			temp = (i & 0x1) ? (3 * i + 1) : (i / 2);
			len = 1;
			while (temp != 1) {
				if (temp & 0x1) {
					temp = 3 * temp + 1;
				}
				else {
					temp >>= 1;
				}
				len++;
			}

			if (len > S) {
				S = len;
				V = i;
			}
		}

		printf("Between %ld and %ld, %ld generates the longest sequence of %ld values.\n", L, H, V, S); 
	}
 
	return 0;
}
/* @END_OF_SOURCE_CODE */
