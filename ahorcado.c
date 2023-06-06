#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define WORDS 5
#define TRYS 7

int belongs (char letra, char vec[], size_t dimvec){
  for (int i=0; i<dimvec; i++){
    if (vec[i] == letra){
      return 1;
    }
  }
  return 0;
}

char pedirLetra(char usadas[], size_t dimusadas){
  printf("Ingrese una letra nueva\n");
  char c = getchar();
  if(belongs(c, usadas,dimusadas) || c<'a' || c>'z'){
    c = pedirLetra(usadas,dimusadas);
  }
  return c;
}

int checkLetter (char * word, char printable[], char letra){
  int correcta = 0;
  for (int i=0; i< sizeof(word); i++){
    if (word[i] == letra){
      printable[i] = letra;
      correcta = 1;
    }
  }
  return correcta;
}

int checkWord(char word1[], char word2[], size_t largo){
  for(int i=0; i<largo; i++){
    if(word1[i]!=word2[i]){
      return 0;
    }
  }
  return 1;
}

void imprimir(char * vec){
  printf("%s\n",vec);
}

int main(void){
  srand(time(NULL));
  char * words[WORDS] = {"arbol","jungla","musica","acero","sushi"};
  char usadas[27];
  size_t dimusadas = 0;
  char * word = words[rand()%WORDS];

  int largo = strlen(word);

  char pr[largo+1];
  int s=0;
  for(; s<largo;){
    pr[s++] = '-';
  }
  pr[s] = 0;
  imprimir(word);


  printf("%s\n",pr);


  char letra;
  for (int i=0; i<TRYS;){
    letra = pedirLetra(usadas,dimusadas);
    usadas[dimusadas++] = letra;

    if(!checkLetter(word,pr,letra)){
      i++;
    }
    printf("%s\n",pr);
    printf("quedan %d intentos\n",TRYS-i);

    if(checkWord(word,pr,largo)){
      printf("ganaste al intento %d.\n",i);
      return 0;
    }

  }
  printf("perdiste.\n");
  return 1;
}