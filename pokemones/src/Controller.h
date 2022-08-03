#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "LinkedList.h"
#include "Pokemones.h"

/** \brief Funcion criterio para Venenos XL
 * (Son tipo veneno y tamaño XL)
 * \param pokemon void*
 * \return 1 si cumple - o si NO cumple
 */
int XLVenenos(void* pokemon);

/** \brief Funcion criterio para Ataques cargados
 * (Pokemones de tipo Bug, Fire y Grass aumentarán su
 * poder un 20% siempre y cuando el tamaño sea XL, un 10% si es L y sino un 5 para cualquier
 * otro tamaño.)
 * \param pokemon void*
 * \return 1 si cumple - o si NO cumple
 */
int AtaqueCargado(void* pokemon);

/** \brief Funcion criterio para la batalla pokemon
 * (Pokémon de tipo Fire de tamaño XL, con ataque Lanzallamas y cuyo valor de ataque sea
 * superior a 80 o de tipo Water tamaño L, con ataque hidrobomba entre superior a 80.)
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
