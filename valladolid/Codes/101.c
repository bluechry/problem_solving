/* @JUDGE_ID: andrea 101 C "Simple Iteration" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <string.h>

/* Data Strucutres */
typedef struct _block {
	int 	block_id;
	int 	cur_pos;
	struct _block* prev;
	struct _block* next;
} block;

typedef struct _table {
	block*	head;
	block*	tail;
} table;

#define MAX_BLOCKS	32

block	block_pool[MAX_BLOCKS];
table	flat_table[MAX_BLOCKS];	


/* Helper Functions */
void init(int num_blocks)
{
	int i;

	for (i = 0; i < num_blocks; i++) {
		block_pool[i].block_id 	= i;
		block_pool[i].cur_pos 	= i;
		block_pool[i].prev		= NULL;
		block_pool[i].next 		= NULL;

		flat_table[i].head = &block_pool[i];
		flat_table[i].tail = &block_pool[i];
	}

	return;
}

int check_valid(int block_id1, int block_id2)
{
	if (block_pool[block_id1].cur_pos == block_pool[block_id2].cur_pos) {
		return 0;
	}

	return 1;
}

void rearrange(block* pBlock)
{
	block* ptr = pBlock;
	block* nextPtr;

	if (ptr == NULL) {
		return;
	}

	/* Head & Tail link of flat_table */	
	if (ptr->prev == NULL) {
		flat_table[ptr->cur_pos].head = NULL;
	}
	flat_table[ptr->cur_pos].tail = ptr->prev;

	/* Remove the subchain which starts with pBlock */
	if (ptr->prev != NULL) {
		(ptr->prev)->next = NULL;
	}

	/* Put blocks in the subchain to original positions */
	while (ptr != NULL) {
		nextPtr = ptr->next;
		
		ptr->prev = NULL;
		ptr->next = NULL;

		ptr->cur_pos = ptr->block_id;

		flat_table[ptr->cur_pos].head = ptr;
		flat_table[ptr->cur_pos].tail = ptr;

		ptr = nextPtr;
	}
	
	return;
}

void move_onto(int src_block_id, int tgt_block_id)
{
	block* src;
	block* tgt;

	src = &block_pool[src_block_id];
	tgt = &block_pool[tgt_block_id];

	rearrange(src->next);
	rearrange(tgt->next);

	/* Head & Tail link of flat_table */
	if (src->prev == NULL) {
		flat_table[src->cur_pos].head = NULL;
	}
	flat_table[src->cur_pos].tail = src->prev;

	/* Remove src block */
	if (src->prev != NULL) {
		(src->prev)->next = NULL;
	}

	/* Put src block behind tgt block */
	src->prev = tgt;
	src->cur_pos = tgt->cur_pos;
	tgt->next = src;

	/* Head & Tail link of flat_table */
	flat_table[tgt->cur_pos].tail = src;	

	return;
}

void move_over(int src_block_id, int tgt_block_id)
{
	block* src;
	block* tgt;

	src = &block_pool[src_block_id];
	tgt = flat_table[block_pool[tgt_block_id].cur_pos].tail;

	rearrange(src->next);

	/* Head & Tail link of flat_table */
	if (src->prev == NULL) {
		flat_table[src->cur_pos].head = NULL;
	}
	flat_table[src->cur_pos].tail = src->prev;

	/* Remove src block */
	if (src->prev != NULL) {
		(src->prev)->next = NULL;
	}

	/* Put src block behind tgt block */
	src->prev = tgt;
	src->cur_pos = tgt->cur_pos;
	tgt->next = src;	

	/* Head & Tail link of flat_table */
	flat_table[tgt->cur_pos].tail = src;

	return;
}

void pile_onto(int src_block_id, int tgt_block_id)
{
	block* src;
	block* tgt;
	block* temp;

	src = &block_pool[src_block_id];
	tgt = &block_pool[tgt_block_id];

	rearrange(tgt->next);

	/* Head & Tail link of flat_table */
	temp = flat_table[src->cur_pos]. tail;

	if (src->prev == NULL) {
		flat_table[src->cur_pos].head = NULL;
	}
	flat_table[src->cur_pos].tail = src->prev;

	/* Remove src block */
	if (src->prev != NULL) {
		(src->prev)->next = NULL;
	}

	/* Put src block behind tgt block */
	src->prev = tgt;
	tgt->next = src;
	while (src != NULL) {
		src->cur_pos = tgt->cur_pos;
		src = src->next;
	}

	/* Head & Tail link of flat_table */
	flat_table[tgt->cur_pos].tail = temp;	

	return;
}

void pile_over(int src_block_id, int tgt_block_id)
{
	block* src;
	block* tgt;
	block* temp;

	src = &block_pool[src_block_id];
	tgt = flat_table[block_pool[tgt_block_id].cur_pos].tail;

	/* Head & Tail link of flat_table */
	temp = flat_table[src->cur_pos]. tail;

	if (src->prev == NULL) {
		flat_table[src->cur_pos].head = NULL;
	}
	flat_table[src->cur_pos].tail = src->prev;

	/* Remove src block */
	if (src->prev != NULL) {
		(src->prev)->next = NULL;
	}

	/* Put src block behind tgt block */
	src->prev = tgt;
	tgt->next = src;
	while (src != NULL) {
		src->cur_pos = tgt->cur_pos;
		src = src->next;
	}

	/* Head & Tail link of flat_table */
	flat_table[tgt->cur_pos].tail = temp;	

	return;
}

void print_blocks(int cur_pos)
{
	block* ptr;

	ptr = flat_table[cur_pos].head;

	while (ptr != NULL) {
		printf(" %d", ptr->block_id);
		ptr = ptr->next;
	}

	return;
}

int main()
{
	int 	num_blocks;
	char 	cmd[32], option[32];
	int		src_block_id, tgt_block_id;
	int		i;

	scanf("%d\n", &num_blocks);
	init(num_blocks);
	
	while (scanf("%s", &cmd[0]) != EOF && memcmp(cmd, "quit", 4) != 0) {
		scanf("%d %s %d\n", &src_block_id, &option[0], &tgt_block_id);

		if (check_valid(src_block_id, tgt_block_id) == 0) {
			continue;
		}

		if (memcmp(cmd, "move", 4) == 0) {
			if (memcmp(option, "onto", 4) == 0) {
				move_onto(src_block_id, tgt_block_id);
			}
			else {
				move_over(src_block_id, tgt_block_id);
			}
		}
		else {
			if (memcmp(option, "onto", 4) == 0) {
				pile_onto(src_block_id, tgt_block_id);
			}
			else {
				pile_over(src_block_id, tgt_block_id);
			}
		}
	}

	for (i = 0; i < num_blocks; i++) {
		printf("%d:", i);
		print_blocks(i);
		printf("\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
