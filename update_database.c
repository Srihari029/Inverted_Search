#include "inverted_search.h"

int update_database(hasht *arr,int size,Slist **head)
{
	int fcount, wcount, i, index;
	char fname[30], *txt, start[2], end[2], word[50], filename[50];
	FILE *fp;
	printf("Enter database_file name : ");
	scanf(" %s",fname);
	txt = strstr(fname,".txt");
        if((txt != NULL) && (strcmp(txt,".txt") == 0))
        {
                printf("INFO : Database file extension valid\n");
        }
        else
        {
                printf("Enter file with .txt extension\n");
                printf("INFO : Database file extension invalid");
                return FAILURE;
        }
	// Open file in read mode
	fp = fopen(fname,"r");
	if(fp == NULL)
	{
		printf("INFO : Database file opening failed\n");
		return FAILURE;
	}
	
	while(feof)
	{
		fscanf(fp,"#%d;",&index);
		// Get index value
		if(fscanf(fp,"%[^;];%d",word,&fcount) != 2)
		{
			
			fclose(fp);
			return SUCCESS;
		}
		Mnode *new = create_Mnode(word);
		if(new == NULL)
		{
			printf("INFO : Memory for Mnode failed\n");
			return FAILURE;
		}
		new->filecount = fcount;
		if(arr[index].link == NULL)
		{
			arr[index].link = new;
		}
		else
		{
			Mnode *temp = arr[index].link;
			while(temp->mainlink)
			{
				temp = temp->mainlink;
			}
			temp->mainlink = new;
		}
		// Subnode
		for(i = 0;i < fcount; i++)
		{
			if(fscanf(fp,";%[^;];%d",filename,&wcount) != 2)
			{
				printf("INFO : filename wordcount failed\n");
				fclose(fp);
				return FAILURE;
			}
			// Check and delete similar files
			check_list(head,filename);
			Snode *snew = create_Snode(filename);
			if(snew == NULL)
			{
				printf("INFO : Memory for Snode failed\n");
				return FAILURE;
			}
			snew->wordcount = wcount;
			if(new->sublink == NULL)
			{
				new->sublink = snew;
			}
			else
			{
				Snode *trav = new->sublink;
				while(trav->sublink)
				{
					trav = trav->sublink;
				}
				trav->sublink = snew;
			}
		}
		fscanf(fp, "#\n");
	}
	fclose(fp);
	return SUCCESS;
}
