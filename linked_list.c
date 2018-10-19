#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

struct song_node * insert_front(char *artist, char *name, struct song_node *next) {
    struct song_node *result = malloc(sizeof(struct song_node));
    strcpy(result->artist,artist);
    strcpy(result->name,name);
    result->next = next;
    return result;
}

void set_node(struct song_node *node, char *artist, char *name, struct song_node *next) {
    strcpy(node->artist,artist);
    strcpy(node->name,name);
    node->next = next;
}

//helper function
int song_cmp(struct song_node *first, struct song_node *second){
	int name_cmp = strcmp(first->name, second->name);
	int artist_cmp = strcmp(first->artist, second->artist);
	if (artist_cmp != 0){
		return (int)(artist_cmp < 0);
	}
    else {
    	return (int)(name_cmp < 0);
    }
}

struct song_node *insert_in_order(struct song_node *node, char *artist, char *name) {
  struct song_node *start = node;
  struct song_node *new = malloc(sizeof (struct song_node) );

  strcpy(new->artist,artist);
  strcpy(new->name,name);

  while( node->next && strcmp(artist, (node->next)->artist) > 0 ) {
      node = node->next;
  }

  while( node->next && strcmp((node->next)->artist, artist)==0 && strcmp(name, (node->next)->name) > 0 ) {
      node = node->next;
  }

  if ( node == start ) {
      start = insert_front(artist, name, node);
  }
  else {
      new->next = node->next;
      node->next = new;
  }
  return start;
}

void print_list(struct song_node *start){
    printf("| ");
  while (start) {
    printf("%s : %s | ", start->artist, start->name);
    start = start->next;
  }
  printf("\n");
}

//helper
void print_node(struct song_node *node){
  printf("%s : %s\n", node->artist, node->name);
}

struct song_node * list_find_node(struct song_node *start, char *song_artist, char *song_name){
  printf("looking for [%s: %s]...\n", song_artist, song_name);
  while(start){
    //printf("in while loop\n");
    if(!(strcmp(start->artist,song_artist) || strcmp(start->name,song_name))){
      printf("Song found! ");
      print_node(start);
      printf("\n");
      return start;
    }
    start = start->next;
  }
  printf("Song not found!\n");
  return NULL;
}

struct song_node * list_find_artist(struct song_node *node, char *artist) {
    while (node) {
        if (! strcmp(node->artist, artist) ) {
            printf("Artist found! ");
            print_node(node);
            return NULL;
        }
        node = node->next;
    }
    printf("Artist not found!");
    return NULL;
}

//helper
int length(struct song_node *node) {
    int result = 0;
    while (node != NULL) {
        result += 1;
        node = node->next;
    }
    return result;
}

struct song_node * get_random(struct song_node *node) {
    struct song_node *decoy = node;
	int chance = ( rand() % length(decoy) );
	for (int i = 0; i < chance; i++){
		node = node -> next;
	}
	return node;
}

struct song_node * remove_node(struct song_node *start, char *song_artist, char *song_name) {
    struct song_node *one = start;
    struct song_node *two;
    if (one) {
        while(!strcmp(start->artist,song_artist) || !strcmp(start->name,song_name)){
            two = one;
            one = one->next;
        }
        if (one == start){
            start = one->next;
        }
        two->next = one->next;
    }
    return two;
}

struct song_node * free_list(struct song_node *start){
  printf("freeing list\n");
  while (start){
    struct song_node *temp;
    temp = malloc(sizeof(start->artist) + sizeof(start->name) + sizeof(struct song_name *));
    temp = start;
    start = start->next;
    free(temp);
    temp = NULL;
  }
  printf("list freed\n");
  return start;
  }
