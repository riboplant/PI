#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define BLOCK_SIZE 100        

/*
filleo con -> lo q me pasaron

*/



typedef struct{
  int id;
  int amount;
  char * sender;
  char * receiver;
}typeTransaction;

typedef struct{
  typeTransaction * transactions;
  unsigned int size;
  unsigned int amount;
}typeBlock;

typedef struct {
  typeBlock * blocks;
  unsigned int transactions_per_block;
  unsigned int max_transaction_amount;
  unsigned int size;
}blockchain;

typeTransaction transaction(char * sender, char * receiver, int amount, int block_amount, int * counter){
  int


}



int main(){
  return 0;
}