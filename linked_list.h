struct song_node {
  char artist[100];
  char name[100];
  struct song_node *next;
};

struct song_node * table[27];

struct song_node * insert_front(struct song_node *, char *);

struct song_node * insert_in_order(char *);

void print_list(struct song_node *);

void print_node(struct song_node *);

//struct song_node * find_node(struct song_node *, struct song_node *);

struct song_node * find_node(struct song_node *, char *, char *)

struct song_node * find_artist(struct song_node *, char *);

struct song_node * get_random(struct song_node *);

struct song_node * remove_node(struct song_node *, struct song_node *);

struct song_node * free_list(struct song_node *);
