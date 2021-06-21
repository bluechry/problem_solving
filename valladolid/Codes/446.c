/* @JUDGE_ID: andrea 446 C "Arithmatics" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

void print_bits(int num, int digits)
{
	int temp;
	
	temp = 1 << (digits - 1);
	while (temp > 0) {
		if (num & temp) {
			printf("1");
		}
		else {
			printf("0");
		}
		temp >>= 1;
	}

	return;
}

int main()
{
	int 	num_cases;
	int 	op1, op2;
	char 	oper;
	int 	result;

	scanf("%d\n", &num_cases);
	while (num_cases-- > 0) {
		scanf("%x %c %x\n", &op1, &oper, &op2);
	
		result = (oper == '+') ? op1 + op2 : op1 - op2;
		
		print_bits(op1, 13);
		printf(" %c ", oper);
		print_bits(op2, 13);
		printf(" = %d\n", result);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
