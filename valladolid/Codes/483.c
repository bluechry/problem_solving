/* @JUDGE_ID: andrea 483 C "Simple Iteration" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <string.h>

void reverse_string(char buf[])
{
	char	*head, *tail;

	head = &buf[0];
	tail = head + strlen(buf) - 1;

	while (head < tail) {
		*head ^= *tail;
		*tail ^= *head;
		*head ^= *tail;

		head++;
		tail--;
	}

	return;
}

int main()
{
	char	ch, buf[4096];
	char	*ptr;

	ptr = &buf[0];
	while ((ch = getchar()) != EOF) {
		if (ch == ' ' || ch == '\n') {
			*ptr = '\0';
			reverse_string(buf);
			printf("%s", buf);
			putchar(ch);
			ptr = &buf[0];
		}
		else {
			*ptr++ = ch;
		}
	}	

	return 0;		
}

/* @END_OF_SOURCE_CODE */
