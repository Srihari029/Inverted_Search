#include "inverted_search.h"

int save_database(hasht *arr,int size)
{
	char save_file[30],*txt;
	int i;
	// Database file name to save
	printf("Enter file name : ");
	scanf(" %s",save_file);
	// Check for .txt extension
	txt = strstr(save_file,".txt");
        if((txt != NULL) && (strcmp(txt,".txt") == 0))
       	{
         	printf("INFO : Save file extension valid\n");
	}
	else
	{
		printf("Enter file with .txt extension\n"); 
		printf("INFO : Save extension invalid");
		return FAILURE;
	}
	FILE *sfp = fopen(save_file,"w");
	if(sfp == NULL)
		return FAILURE;
	Mnode *temp;
    	for(int i = 0; i < size; i++)
    	{
	    if(arr[i].link == NULL)
		    continue;
    	    temp = arr[i].link;
    	    while(temp)
    	    {
    	    	fprintf(sfp,"#%d;", i);
            	fprintf(sfp,"%s;",temp->word);
            	fprintf(sfp,"%d",temp->filecount);
        	    Snode *trav = temp->sublink;
       	     	while(trav)
       	    	{
        	            fprintf(sfp,";%s;%d",trav->filename,trav->wordcount);
                	    trav = trav->sublink;
            	}
            	temp = temp->mainlink;
            	fprintf(sfp,"#\n");
            }
    	}
	fclose(sfp);
	return SUCCESS;
}
