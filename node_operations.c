#include "inverted_search.h"

int insert_at_last(Slist **head,Slist *new)
{
	if(*head == NULL)
        {
                *head = new;
                return SUCCESS;
        }
        Slist *temp = *head;
        while(temp->link != NULL)
                temp = temp->link;
        temp->link = new;
        return SUCCESS;
}

Mnode * create_Mnode(char *ip_word)
{
	Mnode *new = malloc(sizeof(Mnode));
	if(new == NULL)
		return NULL;
	new->filecount = 1;
	strcpy(new->word, ip_word);
	new->mainlink = NULL;
	new->sublink = NULL;
	return new;
}

Snode * create_Snode(char *ip_fname)
{
        Snode *s_new = malloc(sizeof(Snode));
        if(s_new == NULL)
                return NULL;
        s_new->wordcount = 1;
	strcpy(s_new->filename, ip_fname);
        s_new->sublink = NULL;
        return s_new;
}

void print_list(Slist *head)
{
	if(head == NULL)
	{
		printf("INFO : List is empty\n");
	}
 	else
 	{
		while (head)
		{
		    	printf("%s -> ", head -> fname);
		   	head = head -> link;
		}
		printf("NULL\n");
    	}
}

void display_HT(hasht *arr, int size)
{
    Mnode *temp;
    int flag;
    printf("%-25s%-25s%-25s%-25s%-25s\n","INDEX","WORD","FILE COUNT","FILE NAME","WORD COUNT");
    for(int i = 0; i < size; i++)
    {
        temp = arr[i].link;
	if(arr[i].link == NULL)
		continue;
        while(temp)
        {
	    	    
       	    printf("%-25d", i);
            printf("%-25s",temp->word);
	    printf("%-25d",temp->filecount);
	    Snode *trav = temp->sublink;
	    while(trav)
	    {
		    if(flag > 0)
		    {
			for (int i = 0; i < 75; i++)
                    	{
                        	printf(" ");
                    	}
		    	printf("%-25s%-25d\n",trav->filename,trav->wordcount);
		    }
		    else
		    	printf("%-25s%-25d\n",trav->filename,trav->wordcount);
		    trav = trav->sublink;
		    flag ++;
	    }
	    flag = 0;
            temp = temp->mainlink;
        }
    }
}

void check_list(Slist **head,char *filename)
{
	Slist *temp,*temp1=NULL;
    	temp = *head;
    	while(temp != NULL)
    	{
   		if(strcmp(temp->fname,filename) != 0)
        	{
        	    temp1 = temp;
        	    temp = temp->link;
        	}
        	else
        	{
        	    	if(temp1 == NULL)
        	    	{
        	        	*head = temp->link;
                		free(temp);
				break;
           		}
			else	
			{	
            			temp1->link = temp->link;
				free(temp);
				break;
			}

        	}
    	}
}
