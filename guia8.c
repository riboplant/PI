#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <assert.h>

#define MAZO 52
#define RANDOM(n) rand()%n + 1
#define MANO 5
#define PALOS 4

void sort (int mazo[], size_t dim){
  for(int i=0; i<dim; i++){
    int r = RANDOM(MAZO-1);
    int aux = mazo[r];
    mazo[r] = mazo[i];
    mazo[i] = aux;
  }

}

typedef int mano[MANO];

typedef struct 
{
   mano jugador[MAZO/MANO];
   int score ;
} tipoJugador;



void repartir(tipoJugador * player1, tipoJugador * player2, int mazo[]){
  int barrido = 0;
  for(int i=0; i<(MAZO/MANO)/2; i++){
    for(int j=0; j<MANO; j++){
      player1->jugador[i][j] = mazo[barrido++];
      player2->jugador[i][j] = mazo[barrido++];
    }
  }
}

void print_player_cards(tipoJugador player){
  for(int i=0; i<(MAZO/MANO)/2; i++){
    for(int j=0; j<MANO; j++){
      printf("%d ",player.jugador[i][j]);
    }
    printf("\n");
  }
}

int valor_mano(mano mano, int * repetidas){
  int cartas[MAZO/PALOS] = {0};
  for(int i=0; i<MANO; i++){
    cartas[mano[i]-1]++;
  }
  int aux =0;
  for(int i=0; i<MAZO/PALOS; i++){
    if(cartas[i]>=aux){
      aux = i+1;
    }
  }
  *repetidas = cartas[aux-1];
  return aux;
}

int jugar_mano(mano mano_player1, mano mano_player2) {

  for(int i=0; i<MANO; i++){
    mano_player1[i] = (mano_player1[i]%(MAZO/PALOS) )+1;
  }
  for(int i=0; i<MANO; i++){
    mano_player2[i] = (mano_player2[i]%(MAZO/PALOS) )+1;
  }
  int repe1;
  int valor1 = valor_mano(mano_player1, &repe1);
  int repe2;
  int valor2 = valor_mano(mano_player2, &repe2);

  if(repe1>repe2){
    return 1;
  }
  if(repe2>repe1){
    return 2;
  }
  if(repe1==repe2){
    if(valor1>valor2){
      return 1;
    }
    if(valor2>valor1){
      return 2;
    }
    if(valor1==valor2){
      return 0;
    }
  }
  return -1;
}


int card_game(void){
  srand(time(NULL));

  int mazo[MAZO];
  for(int i=0; i<MAZO; i++){
    mazo[i] = i+1;
  }
  sort(mazo, MAZO);

  for(int i=0;i<MAZO;i++){
    printf("%d ",mazo[i]);
  }
  printf("\n");

  tipoJugador player;
  tipoJugador pc;

  player.score = 0;
  pc.score = 0;

  repartir(&player, &pc, mazo);
  print_player_cards(player);
  print_player_cards(pc);

  for(int i=0; i<MAZO/MANO; i++){
    int v = jugar_mano(player.jugador[i], pc.jugador[i]);
    if(v==1){
      player.score++;
    }
    if(v==2){
      pc.score++;
    }
    if(v==0){
      player.score++;
      pc.score++;
    }
  }
  print_player_cards(player);
  print_player_cards(pc);

  printf("%d %d\n", player.score, pc.score);


  if(player.score > pc.score){
    printf("Gana el Jugador\n");
  }
  if(pc.score > player.score){
    printf("Gana la computadora\n");
  }
  if(pc.score == player.score){
    printf("Es un empate\n");
  }
  return 0;
}

#define RADIO 10

int ejercicio5(void){

  struct{
    int x;
    int y;
    int dist;
  }posicion;
  posicion.x=0;
  posicion.y=0;

  int movimientos[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

  int t, r;
  for(t=0; posicion.dist<RADIO; t++){
    r = RANDOM(4) - 1;

    posicion.x+= movimientos[r][0];
    posicion.y+= movimientos[r][1];
   
    posicion.dist = abs(posicion.x) + abs(posicion.y);
  }

  printf("RADIO: %d\nTiempo: %d\nRelacion: %.2f\n", RADIO, t, (double)RADIO/t);
  return 0;
}

typedef float intervalos[2];
#define FUNCION(x) (x*x) - 2;
#define MIN -20
#define MAX 20
#define EPSILON 0.001
#define INTERVALOS 100000
#define DELTAX ((float)(abs(MIN) + abs(MAX)) / INTERVALOS)

  typedef struct {
    unsigned int cant;
    intervalos * pares;
  } tipoRaices;

void escribirValor(tipoRaices * raices, intervalos intervalo){
  raices->cant++;
  raices->pares = realloc(raices->pares, raices->cant * sizeof(intervalos));
  raices->pares[raices->cant-1][0] = intervalo[0];
  raices->pares[raices->cant-1][1] = intervalo[1];
}

void printRaices(const tipoRaices raiz){
  printf("%d\n",raiz.cant);
  for (int i=0; i<raiz.cant; i++)
  {
    printf("%f, %f", *raiz.pares[0], *raiz.pares[1]);
  }
  printf("/n");
}

int main(void){
  tipoRaices raices = {
    .cant = 0,
    .pares = NULL  
  };

float barrido, valor_actual, valor_anterior = FUNCION(MIN);
intervalos ab;
int flag = 0;
for(barrido = MIN; barrido < MAX; barrido += DELTAX){
  valor_actual = FUNCION(barrido);
  if(valor_actual <= 0+EPSILON && valor_actual >= 0-EPSILON){
    if(!flag){
      flag = 1;
      ab[0] = barrido - DELTAX;
    }
    if(flag){
      ab[1] = barrido + DELTAX;
    }
  }
  else if(valor_anterior <= 0+EPSILON && valor_anterior >= 0-EPSILON && flag){
    escribirValor(&raices, ab);
    flag = 0;
    ab[0] = 0;
    ab[1] = 0;
  }
  else if(valor_anterior*valor_actual < 0){
    ab[0] = barrido - DELTAX;
    ab[1] = barrido;
    escribirValor(&raices, ab);
  }
  valor_anterior = valor_actual;
  }
  printRaices(raices);
  free(raices.pares);
  return 0;
}


