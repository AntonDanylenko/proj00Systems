#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

void print_list(struct song_node *start){
  while (start){
    printf("%s : %s | ", start->artist, start->name);
    start = start->next;
  }
  printf("\n");
}

void print_node(struct song_node *node){
  printf("%s : %s\n", node->artist, node->name);
}

struct song_node * find_node_list(struct song_node *start, char *song_artist, char *song_name){
  printf("looking for [%s: %s]\n", song_artist, song_name);
  while(start){
    //printf("in while loop\n");
    if(!(strcmp(start->artist,song_artist) || strcmp(start->name,song_name))){
      printf("node found! ");
      print_node(start);
      printf("\n");
      return start;
    }
    start = start->next;
  }
  printf("node not found\n");
  return NULL;
}

struct song_node * insert_front(struct song_node *start, char *artist, char *name){
  struct song_node *new;
  new = malloc(sizeof(artist) + sizeof(name) + sizeof(struct song_name *));
  strcpy(new->artist, artist);
  strcpy(new->name, name);
  new->next = start;
  return new;
}

/*struct node * free_list(struct node *start){
  while (start){
    struct node *temp = start;
    start = start->next;
    free(temp);
    temp = NULL;
  }
  return start;
  }*/
