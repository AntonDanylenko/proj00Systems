#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"
#include "library.h"

#ifndef LIBRARY_C
#define LIBRARY_C

int find_index(char *artist){
  int index = 0;
  if (artist[0] - 'A' > 25){
    index = 26;
  }
  return artist[0] - 'A';
}

void add_song(char *artist, char *song){
  int index = artist[0] - 'A';
  if (index<0 || index>=27){
    index = 26;
  }
  struct song_node *node = table[index];
  table[index] = malloc(sizeof(struct song_node *));
  table[index] = insert_in_order(node, artist, song);
}

void print_library(){
  for (int i=0; i<27; i++){
    print_library_letter(i);
  }
}

void print_library_letter(int index){
  if (table[index]){
    printf("%c \n", 'A' + index);
    print_list(table[index]);
  }
}

void print_letter(char a){
  printf("%c:", (char)a);
  print_list(table[a-'A']);
}

void find(char *artist, char *song){
  int check = find_index(artist);
  if (list_find_node(table[check],song,artist)){
    printf("Song found! ");
    print_node(list_find_node(table[check],song,artist));
    printf("\n");
  }
  else{
    printf("Song not found! \n");
  }
}

void find_artist(char *artist){
  int check = find_index(artist);
  struct song_node *start = find_first(table[check],artist);
  if (start){
    printf("Artist found! ");
    print_list(start);
    printf("\n");
  }
  else {
    printf("Artist not found!\n");
  }
}

void remove_song(char *artist, char *song){
  int index = artist[0] - 'a';
  if (index<0 || index>=27){
    index = 26;
  }
  struct song_node *node = table[index];
  remove_node(node,artist,song);
}

void clear_library(){
  for (int x=0; x<27; x++){
    table[x] = free_list(table[x]);
  }
}

void print_artist(char *artist){
  struct song_node *node = list_find_artist(node, artist);
  while (node){
    if (!strcmp(node->artist, artist)){
      print_list(node);
    }
  }
  printf("\n");
}

void shuffle(struct song_node **library){
  int a = 0;
  while (a){
    int b = rand() % 27;
    if (get_random(table[b])){
      print_node(get_random(table[b]));
      printf("\n");
      a--;
    }
  }
}

#endif
