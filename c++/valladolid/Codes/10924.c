/* @JUDGE_ID: andrea 10924 C "Number Theory" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <math.h>

int check_prime(int num)
{
	int temp;
	int i;

	if (num == 1) return 1;

	temp = sqrt(num);
	for (i = 2; i <= temp; i++) {
		if (num % i == 0) return 0;
	}	
	
	return 1;
}

int main()
{
	char 	line[32];
	char* 	ptr;
	int		sum;
	
	while (gets(line) != NULL) {
	
		sum = 0;		
		for (ptr = &line[0]; *ptr != '\0'; ptr++) {
			if (*ptr >= 'a' && *ptr <= 'z') {
				sum += *ptr - 'a' + 1;
			}
			else if (*ptr >= 'A' && *ptr <= 'Z') {
				sum += *ptr - 'A' + 27;
			}
		}

		if (check_prime(sum) == 1) {
			printf("It is a prime word.\n");
		}
		else {
			printf("It is not a prime word.\n");
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
