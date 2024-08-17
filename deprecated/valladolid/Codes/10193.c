/* @JUDGE_ID: andrea 10193 C "Simple Iteration" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

int convert(char bin[])
{
	int dec;
	char* ptr;

	for (ptr = &bin[0], dec = 0; *ptr != '\0'; ptr++) {
		dec = (dec << 1) | (*ptr - '0'); 
	}

	return dec;
}

int gcd(int a, int b)
{
	int temp;

	while (b > 0) {
		temp = a;
		a = b;
		b = temp % b;			
	}

	return a;	
}

int main()
{
	char line[32];
	int  S1, S2;
	int  num_cases, i;

	scanf("%d\n", &num_cases);
	for (i = 1; i <= num_cases; i++) {
		gets(line);
		S1 = convert(line);
		gets(line);
		S2 = convert(line);

		if (gcd(S1, S2) != 1) {
			printf("Pair #%d: All you need is love!\n", i);
		}
		else {
			printf("Pair #%d: Love is not all you need!\n", i);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
