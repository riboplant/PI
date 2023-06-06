#ifndef __LIST_H
#define __LIST_H


typedef struct node{
  int head;
  struct node* tail;
} Node;

typedef struct node* List;

int isEmpty(const List list);
int belongs(const List list, int elem);
int size(const List l);
List add(List l, int elem);
List delete(List l, int elem);
int head(const List l);
List tail(const List l);
void freeList(List l);
int * toArray(const List l);
List fromArray(const int v[], unsigned int dim );
int checkElems(const List list, const int v[], int dim);
void PrintList(const List l);

#endif