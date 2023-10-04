/* @JUDGE_ID: andrea 340 C++ "Simlulation" */
/* @BEGIN_OF_SOURCE_CODE */

/*
 * Header Files
 */
#include <iostream>
#include <cstdio>
#include <cstring>

/*
 * Macros
 */
#define SWAP(x, y) 	((x) ^= (y), (y) ^= (x), (x) ^= (y)	
#define MAX(x, y)  	((x) > (y) ? (x) : (y))					// could be replaced with max(x, y) of <algorithm>
#define MIN(x, y)	((x) < (y) ? (x) : (y))					// could be replaced with min(x, y) of <algorithm>
#define ABS(x)		((x) < 0 ? -1 * (x) : (x))

using namespace std;

void check_match(int S[], int G[], int num_elems)
{
	int count_S[16], count_G[16];
	int num_strong, num_total;

	memset(&count_S[0], 0x0, sizeof(int) * 16);
	memset(&count_G[0], 0x0, sizeof(int) * 16);

	// count each elements of S & G
	num_strong = 0;
	for (int i = 0; i < num_elems; i++) {
		count_S[S[i]]++;
		count_G[G[i]]++;

		if (S[i] == G[i]) num_strong++;
	}

	// count total match
	num_total = 0;
	for (int i = 1; i <= 10; i++) {
		num_total += MIN(count_S[i], count_G[i]);
	}

	printf("    (%d,%d)\n", num_strong, num_total - num_strong);

	return;
}

void run_game(int num_elems)
{
	int S[1024], G[1024];

	// receive S
	for (int i = 0; i < num_elems; i++) {
		scanf("%d\n", &S[i]);
	}

	// receive G
	while (1) {
		
		int check_sum = 0;
		for (int i = 0; i < num_elems; i++) {
			scanf("%d\n", &G[i]);
			check_sum += G[i];
		}

		if (check_sum == 0) {
			break;
		}

		check_match(S, G, num_elems);
	}

	return;
}

int main()
{
	int num, count;

	count = 0;
	while (scanf("%d\n", &num) != EOF && num != 0) {

		printf("Game %d:\n", ++count);
	
		run_game(num);	
	}

	return 0;		
}

/* @END_OF_SOURCE_CODE */
