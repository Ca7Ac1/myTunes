#ifndef LIBRARY_H
#define LIBRARY_H

#include "list.h"

typedef struct library
{
	song_node *data[27];
} library;

int get_index(const char *);
library *create_lib();
library *add_song(library *, const char *, const char *);
library *delete_song(library *, const char *, const char *);
library *free_lib(library *);
song_node *search_song(const library *, const char *, const char *);
song_node *search_artist(const library *, const char *);
void print_lib_entries(const library *, char);
void print_lib_artist(const library *, char *);
void print_lib(const library *);
void shuffle(const library *);

#endif