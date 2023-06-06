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
#endif 