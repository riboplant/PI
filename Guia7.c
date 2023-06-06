#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <assert.h>

#define DIM 30

int ejercicio5(char * arr[DIM], char * cursos[DIM], char * cursoG[DIM], char * cursoH[DIM]){
    int dimh = 0, dimg = 0;    
    for (int i=0; i<DIM; i++){
        if (*cursos[i] == 'G'){
                *cursoG[dimg++] = *arr[i];
        }
        else if(*cursos[i] == 'H'){
                *cursoG[dimh++] = *arr[i];
        }
    }

    return 0;
}

char * strcat2(char * s, char * t){
  char * n;
  for(n=s; *n; n++);
  for(;*(n+1);n++){
    *n = *(n+1);
  }
  *(n+1) = 0;
  return s;
}

char * strcat3(char * s, char * t){
  int i = strlen(s);
  char * a = s + i;
  char * b = t;
  for(; *b; b++, a++,i++){
    s = realloc(s,i+2);
    *a = *b;
  }
    *(s+i+1) = 0;
    return s;
}

char * copiaPrefijo(char * s, int n){
  if(!strlen(s)){
    return NULL;
  }
  int i = 0;
  char * a = s;
  while (i<n && *a){
    i++;
    a++;
  }
  *(s+i) = 0;
  return s;
}

/*char * aprobados(char * alumnos, int * proms){
  int dimalumnos = 0;
  for (char*c=alumnos; *c; c++ ){
    dimalumnos++;
  }

  char * aprobados = malloc(dimalumnos);

  for(int i=0; i<dimalumnos; )
}*/

char * aprobados(char * alumnos, int * proms){
  int dimaprobados = 0, totalaprobados = 0;
  char * aprobados = malloc(0);
  for(;*alumnos; alumnos++, proms++){
    if(*proms >= 4){
      dimaprobados+=strlen(alumnos);
      aprobados = realloc(aprobados, dimaprobados);
      strcpy((aprobados+totalaprobados),alumnos);
      totalaprobados++;
    }
  }

  return aprobados;
}

void liberaAprobados(char * s){
  free(s);
}

typedef char * TAlumnos; 

int
main(void) {
TAlumnos alumnos = {"Juan", "Pedro", "Martin", ""};
    int notas[] = {1, 4, 10, 2, 10, 11};
    
    char ** apr = aprobados(alumnos, notas);
    if(apr == NULL){
        puts("No hay suficiente memoria!");
        return 1;
    }
    assert(!strcmp(alumnos[1], apr[0]) && !strcmp(alumnos[2], apr[1]) && !strcmp(alumnos[3], apr[2]));
    
    liberaAprobados(apr);
    
    puts("OK");

  return 0;
}