#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

#ifndef LIBRARY_C
#define LIBRARY_C

int find_index(char letter){
  if ((int)letter>0 && (int)letter<=26){
    return (int)(letter) - 1;
  }
  else{
    return 26;
  }
}

void add_song(struct song_node **library, char *artist_name, char *song_name){
  int index = find_index(artist_name[0]);
  insert_in_order(library[index], artist_name, song_name);
}

void print_library(struct song_node **library){
  for(int x=0; x<27; x++){
    printf("%c list\n", (char)x);
    print_list(library[x]);
  }
}

void print_letter(struct song_node **library, char letter){
  printf("%c list\n", letter);
  int index = find_index(letter);
  print_list(library[index]);
}

struct song_node * find(struct song_node **library, char *artist_name, char *song_name){
  int index = find_index(artist_name[0]);
  return list_find_node(library[index], artist_name, song_name);
}

struct song_node * find_artist(struct song_node **library, char *artist_name){
  int index = find_index(artist_name[0]);
  return list_find_artist(library[index], artist_name);
}

void remove_song(struct song_node **library, char *artist_name, char *song_name){
  int index = find_index(artist_name[0]);
  remove_node(library[index], artist_name, song_name);
}

void clear_library(struct song_node **library){
  for (int x=0; x<27; x++){
    free_list(library[x]);
  }
}

void print_artist(struct song_node **library, char *artist_name){
  int index = find_index(artist_name[0]);
  print_list(list_find_artist(library[index], artist_name));
}

void shuffle(struct song_node **library){
  int index0 = ( rand() % 27 );
  get_random(library[index0]);
  int index1 = ( rand() % 27 );
  get_random(library[index1]);
  int index2 = ( rand() % 27 );
  get_random(library[index2]);
}

#endif
