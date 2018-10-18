#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct song_node {
  char artist[256];
  char name[256];
  struct song_node *next;
};

struct song_node * table[27];

struct song_node * insert_front(struct song_node *, char *, char *);

struct song_node * insert_in_order(char *, char *);

void print_list(struct song_node *);

void print_node(struct song_node *);

//struct song_node * find_node(struct song_node *, struct song_node *);

struct song_node * find_node_list(struct song_node *, char *, char *);

struct song_node * find_artist_list(struct song_node *, char *);

struct song_node * get_random(struct song_node *);

struct song_node * remove_node(struct song_node *, struct song_node *);

struct song_node * free_list(struct song_node *);

#endif
