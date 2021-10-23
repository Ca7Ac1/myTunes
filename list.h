#ifndef LIST_H
#define LIST_H

typedef struct song_node {
    char name[100];
    char artist[100];
    struct song_node *next;
} song_node;

song_node *create_song(char *, char *);
int len(song_node *);
song_node *insert_front(song_node *, char *, char *);

int compare(const song_node *,const song_node *);
int compare_date(const song_node *, char *, char *);

song_node *insert_order(song_node *, char *, char *);
void print_list(song_node *);
void print_node(song_node *);

song_node *find(song_node *, char *, char *);
song_node *find_first(song_node *, char *);
song_node *find_rand(song_node *, unsigned int);

song_node *free_list(song_node *);
song_node *remove_song(song_node *, char *, char *);

#endif
