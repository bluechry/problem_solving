/* @JUDGE_ID: andrea 10282 C++ "Binary Search" */
/* @BEGIN_OF_SOURCE_CODE */

/*
 * Header Files for C++
 */
#include <iostream>
#include <algorithm>

/*
 * Header Files for C
 */
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

#define ABS(x)		((x) < 0 ? -1 * (x) : (x))

/*
 * Namespace(s)
 */
using namespace std;

typedef struct {
	char eng[16];
	char fore[16];
} DictEntry;

DictEntry dict[100000];
int				dict_size;

int str_compare(const void* l, const void* r) {
	return strcmp(((DictEntry* )l)->fore, ((DictEntry* )r)->fore);
}

int binary_search(DictEntry* dict, char* fore) {
	int h = 0, t = dict_size - 1;

	while (h <= t) {
		int mid = (h + t) / 2;
		if (strcmp(dict[mid].fore, fore) < 0) {
			h = mid + 1;
		} else if (strcmp(dict[mid].fore, fore) > 0) {
			t = mid - 1;
		} else {
			return mid;
		}
	}

	return -1;
}

int main() {
	char line[128];

	dict_size = 0;
	while (gets(line)) {
		if (sscanf(line, "%s %s", dict[dict_size].eng, dict[dict_size].fore) == 2) {
			dict_size++;
		}
		else {
			break;
		}
	}

	qsort(dict, dict_size, sizeof(DictEntry), str_compare); 

	while (gets(line)) {
		int idx = binary_search(dict, line);
		(idx == -1) ? puts("eh") : puts(dict[idx].eng);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
