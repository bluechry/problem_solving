/* @JUDGE_ID: andrea 10035 C "Simple Arithmatic" */
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>
#include <string.h>

int main()
{
	unsigned long left, right, carry;
	unsigned long left_digit, right_digit;
	unsigned long nCarry;
	

	while (scanf("%lu %lu", &left, &right) != EOF) {
		if (left == 0 && right == 0) {
			break;
		}

		nCarry = 0;
		carry = 0;
		while (left != 0 || right != 0) {
			left_digit = left % 10;
			left = (left > 0) ? left / 10 : 0;
			right_digit = right % 10;	
			right = (right > 0) ? right / 10 : 0;

			if (carry + left_digit + right_digit >= 10) {
				carry = 1;
				nCarry++; 
			}
			else {
				carry = 0;
			}	
		}

		switch (nCarry) {
		case 0:
			printf("No carry operation.\n");
			break;
		case 1:
			printf("%lu carry operation.\n", nCarry);
			break;
		default:
			printf("%lu carry operations.\n", nCarry);
			break;
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
