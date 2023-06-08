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

void PrintSetRec(List list){
  if(list == NULL){
    return;
  }
  printf("%s\n", list->head);
  PrintSetRec(list->tail);
}

void PrintSet(setADT set){
  PrintSetRec(set->first);
  printf("%ld\n", set->size);
}



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

static int setContainsRec(List list, elemType elem, compare cmp){
  int c;
  if(list == NULL || (c = cmp(list->head, elem)) > 0){
    return 0;
  }
  if(c == 0){
    return 1;
  }
  return setContainsRec(list->tail, elem, cmp);
}

int setContains(const setADT set, elemType element){
  return setContainsRec(set->first, element, set->cmp);
}

static List addRec(List list, elemType elem, int* i, compare cmp){
  int c;
  if(list == NULL || (c = cmp(list->head, elem))>0){
    List aux = malloc(sizeof(Node));
    aux->tail = list;
    aux->head = elem;
    *i = 1;
    return aux;
  }
  if(c < 0){
    list->tail = addRec(list->tail, elem, i, cmp);
  }
  return list;
}

int addElement(setADT set, elemType element){
  int flag = 0;
  set->first = addRec(set->first, element, &flag, set->cmp);
  set->size += flag;
  return flag;
}

static List deleteRec(List list, elemType elem, int* i, compare cmp){
  int c;
  if(list == NULL || (c = cmp(list->head, elem)) > 0){
    return list;
  }
  if(c == 0){
    List aux = list;
    list = list->tail;
    free(aux);
    *i = 1;
    return list;
  }
  list->tail = deleteRec(list->tail, elem, i, cmp);
  return list;
}

int deleteElement(setADT set, elemType element){
  int flag = 0;
  set->first = deleteRec(set->first, element, &flag, set->cmp);
  set->size -= flag;
  return flag;
}

int sizeSet(const setADT set){
  return set->size;
}

void unionRec(List list1, List list2, compare cmp, size_t* i, setADT out){
  if(list1 == NULL && list2 == NULL){
    return;
  }
  else if(list1 == NULL){
    addElement(out, list2->head);
    list2 = list2->tail;
  }
  else if(list2 == NULL){
    addElement(out, list1->head);
    list1 = list1->tail;
  }

  else if(cmp(list1->head, list2->head) < 0){
    addElement(out, list1->head);
    list1 = list1->tail;
  }
  else if(cmp(list1->head, list2->head) > 0){    
    addElement(out, list2->head);
    list2 = list2->tail;
  }
  else if( cmp(list1->head, list2->head) == 0){
    addElement(out, list1->head);
    list1 = list1->tail;
    list2 = list2->tail;
  }
  *i += 1;
  unionRec(list1, list2, cmp, i, out);
}

setADT unionSet(setADT set1, setADT set2){
  setADT resp = newSet(set1->cmp);
  size_t size = 0;
  unionRec(set1->first, set2->first, set1->cmp, &size, resp);
  resp->size = size;
  return resp;
}

static void intersectionRec(List list1, List list2, compare cmp, size_t* i, setADT out){
  if(list1 == NULL || list2 == NULL){
    return;
  }
  int c = cmp(list1->head, list2->head);
  if(c == 0){
    addElement(out, list1->head);
    list1 = list1->tail;
    list2 = list2->tail;
    *i += 1;
  }
  else if(c > 0){
    list2 = list2->tail;
  }
  else{
    list1 = list1->tail;
  }
  intersectionRec(list1, list2, cmp, i, out);
}

setADT intersectionSet(setADT set1, setADT set2){
  setADT resp = newSet(set1->cmp);
  size_t size = 0;
  intersectionRec(set1->first, set2->first, set1->cmp, &size, resp);
  resp->size = size;
  return resp;
}

static void diffRec(List list1, List list2, compare cmp, int* i, setADT out){
  if(list1 == NULL){
    return;
  }
  else if(list2 == NULL){
    addElement(out, list1->head);
    *i += 1;
    list1 = list1->tail;
  }
  else if(cmp(list1->head, list2->head) == 0){
    list1 = list1->tail;
    list2 = list2->tail;
  }
  else if(cmp(list1->head, list2->head) > 0){
    list2 = list2->tail;
  }
  else{
    addElement(out, list1->head);
    *i += 1;
    list1 = list1->tail;
  }
  diffRec(list1, list2, cmp, i, out);
}


setADT diffSet(setADT set1, setADT set2){
  setADT resp = newSet(set1->cmp);
  size_t size = 0;
  diffRec(set1->first, set2->first, set1->cmp, &size, resp);
  resp->size = size;
  return resp;
}