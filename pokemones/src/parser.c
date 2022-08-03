#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Pokemones.h"
#include "parser.h"

int parser_PokemonFromText(FILE* pFile , LinkedList* pArrayListPokemones)
{
	if(pFile != NULL && pArrayListPokemones != NULL)
	{
		char numero[20];
		char nombre[100];
		char tipo[100];
		char tamanio[20];
		char ataqueCargado[100];
		char valorAtaque[100];
		char esVariocolor[100];
		Pokemon* unPokemon;

		while(!feof(pFile))
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",numero,nombre,tipo,tamanio,ataqueCargado,valorAtaque,esVariocolor);
			unPokemon = Pokemon_newParametros(numero, nombre, tipo, tamanio, ataqueCargado, valorAtaque, esVariocolor);
			ll_add(pArrayListPokemones,unPokemon);
		}
	}
    return 1;
}
