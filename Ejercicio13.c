#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "rankingADT.h"


static int compare(char * source, char * target) {
   return strcmp(source, target);
}

int main(void) {
   rankingADT r = newRanking(NULL, 0, compare);  // sin datos iniciales
   addRanking(r, "Footloose");
   addRanking(r, "Yesterday");
   addRanking(r, "La bamba");
   addRanking(r, "Sucio y desprolijo");
   addRanking(r, "Ride of the Valkyries");
   addRanking(r, "Yesterday");   // no lo agrega, pero sube
   addRanking(r, "Ride of the Valkyries");  // no lo agrega, pero sube

   char * aux;
   int n;
   n = getByRanking(r, 6, &aux); // Solo hay 5 elementos, n es 0, aux queda igual
   n = getByRanking(r, 1, &aux); // n = 1, aux = "Yesterday" 
   // No hay que liberar aux, daría error  
   n = getByRanking(r, 0, &aux);  // n=0, no hay puesto 0 en el ranking

   n = getByRanking(r, 2, &aux); // n = 1, aux = "Footloose"
   n = getByRanking(r, 1, &aux); // n = 1, aux = "Footloose"

 
   n = contains(r, "Ride of the Valkyries"); // retorna 1
   n = contains(r, "Sucio y desprolijo"); // retorna 1

   size_t dimTop = 10;
   char ** top = getTopRanking(r, &dimTop);
   // dimTop = 5
   // top = { "Footloose", "Yesterday", "Ride of the Valkyries", 
   //         "Sucio y desprolijo", "La bamba"}

   downByRanking(r, 1);

   dimTop = 2;
   char ** top = getTopRanking(r, &dimTop);
   // dimTop = 2
   // top = { "Yesterday", "Footloose"}


   freeRanking(r);

   return 0;
}
