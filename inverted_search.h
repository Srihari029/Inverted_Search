#ifndef IS_H
#define IS_H

#define SUCCESS 1
#define FAILURE 0

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct node
{
	char *fname;
	struct node *link;
}
Slist;

typedef struct subnode
{
	int wordcount;
	char filename[30];
	struct subnode *sublink;
}
Snode;

typedef struct mainnode
{
        int filecount;
        char word[50];
        struct mainnode *mainlink;
        Snode *sublink;
}
Mnode;

typedef struct hast
{
        int key;
        Mnode *link;
}
hasht;

/* Function Prototype */

/* Main function */
int main(int argc, char *argv[]);
/* User input validation */
int input_from_user(char *argv[],int argc,Slist **head);
/* Function to add name at last in list */
int insert_at_last(Slist **head,Slist *new);
/* Print node */
void print_list(Slist *head);
/* Function to create hash table */
int create_hashtable(hasht *arr,int size);
/* Create mainnode */
Mnode * create_Mnode(char *ip_word);
/* Create subnnode */
Snode * create_Snode(char *ip_fname);
/* Function to create database */
int create_database(hasht *arr,Slist **head);
/* Function to insert word to hashtable */
int insert_to_hashtable(hasht *arr, int index, char *ip_fname, char *ip_word);
/* Function to display hash table */
void display_HT(hasht *arr, int size);
/* Function to search database */
int search_database(hasht *arr,char *search, int size);
/* Function to save database to a file */
int save_database(hasht *arr,int size);
/* Function to update database */
int update_database(hasht *arr,int size, Slist **head);
/* Function to check list and database */
void check_list(Slist **head,char *filename);

#endif
