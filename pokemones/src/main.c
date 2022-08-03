#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Pokemones.h"
#include "inputs.h"

int main()
{
	setbuf(stdout,NULL);

	int cargasFlag;
	cargasFlag = 0;

    int option = 0;

    LinkedList* listaPokemones = ll_newLinkedList();

    do{

    	printf("\nMenu de opciones \n");
		printf("1. Cargar los datos de los pokemones\n");
		printf("2. Modificar valor ataque\n");
		printf("3. Imprimir Pokemones\n");
		printf("4. Filtrar tipo Fuego\n");
		printf("5. Filtrar Extra Grandes de tipo Veneno\n");
		printf("6. Salir\n");
		option = input_GetInt("");
		printf("\n");

		if(option < 1 || option > 6)
		{
			printf("Ingrese una opcion valida");
		}
		else
		{
			if((option != 1 && option != 6) && cargasFlag != 1)
			{
				printf("\nCargue algun pokemon para acceder a la opcion\n");
			}
			else
			{
				switch(option)
				{
					case 1:
						Maggiaiuolo_Pokemones_loadFromText("Data_Pokemones.csv",listaPokemones);
						cargasFlag = 1;
						break;
					case 2:
						Maggiaiuolo_Pokemones_editValorAtaque(listaPokemones);
						break;
					case 3:
						Maggiaiuolo_Pokemones_ListPokemones(listaPokemones);
						break;
					case 4:
						Maggiaiuolo_Pokemones_filtrarFuego(listaPokemones);
						break;
					case 5:
						Maggiaiuolo_Pokemones_filtrarXLVeneno(listaPokemones);
						break;
					case 6:
						printf("Gracias por ultilizar nuestro programa, vuelva pronto!!");
						break;
				}
			}
		}

    } while (option != 6);

    return 0;
}
