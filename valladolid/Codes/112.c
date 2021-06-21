/* @JUDGE_ID: andrea 112 C "Simple Iteration" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

int check_sum(char* tree, int sum, int target)
{
	int result;
	int value, paren, sign;

	/*
	printf("[SUB] sum: %d tree: %s\n", sum, tree);
	*/

	/* add sum to the value of a node */
	tree++;
	if (*tree == '-') {
		sign = -1;
		tree++;
	}
	else {
		sign = 1;
	}

	for (value = 0; *tree != '('; tree++) {
		value *= 10;
		value += (*tree - '0');
	}
	value *= sign;

	/* if a node is a leaf node, check the sum is equal to the target */
	if (tree[0] == '(' && tree[1] == ')' && tree[2] == '(' && tree[3] == ')') {
		if (sum + value == target) {
			return 1;
		}
		else {
			return 0;
		}
	}

	/* traverse a left tree and check a result */
	if (tree[0] != '(' || tree[1] != ')') { 
		result = check_sum(tree, sum + value, target);
		if (result == 1) {
			return 1;
		}
	}

	/* skip the left tree */
	for (paren = 1, tree++; paren > 0; tree++) {
		switch (*tree) {
		case '(': 
			paren++;
			break;
		case ')':
			paren--;
			break;
		}
	}

	/* traverse a right tree and check a result */
	if (tree[0] != '(' || tree[1] != ')') { 
		result = check_sum(tree, sum + value, target);
		if (result == 1) {
			return 1;
		}
	}

	return 0;
}

int main()
{
	int 	target;
	char 	tree[4096];
	int		count, paren;
	char	ch;


	/* processing input */
	while (scanf("%d", &target) != EOF) {

		count = 0;
		paren = 0;
		while (1) {
			ch = getchar();
			if (ch == ' ' || ch == '\t' || ch == '\n') {
				continue;
			}

			switch (ch) {
			case '(':
				tree[count++] = ch;
				paren++;
				break;
			case ')':
				tree[count++] = ch;
				paren--;
				break;
			default:
				tree[count++] = ch;
				break;
			}

			if (count > 0 && paren == 0) {
				tree[count] = '\0';
				break;
			}
		}


		/* traverse a tree and check the sum */
		if (tree[0] == '(' && tree[1] == ')') {
			puts("no");
		}
		else if (check_sum(tree, 0, target) == 1) {
			puts("yes");
		}
		else {
			puts("no");
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
