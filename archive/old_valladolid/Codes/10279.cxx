#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

#define SIZE	1 << 4

char map[SIZE][SIZE];
char click[SIZE][SIZE];

int count_bomb(int r, int c)
{
	int count;
	
	count = 0;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (map[r + i][c + j] == '*') count++;
		}
	}

	return count;
}

int main()
{
	int num_cases;
	scanf("%d\n", &num_cases);

	int size;
	bool is_first = true;
	while (num_cases-- > 0) {
		scanf("%d\n", &size);

		memset(&map[0][0],   '.', sizeof(char) * SIZE * SIZE);
		memset(&click[0][0], '.', sizeof(char) * SIZE * SIZE);

		// read map
		for (int i = 1; i <= size; i++) {
			gets(&map[i][1]);
			map[i][size + 1] = '.';	
		}

		// read click
		for (int i = 1; i <= size; i++) {
			gets(&click[i][1]);
			click[i][size + 1] = '.';
		}

		// check bombs
		bool find = false;
		for (int i = 1; i <= size; i++) {
			for (int j = 1; j <= size; j++) {
				if (click[i][j] == 'x') {
					switch (map[i][j]) {
					case '*':
						find = true;	
						break;
					case '.':
						map[i][j] = count_bomb(i, j) + '0';
						break;
					default:
						break;
					}
				}
			}
		}

		// output map
		if (is_first == true) {
			is_first = false;
		}
		else {
			printf("\n");
		}

		for (int i = 1; i <= size; i++) {
			for (int j = 1; j <= size; j++) {
				if (map[i][j] == '*' && find == false) {
					printf(".");	
				}
				else {
					printf("%c", map[i][j]);
				}
			}
			printf("\n");
		}
	}  

	return 0;
}
