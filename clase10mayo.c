#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "getnum.h"


typedef struct {
  int dia, mes, anio;
} fecha;

typedef struct {
  char nombre[30];
  char telefono[15];
  char domicilio[30];
  fecha nac;
} tipoPersona;

int main(){

  fecha cita = {.anio = 2023, .mes = 6, .dia = 12};
  fecha carde = {20,5,2023};

  fecha nacimiento;
  nacimiento = (fecha){
    .dia = 5,
    .mes = 12,
    .anio = 2002
  };
  // los char[] no son l-values en structs, debo usar strcpy()

  tipoPersona Carlito;
  Carlito.nac.anio = 2004;
  //estructuras anidadas

  return 0;
}