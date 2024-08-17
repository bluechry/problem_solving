/* @JUDGE_ID: andrea 640 C "Number Theory" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <string.h>

#define MAX 1000001

int generate_next_num(int num)
{
	int		next;

	next = num;
	while (num > 0) {
		next += num % 10;
		num /= 10;	
	}

	return next;
}

int main()
{
	char  	check_self_num[MAX];
	int 	i, next;

	/* Set check_self_num[] to 0x0 */
	memset(&check_self_num[0], 0x0, sizeof(char) * MAX);

	for (i = 1; i < MAX; i++) {

		/* Check self numbers */ 
		if (check_self_num[i] == 0x0) {	
			printf("%u\n", i);
		} 	

		/* Generate a next number */
		next = generate_next_num(i);
		if (next < MAX) {
			check_self_num[next] = 0x1;
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
