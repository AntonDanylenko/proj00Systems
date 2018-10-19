#ifndef LIBRARY_H
#define LIBRARY_H

struct song_node * table[27];

int find_index(char);

void add_song( char *, char *);

void find(char *, char *);

void find_artist(char *);

void print_library_letter(int);

void print_letter(char);

void print_artist(char *);

void print_library();

void shuffle();

void remove_song(char *, char *);

void clear_library();

#endif
