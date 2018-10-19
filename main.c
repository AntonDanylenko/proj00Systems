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
  list_find_node(temp, "artist name2", "song name2");
  printf("\n");

  struct song_node *temp01;
  temp01 = malloc(sizeof("Justin Bieber") + sizeof("Baby") + sizeof(struct song_name *));
  strcpy(temp01->artist, "Justin Bieber");
  strcpy(temp01->name, "Baby");
  temp01->next = NULL;

  struct song_node *temp02;
  temp02 = malloc(sizeof("Kim Kardashian") + sizeof("Love") + sizeof(struct song_name *));
  strcpy(temp02->artist, "Kim Kardashian");
  strcpy(temp02->name, "Love");
  temp02->next = NULL;


  printf("\n\n\n");
  print_node(temp01);
  print_node(temp02);
  insert_front(temp01,temp02);
  print_list(temp01);
  print_list(temp02);

  /*
  struct song_node *temp02;
  temp01 = malloc(sizeof(struct song_name *) + sizeof(struct song_name *));
  struct song_node *temp01 = {"Justin Bieber", "Baby", 0};
  struct song_node *temp02 = {"Kim Kardash", "Love", 0};
  temp01 = insert_front(temp01, temp02);
  print_list(temp01);
  */

  print_list(free_list(temp01));
}
