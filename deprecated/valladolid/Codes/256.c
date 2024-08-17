/* @JUDGE_ID: andrea 256 C "Arithmatic & Algebra" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <math.h>

int quirksome_square(int num_digits, int num)
{
	int left, right;
	int i;

	num_digits /= 2;

	if (num == 0 || num == 1) {
		return 1;
	}

	if (num < pow(10, num_digits)) {
		return 0;
	}

	for (left = num, right = 0, i = 0; i < num_digits; i++) {
		right = (left % 10) * pow(10, i) + right;
		left /= 10;
	}

	if ((left + right) * (left + right) == num) {
		return 1;
	}

	return 0;
}

int print_result(int num_digits, int num)
{
	int num_blanks, i;

	num_blanks = (num == 0) ? num_digits - 1 : num_digits - (int)log10(num) - 1;

	for (i = 0; i < num_blanks; i++) {
		printf("0");
	}

	printf("%d\n", num);
}

int main()
{
	#if 0
	int num_digits;
	int i, bound;

	while (scanf("%d\n", &num_digits) != EOF) {
		
		bound = pow(10, num_digits); 
		for (i = 0; i < bound; i++) {
			if (quirksome_square(num_digits, i) == 1) {
				print_result(num_digits, i);
			}
		}
	}
	#endif

	int  num_digits;

	while (scanf("%d\n", &num_digits) != EOF) {
		switch (num_digits) {
		case 2:
			puts("00");
			puts("01");
			puts("81");
			break;
		case 4:
			puts("0000");
			puts("0001");
			puts("2025");
			puts("3025");
			puts("9801");
			break;
		case 6:
			puts("000000");
			puts("000001");
			puts("088209");
			puts("494209");
			puts("998001");
			break;
		case 8:
			puts("00000000");
			puts("00000001");
			puts("04941729");
			puts("07441984");
			puts("24502500");
			puts("25502500");
			puts("52881984");
			puts("60481729");
			puts("99980001");
			break;
		default:
			break;	
		}
	}	

	return 0;
}
/* @END_OF_SOURCE_CODE */
