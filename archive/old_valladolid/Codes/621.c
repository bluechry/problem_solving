/* @JUDGE_ID: andrea 621 C "Ad Hoc" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <string.h>

int main()
{
	int		num_cases;
	char	line[4096];
	int		len;

	scanf("%d\n", &num_cases);
	
	while (num_cases-- > 0) {
	
		gets(&line[0]);
		
		len = strlen(line);

		if ((len == 1 && line[0] == '1') ||
			(len == 1 && line[0] == '4') ||
			(len == 2 && line[0] == '7' && line[1] == '8')) {

			puts("+");
		}
		else if (line[len - 2] == '3' && line[len - 1] == '5') {
			puts("-");
		}
		else if (line[0] == '9' && line[len - 1] == '4') {
			puts("*");
		}
		else if (line[0] == '1' && line[1] == '9' && line[2] == '0') {
			puts("?");
		}
	}

	return 0;		
}

/* @END_OF_SOURCE_CODE */
