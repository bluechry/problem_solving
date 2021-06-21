/* @JUDGE_ID: andrea 10142 C "Simulation" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CAND	20
#define MAX_VOTER	1000
#define MAX_NAME	80

void open_votes(int (*votes)[MAX_CAND + 1], char (*cand_name)[MAX_NAME + 1], int num_voter, int num_cand)
{
	int first_alive_cand[MAX_VOTER + 1];
	int votes_to_get[MAX_VOTER + 1];
	int min, max, who_is_max;
	int is_all_tied, is_winner;
	int i, cand_id; 
	

	/* Init votes to get */	
	memset(votes_to_get, 0x00, sizeof(int) * (MAX_VOTER + 1));
	
	/* Init first_alive_cand */
	for (i = 1; i <= num_voter; i++) {
		first_alive_cand[i] = 1;
	}

	/* Open first votes */
	for (i = 1; i <= num_voter; i++) {
		cand_id = votes[i][first_alive_cand[i]];
		votes_to_get[cand_id]++;
	}

	/* Open rest votes */
	is_all_tied = is_winner = 0;
	while (1) {
		/* Find minimum votes and maximum votes */
		max = 0, min = num_voter;
		for (i = 1; i <= num_cand; i++) {
			max = (votes_to_get[i] >= 0 && votes_to_get[i] > max) ? who_is_max = i, votes_to_get[i] : max;
			min = (votes_to_get[i] >= 0 && votes_to_get[i] < min) ? votes_to_get[i] : min;
		}

		if (max == min) {
			is_all_tied = 1;
			break;
		}
		else if (max * 2 > num_voter) {
			is_winner = 1;
			break;
		}

		for (i = 1; i <= num_voter; i++) {
			if (votes_to_get[votes[i][first_alive_cand[i]]] == min) {
				first_alive_cand[i]++;
				while (votes_to_get[votes[i][first_alive_cand[i]]] <= min) {
					first_alive_cand[i]++;
				}

				votes_to_get[votes[i][first_alive_cand[i]]]++;
			}
		}

		for (i = 1; i <= num_cand; i++) {
			if (votes_to_get[i] == min) {
				votes_to_get[i] = -1;
			}
		}
	}	

	if (is_all_tied == 1) {
		for (i = 1; i <= num_cand; i++) {
			if (votes_to_get[i] > 0) {
				printf("%s\n", &cand_name[i][0]);
			}
		}
	}
	else {
		printf("%s\n", &cand_name[who_is_max][0]);
	}

	return;
}

int main()
{
	int  votes[MAX_VOTER + 1][MAX_CAND + 1];
	char cand_name[MAX_CAND + 1][MAX_NAME + 1];
	int  num_case, num_cand, num_voter;
	char line[MAX_NAME + 1], *ptr;
	int  voter_id, i;

	
	/* Receive Inputs */
	gets(line);
	num_case = atoi(line);
	gets(line);

	while (num_case-- > 0) {
		gets(line);
		num_cand = atoi(line);

		for (i = 1; i <= num_cand; i++) {
			gets(&cand_name[i][0]);
		}

		voter_id = 1;
		while (gets(line) != NULL && line[0] != '\0') {
			ptr = line;
			for (i = 1; i <= num_cand; i++) {
				votes[voter_id][i] = atoi(ptr);
				while (*ptr != ' ') ptr++;
				if (*ptr != '\0') ptr++;
			}
		
			voter_id++;
		}
		num_voter = voter_id - 1;

		open_votes(votes, cand_name, num_voter, num_cand);

		if (num_case != 0) {
			printf("\n");
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
