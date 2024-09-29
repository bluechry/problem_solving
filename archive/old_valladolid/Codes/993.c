/* @JUDGE_ID: andrea 993 C "Arithmatic" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <stdlib.h>

int compare(const void* op1, const void* op2)
{
	char l, r;

	l = *((char* )op1);
	r = *((char* )op2);

	return l - r;
}

int get_digits(int num, char result[])
{
	int i, count;

	count = 0;
	while (num > 1) {
		for (i = 9; i >= 2; --i) {
			if (num % i == 0) {
				result[count++] = '0' + i;
				num /= i;
				break;
			}
		}
		if (i < 2) {
			return -1;
		}
	}
	result[count] = '\0';	

	qsort(&result[0], count, sizeof(char), compare);

	return 0;
}

int main()
{
	int 	n_case, num;
	char 	result[1024];

	scanf("%d\n", &n_case);
	while (n_case-- > 0) {
		scanf("%d\n", &num);

		if (num < 10) {
			printf("%d\n", num);
		}
		else {
			if (get_digits(num, &result[0]) < 0) {
				printf("-1\n");
			}
			else {
				printf("%s\n", result);
			}
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
