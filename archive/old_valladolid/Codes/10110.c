/* @JUDGE_ID: andrea 10110 C "Simple Math" */
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>
#include <math.h>

int main()
{
	unsigned int num;
	int 		 root;
	
	while (scanf("%d", &num) != 0 && num != 0) {
		root = (int)sqrt(num);
		if (root * root == num) {
			printf("yes\n");
		}
		else {
			printf("no\n");
		}
	}

	return 0;

}
/* @END_OF_SOURCE_CODE */
