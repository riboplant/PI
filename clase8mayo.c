#include <stdlib.h>
#include <stdio.h>
#include "getnum.h"
#include <string.h>
#include <ctype.h>

#define LENGTH 25
#define QTY 4

size_t getline(char * s, size_t longMax){
  int c, i=0;
  while((c=getchar()) != '\n' ){
    if (i<longMax){
      s[i++] = c;
    }
  }
  s[i] = 0;
  return i;
}

char * copyName(const char aux[], int len){
  char * line = malloc((len+1)*sizeof(char));
  strcpy(line, aux);
  return line;
}

char ** addPlayer(char ** nombres, int cantJugadores){
  printf("Ingrese jugador nuevo: ");
  char aux[LENGTH+1];
  int len = getline(aux, LENGTH);
  char ** newarr = realloc(nombres, (cantJugadores+1)*sizeof(nombres[0]));
  newarr[cantJugadores] = copyName(aux, len);
  return newarr;
}

#define BLOQUE 10

int * interseccion(const int v1[], const int v2[], size_t dim1, size_t dim2, size_t * dimf){
  int * resp = NULL;
  int i,j,k;
  for(i=0,j=0,k=0; i<dim1 && j<dim2; )
  if (v1[i]<v2[j]){
    i++;
  } else if(v1[i] > v2[j]){
    j++;
  } else{
    //son iguales
    if (k%BLOQUE == 0){
      resp = realloc(resp, (k+BLOQUE)*sizeof(*resp));
    }
    resp[k] = v1[i];
    k++;
    i++;
    j++;
  }
  resp = realloc(resp, k*sizeof(*resp));
  *dimf = k;
  return resp;
}


int main(void){
  int v1[] = {1,2,3,4,5};
  int v2[] = {2,5,6,8};
  size_t dim;

  int * inter = interseccion(v1,v2,5,4,&dim);
  for(int i=0; i<dim; i++){
    printf("%d ",inter[i]);
  }
  printf("\n");

  free(inter);





    // 4 strings que pueda modificar en longitud y contenido
    char * palos[4];
    int cantJugadores = 3;
    char ** nombres = malloc(cantJugadores*sizeof(nombres[0]));

    

    char auxiliar[LENGTH + 1];
    
    for (int i=0; i<cantJugadores; i++){
      printf("Jugador %d: ",i+1);
      size_t len = getline(auxiliar,LENGTH);
      nombres[i] = copyName(auxiliar, len);
    }

    for(int i=0; i<cantJugadores; i++){
      printf("%s\n",nombres[i]);
    }

    nombres = addPlayer(nombres, cantJugadores);
    cantJugadores++;
    for(int i=0; i<cantJugadores; i++){
      printf("%s\n",nombres[i]);
    }

    for(int i=0; i<cantJugadores; i++){
      free(nombres[i]);
    }
    free(nombres);

    // palos[0] debe ser "Copa" (Modificable)
    palos[0] = malloc(5);
    strcpy(palos[0], "Copa");
    palos[1] = malloc(6);
    strcpy(palos[1], "Basto");
    palos[2] = malloc(4);
    strcpy(palos[2], "Oro");
    palos[3] = malloc(7);
    strcpy(palos[3], "Espada");

    //imprimir los palos
    for(int i=0; i<4; i++){
        printf("%s\n", palos[i]);
    }

    //quiero pasar a mayusculas
    //for(char *t=palos[0]; *t=toupper(*t);t++);
    for(int i=0; palos[0][i];i++){
        palos[0][i] = toupper(palos[0][i]);
    }

    //quiero el ultimo espadita
    palos[3] = realloc(palos[3],9);
    strcpy(palos[3], "Espadita");

    
    for(int i=0; i<4; i++){
        free(palos[i]);
    }

    return 0;
}



float * leerNumeros(int * n){
    float * v;
    do{
        *n = getint("ingrese cant num: ");
    }while(*n < 0);

    v = malloc((*n)*sizeof(*v));
    for(int i=0; i<*n; i++){
        v[i] = getfloat("ingrese numero: ");
    }

    return v;
}


int notmain(void){
    int dim;
    float * vec;

    vec = leerNumeros(&dim);

    for(int i=0; i<dim;i++){
        printf("%.2f\n",vec[i]);
    }
    free(vec);

    return 0;  
}