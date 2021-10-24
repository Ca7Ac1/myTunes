#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "library.h"
#include "list.h"


library *create_lib()
{
	library *lib = malloc(sizeof(library));

	int i;
	for (i = 0; i < 27; i++)
	{
		lib->data[i] = NULL;
	}

	return lib;
}

int get_index(char *artist)
{
	return tolower(*artist) < 'a' || twolower(*artist) > 'z' ? 26 : tolower(*artist) - 'a';
}

library *add_song(library *lib, const char *artist, const char *name)
{
	int index = get_index(artist);
	insert_order(lib->data[index], artist, name);

	return lib;
}

song_node *search_song(const library *lib, const char *artist, const char *name)
{
	return find(lib->data[get_index(artist)], artist, name);
}

song_node *search_artist(const library *lib, const char *artist)
{
	return find_first(lib->data[get_index(artist)], artist);
}

void print_lib_entries(const library *lib, char letter)
{
	print_list(lib->data[get_index(&letter)]);
}

void print_lib_artist(const library *lib, char *artist)
{
	print_list_artist(lib->data[get_index(artist)], artist);
}

void print_lib(const library *lib)
{
	int i;
	for (i = 0; i < 27; i++)
	{
		print_list(lib->data[i]);
		printf("\n");
	}
}

void shuffle()
{

}

library *delete_song(library *lib, const char *artist, const char *name)
{
	delete_song(lib->data[get_index(artist)], artist, name);
}

library *free(library *lib)
{
	int i;
	for (i = 0; i < 27; i++)
	{
		free_list(lib->data[i]);
	}

	free(lib);
	return NULL;
}