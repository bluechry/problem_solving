/* @JUDGE_ID: andrea 10220 C "Arithmatic & Algebra" */
/* @BEGIN_OF_SOURCE_CODE */


#include <stdio.h>
#include <math.h>
#include <string.h>

/*@
 * Definitions of Types & Macros
 */
#define MAX(_a, _b) ((_a) > (_b)) ? (_a) : (_b)

#define MAX_DIGITS	2600	

typedef enum {MINUS = -1, PLUS = 1} Sign;

typedef struct {
	Sign sign;
	char digits[MAX_DIGITS];
	int  num_digits;
} Integer; 


/*@
 * Definitions of Internal Functions 
 */
void integer_JustifyZero(Integer* );
void integer_ShiftDigits(Integer* , int );


/*@
 * Definitions of External Functions
 */
void Integer_Init(int, Integer* );
void Integer_InitFromString(char*, Integer* );
void Integer_Print(Integer* );
int  Integer_Compare(Integer* , Integer* );
void Integer_Add(Integer*, Integer*, Integer* );
void Integer_Sub(Integer*, Integer*, Integer* );
void Integer_Mul(Integer*, Integer*, Integer* );
void Integer_Div(Integer*, Integer*, Integer* );


/*@
 * Implemetations of Internal Functions
 */
void integer_JustifyZero(Integer* in)
{
	/*
	 * skip all non-zero digits
	 */
	while (in->num_digits > 0) {
		if (in->digits[in->num_digits - 1] != 0) {
			break;
		}
		in->num_digits--;
	}

	/*
 	 * if all digits are zeros, return "+0"
 	 */
	if (in->num_digits == 0) {
		in->sign = PLUS;
		in->num_digits = 1;
	}

	return;
}


void integer_ShiftDigits(Integer* in, int num_shift)
{
	if (in->num_digits == 1 && in->digits[0] == 0) {
		return;
	}

	memmove(&(in->digits[num_shift]), &(in->digits[0]), in->num_digits);
	memset(&(in->digits[0]), 0x0, num_shift);

	in->num_digits += num_shift;

	return;
}


/*@
 * Implementations of External Functions
 */
void Integer_Init(int num, Integer* out) 
{

	/* 
 	 * verify the sign of the num 
 	 */
	if (num < 0) {
		out->sign = MINUS;
	}
	else {
		out->sign = PLUS;
	}

	/* 
 	 * convert the num to a Integer 
 	 */
	memset(&(out->digits[0]), 0x0, MAX_DIGITS);

	if (num == 0) {
		out->digits[0] = 0;
		out->num_digits = 1;
	}
	else {

		num = abs(num);
		out->num_digits = 0;

		while (num > 0) {
			out->digits[out->num_digits] = num % 10;
			num /= 10;
			out->num_digits++;
		}
	}

	return;
} 


void Integer_InitFromString(char* num, Integer* out)
{
	char* 	ptr;
	int 	i;

	/*
 	 * verify the sign of the num
 	 */
	ptr = num;

	if (ptr[0] == '-' && ptr[1] != '0') {
		out->sign = MINUS;
	}
	else {
		out->sign = PLUS;
	}

	if (ptr[0] == '-') {
		ptr++;
	}

	/*
 	 * convert the num to a Integer
 	 */
	memset(&(out->digits[0]), 0x0, MAX_DIGITS);
	
	out->num_digits = strlen(ptr);

	for (i = 0; i < out->num_digits; i++) {
		out->digits[i] = ptr[out->num_digits - i - 1] - '0';
	}

	integer_JustifyZero(out);

	return;
}

void Integer_Print(Integer* in)
{
	int i;

	/* 
 	 * check the sign of the Integer in 
	 */
	if (in->sign == MINUS) {
		printf("-");
	}

	/* 
 	 * print all digits of the Integer in 
 	 */
	for (i = in->num_digits - 1; i >= 0; i--) {
		printf("%d", in->digits[i]);
	}
	printf("\n");

	return;
} 


int Integer_Compare(Integer* op1, Integer* op2)
{
	int i;

	/*
 	 * compare the signs of two Integers
 	 */
	if (op1->sign == PLUS && op2->sign == MINUS) {
		return -1;
	}
	
	if (op1->sign == MINUS && op2->sign == PLUS) {
		return 1;
	}

	/*
 	 * compare each digit
 	 */
	if (op1->num_digits > op2->num_digits) {
		return -1 * op1->sign;
	}

	if (op1->num_digits < op2->num_digits) {
		return 1 * op1->sign;
	}
	
	for (i = op1->num_digits - 1; i >= 0; i--) {
		if (op1->digits[i] > op2->digits[i]) {
			return -1 * op1->sign;
		}

		if (op1->digits[i] < op2->digits[i]) {
			return 1 * op1->sign;
		}
	}	
	
	return 0;
}


void Integer_Add(Integer* op1, Integer* op2, Integer* result)
{
	int i;
	int carry;

	/*
 	 * init a result
 	 */
	Integer_Init(0, result);

	/*
 	 * if two operands have same signs, 
 	 */
	if (op1->sign == op2->sign) {
		result->sign = op1->sign;
		result->num_digits = MAX(op1->num_digits, op2->num_digits);
	
		carry = 0;
		for (i = 0; i < result->num_digits; i++) {
			result->digits[i] = (op1->digits[i] + op2->digits[i] + carry) % 10;
			carry = (op1->digits[i] + op2->digits[i] + carry) / 10; 
		}

		if (carry > 0) {
			result->digits[i] = carry;
			result->num_digits++;
		}
	}

	/*
 	 * if two operands have different signs,
 	 */
	else if (op1->sign == MINUS) {
		op1->sign = PLUS;
		Integer_Sub(op2, op1, result);
		op1->sign = MINUS;
	}
	else {
		op2->sign = PLUS;
		Integer_Sub(op1, op2, result);
		op2->sign = MINUS;
	}

	integer_JustifyZero(result);

	return;	
}


void Integer_Sub(Integer* op1, Integer* op2, Integer* result)
{


}


void Integer_Mult(Integer* op1, Integer* op2, Integer* result)
{
	int 	i, j;	
	int 	carry;
	Integer temp, row;

	/*
 	 * init a result
 	 */
	Integer_Init(0, result);

	/*
 	 * multiply two Integers
 	 */
	for (i = 0; i < op2->num_digits; i++) {

		Integer_Init(0, &row);

		carry = 0;
		for (j = 0; j < op1->num_digits; j++) {
			row.digits[row.num_digits - 1] = (op2->digits[i] * op1->digits[j] + carry) % 10;				
			carry = (op2->digits[i] * op1->digits[j] + carry) / 10;
			row.num_digits++;
		}

		if (carry > 0) {
			row.digits[j] = carry;
			row.num_digits++;
		}

		integer_JustifyZero(&row);

		integer_ShiftDigits(&row, i);

		Integer_Add(result, &row, &temp);

		*result = temp;
	}

	/*
 	 * verify a sign of the result
 	 */
	result->sign = op1->sign * op2->sign;		

	return;
}


void Integer_Div(Integer* op1, Integer* op2, Integer* result)
{


}


int main()
{
	Integer fact[1024], temp;
	int 	num, sum;
	int 	i;

	Integer_Init(1, &fact[0]);
	for (i = 1; i <= 1000; i++) {
		Integer_Init(i, &temp);
		Integer_Mult(&fact[i - 1], &temp, &fact[i]);	
	}	

	while (scanf("%d\n", &num) != EOF) {
	
		sum = 0;	
		for (i = 0; i < fact[num].num_digits; i++) {
			sum += fact[num].digits[i];
		}

		printf("%d\n", sum);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
