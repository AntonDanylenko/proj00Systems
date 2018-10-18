#ifndef LIBRARY_H
#define LIBRARY_H

void add_song(struct song_node **, char *, char *);
void print_library(struct song_node **);
void print_letter(struct song_node **, char);
struct song_node * find(struct song_node **, char *, char *);
struct song_node * find_artist(struct song_node **, char *);
void remove_song(struct song_node **, char *, char *);
void clear_library(struct song_node **);
void print_artist(struct song_node **, char *);
void shuffle(struct song_node **);

#endif
