/* @JUDGE_ID: andrea 195 C "Combinatoric" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int compare(const void* left, const void* right)
{
	char op1, op2;

	op1 = *(char*)left;
	op2 = *(char*)right;

	if (tolower(op1) != tolower(op2)) {
		return tolower(op1) - tolower(op2);	
	}
	else {
		return op1 - op2;	
	}

	return *(char*)left - *(char*)right;
}

void perm(char symbol[], int num_symbol, char used_flag[], char output[], int pos)
{
	char  	prev_sym;
	int		i;

	/* If all symbols are used, print a word */ 
	if (pos == num_symbol) {
		output[pos] = '\0';
		printf("%s\n", output);
		return;
	}

	/* Pick up a next symbol & permutate other symbols */
	prev_sym = '\0'; 
	for (i = 0; i < num_symbol; i++) {
		if (used_flag[i] || prev_sym == symbol[i])
			continue; 
	
		output[pos] = symbol[i];	
		used_flag[i] = 0x1;
		perm(symbol, num_symbol, used_flag, output, pos + 1);
		used_flag[i] = 0x0; 
		prev_sym = symbol[i];
	}
	
	return;	
}

int main()
{
	int  num_cases, num_symbol;
	char symbol[1024], used_flag[1024], output[1024];

	/* # of input cases */
	scanf("%d\n", &num_cases);

	while (num_cases-- > 0) {
		/* Receive a line */
		gets(symbol);

		/* Sort characters */
		num_symbol = strlen(symbol);
		qsort(&symbol[0], num_symbol, sizeof(char), compare);

		/* Generate permutation */
		memset(&used_flag[0], 0x0, sizeof(char) * num_symbol);
		perm(symbol, num_symbol, used_flag, output, 0); 
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
