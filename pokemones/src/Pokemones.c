#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pokemones.h"


Pokemon* Pokemon_new()
{
	return (Pokemon*) malloc(sizeof(Pokemon));
}
Pokemon* Pokemon_newParametros(char* numero,char* nombreStr,char* tipo,char* tamanio, char* ataqueCargado,char* valorAtaque,char* esVariocolor)
{
	Pokemon* pokemon;
	pokemon = Pokemon_new();
	if(numero != NULL && nombreStr != NULL && tipo != NULL && tamanio != NULL && ataqueCargado != NULL && valorAtaque != NULL && esVariocolor != NULL)
	{
		Pokemon_setNumero(pokemon,atoi(numero));
		Pokemon_setNombre(pokemon,nombreStr);
		Pokemon_setTipo(pokemon, tipo);
		Pokemon_setTamanio(pokemon, tamanio);
		Pokemon_setAtaqueCargado(pokemon, ataqueCargado);
		Pokemon_setValorAtaque(pokemon, atoi(valorAtaque));
		Pokemon_setEsVariocolor(pokemon, atoi(esVariocolor));
	}
	return pokemon;
}

void Pokemon_printUno(Pokemon* this)
{
	int numero;
	char nombre[50];
	char tipo[50];
	char tamanio[50];
	char ataqueCargado[50];
	int valorAtaque;
	int esVariocolor;

	Pokemon_getNumero(this, &numero);
	Pokemon_getNombre(this, nombre);
	Pokemon_getTipo(this, tipo);
	Pokemon_getTamanio(this, tamanio);
	Pokemon_getAtaqueCargado(this, ataqueCargado);
	Pokemon_getValorAtaque(this, &valorAtaque);
	Pokemon_getEsVariocolor(this, &esVariocolor);

	printf("%4d %15s %15s %10s %15s %15d %15d \n",numero,nombre,tipo,tamanio,ataqueCargado,valorAtaque,esVariocolor);
}

int Pokemon_setNumero(Pokemon* this,int numero)
{
	int respuesta;
	respuesta = 0;
	if(this != NULL)
	{
		if(numero > 0)
		{
			this->numero = numero;
			respuesta = 1;
		}
	}

	return respuesta;
}
int Pokemon_getNumero(Pokemon* this,int* numero)
{
	int respuesta;
	respuesta = 0;
	if(this != NULL)
	{
		*numero = this->numero;
		respuesta = 1;
	}

	return respuesta;
}

int Pokemon_setNombre(Pokemon* this,char* nombre)
{
	int respuesta;
	respuesta = 0;
	if(this != NULL)
	{
		if(nombre != NULL)
		{
			strcpy(this->nombre,nombre);
			respuesta = 1;
		}
	}

	return respuesta;
}
int Pokemon_getNombre(Pokemon* this,char* nombre)
{
	int respuesta;
	respuesta = 0;
	if(this != NULL)
	{
		strcpy(nombre, this->nombre);
		respuesta = 1;
	}

	return respuesta;
}

int Pokemon_setTipo(Pokemon* this,char* tipo)
{
	int respuesta;
		respuesta = 0;
		if(this != NULL)
		{
			if(tipo != NULL)
			{
				strcpy(this->tipo,tipo);
				respuesta = 1;
			}
		}

		return respuesta;
}
int Pokemon_getTipo(Pokemon* this,char* tipo)
{
	int respuesta;
	respuesta = 0;
	if(this != NULL)
	{
		strcpy(tipo, this->tipo);
		respuesta = 1;
	}

	return respuesta;
}

int Pokemon_setTamanio(Pokemon* this,char* tamanio)
{
	int respuesta;
		respuesta = 0;
		if(this != NULL)
		{
			if(tamanio != NULL)
			{
				strcpy(this->tamanio,tamanio);
				respuesta = 1;
			}
		}

		return respuesta;
}
int Pokemon_getTamanio(Pokemon* this,char* tamanio)
{
	int respuesta;
	respuesta = 0;
	if(this != NULL)
	{
		strcpy(tamanio, this->tamanio);
		respuesta = 1;
	}

	return respuesta;
}

int Pokemon_setAtaqueCargado(Pokemon* this,char* ataqueCargado)
{
	int respuesta;
		respuesta = 0;
		if(this != NULL)
		{
			if(ataqueCargado != NULL)
			{
				strcpy(this->ataqueCargado,ataqueCargado);
				respuesta = 1;
			}
		}

		return respuesta;
}
int Pokemon_getAtaqueCargado(Pokemon* this,char* ataqueCargado)
{
	int respuesta;
	respuesta = 0;
	if(this != NULL)
	{
		strcpy(ataqueCargado, this->ataqueCargado);
		respuesta = 1;
	}

	return respuesta;
}

int Pokemon_setValorAtaque(Pokemon* this,int valorAtaque)
{
	int respuesta;
	respuesta = 0;
	if(this != NULL)
	{
		if(valorAtaque > 0)
		{
			this->valorAtaque = valorAtaque;
			respuesta = 1;
		}
	}

	return respuesta;
}
int Pokemon_getValorAtaque(Pokemon* this,int* valorAtaque)
{
	int respuesta;
	respuesta = 0;
	if(this != NULL)
	{
		*valorAtaque = this->valorAtaque;
		respuesta = 1;
	}

	return respuesta;
}

int Pokemon_setEsVariocolor(Pokemon* this,int esVariocolor)
{
	int respuesta;
	respuesta = 0;
	if(this != NULL)
	{
		this->esVariocolor = esVariocolor;
		respuesta = 1;
	}

	return respuesta;
}

int Pokemon_getEsVariocolor(Pokemon* this,int* esVariocolor)
{
	int respuesta;
	respuesta = 0;
	if(this != NULL)
	{
		*esVariocolor = this->esVariocolor;
		respuesta = 1;
	}

	return respuesta;
}
