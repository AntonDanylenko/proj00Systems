struct song_node{ 
  char artist[100];
  char name[100];
  struct song_node *next;
};

struct song_node * table[27];
