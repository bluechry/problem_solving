/* @JUDGE_ID: andrea 10093 C "Simple Iteration" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

int main()
{
	char 	line[1024];
	char* 	ptr;
	int		max, sum, base, temp;

	while (gets(line) != NULL) {

		sum = 0;
		max = 1;	
		for (ptr = &line[0]; *ptr != '\0'; ptr++) {

			temp = 0;			
			if (*ptr >= '0' && *ptr <= '9') {
				temp = *ptr - '0';
			}
			else if (*ptr >= 'A' && *ptr <= 'Z') {
				temp = *ptr - 'A' + 10;
			}
			else if (*ptr >= 'a' && *ptr <= 'z') {
				temp = *ptr - 'a' + 36;
			}

			sum += temp; 
			max = (temp > max) ? temp : max;
		}

		for (base = max; base < 62; base++) {
			if (sum % base == 0) {
				break;
			}
		}
		
		if (base == 62) {
			printf("such number is impossible!\n");
		}
		else {
			printf("%d\n", base + 1);
		}
	
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
