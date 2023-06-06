#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <assert.h>

#define COLS 7
#define FILS 6
#define DIRECS 8

typedef enum {DER=0, IZQ, ABA, ARR, I_AR, I_AB, D_AR, D_AB } Tdireccion;
const int direc[8][2] = { {1,0}, {-1,0}, {0,1}, {0,-1}, {-1,-1}, {-1,1}, {1,-1}, {1,1} };
typedef struct {
	char * palabra;
	size_t fila;
	size_t columna;
	Tdireccion direccion;
} posicion;
typedef posicion * posiciones;

int check_direc(char matriz[][COLS], char * word, int posy, int posx, int incx, int incy){
  int estaEnMat=1;
  int i;
  for(i=0; *(word+i) && estaEnMat && posx>=0 && posy>=0 && posx<COLS && posy<FILS;i++,posx+=incx,posy+=incy){
    if(*(word+i) != matriz[posy][posx]){
      estaEnMat=0;
    }
  }
  return *(word+i)=='\0' && estaEnMat;
}

int check_pos(char matriz[][COLS], char * word, int posy, int posx){
  int flag = -1;
  for(int d=0; d<DIRECS; d++){
    if(check_direc(matriz, word, posy, posx, direc[d][0], direc[d][1])){
      flag = d;
    }
  }
  return flag;
}

void agregar_posicion( posiciones *vec , char * word, int posx, int posy, int dir, int *cant ){

    int n = *cant;
    *cant += 1;
    *vec = realloc( *vec, (*cant) * sizeof(posicion));
    (*vec)[n].palabra = malloc(strlen(word)+1);//error SEGV
    strcpy((*vec)[n].palabra, word);
    (*vec)[n].fila = posy;
    (*vec)[n].columna = posx;
    (*vec)[n].direccion = dir;
}

void agregar_ultimo(posiciones* vec, int* cant){
  *vec = realloc(*vec, ++(*cant)*sizeof(posicion));
  (*vec)[*cant-1].palabra = NULL;
}

void liberar(posiciones poss, int cant){
    printf("cant: %d\n",cant);

  for(int i=0; i<cant; i++){
    free((poss)[i].palabra);
  }
  free(poss);
}

void imprimirTodo(int cant, posiciones arr){
  for(int i=0; i<cant; i++){
    printf("Palabra: %s\n", arr[i].palabra);
    printf("posx: %d\n", arr[i].columna);
    printf("posy: %d\n", arr[i].fila);
    printf("direc: %d\n", arr[i].direccion);
    printf("\n");
  }


}

posiciones resolverSopa(char matriz[][COLS], char * diccionario[], int*cant){
  *cant = 0;
  posiciones poss = NULL;


  int aux;
  for(int i=0; i<FILS; i++){
    for(int j=0; j<COLS; j++){
      for(int w=0; *diccionario[w]; w++){
        if((aux = check_pos(matriz, diccionario[w], i, j)) > -1){
          agregar_posicion(&poss, diccionario[w], j, i, aux, cant);
        }
      }
    }
  }
  printf("cant: %d\n",*cant);
  agregar_ultimo(&poss, cant);
  return poss;
}

int main(void){
char * diccionario[] = {"ARRE", "CANCION", "CAPA", "ERROR", "ORCO", "PERRO", "PERTINAZ", "REA", "RIO", ""};
  int cant;
  char sopa[FILS][COLS] =
     {{'X','X','X','O','X','X','X'},
      {'A','P','A','C','Y','Y','O'},
      {'Z','E','Z','R','Z','C','X'},
      {'E','R','R','O','R','X','X'},
      {'X','R','I','O','I','E','X'},
      {'X','O','X','X','O','X','X'}};
  
  posiciones res = resolverSopa( sopa, diccionario, &cant);
  // La cantidad de palabras encontradas debe ser 9
  imprimirTodo(cant,res);
  printf("%p\n",((struct posicion*)NULL)->fila);
  liberar(res, cant);
  return 0;
}
