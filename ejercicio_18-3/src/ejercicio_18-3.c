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
#include "UTN.h"

int main(void) {

/*Ejercicio 18-3:
Escribir y leer un archivo binario con 5 números enteros.
Mostrar los datos luego de la lectura del
archivo*/

	FILE* pArchivo ;
	int numeros [5] = {1,2,3,4,5};
	char array[5];
	int aux[5];
	int i ;

	pArchivo = fopen("NuevoArchivoBinario.txt", "r");
	if(pArchivo != NULL)
	{
//primero la direccion de la variable ,
//cuantos bits va a leer del puntero que le pase para escribir en el  archivio,
//luego cuantas de esas , osea cuantas queremos que se escriban
//depsues el puntero al archivo
//		fwrite(&numeros ,sizeof(int) ,sizeof(numeros) , pArchivo);
		fread(&array, sizeof(int), sizeof(numeros), pArchivo);


		printf("\n array : %c", array[0]);



		fclose(pArchivo);
	}



	return EXIT_SUCCESS;
}
