/* @JUDGE_ID: andrea 10019 C "Simple Iteration" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

int convert_to_hexa(int dec)
{
	int result;
	int base;

	base = 1;
	result = 0;
	while (dec > 0) {
		result += (dec % 10) * base;
		dec /= 10;	
		base *= 16;
	}

	return result;
}

int count_bits(int num)
{
	int count;

	count = 0;
	while (num > 0) {
		if (num & 0x1) {
			count++;
		}
		num >>= 1; 
	}
	
	return count;	
}

int main()
{
	int num_cases;
	int dec, hexa;
	int b1, b2;

	scanf("%d\n", &num_cases);
	while (num_cases-- > 0) {
		scanf("%d\n", &dec);
		hexa = convert_to_hexa(dec);
	
		b1 = count_bits(dec);
		b2 = count_bits(hexa);

		printf("%d %d\n", b1, b2);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
