#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

typedef struct song_node {
	char name[100];
	char artist[100];
	struct song_node *next;
} song_node;

song_node *create_song(char *artist, char *name)
{
	song_node *node = malloc(sizeof(song_node));
	strcpy(node->name, name);
	strcpy(node->artist, artist);

	node->next = NULL;

	return node;
}

int len(song_node *node)
{
	int size = 0;
	
	while (node)
	{
		node++;
		size++;
	}
	
	return size;
}

song_node *insert_front(song_node *node, char *artist, char *name)
{
	song_node *front = create_song(node, artist);
	front->next = node;

	return front;
}

int compare(const song_node *a, const song_node *b)
{
	return strcmp(a->artist, b->artist) == 0 ? 
		   strcmp(a->name, b->name) : strcmp(a->artist, b->artist);
}

int compare_data(const song_node *a, char *artist, char *name)
{
	return strcmp(a->artist, artist) == 0 ? 
		   strcmp(a->name, name) : strcmp(a->artist, artist);
}


song_node *insert_order(song_node *node, char *artist, char *name)
{
	song_node *front = node;
	song_node *insert = create_song(name, artist);
	
	if (node == NULL || compare(insert, node) <= 0)
	{
		insert->next = front;
		return insert;
	}
	
	while (node->next)
	{
		if (compare(insert, node->next) <= 0)
		{
			insert->next = node->next;
			node->next = insert;
			return front;
		}
	}
	
	node->next = insert;
	return front;
}

void print_list(song_node *node)
{
	printf("[ ");
	
	while (node)
	{
		printf("%s, %s", node->artist, node->name);
		                                                                                                                                                                                                                         
	}
	
	printf(" ]");
}

song_node *find(song_node *node, char *artist, char *name)
{
	while (node)
	{ 
		if (compare_data(node, artist, name) == 0) 
		{
			return node;
		}
		
		node = node->next;
	}
	
	return NULL;
}

song_node *find_first(song_node *node, char *artist)
{
	while (node)
	{ 
		if (strcmp(node->artist, artist) == 0) 
		{
			return node;
		}
		
		node = node->next;
	}
	
	return NULL;
}

song_node *find_rand(song_node *node, unsigned int seed)
{
	srand(seed);
}



