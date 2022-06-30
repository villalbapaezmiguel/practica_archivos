/*
 ============================================================================
 Name        : ejercicio_18-3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UTN.h"

int array_agregarDatos(int array[] , int* numeroIngresado , int posicion);
void array_imprimir (int array [], int limite);
int array_guardarDatos(int array [], int limite , char* NombreDelArchivo);
int main(void) {

/*Ejercicio 18-3:
Escribir y leer un archivo binario con 5 números enteros.
Mostrar los datos luego de la lectura del
archivo*/

//	FILE* pArchivo ;
//	int numeros [5] = {1,2,3,4,5};
//	char array[5];
//	int aux[5];
//	int i ;
	int arrays [50];
	int numeroIngresado ;
	int contadorEnteros = 0;
	int opcion ;
//

	do {

		printf("\n1)ingresar datos\n2)guardar datos en archivo\n3)imprimir\n4)leer o obtener datos del archivo\n5)salir");
		utn_getNumero(&opcion, "\nIngtrese opcion :", "\nERROR", 1, 5, 2);

		switch(opcion)
		{
		case 1://ingresar datos
			printf("\n----------------------------Ingreso de datos-------------------------");
					array_agregarDatos(arrays, &numeroIngresado , contadorEnteros);
					contadorEnteros ++;
			break;

		case 2://guardar datos en archivo
			printf("\n----------------------------Guardar datos-------------------------");
			if(array_guardarDatos(arrays, contadorEnteros, "archivo.csv") == 0)
			{
				printf("\nArchivo guardado ");
			}
			break;

		case 3://imprimir
			printf("\n----------------------------lista-------------------------");
			array_imprimir(arrays, contadorEnteros);
			break;

		case 4://leer o obtener datos del archivo
			break;

		case 5://salir
			break;

		}


	} while (opcion != 5);




//	pArchivo = fopen("NuevoArchivoBinario.txt", "r");
//	if(pArchivo != NULL)
//	{
////primero la direccion de la variable ,
////cuantos bits va a leer del puntero que le pase para escribir en el  archivio,
////luego cuantas de esas , osea cuantas queremos que se escriban
////depsues el puntero al archivo
////		fwrite(&numeros ,sizeof(int) ,sizeof(numeros) , pArchivo);
////		fread(&array, sizeof(int), sizeof(numeros), pArchivo);
//
//
//		printf("\n array : %c", array[0]);
//
//
//
//
//
//		fclose(pArchivo);
//	}

	return EXIT_SUCCESS;
}

/*Guarda los datos del array en un archivo*/
int array_guardarDatos(int array [], int limite , char* NombreDelArchivo)
{
	int retorno = -1;
	int i;
	FILE* pArchivo ;

	if(limite > 0 && NombreDelArchivo != NULL)
	{
//		utn_getNombre(NombreDelArchivo, 50, "\nIngrese nombre del archivo :", "\nerror", 2);

		pArchivo = fopen(NombreDelArchivo , "w");
		if(pArchivo != NULL)
		{
			retorno = 0;
			for (i = 0; i < limite; ++i) {

				fprintf(pArchivo, "%d - %d \n", i , array[i]);
			}

			fclose(pArchivo);
		}


	}


	return retorno;

}

/*esta funcion agrega los enteros en el array*/
int array_agregarDatos(int array[] , int* numeroIngresado , int posicion )
{
	int retorno = -1;

	if((numeroIngresado >= 0 || numeroIngresado <= 0))
	{
		if(utn_getNumero(numeroIngresado, "\nIngrese un numero:", "\nERROR", -10, 100, 2) == 0)
		{

			array[posicion] = *numeroIngresado;
			retorno = 0;
		}
	}

	return retorno;
}


void array_imprimir (int array [], int limite)
{
	int i ;

	for (i = 0; i < limite; ++i) {

		printf("\n%d numero : %d", i, array[i]);

	}


}


