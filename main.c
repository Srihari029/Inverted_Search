/***************************************************************************************************************************************************
*Author		:Emertxe(http://www.emertxe.com)
*Date		:Mon 22 May 2017 14:00:05 IST
*File		:main.c
*Title		:Driver function
*Description	:This function acts like the driver function for the project inverted search
****************************************************************************************************************************************************/
#include "inverted_search.h"

int main(int argc, char *argv[])
{
	Slist *head = NULL;
	char search_word[30];
	// Input validation
	if(input_from_user(argv,argc,&head) == SUCCESS)
	{

		int size = 28,up = 0,cr = 0;
		hasht array[size];
		// Create hash table
		if(create_hashtable(array,size) == SUCCESS)
		{
			printf("INFO : Hashtable creation success!\n");	
		}
		else
		{
			printf("INFO : Hashtable creation failed!\n");
		}
		char ch;
		int opt;
		while(1)
		{

			printf("1. Create Database\n2. Display Database\n3. Search Database\n4. Update Database\n5. Save Database\n6. Exit\n");
			while(1)
			{
				printf("Enter the option : ");
				if(scanf("%d",&opt) == 1)
				{
					while((ch = getchar()) != '\n' && ch != EOF);
					break;
				}
				else
				{
					printf("Enter a valid option\n");
					while((ch = getchar()) != '\n' && ch != EOF);
				}
			}
			switch(opt)
			{
				case 1:
					if(cr == 1)
					{
						printf("INFO : Database already created\n");
						break;
					}
					
					if(create_database(array,&head) == SUCCESS)
					{
						printf("INFO : Create database success!\n");	
					}
					else
					{
						printf("INFO : Create database failed!\n");
					}
					cr = 1;
					break;
				case 2: 
					display_HT(array, size);
					break;
				case 3:
					printf("Enter a Word to search : ");
					scanf(" %s",search_word);
					if(search_database(array,search_word,size) == SUCCESS)
                                        {
						printf("\n");
                                                printf("INFO : Search database success!\n");
                                        }
                                        else
                                        {
                                                printf("INFO : Search database failed!\n");
                                        }
                                        break;
				case 4:
				 	if(up == 1 || cr == 1)
					{
						printf("INFO : Database already created\n");
						break;
					}
					if(update_database(array,size,&head) == SUCCESS)
                                        {
                                                printf("INFO : Update database success!\n");
                                        }
                                        else
                                        {
                                                printf("INFO : Update database failed!\n");
                                        }
					up = 1;
                                        break;
				case 5:
					if(save_database(array,size) == SUCCESS)
                                        {
                                                printf("INFO : Save database success!\n");
                                        }
                                        else
                                        {
                                                printf("INFO : Save database failed!\n");
                                        }
                                        break;
				case 6:
					return 0;
				default:
					printf("Enter a valid option\n");
			}
			if(opt == 6)
				break;
		}
	}
	else
	{
		printf("INFO : Input validation failed\n");
	}
	return 0;
}

