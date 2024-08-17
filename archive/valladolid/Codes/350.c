/* @JUDGE_ID: andrea 350 C "Arithmatic" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <string.h>

int main()
{
	int 	Z, I, M, L;
	char 	exist[10000];
	int		next_val, count, num_case;

	num_case = 0;
	while (scanf("%d %d %d %d\n", &Z, &I, &M, &L) != EOF) {
		if (Z == 0 && I == 0 && M == 0 && L == 0) {
			break;
		} 

		num_case++;

		memset(exist, 0x0, sizeof(char) * 10000);
		count = 0;
		next_val = L;
		while (exist[next_val] == 0) {
			exist[next_val] = count++;
			next_val = (Z * next_val + I) % M;
		}

		printf("Case %d: %d\n", num_case, count - exist[next_val]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
