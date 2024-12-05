#include "inverted_search.h"

int insert_to_hashtable(hasht *arr, int index, char *ip_fname, char *ip_word)
{
	// Create a mainnode
        Mnode *new = create_Mnode(ip_word);	
	if(new == NULL)
       	    	return FAILURE;
    	// Create a subnode
      	Snode *s_new = create_Snode(ip_fname);
       	if(s_new == NULL)
        	return FAILURE;
	// Check for link part of array
        if(arr[index].link == NULL)
        {
                arr[index].link = new;
                (arr[index].link)->sublink = s_new;
                return SUCCESS;
        }
        Mnode *temp = arr[index].link,*bef = NULL;
        while(temp)
        {
		// Check if word in main and scan is same
                if(strcmp(temp->word,new->word) == 0)
                {
			Snode *trav = temp->sublink,*prev = NULL;
			while(trav)
			{	
				// Check if both words are from same file 
				if(strcmp(s_new->filename,trav->filename) == 0)
				{
					trav->wordcount ++;
					return SUCCESS;
				}
				else
				{
					prev = trav;
					trav = trav->sublink;
				}
			}
			prev->sublink = s_new;
			temp->filecount++;
			return SUCCESS;
		}	
		else
		{
			bef = temp;
			temp = temp->mainlink;
		}
	}
	bef->mainlink = new;
       	new->sublink = s_new;
    	return SUCCESS;
}

