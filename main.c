#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"
#include "library.h"

int main(){
  struct song_node *temp;
  temp = malloc(sizeof("artist name") + sizeof("song name") + sizeof(struct song_name *));
  struct song_node *temp1;
  temp1 = malloc(sizeof("artist name1") + sizeof("song name1") + sizeof(struct song_name *));
  struct song_node *temp2;
  temp2 = malloc(sizeof("artist name2") + sizeof("song name2") + sizeof(struct song_name *));

  strcpy(temp->artist, "artist name");
  strcpy(temp->name, "song name");
  temp->next = temp1;

  strcpy(temp1->artist, "artist name1");
  strcpy(temp1->name, "song name1");
  temp1->next = temp2;

  strcpy(temp2->artist, "artist name2");
  strcpy(temp2->name, "song name2");
  temp2->next = NULL;

  print_node(temp);
  printf("\n");
  print_list(temp);

  print_node(temp);
  find_node_list(temp, "artist name2", "song name2");
  printf("\n");

  print_list(insert_front(temp, "artist0000", "song0000"));
}
