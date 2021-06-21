/* @JUDGE_ID: andrea 713 C "Arithmatic" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <string.h>

void strip_trailing_zeros(char* buffer)
{
	int length;
	int i;

	length = strlen(buffer);
	for (i = length - 1; i >= 0; i--) {
		if (buffer[i] != '0') break;
	}

	if (i < 0) {
		buffer[1] = '\0';
	}
	else {
		buffer[i + 1] = '\0';
	}

	return;
}

void strip_leading_zeros(char* buffer)
{
	int length;
	int i;

	length = strlen(buffer);
	for (i = 0; i < length; i++) {
		if (buffer[i] != '0') break;
	}

	if (i == length) {
		buffer[1] = '\0';
	} 
	else {
		memmove(&buffer[0], &buffer[i], sizeof(char) * (length - i + 1));
	}

	return;
}

void add_two_string(char* op1, char* op2, char* out)
{
	int	  carry;
	int   sum;

	carry = 0;
	while (*op1 != '\0' || *op2 != '\0') {
		sum = carry;
		if (*op1 != '\0') {
			sum += *op1++ - '0';
		}
		if (*op2 != '\0') {
			sum += *op2++ - '0';
		}	

	 	carry = sum / 10;
		*out++ = sum % 10 + '0';
	}

	if (carry > 0) {
		*out++ = carry + '0';
		*out = '\0';
	}
	else {
		*out = '\0';
	}

	return;
}

int main()
{
	int num_cases;
	char op1[256], op2[256], out[256];

	scanf("%d\n", &num_cases);
	while (num_cases-- > 0) {
		scanf("%s %s\n", &op1[0], &op2[0]);
		
		strip_trailing_zeros(op1);
		strip_trailing_zeros(op2);

		add_two_string(op1, op2, out);

		strip_leading_zeros(out);

		printf("%s\n", out);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
