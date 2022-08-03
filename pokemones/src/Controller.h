#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "LinkedList.h"
#include "Pokemones.h"

int XLVenenos(Pokemon* pokemon);

int Maggiaiuolo_Pokemones_loadFromText(char* path , LinkedList* pArrayListPokemones);
int Maggiaiuolo_Pokemones_ListPokemones(LinkedList* pArrayListPokemones);
int Maggiaiuolo_Pokemones_editValorAtaque(LinkedList* pArrayListPokemones);
int Maggiaiuolo_Pokemones_filtrarFuego(LinkedList* pArrayListPokemones);
int Maggiaiuolo_Pokemones_filtrarXLVeneno(LinkedList* pArrayListPokemones);

#endif /* CONTROLLER_H_ */
