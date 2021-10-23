#ifndef LIBRARY_H
#define LIBRARY_H

typedef struct library {
	song_node **data;
} library;

library *create_lib();

#endif