#include <stdlib.h>
#include <stdio.h>
#include "getnum.h"

#define TAM 10

int
parte1(void) {

    int * arr1;
    arr1 = malloc(TAM*sizeof(int));

    for (int i=0; i<TAM; i++){
        arr1[i]=0;
    }
    free(arr1);

    int * arr2 = NULL;
    arr2 = realloc(arr2,TAM*sizeof(int));

    arr2 = calloc(TAM, sizeof(int));


    return 0;
}

int parte2(void){

    int barrido;
    int * vector = NULL;

    for (int cant = 0; (barrido=getchar()) != '\n'; cant++)
    {
        vector = realloc(vector, cant*sizeof(int));
        vector[cant] = barrido;
        printf("%d  ", barrido);
    }



    free(vector);

    return 0;
}


int no_rep(int*vec, int dim){
    for(int i=0; i<dim-2; i++){
        if (vec[i] == vec[dim-1]){
            return 1;
        }
    }
    return 0;
}

int* add(int*vec, int *pdim, int obj){
    int dim = *pdim;
    vec = realloc(vec, (dim+1)*sizeof(int));
    vec[dim] = obj;
    (*pdim)++;
    return vec;
}


int parte3(void){

    int aux, cant = 0;
    int*vector = NULL;
    do
    {
        aux = getint("");
        vector = add(vector,&cant, aux);
    } while (no_rep(vector, cant));
    free(vector);
    return 0;
}

