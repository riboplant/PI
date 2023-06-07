#ifndef __SETADT_H
#define __SETADT_H

typedef char* elemType;
typedef int (*compare)(const elemType e1, const elemType e2);
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