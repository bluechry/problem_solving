/* @JUDGE_ID: andrea 10336 C++ "Simlulation" */
/* @BEGIN_OF_SOURCE_CODE */

/*
 * Header Files
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

/*
 * Macros
 */
#define SWAP(x, y) 	((x) ^= (y), (y) ^= (x), (x) ^= (y)	
#define MAX(x, y)  	((x) > (y) ? (x) : (y))					// could be replaced with max(x, y) of <algorithm>
#define MIN(x, y)	((x) < (y) ? (x) : (y))					// could be replaced with min(x, y) of <algorithm>
#define ABS(x)		((x) < 0 ? -1 * (x) : (x))

using namespace std;

#define LANG_SZ	32

typedef struct {
	char lang;
	int	 count;
} Lang; 

Lang lang_info[LANG_SZ];

#define MAP_SZ	1024

char map[MAP_SZ][MAP_SZ];

void check_lang(char lang, int i, int j)
{
	map[i][j] = '.';

	if (map[i - 1][j] == lang) {
		check_lang(lang, i - 1, j);
	}
	if (map[i][j - 1] == lang) {
		check_lang(lang, i, j - 1);
	}
	if (map[i][j + 1] == lang) {
		check_lang(lang, i, j + 1);
	}
	if (map[i + 1][j] == lang) {
		check_lang(lang, i + 1, j);
	}
	
	return;
}

int compare(const void* op1, const void* op2)
{
	Lang* left 	= (Lang*) op1;
	Lang* right	= (Lang*) op2;

	if (left->count == right->count) {
		return left->lang - right->lang;		// ascending order for a lang name
	}
 
	return -1 * (left->count - right->count);	// descending order for a # of state
}

int main()
{
	int num_world;

	scanf("%d\n", &num_world);
	for (int world = 1; world <= num_world; world++) {

		// init a lang_info
		memset(&lang_info[0], 0x0, sizeof(Lang) * LANG_SZ);

		// init a map
		memset(&map[0][0], '.', sizeof(char) * MAP_SZ * MAP_SZ);

		// read language distribution 
		int row, col;

		scanf("%d %d\n", &row, &col);

		for (int i = 1; i <= row; i++) {
			gets(&map[i][1]);
			map[i][col + 1] = '.';
		}

		// count each language
		for (int i = 1; i <= row; i++) {
			for (int j = 1; j <= col; j++) {
				if (map[i][j] != '.') {
					char lang = map[i][j];

					lang_info[lang - 'a'].lang = lang;
					lang_info[lang - 'a'].count++;

					check_lang(lang, i, j);
				}
			}
		}

		// sort lang_info
		qsort(&lang_info[0], LANG_SZ, sizeof(Lang), compare);

		// dump lang_info
		printf("World #%d\n", world);
		for (int i = 0; i < LANG_SZ; i++) {
			if (lang_info[i].count == 0) {
				break;
			}
			printf("%c: %d\n", lang_info[i].lang, lang_info[i].count);
		} 
	}

	return 0;		
}

/* @END_OF_SOURCE_CODE */
