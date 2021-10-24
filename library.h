#ifndef LIBRARY_H
#define LIBRARY_H

#include "list.h"

typedef struct library
{
	song_node *data[27];
} library;

library *create_lib();
library *add_song(const char *, const char *)
#endif