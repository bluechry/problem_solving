/* @JUDGE_ID: andrea 673 C++ "Simple Iteration" */
/* @BEGIN_OF_SOURCE_CODE */

#include <iostream>
#include <stack>
#include <stdio.h>

using namespace std;

bool check_grammar(char line[])
{
	stack<char>	s;
	bool		result;
	char		*ptr, ch;

	ptr = &line[0];
	result = true;
	while ((ch = *ptr++) != '\0' && result) {
		
		switch (ch) {
		case '(':
			s.push(ch);
			break;
		case '[':
			s.push(ch);
			break;
		case ')':
			if (s.empty() || s.top() != '(') {
				result = false;
			}
			else {
				s.pop();
			}
			break;
		case ']':
			if (s.empty() || s.top() != '[') {
				result = false;
			}
			else {
				s.pop();
			}
			break;
		default:
			break;
		}
	}

	if (result && s.empty()) {
		return true;
	}
	else {
		return false;
	}
}

int main()
{
	int		num_cases;
	char	line[256];

	scanf("%d\n", &num_cases);
	while (num_cases-- > 0) {
		gets(line);

		if (check_grammar(line)) {
			puts("Yes");
		}
		else {
			puts("No");
		}
	}

	return 0;		
}

/* @END_OF_SOURCE_CODE */
