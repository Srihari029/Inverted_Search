#include "inverted_search.h"

int create_database(hasht *arr,Slist **head)
{
	int index;
        Slist *temp = *head;
        char tempword[30];
        while(temp)
        {
		// Open file in read mode
                FILE *fp = fopen(temp->fname,"r");
                if(fp == NULL)
                {
                        printf("INFO : File for index cannot be opened\n");
                        return FAILURE;
                }
		else
		{
			printf("INFO : File for index open\n");
		}
                while(fscanf(fp,"%s",tempword) == 1)
		{
			// For digit
			if(isdigit(tempword[0]))
				index = 26;
			// For punctuations
			else if(ispunct(tempword[0]))
				index = 27;
			else
                        	index = tolower(tempword[0]) % 97;

			// Insert the data to database
			if(insert_to_hashtable(arr,index,temp->fname,tempword) == SUCCESS)
			{
				printf("INFO : Word added to database\n");
			}
			else
			{
				printf("INFO : Word to database failed!\n");
				return FAILURE;
			}
                }
		// Close file
		fclose(fp);
		temp = temp->link;
	}
	return SUCCESS;
}
