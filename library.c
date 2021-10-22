#include <stdio.h>
#include <stdlib.h>

#include "list.h"


typedef struct library {
	song_node **data;
} library;

library *create_lib() {
	library *lib = malloc(sizeof(library));
	lib->data = malloc(27*sizeof(song_node *);
	int i;
	for(i = 0; i < 27; i++) {
		lib[i] = NULL;			
	}
}


