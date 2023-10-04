/* @JUDGE_ID: andrea 11219 C "Simple Iteration" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

int main()
{
	int num_cases;
	int cur_year, cur_month, cur_day;
	int bir_year, bir_month, bir_day;
	int i, age;

	
	scanf("%d\n", &num_cases);
	for (i = 1; i <= num_cases; i++) {
		scanf("%2d/%2d/%4d\n", &cur_day, &cur_month, &cur_year);
		scanf("%2d/%2d/%4d\n", &bir_day, &bir_month, &bir_year);
		
		age = cur_year - bir_year;
		if ( (cur_month < bir_month) || (cur_month == bir_month && cur_day < bir_day) )
			--age;

		if (age > 130)
			printf("Case #%d: Check birth date\n", i);
		else if (age < 0)
			printf("Case #%d: Invalid birth date\n", i);
		else
			printf("Case #%d: %d\n", i, age);
			
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
