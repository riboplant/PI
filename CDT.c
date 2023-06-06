#include "TAD.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Complex{
  int real;
  int imaginary;
} Complex;

ComplejoADT nuevoComp(int i, int j){
  Complex* n = malloc(sizeof(Complex));
  n->real = i;
  n->imaginary = j;
  return n;
}

int parteRealComp(ComplejoADT n){
  return n->real;
}

int parteImagComp(ComplejoADT n){
  return n->imaginary;
}

ComplejoADT sumaComp(ComplejoADT n1, ComplejoADT n2){
  Complex* n = malloc(sizeof(Complex));
  n->real = n1->real + n2->real;
  n->imaginary = n1->imaginary + n2->imaginary;
  return n;
}

ComplejoADT restaComp(ComplejoADT n1, ComplejoADT n2){
  Complex* n = malloc(sizeof(Complex));
  n->real = n1->real - n2->real;
  n->imaginary = n1->imaginary - n2->imaginary;
  return n;
}

ComplejoADT multiplicaComp(ComplejoADT n1, ComplejoADT n2){
  Complex* n = malloc(sizeof(Complex));
  n->real = ((n1->real)*(n2->real)) - ((n1->imaginary)*(n2->imaginary));
  n->imaginary = ((n1->real)*(n2->imaginary)) + ((n2->real)*(n1->imaginary));
  return n;
}

ComplejoADT conjugadoComp(ComplejoADT n){
  Complex* m = malloc(sizeof(Complex));
  m->real = n->real;
  m->imaginary = - n->imaginary;
  return n;
}

ComplejoADT divideComp(ComplejoADT n1, ComplejoADT n2){
  Complex* n = malloc(sizeof(Complex));
  Complex* aux = conjugadoComp(n2);
  aux = multiplicaComp(n2, aux);
  Complex* auxx = multiplicaComp(n1,aux);
  n->real = (auxx->real) / aux->real;
  n->imaginary = (auxx->imaginary) / aux->real;
  return n;
}

void liberaComp(ComplejoADT n){
  free(n);
}