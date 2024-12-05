#include "inverted_search.h"

// Function to create hash table
int create_hashtable(hasht *arr,int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		arr[i].key = i;
		arr[i].link = NULL;
	}
	return SUCCESS;
}
