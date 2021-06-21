/* @JUDGE_ID: andrea 498 C++ "Arithmetic" */
/* @BEGIN_OF_SOURCE_CODE */

/*
 * Header Files
 */
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>

/*
 * Macros
 */
#define SWAP(x, y) 	((x) ^= (y), (y) ^= (x), (x) ^= (y)	
#define MAX(x, y)  	((x) > (y) ? (x) : (y))					// could be replaced with max(x, y) of <algorithm>
#define MIN(x, y)	((x) < (y) ? (x) : (y))					// could be replaced with min(x, y) of <algorithm>
#define ABS(x)		((x) < 0 ? -1 * (x) : (x))

using namespace std;

void parse_line(char line[], vector<double>& value)
{
	char* ptr = &line[0];

	while (*ptr != '\0') {

		double val;

		// skip leading whitespaces
		while (*ptr != '\0' && isspace(*ptr)) ptr++;

		// read a value
		val = atof(ptr);
		value.push_back(val);

		// skip following whitespaces
		while (*ptr != '\0' && !isspace(*ptr)) ptr++;
	}

	return;
}

int main()
{
	char line[1024];

	while (gets(line) != NULL) {

		vector<double> coef;
		vector<double> xval;
	
		// obtain coefficients	
		parse_line(line, coef);

		// obtain x values
		gets(line);
		parse_line(line, xval);

		// calculate the expression
		for (int i = 0; i < xval.size(); i++) {

			double x   = xval[i];
			double sum = coef[0];
			for (int j = 1; j < coef.size(); j++) {
				sum = sum * x + coef[j];				
			}

			if (i > 0) {
				printf(" %.0lf", sum);
			}
			else {
				printf("%.0lf", sum);
			}
		}
		printf("\n");	
	}

	return 0;		
}

/* @END_OF_SOURCE_CODE */
