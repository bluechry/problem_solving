/* @JUDGE_ID: andrea 374 C "Number Theory" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

int modular(int B, int P, int M)
{
	int temp;
	int result;

	if (P == 0) 
		return 1;

	if (B == 1) 
		return 1;
	
	if (B == 0)
		return 0;

	temp = modular(B, P >> 1, M) % M;
	temp = (temp * temp) % M;
	result = (P & 0x1) ? (temp * (B % M)) % M : temp % M;

	return result;
}

int main()
{
	int B, P, M, R;

	while (scanf("%d\n", &B) != EOF) {
		scanf("%d\n", &P);
		scanf("%d\n", &M);

		R = modular(B, P, M);

		printf("%d\n", R);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
