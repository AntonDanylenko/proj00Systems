#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct song_node {
  char artist[256];
  char name[256];
  struct song_node *next;
};

//struct song_node * table[27];

//helper
void set_node(struct song_node *, char *, char *, struct song_node *);
//helper
struct song_node * find_first(struct song_node *, char*);

struct song_node * insert_front(char *, char *, struct song_node *);

struct song_node * insert_in_order(struct song_node *, char *, char *);

void print_list(struct song_node *);

void print_node(struct song_node *); //helper

struct song_node * list_find_node(struct song_node *, char *, char *);

struct song_node * list_find_artist(struct song_node *, char *);

struct song_node * get_random(struct song_node *);

struct song_node * remove_node(struct song_node *, char *, char *);

struct song_node * free_list(struct song_node *);

#endif
