/* @JUDGE_ID: andrea 484 C "Search" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <stdlib.h>

/*
 * Definitions of Types
 */
typedef struct {
	int value; 
	int	count;
} Elem; 

typedef struct {
	int 	length;
	int		num_elems;
	Elem*	array;
} VarArray;


/*
 * Definitions of Interfaces
 */
int VarArray_Init(VarArray* , int );
int VarArray_Final(VarArray* );
int VarArray_Extend(VarArray*, int );
int VarArray_Dump(VarArray* );

int VarArray_Init(VarArray* varArray, int length)
{
	varArray->array		= (Elem* )malloc(sizeof(Elem) * length);
	if (varArray->array == NULL) {
		return -1;
	}

	varArray->length 	= length;
	varArray->num_elems = 0;
	
	return 0;
}

int VarArray_Final(VarArray* varArray)
{
	free(varArray->array);
	varArray->length	= 0;
	varArray->num_elems = 0;

	return 0;
}

int VarArray_Extend(VarArray* varArray, int length)
{
	Elem*	temp;

	temp = varArray->array;
	varArray->array = (Elem* )realloc(varArray->array, sizeof(Elem) * length);
	if (varArray->array == NULL) {
		return -1;
	}

	if (temp != varArray->array) {
		free(temp);
	}

	varArray->length = length;
	
	return 0;
}

int VarArray_Insert(VarArray* varArray, Elem* elem)
{
	int num_elems;
	int	ret;	

	num_elems = varArray->num_elems;
	if (num_elems >= varArray->length) {
		ret = VarArray_Extend(varArray, 2 * num_elems);
		if (ret < 0) {
			return -1;
		}
	}

	varArray->array[num_elems] = *elem;
	varArray->num_elems++;
	
	return 0; 
}

int VarArray_Dump(VarArray* varArray)
{
	int i, num_elems;

	num_elems = varArray->num_elems;
	for (i = 0; i < num_elems; i++) {
		printf("%d %d\n", varArray->array[i].value, varArray->array[i].count);
	}
	
	return 0;	
}

int main()
{
	VarArray	freq_num;
	Elem		elem;
	int			num, i;

	VarArray_Init(&freq_num, 4096);

	while (scanf("%d", &num) != EOF) {

		for (i = 0; i < freq_num.num_elems; i++) {
			if (freq_num.array[i].value == num) {
				break;
			}	
		}

		if (i == freq_num.num_elems) {
			elem.value = num;
			elem.count = 1;

			VarArray_Insert(&freq_num, &elem);
		}
		else {
			freq_num.array[i].count++; 
		}
	}

	VarArray_Dump(&freq_num);

	VarArray_Final(&freq_num);

	return 0;		
}

/* @END_OF_SOURCE_CODE */
