#include "setADT.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
  elemType head;
  struct Node * tail;
} Node;
typedef Node * List;

typedef struct setCDT{
  List first;
  size_t size;
  compare cmp;
} setCDT;

/* Retorna un nuevo conjunto vacío */
setADT newSet(compare cmp){
  setADT new = malloc(sizeof(setCDT));
  new->first = NULL;
  new->cmp = cmp;
  new->size = 0;
  return new;
}

static void freeSetNodes(List list){
  if(list == NULL){
    return;
  }
  freeSetNodes(list->tail);
  free(list);
}

void freeSet(setADT set){
  freeSetNodes(set->first);
  free(set);
}

int isEmptySet(setADT set){
  return set->size == 0;
}

static int setContainsRec(List list, elemType elem){
  if(list == NULL || list->head > elem){
    return 0;
  }
  if(list->head == elem){
    return 1;
  }
  return setContainsRec(list->tail, elem);
}

int setContains(const setADT set, elemType element){
  return setContainsRec(set->first, element);
}

static List addRec(List list, elemType elem, int* i){
  if(list == NULL || list->head > elem){
    List aux = malloc(sizeof(Node));
    aux->tail = list;
    aux->head = elem;
    return aux;
    *i = 1;
  }
  if(list->head < elem){
    list->tail = addRec(list->tail, elem, i);
  }
  return list;
}

int addElement(setADT set, elemType element){
  int flag = 0;
  set->first = addRec(set->first, element, &flag);
  set->size += flag;
  return flag;
}

static List deleteRec(List list, elemType elem, int* i){
  if(list == NULL || list->head > elem){
    return list;
  }
  if(list->head == elem){
    List aux = list;
    list = list->tail;
    free(aux);
    *i = 1;
    return list;
  }
  list->tail = deleteRec(list->tail, elem, i);
  return list;
}

int deleteElement(setADT set, elemType element){
  int flag = 0;
  set->first = deleteRec(set->first, element, &flag);
  set->size -= flag;
  return flag;
}

int sizeSet(const setADT set){
  return set->size;
}

setADT unionSet(setADT set1, setADT set2);

setADT intersectionSet(setADT set1, setADT set2);

setADT diffSet(setADT set1, setADT set2);