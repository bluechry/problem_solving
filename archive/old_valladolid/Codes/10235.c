/* @JUDGE_ID: andrea 10235 C "Simple Iteration" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <math.h>

int isPrime(int num)
{
    int i, temp;

    /* Check Prime or not */
    temp = sqrt(num);
    for (i = 2; i <= temp; i++) {
        if (num % i == 0) {
            return 0;
        }   
    }   

    return 1;
}

int main()
{
    int num, rev;
    int temp;

    while (scanf("%d\n", &num) != EOF) {
        temp = num;

        /* Check Prime or not */
        if (isPrime(temp) == 0) {
            printf("%d is not prime.\n", num);
        }   
        /* Check Emirp or not */
        else {   

            /* reverse the given number */
            rev = 0;
            while (temp > 0) {
                rev = rev * 10 + temp % 10; 
                temp /= 10; 
            }   

            if (rev != num && isPrime(rev)) {
                printf("%d is emirp.\n", num);
            }   
            else {
                printf("%d is prime.\n", num);
            }   
        }   

    }   

    return 0;
}

/* @END_OF_SOURCE_CODE */

