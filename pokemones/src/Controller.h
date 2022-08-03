#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "LinkedList.h"
#include "Pokemones.h"

/** \brief Funcion criterio para Venenos XL
 * (Son tipo veneno y tama�o XL)
 * \param pokemon void*
 * \return 1 si cumple - o si NO cumple
 */
int XLVenenos(void* pokemon);

/** \brief Funcion criterio para Ataques cargados
 * (Pokemones de tipo Bug, Fire y Grass aumentar�n su
 * poder un 20% siempre y cuando el tama�o sea XL, un 10% si es L y sino un 5 para cualquier
 * otro tama�o.)
 * \param pokemon void*
 * \return 1 si cumple - o si NO cumple
 */
int AtaqueCargado(void* pokemon);

/** \brief Funcion criterio para la batalla pokemon
 * (Pok�mon de tipo Fire de tama�o XL, con ataque Lanzallamas y cuyo valor de ataque sea
 * superior a 80 o de tipo Water tama�o L, con ataque hidrobomba entre superior a 80.)
 * \param pokemon void*
 * \return 1 si cumple - o si NO cumple
 */
int BatallaPokemon(void* pokemon);


int Maggiaiuolo_Pokemones_loadFromText(char* path , LinkedList* pArrayListPokemones);
int Maggiaiuolo_Pokemones_ListPokemones(LinkedList* pArrayListPokemones);
int Maggiaiuolo_Pokemones_editValorAtaque(LinkedList* pArrayListPokemones);
int Maggiaiuolo_Pokemones_filtrarFuego(LinkedList* pArrayListPokemones);
int Maggiaiuolo_Pokemones_filtrarXLVeneno(LinkedList* pArrayListPokemones);
int Maggiaiuolo_Pokemones_ataqueCargado(LinkedList* pArrayListPokemones);
int Maggiaiuolo_Pokemones_batallaPokemon(LinkedList* pArrayListPokemones);

#endif /* CONTROLLER_H_ */
