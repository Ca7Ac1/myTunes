#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

song_node * free_list(song_node *list) {
    song_node *start = list;
    while(list) {
        song_node *next = list->next;
        free(list);
        list = next;
    }
    return start;
}

song_node *remove_song(song_node *list, char *artist, char *name) {
    if(compare_data(list, artist, name) == 0) {
        song_node * l = list->next;
        free(list);
        return l;
    }

    song_node *l = list;
    while (l->next) {
        if(compare_data(l->next, artist, name) == 0) {
            song_node *p = l->next;
            l->next = l->next->next;
            free(p);
            return list;
        }
        l = l->next;
    }
    return list;
}

