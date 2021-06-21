/* @JUDGE_ID: andrea 488 C "Simple Iteration" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

void make_wave(int amp, int freq, char buf[])
{
	char* 	ptr;
	int		i, j;

	ptr = &buf[0];

	for (i = 1; i <= amp; i++) {
		for (j = 1; j <= i; j++) {
			*ptr++ = i + '0';
		}
		*ptr++ = '\n';
	}

	for (i = amp - 1; i >= 1; i--) {
		for (j = 1; j <= i; j++) {
			*ptr++ = i + '0';
		}
		*ptr++ = '\n';
	}

	*ptr = '\0';

	return;
}

int main()
{
	char	buf[4096];
	int		num_cases;
	int		amp, freq;
	int		i, isFirst;

	
	scanf("%d\n", &num_cases);

	isFirst = 1;
	while (num_cases-- > 0) {
		if (isFirst) {	
			isFirst = 0;
		}
		else {
			printf("\n");
		}

		scanf("%d\n", &amp);
		scanf("%d\n", &freq);

		make_wave(amp, freq, buf);

		for (i = 0; i < freq - 1; i++) {
			printf("%s\n", buf);
		}
		printf("%s", buf);
	}

	return 0;		
}

/* @END_OF_SOURCE_CODE */
