#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#ifndef LINKED_LISTS_C
#define LINKED_LISTS_C

void print_list(struct song_node *start){
  while (start){
    printf("%s : %s |", start->artist, start->name);
    start = start->next;
  }
  printf("\n");
}

void print_node(struct song_node *node){
  printf("%s : %s", node->artist, node->name);
}

struct song_node * find_node(struct song_node *start, char *song_artist, char *song_name){
  printf("looking for [%s: %s]\n", song_artist, song_name);
  while(start){
    if(!strcmp(start->artist,song_artist) && !strcmp(start->name,song_name)){
      printf("node found! ");
      print_node(start);
      return start;
    }
    start = start->next;
  }
  printf("node not found");
}
  
/*struct song_node * insert_front(struct node *start, int num){
  struct node *new;
  new = malloc(sizeof(num) + sizeof(start));
  new->i = num;
  new->next = start;
  return new;
}

struct node * free_list(struct node *start){
  while (start){
    struct node *temp = start;
    start = start->next;
    free(temp);
    temp = NULL;
  }
  return start;
  }*/

#endif
