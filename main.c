#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"
#include "library.h"

int main(){
  struct song_node *temp;
  temp = malloc(sizeof("artist name") + sizeof("song name") + sizeof(struct song_node *));
  strcpy(temp->artist, "artist name");
  strcpy(temp->name, "song name");
  temp->next = NULL;

  print_list(temp);
}
