/* @JUDGE_ID: andrea 424 C "Simple Iteration" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <string.h>

#define MAX_DIGIT	1024

typedef struct {
	int 	nDigits;
	char	value[MAX_DIGIT];
} BigInt; 

void setBigInt(BigInt* bigInt, char numString[])
{
	int len, i;

	len = strlen(numString);

	memset(&(bigInt->value[0]), 0x0, sizeof(char) * MAX_DIGIT);

	bigInt->nDigits = len;

	for (i = 0; i < len; i++) {
		bigInt->value[i] = numString[len - i - 1] - '0';
	} 

	return;	
}

void addBigInt(BigInt* left, BigInt* right, BigInt* result)
{
	int leftPos, rightPos, resultPos;
	int carry, sum;

	leftPos = rightPos = resultPos = 0;
	carry = 0;
	while (leftPos < left->nDigits || rightPos < right->nDigits) {
		sum = carry;
		sum += left->value[leftPos++]; 
		sum += right->value[rightPos++]; 

		carry = sum / 10;
		sum = sum % 10;
		result->value[resultPos++] = sum;
	}

	if (carry > 0) {
		result->value[resultPos++] = carry;
	}
	result->nDigits = resultPos;

	return;
}

void printBigInt(BigInt* bigInt)
{
	int i;

	for (i = bigInt->nDigits - 1; i >= 0; i--) {
		printf("%d", bigInt->value[i]);
	}	

	return;
}

int main()
{
	BigInt 	num;
	BigInt 	result;
	char 	line[1024];

	setBigInt(&result, "0");
	while (gets(line) != NULL && line[0] != '0') {
		setBigInt(&num, line);
		addBigInt(&result, &num, &result);
	}

	printBigInt(&result);
	printf("\n");

	return 0;
}
/* @END_OF_SOURCE_CODE */
