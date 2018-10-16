#include <stdio.h>
#include <stdlib.h>
#include "linked_lists.h"
#ifndef LINKED_LISTS_C
#define LINKED_LISTS_C

void print_list(struct node *start){
  while (start){
    printf("%d, ", start->i);
    start = start->next;
  }
  printf("\n");
}

struct node * insert_front(struct node *start, int num){
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
}

#endif
