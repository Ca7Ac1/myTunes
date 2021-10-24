#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "list.h"

song_node *create_song(const char *artist, const char *name)
{
	song_node *node = malloc(sizeof(song_node));
	strcpy(node->name, name);
	strcpy(node->artist, artist);

	node->next = NULL;

	return node;
}

int len(const song_node *node)
{
	int size = 0;

	while (node)
	{
		node = node->next;
		size++;
	}

	return size;
}

song_node *insert_front(const song_node *node, const char *artist, const char *name)
{
	song_node *front = create_song(artist, name);
	front->next = node;

	return front;
}

int compare(const song_node *a, const song_node *b)
{
	return strcasecmp(a->artist, b->artist) == 0 ? strcasecmp(a->name, b->name) : strcasecmp(a->artist, b->artist);
}

int compare_data(const song_node *a, const char *artist, const char *name)
{
	return strcasecmp(a->artist, artist) == 0 ? strcasecmp(a->name, name) : strcasecmp(a->artist, artist);
}

song_node *insert_order(song_node *node, const char *artist, const char *name)
{
	song_node *front = node;

	if (node == NULL || compare_data(node, artist, name) <= 0)
	{
		return insert_front(node, artist, name);
	}

	while (node->next)
	{
		if (compare_data(node->next, artist, name) <= 0)
		{
			node->next = insert_front(node->next, artist, name);
			return front;
		}
		node = node->next;
	}

	node->next = create_song(artist, name);
	return front;
}

void print_list(const song_node *node)
{
	printf("[ ");

	while (node)
	{
		print_node(node);

		if (node->next)
		{
			printf(" | ");
		}
		
		node = node->next;
	}

	printf(" ]");
}

void print_list_artist(const song_node *node, const char *artist)
{
	node = find_first(node, artist);
	
	printf("[ ");

	while (node)
	{
		print_node(node);

		if (node->next)
		{
			printf(" | ");
		}
		
		node = node->next;
	}

	printf(" ]");
}

void print_node(const song_node *node)
{
	printf("{%s, %s}", node->artist, node->name);
}

song_node *find(const song_node *node, const char *artist, const char *name)
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

song_node *find_first(const song_node *node, const char *artist)
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

song_node *find_rand(const song_node *node)
{
	srand(time(NULL));

	int i;
	for (i = rand() % len(node); i > 0; i--)
	{
		node = node->next;
	}

	return node;
}

song_node *free_list(song_node *list)
{
	song_node *start = list;
	while (list)
	{
		song_node *next = list->next;
		free(list);
		list = next;
	}
	return start;
}

song_node *remove_song(song_node *list, char *artist, char *name)
{
	if (compare_data(list, artist, name) == 0)
	{
		song_node *l = list->next;
		free(list);
		return l;
	}

	song_node *l = list;
	while (l->next)
	{
		if (compare_data(l->next, artist, name) == 0)
		{
			song_node *p = l->next;
			l->next = l->next->next;
			free(p);
			return list;
		}
		l = l->next;
	}
	return list;
}
