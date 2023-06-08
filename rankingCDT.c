#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "rankingADT.h"

typedef struct Node{
  elemType head;
  int range;
  struct Node* tail;
} Node;

typedef Node* List;

typedef struct rankingCDT{
  List first;
  size_t size;
  compare cmp;
} rankingCDT;

static List newRec(List list, elemType elems[], size_t dim, int rank){
  if(dim == 0){
    return NULL;
  }
  list->head = *elems;
  list->range = rank;
  list->tail = newRec(list->tail, elems+1, dim-1, rank+1);
  return list;
}

rankingADT newRanking(elemType elems[], size_t dim, compare comp){
  rankingADT rank = malloc(sizeof(rankingCDT));
  rank->cmp = comp;
  rank->size = dim;
  if(dim == 0){
    rank->first = NULL;
  }
  else{
    rank->first = newRec(rank->first, elems, dim, 1);
  }
  return rank;
}

void addRanking(rankingADT ranking, elemType elem){
  
}

size_t size(const rankingADT ranking);

int getByRanking(rankingADT ranking, size_t n, elemType * elem);

elemType * getTopRanking(const rankingADT ranking, size_t * top);

int contains(rankingADT ranking, elemType elem);

void downByRanking(rankingADT ranking, size_t n);

void freeRanking(rankingADT r);