#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "list.h"

List removeIf(List list, int(*fn)(int)){
  if(list == NULL){
    return NULL;
  }
  if(fn(list->head)){
    List aux = list;
    list = list->tail;
    free(aux);
    list = removeIf(list, fn);
    return list;
  }
  list->tail = removeIf(list->tail, fn);
  return list;
}
int esImpar(int x) {
    return x % 2;
}
 
int esPositivo(int x) {
    return x > 0;
}
 
int esPar(int x) {
    return !esImpar(x);
}
int true(int n){
  return 1;
}



int main(void){
int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int v_i[] = {1, 3, 5, 7, 9};
  int v_p[] = {2, 4, 6, 8};
  int p[] = {2, 4, 6, 8, 4, 2, 0, -10};

  List l1 = fromArray(v, 9);
  l1 = removeIf(l1, esPar);
  assert(checkElems(l1,v_i, 5));
    freeList(l1);

  l1 = fromArray(v, 9);
  l1 = removeIf(l1, esImpar);
  assert(checkElems(l1,v_p, 4));
    freeList(l1);

  l1 = fromArray(v, 9);
  l1 = removeIf(l1, true);
  assert(l1==NULL);
    freeList(l1);

  l1 = fromArray(p, 8);
  l1 = removeIf(l1, esPar);
  assert(l1==NULL);
    freeList(l1);

  l1 = fromArray(p, 8);
  l1 = removeIf(l1, esImpar);
  assert(checkElems(l1, p, 8));
    freeList(l1);
  
  l1 = removeIf(NULL, esImpar);
  assert(l1==NULL);
    freeList(l1);

  printf ("OK!\n");
  return 0;
}