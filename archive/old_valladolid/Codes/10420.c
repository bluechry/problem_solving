/* @JUDGE_ID: andrea 10420 C "Sorting" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int string_compare(const void* op1, const void* op2)
{
	return strcmp(*(char** )op1, *(char** )op2);
}

int main()
{
	char	country_table[2048][128];
	char*	index[2048];
	char*	ptr;
	int		num_countries, num_dups, i;

	/* input processing */
	scanf("%d\n", &num_countries);
	for (i = 0; i < num_countries; i++) {	
		gets(&country_table[i][0]);
		index[i] = &country_table[i][0];
		ptr = strchr(&country_table[i][0], ' ');
		*ptr = '\0';	
	}

	/* sort countries */
	qsort(&index[0], num_countries, sizeof(char*), string_compare);

	/* count duplicates */
	strcpy(&country_table[num_countries][0], "$$$");
	index[num_countries] = &country_table[num_countries][0];
	num_countries++;
	
	num_dups = 0;
	for (i = 0; i < num_countries - 1; i++) {
		num_dups++;
		if (strcmp(index[i], index[i + 1])) {
			printf("%s %d\n", index[i], num_dups);
			num_dups = 0;
		}
	} 
	
	return 0;		
}

/* @END_OF_SOURCE_CODE */
