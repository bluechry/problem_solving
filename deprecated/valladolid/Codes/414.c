/* @JUDGE_ID: andrea 414 C "Ad Hoc" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

int count_space(char line[])
{
	char* ptr;
	int   num_spaces;

	num_spaces = 0;
	for (ptr = &line[0]; *ptr != '\0'; ptr++) {
		if (*ptr == ' ') num_spaces++;
	}

	return num_spaces;
}

int main()
{
	char line[32];
	int	 num_lines, num_spaces;
	int  total_spaces, min_spaces;
	int  i;

	while (scanf("%d\n", &num_lines) != EOF && num_lines != 0) {
		total_spaces = 0;
		min_spaces = 99;
		for (i = 0; i < num_lines; i++) {
			gets(line);
			num_spaces = count_space(line);	
			if (min_spaces > num_spaces) min_spaces = num_spaces;
			total_spaces += num_spaces;
		}	

		printf("%d\n", total_spaces - min_spaces * num_lines);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
