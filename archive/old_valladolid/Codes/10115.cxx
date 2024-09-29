/* @JUDGE_ID: andrea 10115 C++ "Simlulation" */
/* @BEGIN_OF_SOURCE_CODE */

/*
 * Header Files
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

/*
 * Macros
 */
#define SWAP(x, y) 	((x) ^= (y), (y) ^= (x), (x) ^= (y)	
#define MAX(x, y)  	((x) > (y) ? (x) : (y))					// could be replaced with max(x, y) of <algorithm>
#define MIN(x, y)	((x) < (y) ? (x) : (y))					// could be replaced with min(x, y) of <algorithm>
#define ABS(x)		((x) < 0 ? -1 * (x) : (x))

using namespace std;

typedef struct {
	char find[128];
	char replace[128];
	int	 len_find;
	int	 len_replace;
} Rule;

bool replace(char line[], Rule* rule)
{
	char *s1, *s2;

	if ((s1 = strstr(line, rule->find)) == NULL) {
		return false;
	}

	s2 = s1 + rule->len_find;
	if (s2 == NULL) {
		memcpy(s2, rule->replace, rule->len_replace + 1);
	}
	else {
		char *move;
		move = s2 + (rule->len_replace - rule->len_find);
		memmove(move, s2, strlen(s2) + 1);
		memcpy(s1, rule->replace, rule->len_replace); 
	}
	
	return true;
}

int main()
{
	Rule	rules[16];
	int 	num_rules;
	char	line[512];

	while (scanf("%d\n", &num_rules) != EOF && num_rules != 0) {

		// read rules
		for (int i = 0; i < num_rules; i++) {

			gets(rules[i].find);
			gets(rules[i].replace);

			rules[i].len_find 	 = strlen(rules[i].find);
			rules[i].len_replace = strlen(rules[i].replace);
		}

		// read a sentence
		gets(line);

		// replace a word using the rules
		for (int i = 0; i < num_rules; i++) {
			while (replace(line, &rules[i])) ; 
		}

		// output a result
		printf("%s\n", line);
	}	

	return 0;		
}

/* @END_OF_SOURCE_CODE */
