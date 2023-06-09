#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "rankingADT.h"

typedef struct rankingCDT{
  elemType* vec;
  size_t size;
  comp cmp;
} rankingCDT;

static void swap(elemType vec[], int pos1, int pos2){
  elemType aux = vec[pos1];
  vec[pos1] = vec[pos2];
  vec[pos2] = aux;
  return;
}

rankingADT newRanking(elemType elems[], size_t dim, comp cmp){
  rankingADT r = malloc(sizeof(rankingCDT));
  r->size = dim;
  r->cmp = cmp;
  r->vec = malloc(dim * sizeof(elemType));
  for(int i=0; i<dim; i++){
    r->vec[i] = elems[i];
  }
  return r;
}

void addRanking(rankingADT ranking, elemType elem){
  if(contains(ranking, elem)){
    return;
  }
  ranking->size += 1;
  ranking->vec = realloc(ranking->vec, ranking->size * sizeof(elemType));
  ranking->vec[(ranking->size)-1] = elem;
  return;
}

size_t size(const rankingADT ranking){
  return ranking->size;
}

int getByRanking(rankingADT ranking, size_t n, elemType * elem){
  if(n > ranking->size || n<= 0){
    return 0;
  }
  *elem = ranking->vec[n-1];
  if(n-1 > 0){
    swap(ranking->vec, n-1, n-2);
  }
  return 1;
}

elemType * getTopRanking(const rankingADT ranking, size_t * top){
  if(*top > ranking->size){
    *top = ranking->size;
  }
  elemType* aux = malloc(*top * sizeof(elemType));
  for(int i=0; i<*top; i++){
    aux[i] = ranking->vec[i];
  }
  return aux;
}

int contains(rankingADT ranking, elemType elem){
  for(int i=0; i<ranking->size; i++){
    if(ranking->cmp(ranking->vec[i], elem) == 0){
      if(i>0){
        swap(ranking->vec,i, i-1);
      }
      return i+1;
    }
  }
  return 0;
}

void downByRanking(rankingADT ranking, size_t n){
  if(n>ranking->size){
    return;
  }
  swap(ranking->vec, n, n-1);
}

void freeRanking(rankingADT r){
  free(r->vec);
  free(r);
}

void PrintRanking(rankingADT ranking){
  printf("Size: %d\n", ranking->size);
  for(int i=0; i<ranking->size; i++){
    printf("%s\n", ranking->vec[i]);
  }
}