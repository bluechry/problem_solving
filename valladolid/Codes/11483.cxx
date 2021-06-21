/* @JUDGE_ID: andrea xxx C++ "Simlulation" */
/* @BEGIN_OF_SOURCE_CODE */

/*
 * Header Files
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>

/*
 * Macros
 */
#define SWAP(x, y) 	((x) ^= (y), (y) ^= (x), (x) ^= (y)	
#define PSWAP(px, py, type) \
do { \
    type* ptr = px;\
    px = py;\
    py = ptr;\
} while(0)
#define MAX(x, y)  	((x) > (y) ? (x) : (y))					// could be replaced with max(x, y) of <algorithm>
#define MIN(x, y)	((x) < (y) ? (x) : (y))					// could be replaced with min(x, y) of <algorithm>
#define ABS(x)		((x) < 0 ? -1 * (x) : (x))

using namespace std;

void make_output(char* in, char* out)
{
	char* ptr = &in[0];

	while (*ptr != '\0') {
		if (*ptr == '"') {
			*out++ = '\\';
			*out++ = *ptr++; 
		}
		else if (*ptr == '\\') {
			*out++ = '\\';
			*out++ = *ptr++; 
		}
		else {
			*out++ = *ptr++;
		}
	}

	*(out - 1) = '\0';

	return;
}

int main()
{

	int num_lines;
	int count = 0;

	while (scanf("%d\n", &num_lines) != EOF) {

		if (num_lines == 0) {
			break;
		}

		printf("Case %d:\n", ++count);
		printf("#include<string.h>\n");
		printf("#include<stdio.h>\n");
		printf("int main()\n");
		printf("{\n");

		for (int i = 0; i < num_lines; i++) {
			char line[128];
			fgets(line, 128, stdin);

			char output[256];
			make_output(line, output);

			printf("printf(\"%s\\n\");\n", output);	
		}

		printf("printf(\"\\n\");\n");
		printf("return 0;\n");
		printf("}\n");
	
	}		

	return 0;		
}
/* @END_OF_SOURCE_CODE */
