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


typedef float (*func)(float);
typedef float intervalos[2];
#define MIN -20
#define MAX 20
#define EPSILON 0.001
#define INTERVALOS 100000
#define DELTAX ((float)(abs(MIN) + abs(MAX)) / INTERVALOS)

typedef struct {
    unsigned int cant;
    intervalos * pares;
  } tipoRaices;

void escribirValor(tipoRaices * raices, intervalos intervalo){
  raices->cant++;
  raices->pares = realloc(raices->pares, raices->cant * sizeof(intervalos));
  raices->pares[raices->cant-1][0] = intervalo[0];
  raices->pares[raices->cant-1][1] = intervalo[1];
}

void printRaices(const tipoRaices raiz){
  printf("%d\n",raiz.cant);
  for (int i=0; i<raiz.cant; i++)
  {
    printf("%f, %f", *raiz.pares[0], *raiz.pares[1]);
  }
  printf("/n");
}

void raices(func function){
  tipoRaices raices = {
    .cant = 0,
    .pares = NULL  
  };

float barrido, valor_actual, valor_anterior = function(MIN);
intervalos ab;
int flag = 0;
for(barrido = MIN; barrido < MAX; barrido += DELTAX){
  valor_actual = function(barrido);
  if(valor_actual <= 0+EPSILON && valor_actual >= 0-EPSILON){
    if(!flag){
      flag = 1;
      ab[0] = barrido - DELTAX;
    }
    if(flag){
      ab[1] = barrido + DELTAX;
    }
  }
  else if(valor_anterior <= 0+EPSILON && valor_anterior >= 0-EPSILON && flag){
    escribirValor(&raices, ab);
    flag = 0;
    ab[0] = 0;
    ab[1] = 0;
  }
  else if(valor_anterior*valor_actual < 0){
    ab[0] = barrido - DELTAX;
    ab[1] = barrido;
    escribirValor(&raices, ab);
  }
  valor_anterior = valor_actual;
  }
  printRaices(raices);
  free(raices.pares);
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