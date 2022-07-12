/*
 ============================================================================
 Name        : Practica_ABM.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Persona.h"
#include "UTN.h"
#define CANTIDAD_PERSONAS  30
/**
 * 1 Alta alumno
 * 2 Baja alumno
 * 3 Modificar alumno
 * 4 Ordenar por nombre
 * 5 Imprimir
 * 6 Informe promedio alturas
 * 7 Informe alumno mas alto
 * 8 Guardar a Archivo
 * 9 leer desde archivo
 *
 * 10 salir
 **/

int main(void) {

	Persona listaPersona[CANTIDAD_PERSONAS];
	int lugarLibre_alta ;
	int idBaja ;

	lista_AltaForzada(listaPersona, CANTIDAD_PERSONAS, 0, "Migue", 20, 1.70, 10,12, 2001);
	lista_AltaForzada(listaPersona, CANTIDAD_PERSONAS, 1, "Alexis", 20, 1.63, 18,4, 2001);
	lista_AltaForzada(listaPersona, CANTIDAD_PERSONAS, 2, "Pepe", 63, 1.62, 9,5, 1990);
	lista_AltaForzada(listaPersona, CANTIDAD_PERSONAS, 3, "Abel", 32, 1.70, 19,8, 1999);

	if(lista_Inicializar(listaPersona, CANTIDAD_PERSONAS) == 0)
	{
		printf("\n--------se inicializo correctamente---------------");
	}


	int opcion;


	do {
		printf("\n1 Alta persona \n2 Baja persona \n3 Modificar persona\n4 Ordenar por nombre \n5 Imprimir \n6 Informe promedio alturas \n7 Informe persona mas alto \n8 Guardar a Archivo \n9 leer desde archivo");
//		utn_pedirInt(&opcion, "\nIngrese opcion : ", "\nerror", 1, 10, 2);
		utn_getNumero(&opcion, "\nIngrese opcion : ", "\nerror", 1,10, 2);

		switch(opcion )
		{
			case 1:
				if(lista_BuscarLugarLibre(listaPersona, CANTIDAD_PERSONAS) != -1)
				{
					lugarLibre_alta = lista_BuscarLugarLibre(listaPersona, CANTIDAD_PERSONAS);
					if(lugarLibre_alta != -1)
					{
						if(lista_Alta(listaPersona, CANTIDAD_PERSONAS, lugarLibre_alta) == 0)
						{
							printf("\n------------------ALTA FINALIZADA--------------------");
						}
					}
				}else{
					printf("\n No se encontro lugar libre");
				}
				break;
			case 2:

				utn_pedirInt(&idBaja, "\nIngrese el id a dar de baja : ", "\nerror", 0, CANTIDAD_PERSONAS, 2);
				if(lista_BuscarPorID(listaPersona, CANTIDAD_PERSONAS, &idBaja) >= 0)
				{
					if(lista_Baja(listaPersona, CANTIDAD_PERSONAS, &idBaja) == 0)
					{
						printf("\n------------------BAJA FINALIZADA--------------------");
					}
				}

				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
					lista_Imprimir(listaPersona, CANTIDAD_PERSONAS);
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				break;



		}


	} while (opcion != 10);





	return EXIT_SUCCESS;
}
