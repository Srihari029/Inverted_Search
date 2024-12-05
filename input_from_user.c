/***************************************************************************************************************************************************
*Author         :Emertxe(http://www.emertxe.com)
*Date           :Mon 22 May 2017 14:20:10 IST
*File           :input_from_user.c
*Title          :To read the input from the user.
*Description    :The search phase is going to begin. To search, collect the user input text. It should be
		:stored in a character string.
****************************************************************************************************************************************************/
#include "inverted_search.h"

int input_from_user(char *argv[],int argc,Slist **head)
{
	int i;
	char *txt;
	if(argc < 2)
        {
                printf("FORMAT : ./a.out  <file-1>  <file-2>  ...  <file-n>\n");
                return FAILURE;
        }
	for(i = 1; i < argc; i++)
	{
		txt = strstr(argv[i],".txt");
		if((txt != NULL) && (strcmp(txt,".txt") == 0)) 
		{
			printf("INFO : File extension at argument %d is valid\n",i);
			FILE *fname = fopen(argv[i],"r");
			if(fname != NULL)
			{
				printf("INFO : File at argument %d open success\n",i);
				fseek(fname,0,SEEK_END);
				if(ftell(fname) != 0)
				{
					// Create node
					Slist *new = malloc(sizeof(Slist));
					new->fname = argv[i];
					new->link = NULL;
					if(*head == NULL)
					{
						*head = new;
						printf("INFO : File name at argument %d added to list\n",i);
					}
					else
					{
						Slist *temp = *head;
						while(temp != NULL)
						{
							if(strcmp(temp->fname,argv[i]) == 0)
							{
								printf("INFO : File at %d already exist in list\n",i);
								return FAILURE;
							}
							else
								temp = temp->link;
						}
						// insert the name at last
						insert_at_last(head,new);
					}
				}
				else
				{
					printf("INFO : File at argument %d is empty\n",i);
					return FAILURE;
				}
				rewind(fname);
			}
			else
			{
				printf("INFO : File at argument %d open failed !\n",i);
				return FAILURE;
			}
		}
		else
		{
			printf("INFO : File extension at argument %d invalid !\n",i);
			return FAILURE;	
		}
	}
	return SUCCESS;
}

