/* @JUDGE_ID: andrea ##### C "Simple Iteration" */
/* @BEGIN_OF_SOURCE_CODE */

/*
 * Header Files
 */
#include <stdio.h>

/*
 * Macros
 */
#define SWAP(x, y) 	((x) ^= (y), (y) ^= (x), (x) ^= (y))
#define MAX(x, y)  	((x) > (y) ? (x) : (y))
#define MIN(x, y)	((x) < (y) ? (x) : (y))

#include <stdio.h>

int main()
{
    int     num_cases;
    char    line[256], ch; 
    int     repeat, i;

    scanf("%d\n", &num_cases);

    for (i = 1; i <= num_cases; i++) {

        printf("Case %d: ", i); 

        while (scanf("%c%d", &ch, &repeat) == 2) {
            while (repeat-- > 0) {
                putchar(ch);
            }   
        }   
        printf("\n");
    }   

    return 0;
}
/* @END_OF_SOURCE_CODE */
