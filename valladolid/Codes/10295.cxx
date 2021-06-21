/* @JUDGE_ID: andrea 10295 C++ "Simlulation" */
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
	char 	keyword[20];
	double 	value;
} Keyword;

Keyword keyword[1024];
int		num_keywords;

double find_hay_point_val(char buf[])
{
	int head, tail, mid;

	head = 0;
	tail = num_keywords - 1;

	while (head <= tail) {
		mid = (head + tail)	>> 1;

		int temp = strcmp(buf, keyword[mid].keyword);
		if (temp == 0) {
			return keyword[mid].value;
		}
		else if (temp < 0) {
			tail = mid - 1;
		}
		else {
			head = mid + 1;
		}
	}	

	return 0.0;
}

double calc_hay_point_val()
{
	char	ch, buf[20];
	double 	sum;
	int		length;

	sum = 0.0;
	length = 0;
	while (1) {
		ch = getchar();
		
		if (ch == '\n' || ch == ' ' || ch =='.') {
			if (length <= 16) {
				buf[length] = '\0';
				sum += find_hay_point_val(buf);
			}

			length = 0;

			if (ch == '.') {
				break;
			}
		}
		else {
			if (length < 16) {
				buf[length++] = ch;
			}
			else {
				length++;
			}
		}
	}

	return sum;
}

int compare(const void* op1, const void* op2)
{
	char* l;
	char* r;

	l = ((Keyword* )op1)->keyword;
	r = ((Keyword* )op2)->keyword;

	return strcmp(l, r);
}

int main()
{
	int num_desc, i;

	scanf("%d %d\n", &num_keywords, &num_desc);

	for (i = 0; i < num_keywords; i++) {
		scanf("%s %lf\n", keyword[i].keyword, &keyword[i].value);
	}

	qsort(keyword, num_keywords, sizeof(Keyword), compare);

	for (i = 0; i < num_desc; i++) {
		printf("%.0lf\n", calc_hay_point_val());
	}

	return 0;		
}

/* @END_OF_SOURCE_CODE */
