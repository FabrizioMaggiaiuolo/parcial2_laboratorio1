#ifndef POKEMONES_H_
#define POKEMONES_H_

typedef struct
{
	int numero;
	char nombre[50];
	char tipo[50];
	char tamanio[20];
	char ataqueCargado[50];
	int valorAtaque;
	int esVariocolor;

}Pokemon;

Pokemon* Pokemon_new();
Pokemon* Pokemon_newParametros(char* numero,char* nombreStr,char* tipo,char* tamanio, char* ataqueCargado,char* valorAtaque,char* esVariocolor);

void Pokemon_printUno(Pokemon* this);

int Pokemon_setNumero(Pokemon* this,int numero);
int Pokemon_getNumero(Pokemon* this,int* numero);

int Pokemon_setNombre(Pokemon* this,char* nombre);
int Pokemon_getNombre(Pokemon* this,char* nombre);

int Pokemon_setTipo(Pokemon* this,char* tipo);
int Pokemon_getTipo(Pokemon* this,char* tipo);

int Pokemon_setTamanio(Pokemon* this,char* tamanio);
int Pokemon_getTamanio(Pokemon* this,char* tamanio);

int Pokemon_setAtaqueCargado(Pokemon* this,char* ataqueCargado);
int Pokemon_getAtaqueCargado(Pokemon* this,char* ataqueCargado);

int Pokemon_setValorAtaque(Pokemon* this,int valorAtaque);
int Pokemon_getValorAtaque(Pokemon* this,int* valorAtaque);

int Pokemon_setEsVariocolor(Pokemon* this,int esVariocolor);
int Pokemon_getEsVariocolor(Pokemon* this,int* esVariocolor);
#endif /* POKEMONES_H_ */
