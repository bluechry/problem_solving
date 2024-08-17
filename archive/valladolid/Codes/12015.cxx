#include <iostream>
#include <cstdio>

using namespace std;

typedef struct {
	char site[128];
	int	 relevance;
} SiteInfo;

int main()
{
	int num_cases;

	scanf("%d\n", &num_cases);

	for (int i = 1; i <= num_cases; i++) {

		printf("Case #%d:\n", i);

		SiteInfo siteInfo[16];

		for (int j = 0; j < 10; j++) {
			scanf("%s %d\n", &siteInfo[j].site[0], &siteInfo[j].relevance);
		}

		int max = siteInfo[0].relevance;
		for (int i = 1; i < 10; i++) {
			if (siteInfo[i].relevance > max) {
				max = siteInfo[i].relevance;
			}
		}

		for (int i = 0; i < 10; i++) {
			if (siteInfo[i].relevance == max) {
				printf("%s\n", siteInfo[i].site);
			}
		}
	}
	
	return 0;
}
