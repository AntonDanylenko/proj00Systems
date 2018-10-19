#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"
#include "library.h"

int main(){
    printf("\nTESTING LINKED LIST FUNCTIONS\n");
    printf("==========================================\n");
    struct song_node *node1;
    node1 = malloc(sizeof("The Chainsmokers") + sizeof("Closer") + sizeof(struct song_name *));
    set_node(node1, "The Chainsmokers", "Closer", NULL);

    struct song_node *node2;
    node2 = malloc(sizeof("Justin Bieber") + sizeof("baby") + sizeof(struct song_name *));
    set_node(node2, "Justin Bieber", "Baby", node1);

    struct song_node *node3;
    node3 = malloc(sizeof("Imagine Dragons") + sizeof("Believer") + sizeof(struct song_name *));
    set_node(node3, "Imagine Dragons", "Believer", node2);

    struct song_node *node4;
    node4 = malloc(sizeof("Ed Sheeran") + sizeof("Shape of You") + sizeof(struct song_name *));
    set_node(node4, "Ed Sheeran", "Shape of You", node3);

    struct song_node *node5;
    node5 = malloc(sizeof("Ed Sheeran") + sizeof("Perfect") + sizeof(struct song_name *));
    set_node(node5, "Ed Sheeran", "Perfect", node4);

    struct song_node *node6;
    node6 = malloc(sizeof("Charlie Puth") + sizeof("Attention") + sizeof(struct song_name *));
    set_node(node6, "Charlie Puth", "Attention", node5);

    printf("=~=~=~=[ print_list test ]=~=~=~=\n");
    print_list(node6);

    printf("==========================================\n");
    printf("=~=~=~=[ insert_front test ]=~=~=~=\n");
    printf("Adding [Ariana Grande : Side to Side] to the front...\n\n");

    printf("Updated List:\n");
    print_list(insert_front("Ariana Grande", "Side to Side", node6));

    printf("==========================================\n");
    printf("=~=~=~=[ insert_in_order test ]=~=~=~=\n");
    printf("Adding [Flo Rida : My House] into proper space...\n\n");

    printf("Updated list:\n");
    print_list(insert_in_order(node6, "Flo Rida", "My House"));

    printf("==========================================\n");
    printf("=~=~=~=[ list_find_node test ]=~=~=~=\n");
    list_find_node(node6, "Ed Sheeran", "Galway Girl");
    list_find_node(node6, "Charlie Puth", "Attention");

    printf("==========================================\n");
    printf("=~=~=~=[ list_find_artist test ]=~=~=~=\n");

    printf("Searching for Justin Bieber...\n");
    list_find_artist(node6, "Justin Bieber");

    printf("==========================================\n");
    printf("=~=~=~=[ get_random test ]=~=~=~=\n");

    printf("Getting random song... ");
    print_node(get_random(node6));
    printf("Getting random song... ");
    print_node(get_random(node6));
    printf("Getting random song... ");
    print_node(get_random(node6));

    printf("==========================================\n");
    printf("=~=~=~=[ remove_node test ]=~=~=~=\n");

    printf("Removing [Imagine Dragons : Believer]...\n\n");
    remove_node(node6, "Imagine Dragons", "Believer");

    printf("Updated list:\n");
    print_list(node6);

    printf("==========================================\n");
    printf("=~=~=~=[ free_list test ]=~=~=~=\n");

    printf("Freeing list...\n\n");
    free_list(node6);

    printf("Updated list:\n");
    print_list(node6);

    /*
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

  print_list(free_list(temp01));
  */

  printf("==========================================\n");
  printf("\nTESTING MUSIC LIBRARY FUNCTIONS\n");
  printf("==========================================\n");
  printf("====[ add_song test ]====\n");

  add_song("Nial Horan", "Slow Hands");
  add_song("Ariana Grande","Into You");
  add_song("Ed Sheeran","Galway Girl");
  add_song("Martin Garrix","There for You");
  add_song("Halsey","Now or Never");
  add_song("Clean Bandit","Symphony");
  add_song("Rita Ora","Your Song");
  add_song("Sam Hunt","Body Like a Back Road");
  add_song("Calvin Harris","Slide");
  add_song("Kendrick Lamar","Humble");

  print_library();

  printf("==========================================\n");
  printf("====[ print_letter test ]====\n");

  print_letter('S');

  print_letter('N');

  print_letter("H");

  printf("==========================================\n");
  printf("====[ print_artist test ]====\n");

  print_artist("Calvin Harris");

  print_artist("Rita Ora");

  print_artist("Halsey");

  printf("==========================================\n");
  printf("====[ print_library test ]====\n");

  print_library();

  printf("==========================================\n");
  printf("====[ find test ]====\n");

  find("Ed Sheeran","Galway Girl");

  find("The Jackson Brothers", "ABC");

  printf("==========================================\n");
  printf("====[ find_artist test ]====\n");

  find_artist("Martin Garris");

  find_artist("Lebron James");

  printf("==========================================\n");
  printf("====[ shuffle test ]====\n");

  shuffle();
  shuffle();
  shuffle();

  printf("==========================================\n");
  printf("====[ remove_song test ]====\n");

  remove_song("Kendrick Lamar", "Humble");

  remove_song("Nial Horan","Slow Hands");

  printf("==========================================\n");
  printf("====[ clear_library test ]====\n");

  clear_library();
}
