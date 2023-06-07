#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "list.h"

List concatenarLista(List list1, List list2){
  if(list1 == NULL && list2 == NULL){
    return NULL;
  }
  if(list1 == NULL){
    List aux = malloc(sizeof(Node));
    aux->head = list2->head;
    aux->tail = concatenarLista(list1, list2->tail);
    return aux;
  }
  list1->tail = concatenarLista(list1->tail, list2);
  return list1;

}



typedef int (*fnInt) (int);


void transforma(int v[], size_t dim, fnInt f){
  if(dim == 0){
    return;
  }
  *v = f(*v);
  transforma(v+1, dim-1, f);
}
static void assertArrayEquals(const int *, const int *, size_t);
 
int cuadrado(int x) {
    return x * x;
}
 
// Sólo para testing
static void
assertArrayEquals(const int * expected, const int * actual, size_t dim) {
    for(int i = 0; i < dim; i++) {
        assert(expected[i] == actual[i]);
    }
}
 
typedef int (*fnn) (int, int);
int operatoria(int v[], size_t dim, int base, fnn f){
  if(dim == 0){
    return base;
  }
  return f(*v, operatoria(v+1, dim-1, base, f));
}
 
int producto(int x, int y) {
    return x * y;
}
 
int suma(int x, int y) {
    return x + y;
}
typedef int (*fn) (int);
  
List depuraLista(List list, fn f){
  if(list == NULL){
    return NULL;
  }
  if(f(list->head)){
    List aux = list;
    list = list->tail;
    free(aux);
    list = depuraLista(list, f);
    return list;
  }
  list->tail = depuraLista(list->tail, f);
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
 

int
main(void) {
    fn f = &esImpar;
    int v1[] = {4,3,7,2,6};
    List l1 = fromArray(v1, 5);
 
    l1 = depuraLista(l1, f);
    int v1res[] = {4,2,6};
    assert(checkElems(l1, v1res, 3));
    freeList(l1);
 
    List l2 = fromArray(v1, 5);
    assert(depuraLista(l2, esPositivo) == NULL);
 
    List l3 = fromArray(v1, 5);
    l3 = depuraLista(l3, esPar);
    int v3res[] = {3,7};
    assert(checkElems(l3, v3res, 2));
    freeList(l3);
 
    printf("OK!\n");
    return 0;
}