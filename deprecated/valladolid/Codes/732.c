/* @JUDGE_ID: andrea 732 C "Back Tracking" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <string.h>

#define MAX_STACK 	1024	
#define MAX_BUF		2048	

typedef struct _stack {
	unsigned int count;
	unsigned int elem[MAX_STACK];	
} stack;


void check_anagram(char* src, char* tgt, char* seq, int seq_idx, int out_idx, stack* s)
{
	char* ptr;
	char  temp;

	/* No more characters to push or pop */
	if (s->count == 0 && *src == '\0') {
		seq[seq_idx] = '\0';
		for (ptr = seq; *(ptr + 1) != '\0'; ++ptr) {
			printf("%c ", *ptr);	
		}
		printf("%c\n", *ptr);

		return;
	}

	/* Put a charcter into the stack */
	if (*src != '\0') {
		s->elem[s->count++] = *src; 
		seq[seq_idx] = 'i';
		check_anagram(src + 1, tgt, seq, seq_idx + 1, out_idx, s);
		seq[seq_idx] = '\0';
		--s->count;
	}

	/* Pop a character from the stack */
	if (s->count != 0) {
		temp = s->elem[--s->count];
		if (temp == tgt[out_idx]) {
			seq[seq_idx] = 'o';
			check_anagram(src, tgt, seq, seq_idx + 1, out_idx + 1, s);
			seq[seq_idx] = '\0';
		}
		s->elem[s->count++] = temp; 
	}

	return;	
}


int main()
{
	char  src[MAX_BUF], tgt[MAX_BUF];
	char  seq[MAX_BUF];
	stack s;

	s.count = 0;

	while (scanf("%s", &src[0]) != EOF && scanf("%s", &tgt[0]) != EOF) {
		puts("[");
		if (strlen(src) == strlen(tgt)) {
			check_anagram(src, tgt, seq, 0, 0, &s); 
		}
		puts("]");
	}
	
	return 0;
}
/* @END_OF_SOURCE_CODE */
