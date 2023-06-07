#ifndef __TAD_H
#define __TAD_H
typedef struct Complex* ComplejoADT; 
ComplejoADT nuevoComp(int i, int j);
int parteRealComp(ComplejoADT n);
int parteImagComp(ComplejoADT n);
ComplejoADT sumaComp(ComplejoADT n1, ComplejoADT n2);
ComplejoADT restaComp(ComplejoADT n1, ComplejoADT n2);
ComplejoADT multiplicaComp(ComplejoADT n1, ComplejoADT n2);
ComplejoADT divideComp(ComplejoADT n1, ComplejoADT n2);
ComplejoADT conjugadoComp(ComplejoADT n);
void liberaComp(ComplejoADT n);

//-------------------------------------------------------------

typedef struct listCDT * listADT;
typedef char elemType;
typedef int (*compare)(elemType e1, elemType e2);

listADT newList(compare cmp);
void freeList(listADT list);
int isEmptyList(const listADT list);
size_t sizeList(const listADT list);
int addList(listADT list, elemType elem);
int removeList(listADT list, elemType elem);
// elemType get(const listADT list, size_t idx);
int belongsList(const listADT list, elemType elem);

//-----------------------------------------------------------

typedef struct setCDT * setADT;
/* Retorna un nuevo conjunto vacío */
setADT newSet(compare cmp);
void freeSet(setADT set);
int isEmptySet(setADT set);
int setContains(const setADT set, elemType element);
int addElement(setADT set, elemType element);
int deleteElement(setADT set, elemType element);
int sizeSet(const setADT set);
setADT unionSet(setADT set1, setADT set2);
setADT intersectionSet(setADT set1, setADT set2);
setADT diffSet(setADT set1, setADT set2);

#endif 