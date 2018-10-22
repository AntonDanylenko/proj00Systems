#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linked_list.h"
#include "library.h"

#ifndef LIBRARY_C
#define LIBRARY_C

int find_index(char *artist){
  int index = artist[0] - 'A';
  if (index > 25){
    index = 26;
  }
  return index;
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
    printf("%c \n", (char)index + 'A');
    print_list(table[index]);
  }
}

void print_letter(char a){
  if (table[(int)a-'A']){
    printf("%c \n", a);
    print_list(table[(int)a-'A']);
  }
}

void find(char *artist, char *song){
  int check = find_index(artist);
  if (list_find_node(table[check],artist,song)){
    printf("Song found! ");
    print_node(list_find_node(table[check],artist,song));
    printf("\n");
  }
  else{
    printf("Song not found! \n");
  }
}

void find_artist(char *artist){
  int index = find_index(artist);
  //printf("index: %d\n", index);
  //print_node(table[index]);
  struct song_node *start = find_first(table[index],artist);
  //print_node(start);
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
  int index = find_index(artist);
  print_list(remove_node(table[index],artist,song));
}

void clear_library(){
  for (int x=0; x<27; x++){
    table[x] = free_list(table[x]);
  }
}

void print_artist(char *artist){
  printf("printing artist\n");
  int index = find_index(artist);
  struct song_node *node = list_find_artist(table[index], artist);
  print_list(node);
}

void shuffle(){
  srand(time(0));
  int b = rand() % 27;
  while(!table[b]){
    //printf("Changing b\n");
    b = rand() % 27;
  }
  //printf("b: %d\n", b);
  if (get_random(table[b])){
    print_node(get_random(table[b]));
    printf("\n");
  }
}

#endif
