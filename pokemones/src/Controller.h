#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "LinkedList.h"
#include "Pokemones.h"

int XLVenenos(void* pokemon);
int AtaqueCargado(void* pokemon);
int BatallaPokemon(void* pokemon);

int Maggiaiuolo_Pokemones_loadFromText(char* path , LinkedList* pArrayListPokemones);
int Maggiaiuolo_Pokemones_ListPokemones(LinkedList* pArrayListPokemones);
int Maggiaiuolo_Pokemones_editValorAtaque(LinkedList* pArrayListPokemones);
int Maggiaiuolo_Pokemones_filtrarFuego(LinkedList* pArrayListPokemones);
int Maggiaiuolo_Pokemones_filtrarXLVeneno(LinkedList* pArrayListPokemones);
int Maggiaiuolo_Pokemones_ataqueCargado(LinkedList* pArrayListPokemones);
int Maggiaiuolo_Pokemones_batallaPokemon(LinkedList* pArrayListPokemones);

#endif /* CONTROLLER_H_ */
