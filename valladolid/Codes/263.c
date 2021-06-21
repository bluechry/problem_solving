/* @JUDGE_ID: andrea 263 C "Simulation" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse_string(char buf[])
{
	int i, j, temp;

	for (i = 0, j = strlen(buf) - 1; i < j; i++, j--) {
		temp = buf[i];
		buf[i] = buf[j];
		buf[j] = temp; 
	}
	
	return;
}

int compare_char(const void* op1, const void* op2)
{
	return *((char* )op1) - *((char* )op2);
}

void sort_string(char buf[])
{
	int num_elems;
	
	num_elems = strlen(buf);
	qsort(&buf[0], num_elems, sizeof(char), compare_char);

	return;
}

void convert_int_to_string(int num, char buf[])
{
	int count;

	count = 0;
	while (num > 0) {
		buf[count++] = '0' + num % 10;
		num /= 10;
	}
	buf[count] = '\0';

	reverse_string(buf);	

	return;
}

int convert_string_to_int(char buf[])
{
	int num;

	num = atoi(buf);	

	return num;
}

int check_num_table(int num, int num_table[], int num_elems)
{
	int i;

	for (i = 0; i < num_elems; i++) {
		if (num_table[i] == num) {
			return 1;
		}
	}

	return 0;
}

int main()
{
	int 	num;
	int 	op1, op2, count;
	int 	num_table[1024];
	char 	buf[16];

	while (scanf("%d\n", &num) != EOF && num != 0) {
	
		printf("Original number was %d\n", num);

		count = 0;
		num_table[count++] = num;

		while (1) {
			convert_int_to_string(num, buf);
			sort_string(buf);
			op1 = convert_string_to_int(buf);

			reverse_string(buf);
			op2 = convert_string_to_int(buf);

			num = op2 - op1;
			printf("%d - %d = %d\n", op2, op1, num);

			if (check_num_table(num, num_table, count) == 1) {
				printf("Chain length %d\n\n", count);
				break;
			}
			else {
				num_table[count++] = num;
			}
		}	
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
