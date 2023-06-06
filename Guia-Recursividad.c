#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <math.h>
//#include <ctype.h>

int palindromoRec(const char* s, unsigned int len){
  if(len<=1){
    return 1;
  }
  return s[0]==s[len-1] && palindromoRec(s+1, len-2);
}

int palindromo(const char* s){
  return palindromoRec(s,strlen(s));
}

void regla(int h){
  if(h==1){
    printf("%d",1);
    return;
  }
  regla(h/2);
  printf("%d",h);
  regla(h/2);
}

int branches(int ini, int min){
  if(ini < min){
    return 0;
  }
  return 1 + 2 * branches(ini/2, min);
}

void factorial(int n, int* resp){
  if(n == 1){
    *resp=1;
    return;
  }
  factorial(n-1, resp);
  *resp *= n;
}

int ej1(const int v[], unsigned int dim){
  if(dim == 1){
    return *v;
  }
  return *v + ej1(v+1, dim-1);
}

int suma(int num){
  if(num<10){
    return num;
  }
  return num%10 + suma(num/10);
}

int productoEsc(const int vec1[], const int vec2[], unsigned int dim){
  if(dim == 1){
    return ((*vec1) * (*vec2));
  }
  return ((*vec1) * (*vec2)) + productoEsc(vec1+1, vec2+1, dim-1);
}

/*
int esPalindromoRec(const char* s, unsigned int len){
  if(len<=1){
    return 1;
  }
  return (*s == s[len-1]) && esPalindromoRec(s+1, len-2);
}

int esPalindromo(const char* s){
int len = strlen(s);
return esPalindromoRec(s, len);
}
*/

int busquedaBinaria(const int vec[], unsigned int dim, int n){
  if(dim==0){
    return 0;
  }
  if(vec[dim/2]==n){
    return 1;
  }
  if(vec[dim/2]>n){
    return busquedaBinaria(vec, dim/2, n);
  }
  else{
    return busquedaBinaria(vec + dim/2 + 1, dim - dim/2 - 1, n);
  }
}

int Ackermann(unsigned int a, unsigned int b){
  if(a == 0){
    return b + 1;
  }
  else if(b == 0){
    return Ackermann(a-1, 1);
  }
  else{
    return Ackermann( a-1, Ackermann(a,b-1));
  }
}

#define EPSILON 0.01

float raizCuadrada(float valorAnterior, int iteraciones, float x){
  if (iteraciones == 0){
    return x / 2;
  }
  return (raizCuadrada(valorAnterior, iteraciones-1, x) + (x / raizCuadrada(valorAnterior, iteraciones-1, x)))/2;
}

void invierteRec(char * origen, char * destino, unsigned int len){
  if(len == 0){
    destino[0] = 0;
    return;
  }
  destino[0] = origen[len-1];
  invierteRec(origen, destino+1, len-1);

}

void invierte(char * origen, char * destino){
  invierteRec(origen, destino, strlen(origen));
}

#define MAX 10

void reemplazoRec(int m[][MAX], unsigned int dim, unsigned int fila, unsigned int columna, int incrementoy, unsigned int incrementox){
  if(fila<0 || columna<0 || fila >= dim || columna>=dim){
    return;
  }
  m[fila][columna] = ( m[fila][columna]?0:1 );
  reemplazoRec(m, dim, fila+incrementoy, columna+incrementox, incrementoy, incrementox);
}

void reemplazo(int m[][MAX], unsigned int dim, unsigned int fila, unsigned int columna){
  reemplazoRec(m, dim, fila, columna, 1, 1);
  reemplazoRec(m, dim, fila, columna, 1, -1);
  reemplazoRec(m, dim, fila, columna, -1, 1);
  reemplazoRec(m, dim, fila, columna, -1, -1);
  m[fila][columna] = ( m[fila][columna]?0:1 );
}

int balance(char * s){
  if(*s == 0){
    return 0;
  }
  return ( (*s=='(')?1:0 ) + ( (*s==')')?-1:0 ) + balance(s+1);
}

char * strrchrRec(char * s, char c){
  if(*s == 0){
    return NULL;
  }
  char* resp = strrchrRec(s+1, c);
  if(*s == c){
    return (resp == NULL) ? s : resp;
  }
  return resp;  
}


void piramide(int*  latas, int * altura){
  if(*latas<(*altura)*(*altura)){
    (*altura)--;
    return;
  }
  (*latas)-=(*altura)*(*altura);
  (*altura)++;
  piramide(latas, altura);
}

int orden(const int vec[]){
  if(vec[1] == -1 || vec[0] == -1){
    return 0;
  }
  if(vec[2] == -1){
    return (vec[0]<vec[1])?1:-1;
  }
  if(vec[0]>vec[1]){
    return -(orden(vec+1) == -1);
  }
  if(vec[0]<vec[1]){
    return (orden(vec+1)) == 1;
  }
  return 0;
}
int isdigit(char c){
  if(c >= '0' && c <= '9'){
    return 1;
  }
  else{
    return 0;
  }
}

int isalpha(char c){
  if(c >= 'a' && c <= 'z'){
    return 1;
  }
  else{
    return 0;
  }
}

int bienformado(const char * s){ 
  //2aa falla, abcd22 tambien
  if(*s == 0){
    return 0;
  }
  else if(isdigit(*s)){
    return bienformado(s+1) - (int)*s + '0';
  }
  else if(isalpha(*s)){
    return 1 + bienformado(s+1);
  }
  else{
    return 110;
  }
}

int main(void) {
  char * zero[]={"abcd4a10bb2", "", "0000", "a1", "abc3", "0a1"};

  char * not_zero[] ={ "a", "1", "a2", "abc2", "abc4", "abc33", "0123", "2aa", "$1", "@@2", "abcd22", "@@"};

  for(int i=0; i < sizeof(zero)/sizeof(zero[0]);i++) {
    printf("%s\n", zero[i]);
    assert(bienformado(zero[i])==0);
  }    

  for(int i=0; i < sizeof(not_zero)/sizeof(not_zero[0]);i++) {
    printf("%s\n", not_zero[i]);
    assert(bienformado(not_zero[i]) !=0);
 }
  printf ("OK!\n");
  return 0;
}