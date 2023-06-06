#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "list.h"

int sumAll(List list){
  if(list == NULL ){
    return 0;
  }
  return list->head + sumAll(list->tail);
}

int odds1(List list){
  if(list == NULL || list->tail == NULL){
    return 1;
  }
  return ((list->head)%2) && odds1(list->tail);
}

int odds2(List list){
  if(isEmpty(list)){
    return 0;
  }
  else{
    return odds1(list);
  }
}
void order(List list){
  if(list == NULL || list->tail == NULL){
  return;
  }
  
  if(list->head < list->tail->head){
    order(list->tail);
  }
  else{
  List aux = list->tail->tail;
  free(list->tail);
  list->tail = aux;
  order(list);
  }
}

#define ELEMS 200

List addAll(List list1, List list2){
  if ( list2 == NULL){//aca no es el error
    ;
  }
  else if (list1==NULL)
  {
    list1 = malloc(sizeof(Node));
    list1->head = list2->head;
    list1->tail = NULL;
    list1->tail = addAll(list1->tail, list2->tail);
  }
  else if( list1->head < list2->head ){
    list1->tail = addAll(list1->tail, list2);
  }
  else if( list1->head == list2->head){
    list1->tail = addAll(list1->tail, list2->tail);
    }
  else if( list1->head > list2->head){
    int numl1 = list1->head;
    list1->head = list2->head;
    List aux = malloc(sizeof(Node));
    aux->head = numl1;
    aux->tail = list1->tail;
    list1->tail = aux;
    list1->tail = addAll(list1->tail, list2->tail);
  }
  return list1;
}

int revisar(void){
  int pares[ELEMS], impares[ELEMS];

  for(int i=1; i <= ELEMS; i++) {
    pares[i-1] = i * 2 ;
    impares[i-1] = i * 2 - 1;
  }

  List lPar = fromArray(pares, ELEMS);
  List lImpar = fromArray(impares, ELEMS);

  printf("Imprimio listas pares e impares\n");
  PrintList(lPar);
  PrintList(lImpar);

  lPar = addAll(lPar, lImpar);
  printf("Imprimo lista de todos (pares+impares)\n");
  PrintList(lPar);

  int all[ELEMS * 2];
  for(int i=1, j=0; i <= ELEMS; i++) {
    all[j++] = i * 2 - 1;
    all[j++] = i * 2 ;
  }
  assert(checkElems(lPar, all, ELEMS*2));
  freeList(lPar);//libero primera vez

  lPar = NULL;
  lPar = addAll(lPar, lImpar);
  printf("Imprimo Impares en la lista que se llama pares(NULL+Impares)\n");
  PrintList(lPar);
  assert(checkElems(lPar, impares, ELEMS));

  lPar = addAll(lPar, lImpar);//entonces aca estoy devolviendo lImpar en vez de lPar ??
  printf("Imprimo Impares (Impares+Impares)\n");
  PrintList(lPar);
  assert(checkElems(lPar, impares, ELEMS));
  printf("Libero lista pares\n");
  freeList(lPar);//libero segunda vez, esta da error !!
  //PrintList(lPar); //Parece que lPares = lImpares


  lPar = fromArray(pares, ELEMS);
  printf("reinicio lista pares con los pares e imprimo\n");
  PrintList(lPar);
  //lImpar = addAll(lImpar, lPar);//aca falla pues dice lImpares esta liberada ?? //
  //PrintList(lImpar);

  //assert(checkElems(lImpar, all, ELEMS*2));
  //freeList(lPar);
  //freeList(lImpar);
   
  int w[] = {1,2,3,4,5,6,7,8};
  List l1 = fromArray(w,3);
  List l2 = fromArray(w+3,5);
  l1 = addAll(l1,l2);
  assert(checkElems(l1, w, 8));
  freeList(l1);
  freeList(l2);//me dice que ya la libere ?? se igualan de nuevo la puta madre

  l1 = fromArray(w,8);
  l2 = fromArray(w,8);
  l1 = addAll(l1,l2);
  assert(checkElems(l1, w, 8));
  freeList(l2);
  freeList(l1);
  
  puts("OK!");
  return 0;
}

List restaList(List list1, List list2){
  if(list1 == NULL){
    return NULL;
  }
  else if(list2 != NULL && list1->head == list2->head){
    return restaList(list1->tail, list2->tail);
  }
  else if(list2 != NULL && list1->head > list2->head){
    return restaList(list1, list2->tail);
  }
    List aux = malloc(sizeof(Node));
    aux->head = list1->head;
    aux->tail = restaList(list1->tail, list2);
    return aux;
}

List deleteDupl2(List list){
  if(list == NULL || list->tail == NULL){
    return list;
  }
  if(list->head == list->tail->head){
    List aux = list->tail;
    list->tail = aux->tail;
    free(aux);
    return deleteDupl2(list);
  }
  else{
    list->tail = deleteDupl2(list->tail);
    return list;
  }
}

void deleteDupl(List list){
  list = deleteDupl2(list);
}

List listIntersec(List list1, List list2){
  if(list1 == NULL || list2 == NULL ){
    return NULL;
  }
  if(list1->head == list2->head){
    List rta = malloc(sizeof(Node));
    rta->head = list1->head;
    rta->tail = listIntersec(list1->tail, list2->tail);
    return rta;
  }
  if(list1->head > list2->head){
    return listIntersec(list1, list2->tail);
  }
  return listIntersec(list1->tail, list2);
}

List listUnion(List list1, List list2){
  if(list1 == NULL && list2 == NULL){
    return NULL;
  }
  if(list1 == NULL){
    List rta = malloc(sizeof(Node));
    rta->head = list2->head;
    rta->tail = listUnion(list1, list2->tail);
    return rta;
  }
  if(list2 == NULL){
    List rta = malloc(sizeof(Node));
    rta->head = list1->head;
    rta->tail = listUnion(list1->tail, list2);
    return rta;
  }
  if(list1->head == list2->head){
    List rta = malloc(sizeof(Node));
    rta->head = list1->head;
    rta->tail = listUnion(list1->tail, list2->tail);
    return rta;
  }
  if(list1->head > list2->head){
    List rta = malloc(sizeof(Node));
    rta->head = list2->head;
    rta->tail = listUnion(list1, list2->tail);
    return rta;
  }
  if(list1->head < list2->head){
    List rta = malloc(sizeof(Node));
    rta->head = list1->head;
    rta->tail = listUnion(list1->tail, list2);
    return rta;
  }

}

typedef struct nodeBrief * ListBrief; 
typedef struct nodeBrief {
		int head;
		size_t count;
		struct nodeBrief * tail;
	} NodeBrief;

ListBrief comprimeList(List list){
  if(list == NULL){
    return NULL;
  }
  ListBrief aux = comprimeList(list->tail);
  if(aux == NULL){
    ListBrief brief = malloc(sizeof(ListBrief));
    brief->head = list->head;
    brief->count = 1;
    brief->tail = NULL;
    return brief;
  }
  if(list->head == aux->head){
    aux->count += 1;
    return aux;    
  }
  ListBrief juanpa = malloc(sizeof(NodeBrief));
  juanpa->head = list->head;
  juanpa->count = 1;
  juanpa->tail = aux;
  return juanpa;
}

/*ListBrief compRec(List list, ListBrief brief){
  if(list == NULL){
    return NULL;
  }
  if(list->head == brief->head){
    brief->count+=1;
    return compRec(list->tail, brief);
  }
  ListBrief rta = malloc(sizeof(NodeBrief));
  rta->head = list->head;
  rta->count = 1;
  rta->tail = compRec(list->tail, rta);
  return rta;
}

ListBrief comprimeList(List list){
  if(list == NULL){
    return NULL;
  }
  ListBrief rta = malloc(sizeof(NodeBrief));
  rta->head = list->head;
  rta->count = 1;
  rta->tail = compRec(list->tail, rta);
  return rta;
}*/

void freeListBrief(ListBrief lb) {
   if ( lb == NULL)
     return;
   freeListBrief(lb->tail);
   free(lb);
}

int main(void) {
   int v[] = {1,1,2,3,3,3,3,3,10,100,100,998};
  List list = fromArray(v, sizeof(v)/sizeof(v[0]));
  ListBrief bf = comprimeList(list);
  ListBrief aux = bf;
  assert(aux->head ==1 && aux->count == 2);

  aux = aux->tail;
  assert(aux->head ==2 && aux->count == 1);

  aux = aux->tail;
  assert(aux->head ==3 && aux->count == 5);

  aux = aux->tail;
  assert(aux->head ==10 && aux->count == 1);

  aux = aux->tail;
  assert(aux->head ==100 && aux->count == 2);

  aux = aux->tail;
  assert(aux->head ==998 && aux->count == 1);

  aux = aux->tail;
  assert(aux == NULL);

  freeList(list);
  freeListBrief(bf);
  
  printf ("OK!\n");
  return 0;
}
