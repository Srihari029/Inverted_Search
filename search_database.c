#include "inverted_search.h"

int search_database(hasht *arr,char *search,int size)
{
	int index,i;
	if(isdigit(search[0]))
      		index = 26;
      	// For punctuations
   	else if(ispunct(search[0]))
          	index = 27;
    	else
      		index = tolower(search[0]) % 97;
	
	// If array link is null
	if(arr[index].link == NULL)
	{
		printf("Word not found in database!\n");
		return FAILURE;
	}
	Mnode *temp = arr[index].link;
	while(temp)
	{
		if(strcmp(temp->word,search) == 0)
		{
			printf("'%s' is present %d times in files : ",search,temp->filecount);
			Snode *trav = temp->sublink;
			while(trav)
			{
				printf("%s - %d times ",trav->filename,trav->wordcount);
				trav = trav->sublink;
			}
			return SUCCESS;
		}
		temp = temp->mainlink;
	}
	printf("Word not found in database!\n");
	return FAILURE;
}

