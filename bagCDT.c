#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bagTAD.h"

typedef int (*comp)(const elemType, const elemType);

typedef struct obj{
  elemType name;
  size_t qty;
} obj;

typedef struct bagCDT{
  obj** elems; 
  size_t size;
  comp cmp;
} bagCDT;

static void freeObj(obj* vec[], size_t dim){
  for(int i=0; i<dim; i++){
    free(vec[i]);
  }
}

void freeBag( bagADT bag){
  freeObj(bag->elems, bag->size);
  free(bag);
}
 
bagADT newBag(){
  bagADT new = malloc(sizeof(bagCDT));
  new->cmp = compare;
  new->size = 0;
  new->elems = NULL;
  return new;
}
 
static int belongs(obj* vec[], elemType elem, size_t size, comp cmp){
  for(int i=0; i<size; i++){
    if(cmp(vec[i]->name, elem) == 0){
      return i+1;
    }
  }
  return 0;
}

unsigned int add(bagADT bag, elemType elem){
  int c;
  if((c = belongs(bag->elems, elem, bag->size, bag->cmp))){
    bag->elems[c-1]->qty+=1;
    return bag->elems[c-1]->qty;
  }
  obj* aux = malloc(sizeof(obj));
  aux->name = elem;
  aux->qty = 1;
  bag->size+=1;
  bag->elems = realloc(bag->elems, bag->size * sizeof(obj*));
  bag->elems[bag->size-1] = aux;
  return 1;
}
 
/* Retorna cuántas veces aparece el elemento en el bag */
unsigned int count(const bagADT bag, elemType elem){
  int c;
  if((c=belongs(bag->elems, elem, bag->size, bag->cmp))){
    return bag->elems[c-1]->qty;
  }
  else{
    return 0;
  }
}
 
/* Retorna la cantidad de elementos distintos que hay en el bag */
unsigned int size(const bagADT bag){
  return bag->size;
}
 
/* Retorna el elemento que aparece más veces. Si hay más de uno 
** con esa condición, retorna cualquiera de los dos. 
** Precondicion: el bag no debe estar vacio. En caso de estar vacío, aborta
** la ejecución
*/
elemType mostPopular(bagADT bag){
  if(bag->size == 0){
    exit(1);
  }
  int max = 0;
  elemType maxrep;
  for(int i=0; i< bag->size; i++){
    if(bag->elems[i]->qty > max){
      max = bag->elems[i]->qty;
      maxrep = bag->elems[i]->name;
    }
  }
  return maxrep;
}