#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <assert.h>
#include "random.h"

#define TOPE 10
#define RANDOM (randInt(-1,1))
typedef struct {
  int x;
  int y;
} tPunto2D;

typedef tPunto2D * tPosiciones;


int ej1(void){
  randomize();
  tPosiciones vec = malloc(TOPE*sizeof(tPunto2D));
  tPunto2D actual = {0,0};

  int n = 0;
  do{
    if(n%TOPE==0){
      vec = realloc(vec, sizeof(vec) + TOPE);
    }
    vec[n++] = actual;
    actual.x = actual.x + RANDOM;
    actual.y = actual.y + RANDOM;
  }
  while(actual.x != 0 && actual.y != 0);

  free(vec);
  printf("%d",n);

  return 0;
}

int esPotenciaDe3(int n){
  if(n==1){
    return 1;
  }
  else if(n<1 || n%3){
    return 0;
  }

  return esPotenciaDe3(n/3);

}


int igualesRet(const int veca[], const int vecb[]){
  if(*veca != *vecb){
    return 0;
  }

  if(*veca==-1){
    return 1;
  }
  else{
    return igualesRet(veca+1, vecb+1 );
  }

}


void igualesVoid(const int veca[], const int vecb[], int * rta){
  if(*veca != *vecb){
    *rta = 0;
    return;
  }

  if(*veca==-1){
    *rta = 1;
    return;
  }
  else{
    igualesVoid(veca+1, vecb+1, rta );
  }
}

void recMinMax(const int v[], int dim, int * min, int * max){
  if(dim == 0){
    *min = *max = 0;
    return;
  }
  if(*v<=0){
    *min = *max = -1;
    return;
  }

  if(dim==1){
    *min = *max = *v;
    return;
  }
  recMinMax(v+1, dim-1, min, max);
  if(*min != -1){
    *min = (*min >= *v)? *v : *min;
    *max = (*max <= *v)? *v : *max;
  }
}

int main(void){
int v[] = {3, 1, 5, 2, 6, 99, -3, 2};
    int min, max;
    recMinMax(v, 0, &min, &max);
    assert(min == 0 && max == 0);
    recMinMax(v, 1, &min, &max);
    assert(min == 3 && max == 3);
    recMinMax(v, 2, &min, &max);
    assert(min == 1 && max == 3);
    recMinMax(v, 3, &min, &max);
    assert(min == 1 && max == 5);
    recMinMax(v, 6, &min, &max);
    assert(min == 1 && max == 99);
    recMinMax(v, 8, &min, &max);
    assert(min == -1 && max == -1);
    printf("OK!\n");
    return 0;
}

