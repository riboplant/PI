


#include "list.h"
#include <stdlib.h>
#include <stdio.h>

int isEmpty(const List list){
  return list == NULL;
}

int belongs(const List l, int elem){
  if(l == NULL || l->head > elem){
    return 0;
  }
  if(l->head == elem){
    return 1;
  }
  else{
    return belongs(l->tail, elem);
  }
}

int size(const List l){
  if(l == NULL){
    return 0;
  }
  else{
    return 1 + size(l->tail);
  }
}

List add(List l, int elem){
  if(l == NULL || elem < l->head){
    List aux = malloc(sizeof(struct node));
    aux->head = elem;
    aux->tail = l;
    return aux;
  }
  if(elem == l->head){
    return l;
  }
  l->tail = add(l->tail, elem);
  return l;
}

List delete( List l, int elem){
  if(l == NULL || l->head > elem){
    return l;
  }
  if( l->head == elem ){
    List aux = l->tail;
    free(l);
    return aux;
  }
  l->tail = delete(l->tail,elem);
  return l;
}

int head(const List l){
  if(!isEmpty(l)){
    return l->head;
  }
  else{
    fprintf(stderr, "Error al invocar head");
    exit(1);
  }
}

List tail(const List l){
  if(!isEmpty(l)){
    return l->tail;
  }
  else{
    fprintf(stderr, "Error al invocar tail");
    exit(1);
  }
}

void freeList(List l){
  if( l == NULL){
    return;
  }
  freeList(l->tail);
  free(l);
}

int * toArray(List l){
  int dim = size(l);
  int * resp = malloc(dim*sizeof(l->head));
  for(int i=0; i<dim; i++, l=l->tail){
  resp[i] = l->head;
  }
  return resp;
}

int getRec(const List l, unsigned int index){

  if(index == 0 || l == NULL){
    return l->head;
  }
  return getRec(l->tail, index-1);
}

int get(const List l, unsigned int index){
  if(index < size(l)){
    return getRec(l, index);
  }
  else{
    fprintf(stderr, "Error al invocar get (out of range)");
    exit(1);
  }
}

List fromArray(const int v[], unsigned int dim){
  List ans = NULL;
  while (dim) {
     List aux = malloc(sizeof(Node));
     aux->head = v[--dim];
     aux->tail = ans;
     ans = aux;
  }
  return ans;
}

int checkElems(const List list, const int v[], int dim) {
  int i;
  List aux;
  for(i=0, aux=list; i<dim && aux != NULL; i++, aux = aux->tail) {
    if ( aux->head != v[i])
       return 0;
  }
  return aux == NULL && i==dim;
}

void PrintList(const List l){
  if( l != NULL ){
    printf("%d ",l->head);
    PrintList(l->tail);
  }
  else{
    printf("\n\n");
    return;
  }
  return;
}