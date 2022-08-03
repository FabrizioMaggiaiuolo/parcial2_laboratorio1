#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Pokemones.h"
#include "parser.h"
#include "inputs.h"

int Maggiaiuolo_Pokemones_loadFromText(char* path , LinkedList* pArrayListPokemones)
{
	int respuesta;
	respuesta = 0;
	if(path != NULL)
	{
		if(pArrayListPokemones != NULL)
		{
			FILE* pFile = fopen(path,"r");

			parser_PokemonFromText(pFile, pArrayListPokemones);

			fclose(pFile);

			respuesta = 1;
		}
	}

	return respuesta;
}


int Maggiaiuolo_Pokemones_ListPokemones(LinkedList* pArrayListPokemones)
{
	Pokemon* aux;

	printf("%4s %12s %15s %13s %17s %18s %15s \n","Numero","Nombre","Tipo","Tamañio","Ataque Cargado","Valor de ataque","Vario color");
	for(int i = 0;i<ll_len(pArrayListPokemones); i++)
	{
		aux = (Pokemon*) ll_get(pArrayListPokemones, i);
		Pokemon_printUno(aux);
	}
	return 1;
}

int Maggiaiuolo_Pokemones_editValorAtaque(LinkedList* pArrayListPokemones)
{
	int numero;
	numero = input_GetInt("Ingrese el numero del pokemon que quiere modificar");

	Pokemon* unPokemon;
	unPokemon = ll_get(pArrayListPokemones, numero-1);
	Pokemon_setValorAtaque(unPokemon, input_GetInt("Ingrese el nuevo valor de ataque"));
	return 1;
}

int TipoFuego(Pokemon* pokemon)
{
	int retorno;
	retorno = 0;
	if(pokemon != NULL)
	{
		if(strcmp(pokemon->tipo,"Fire") == 0)
		{
			retorno = 1;
		}
	}
	return retorno;
}

int Maggiaiuolo_Pokemones_filtrarFuego(LinkedList* pArrayListPokemones)
{
	FILE* pFile;

	Pokemon* auxPoke;

	int numero;
	char nombre[50];
	char tipo[50];
	char tamanio[50];
	char ataqueCargado[50];
	int valorAtaque;
	int esVariocolor;

	if(pArrayListPokemones != NULL)
	{
		pFile = fopen("tipoFuego.csv","w");

		for(int i = 0; i<ll_len(pArrayListPokemones);i++)
		{
			auxPoke = (Pokemon*)ll_get(pArrayListPokemones, i);
			if(TipoFuego(auxPoke) == 1)
			{
				Pokemon_getNumero(auxPoke, &numero);
				Pokemon_getNombre(auxPoke, nombre);
				Pokemon_getTipo(auxPoke, tipo);
				Pokemon_getTamanio(auxPoke, tamanio);
				Pokemon_getAtaqueCargado(auxPoke, ataqueCargado);
				Pokemon_getValorAtaque(auxPoke, &valorAtaque);
				Pokemon_getEsVariocolor(auxPoke, &esVariocolor);

				fprintf(pFile,"%d,%s,%s,%s,%s,%d,%d \n",numero,nombre,tipo,tamanio,ataqueCargado,valorAtaque,esVariocolor);
			}
		}

		fclose(pFile);
	}

	return 1;
}

int XLVenenos(void* pokemon)
{
	int retorno;
	retorno = 0;

	Pokemon* pPokemon;

	if(pokemon != NULL)
	{
		pPokemon = (Pokemon*) pokemon;
		if(strcmp(pPokemon->tamanio,"XL") == 0 && strcmp(pPokemon->tipo,"Poison") == 0)
		{
			retorno = 1;
		}
	}
	return retorno;
}

int Maggiaiuolo_Pokemones_filtrarXLVeneno(LinkedList* pArrayListPokemones)
{
	LinkedList* listaVenenos;
	listaVenenos = ll_filter(pArrayListPokemones, &XLVenenos);

	Maggiaiuolo_Pokemones_ListPokemones(listaVenenos);
	return 1;
}

int AtaqueCargado(void* pokemon)
{
	Pokemon* pPokemon;

	if(pokemon != NULL)
	{
		pPokemon = (Pokemon*) pokemon;

		if(strcmp(pPokemon->tipo,"Bug") == 0 || strcmp(pPokemon->tipo,"Fire") == 0 || strcmp(pPokemon->tipo,"Grass") == 0)
		{
			if(strcmp(pPokemon->tamanio,"XL") == 0)
			{
				pPokemon->valorAtaque += (pPokemon->valorAtaque*20/100);
			}
			else
			{
				if(strcmp(pPokemon->tamanio,"L") == 0)
				{
					pPokemon->valorAtaque += (pPokemon->valorAtaque*10/100);
				}
				else
				{
					pPokemon->valorAtaque += (pPokemon->valorAtaque*5/100);
				}
			}
		}
	}
	return 1;
}

int Maggiaiuolo_Pokemones_ataqueCargado(LinkedList* pArrayListPokemones)
{
	if(pArrayListPokemones != NULL)
	{
		ll_map(pArrayListPokemones, &AtaqueCargado);
	}
	return 1;
}

int BatallaPokemon(void* pokemon)
{
	int retorno;
	retorno = 0;

	if(pokemon != NULL)
	{
		Pokemon* pPokemon = (Pokemon*) pokemon;

		if(pPokemon->valorAtaque > 80)
		{
			if(strcmp(pPokemon->tipo,"Fire") == 0 )
			{
				if(strcmp(pPokemon->tamanio,"XL") == 0 && strcmp(pPokemon->ataqueCargado,"Lanzallamas") == 0 )
				{
					printf("%d\n",pPokemon->numero);
					retorno = 1;
				}
			}
			else
			{
				if(strcmp(pPokemon->tipo,"Water") == 0 )
				{
					if(strcmp(pPokemon->tamanio,"L") == 0 && strcmp(pPokemon->ataqueCargado,"Hidrobomba") == 0)
					{
						printf("%d\n",pPokemon->numero);
						retorno = 1;
					}
				}
			}
		}
	}

	return retorno;
}

int Maggiaiuolo_Pokemones_batallaPokemon(LinkedList* pArrayListPokemones)
{
	if(pArrayListPokemones != NULL)
	{
		int retorno;
		retorno = ll_count(pArrayListPokemones,&BatallaPokemon);
		if(retorno > 2)
		{
			printf("Se puede ganar la batalla\n");
			printf("Hay %d pokemones disponibles para la batalla\n",retorno);
		}
		else
		{
			printf("No se puede ganar la batalla\n");
			printf("Solo hay %d pokemones disponibles para la batalla\n",retorno);
		}
	}
	return 1;
}
