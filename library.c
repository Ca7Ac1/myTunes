#include <stdio.h>
#include <stdlib.h>

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
