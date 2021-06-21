/* @JUDGE_ID: andrea 11121 C "Simple Iteration" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

void base_conversion(int num, int base, char conv[])
{
	int remain;
	int i, j; 

	if (num == 0) {
		conv[0] = '0';
		conv[1] = '\0';

		return;
	}

	i = 0;
	while (num != 0) {

		remain = num % base;
		if (remain < 0) {
			remain -= base;
		}
		num = (num - remain) / base;

		conv[i++] = (remain < 10) ? remain + '0' : remain - 10 + 'A';
 	}
	conv[i] = '\0';

	for (j = 0, --i; j < i; ++j, --i) {
		conv[i] ^= conv[j];
		conv[j] ^= conv[i];
		conv[i] ^= conv[j];
	}

	return;
}

int main()
{
	int  num_cases, num, i;
	char conv[1024];

	scanf("%d\n", &num_cases);
	for (i = 1; i <= num_cases; i++) {
		scanf("%d\n", &num);
		base_conversion(num, 16, conv);
		printf("Case #%d: %s\n", i, conv); 
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
