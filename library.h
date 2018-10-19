#ifndef LIBRARY_H
#define LIBRARY_H

int find_index(char);

void add_song(struct song_node **, char *, char *);

struct song_node * find(struct song_node **, char *, char *);

struct song_node * find_artist(struct song_node **, char *);

void print_letter(struct song_node **, char);

void print_artist(struct song_node **, char *);

void print_library(struct song_node **);

void shuffle(struct song_node **);

void remove_song(struct song_node **, char *, char *);

void clear_library(struct song_node **);

#endif
