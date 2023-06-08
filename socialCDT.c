#include "socialTAD.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct Relaciones{
  elemType name;
  struct Relaciones* tail;
} Relaciones;
typedef struct Relaciones* ListRel;


typedef struct socialCDT{
  elemType persona;
  ListRel allegados;
  struct socialCDT* siguiente;
  size_t size;
} socialCDT;

socialADT newSocial(){
  return NULL;
}
 
static void freeRels(ListRel list){
  if(list == NULL){
    return;
  }
  freeRels(list->tail);
  free(list);
}

void freeSocial(socialADT soc){
  if(soc == NULL){
    return;
  }
  free(soc->siguiente);
  freeRels(soc->allegados);
  free(soc);
}
 
/* Almacena una nueva persona. Si la persona existe, no hace nada
** Guarda una copia del nombre, no simplemente el puntero
*/

static int relBelongs(ListRel list, const char* name){
  if(list == NULL){
    return 0;
  }
  if(strcmp(list->name, name) == 0){
    return 1;
  }
  return relBelongs(list->tail, name);
}

static int socBelongs(socialADT soc, const char* name){
  if(soc == NULL){
    return 0;
  }
  if(strcmp(soc->persona, name) == 0){
    return 1;
  }
  return socBelongs(soc->siguiente, name);
}

void addPerson(socialADT soc, const char * name){
  if(soc == NULL){
    soc = malloc(sizeof(socialCDT));
    strcpy(soc->persona, name);
    soc->size = 1;
    soc->siguiente = NULL;
    soc->allegados = NULL;
    return soc;
  }
  if(strcmp(soc->persona, name) == 0){
    return;
  }
  soc->siguiente = socBelongs(soc->siguiente, name);
  return;
}

/* Si existe una persona con ese nombre, agrega la nueva relación
** Si la persona no existe, no hace nada
** Si related ya estaba relacionado, lo agrega repetido
** Almacena una copia de related, no simplemente el puntero
**
 */

void addRelRec(ListRel list, elemType elem){
  if(list == NULL || strcmp(list->name, elem) == )


}



void addRelated(socialADT soc, const char * name, const char * related){
  if(!socBelongs(soc, name)){
    return;
  }

  addRelRec(soc, related);

}

/* Retorna una copia de los nombres relacionados con una persona
** en orden alfabético.
** Para marcar el final, después del último nombre se coloca NULL
** Si la persona no existe, retorna un vector que sólo tiene a NULL como 
** elemento
 */
char ** related(const socialADT soc, const char * person);

/* Retorna una copia de los nombres de las personas en orden alfabético.
** Para marcar el final, después del último nombre se coloca NULL
** Si no hay personas, retorna un vector que sólo tiene a NULL como 
** elemento
 */
char ** persons(const socialADT soc);
