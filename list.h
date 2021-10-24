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
int compare_date(const song_node *, char *, char *);
void print_list(const song_node *);
void print_list_artist(const song_node *, const char *);
void print_node(const song_node *);
song_node *insert_order(song_node *, const  char *, const  char *);
song_node *create_song(const char *, const char *);
song_node *insert_front(song_node *, char *, char *);
song_node *find(const song_node *, const char *, const char *);
song_node *find_first(const song_node *, const char *);
song_node *find_rand(const song_node *);
song_node *free_list(const song_node *);
song_node *remove_song(const song_node *, const  char *, const char *);

#endif
