#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

struct song_node * insert_front(struct song_node *start, struct song_node *next) {
    start->next = next;
    return start;
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

struct song_node *insert_in_order(struct song_node *start, struct song_node *addition) {
    insert_front(start , addition);
    struct song_node * next = start;
    while( strcmp(addition->name , next->name) > 0 ){
        next = next->next;
        addition->next = next;
    }
}

void print_list(struct song_node *start){
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

struct song_node * list_find_artist(struct song_node *node, char *artist) {
    while (node) {
        if (! strcmp(node->artist, artist) ) {
            return (struct song_node*)node->name;
        }
        node = node->next;
    }
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

struct song_node * remove_node(struct song_node *start, struct song_node *remove) {
    while (start->next) {
        if (start->next == remove) {
            struct song_node *temp0 = start->next;
            struct song_node *temp = temp0->next;
            free(start->next);
            start->next = temp;
            return remove;
        }
    }
    start = start->next;
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
