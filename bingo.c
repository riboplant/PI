#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLS 5
#define FILS 3
#define MAX 90
#define RANDOM(dim) rand()%dim

typedef  int TipoLinea[5];
typedef  TipoLinea  TipoCarton [3];

int belongs(int arr[], int num, size_t dim){
  int belongs = 0;
  for(int i=0; i<dim; i++){
    if (arr[i] == num){
      belongs = 1;
    }
  }
  return belongs;
}

void tomaNumero(int pos[], int dim, int n){
  for(int i=n; i<dim; i++){
    pos[i] = pos[i+1];
  }
}

void generarCarton(TipoCarton carton){
  int aux[MAX]; 
  for (int i=0; i<MAX ;i++){
    aux[i] = i+1;
    //printf("%d ",i+1);
  }
  size_t dim = MAX;
  int r;
  for(int i=0; i<FILS; i++){
    for (int j=0; j<COLS; j++){
      r = RANDOM(dim);
      dim--;
      carton[i][j] = aux[r];
      tomaNumero(aux, dim, r);
    }

  }
   

}

void imprimirCarton(TipoCarton carton){
  for(int i=0; i<FILS; i++){
    for (int j=0; j<COLS; j++){
      printf("%d ", carton[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void sacarBolilla(int bolillero[], int extraidas[], size_t dimbol, size_t dimext){
  int r = RANDOM(dimbol);
  extraidas[dimext] = bolillero[r];
  tomaNumero(bolillero, dimbol-1, r);
}

void controlarCarton(int bolillero[], size_t dimbol, TipoCarton carton){
  //agregar que se fije si cada numero de las filas esta --> fila completa si todas las filas comp -->fila
  //usar un int filcomp[3] = {0,0,0} y modificar las pos de las que esten completas (para dentro de la funcion)
  int bingo =1;
  for (int i=0, filac; i<FILS; i++){
    filac = 1;
    for (int j=0; j<COLS; j++){
      if ()
    }
  }


}

int main(){
  srand(time(NULL));
  TipoCarton player1, player2;
  int bolillero[MAX], extraidas[MAX];
  size_t dimbol = MAX, dimext = 0;
  for(int i=0; i<MAX; i++){
    bolillero[i] = i+1;
  }

  generarCarton(player1);
  generarCarton(player2);
  imprimirCarton(player1);
  imprimirCarton(player2);

  for(int i=0; i<10; i++){
    sacarBolilla(bolillero,extraidas,dimbol--,dimext++);
    for(int j=0; j<dimext; j++){
      printf("%d ",extraidas[j]);
    }
    printf("\n");
  }


  return 0;
}