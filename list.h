#ifndef LIST_H
#define LIST_H

typedef struct song_node
{
    char name[100];
    char artist[100];
    struct song_node *next;
} song_node;

int len(const song_node *);
int compare(const song_node *, const song_node *);
int compare_data(const song_node *, const char *, const char *);
void print_list(const song_node *);
void print_list_artist(song_node *, const char *);
void print_node(const song_node *);
song_node *insert_order(song_node *, const char *, const char *);
song_node *create_song(const char *, const char *);
song_node *insert_front(song_node *, const char *, const char *);
song_node *find(song_node *, const char *, const char *);
song_node *find_first(song_node *, const char *);
song_node *find_rand(song_node *);
song_node *free_list(song_node *);
song_node *remove_song(song_node *, const char *, const char *);

#endif
