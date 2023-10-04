/* @JUDGE_ID: andrea 594 C "Ad Hoc" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

#define BYTES_PER_NUM	4
#define BITS_PER_BYTE	8

int convert(int num)
{
	int conv_num;
	int count;

	count = BYTES_PER_NUM;
	conv_num = 0;
	while (count-- > 0) {
		conv_num = (conv_num << BITS_PER_BYTE) | (num & 0xff);
		num >>= BITS_PER_BYTE; 
	}

	return conv_num;
}

int main()
{
	int num, conv_num;

	while (scanf("%d\n", &num) != EOF) {
		conv_num = convert(num);	
		
		printf("%d converts to %d\n", num, conv_num);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
