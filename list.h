#ifndef LIST_H
#define LIST_H



typedef struct song_node {
    char name[100];
    char artist[100];
    struct song_node *next;
} song_node;

#endif
