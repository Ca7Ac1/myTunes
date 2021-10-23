#ifndef LIBRARY_H
#define LIBRARY_H

#include "list.h"

typedef struct library {
	song_node **data;
} library;

library *create_lib();

#endif