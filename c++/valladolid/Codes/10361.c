/* @JUDGE_ID: andrea 10361 C "Ad Hoc" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <string.h>

int main()
{
	char	line1[128], line2[128];
	char	*s1, *s2, *s3, *s4, *s5;
	char	*ptr;
	int		num_cases;

	scanf("%d\n", &num_cases);

	while (num_cases-- > 0) {

		gets(&line1[0]);
		gets(&line2[0]);

		s1 = &line1[0];
		ptr = strchr(s1, '<');
		*ptr = '\0';
		
		s2 = ++ptr;
		ptr = strchr(s2, '>');
		*ptr = '\0';

		s3 = ++ptr;
		ptr = strchr(s3, '<');
		*ptr = '\0';

		s4 = ++ptr;
		ptr = strchr(s4, '>');
		*ptr = '\0';

		s5 = ++ptr;

		ptr = &line2[0];
		ptr = ptr + strlen(line2) - 3;
		*ptr = '\0';
	
		printf("%s%s%s%s%s\n", s1, s2, s3, s4, s5);	
		printf("%s%s%s%s%s\n", line2, s4, s3, s2, s5);
	}	

	return 0;		
}

/* @END_OF_SOURCE_CODE */
