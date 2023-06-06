#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "getnum.h"

#define X 5 
#define RANDOM (rand()%9)+1
#define MAXLVL 10.0
#define MINLVL 1
#define BASE 10

int belongs(int * arr, int dim, int num){
  int belongs=0;
  for(int i=0; i<dim; i++){
    if (arr[i]==num){
      belongs=1;
    }
  }
  return belongs;
}


int * GenerarAleatorio(void){
  int * arr = calloc(X,sizeof(int));
  for (int i=0; i<X; i++){
    int flag = 1, num;
    while(flag==1){
      int aux=RANDOM;
      flag = belongs(arr,i,aux);
      num = aux;
    }
    arr[i]=num;
    //printf("%d\n",num);
  }
  return arr;
}

int elegirNivel(){
  int nivel;
  while( (nivel = (getint("Elegir nivel(1-10): "))) <= MINLVL || nivel >= MAXLVL){
  }
  return nivel;
}

int * leerNumero(void){
  char arr[X+1];
  int i=0;
  printf("Ingrese un numero de %d digitos sin repeticiones: ",X);
  while (i<X)
  {
    arr[i] = getchar();
    //printf("%c\n",arr[i]);
    i++;
  }
  arr[X] = 0;
  //printf("%s\n",arr);

  int num = atoi(arr);
  //printf("%d\n", num);

  int * in = malloc(X*sizeof(int));
  for(int i=0; i<X; i++){
    in[i] = (int)(num/pow(BASE,(double)(X-i-1)))%BASE;
    //printf("%d\n", in[i]);
  }  
  while (getchar() != '\n');

  return in;
}

int numeroValido(int * num){
  int valid = 1;
  for (int i=0; i<X; i++){
    for (int j=i+1; j<X; j++){
      if (num[i] == num[j] || num[i] < 1 || num[i] > 9 ){
        valid = 0;
      }
    }
  }

  return valid;
}

int coincideNumero(int * in, int * try){
  int bien = 0, regular = 0, perfecto = 1;
  for (int i=0; i<X; i++){
    if (in[i] == try[i]){
      bien++;
    }else if (belongs(in,X,try[i])){
      regular++;
        perfecto = 0;
    }else{
      perfecto = 0;
    }
  }
  printf("Bien: %d, Regular: %d\n", bien, regular);
  return perfecto;
}

int * ingresar (void){

  int * ingreso;
  int try = 0;
  do
  {
    if(try){
      free(ingreso);
    }
    try++;

  ingreso = leerNumero();
  } while (!numeroValido(ingreso));

  return ingreso;
}

void imprimir(int * arr, int dim){
  for (int i=0; i<X; i++){
    printf("%d", arr[i]);
  }
  printf("\n");
}

int main(void){
  srand(time(NULL));
  int * arr = GenerarAleatorio();
  imprimir(arr, X);
  //int level = elegirNivel();
  int level = 5;

  int * ingreso; 
  imprimir(arr, X);
  int i=0, p;
  do{
    if(i){
      free(ingreso);
    }
    i++;
    printf("intento %d\n",i);

    ingreso = ingresar();
    imprimir(ingreso, X);
    p = coincideNumero(arr, ingreso);
  } while (i<level &&  !p);
  
  if (p){
    printf("El numero es correcto.\n");
  }else {
    printf("Perdiste.\n");
  }

  free(arr);
  free(ingreso);
  return 0;
}