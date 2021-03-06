/*
 ============================================================================
 Name        : Practica_fscanf.c
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
#include "Alumno.h"
#define CANTIDAD_PERSONA 3

typedef struct {

	char nombre[32];
	char apellido[32];
	int edad;
	int id;

}Persona;

int main(void) {

	FILE* pArchivo ;
	Persona listaPersonas[CANTIDAD_PERSONA];
	eAlumno* listaAlumno[10];
	eAlumno* auxAlumno ;
	int i = 0;
	int j =0;
	char escribir = 'w';
	char leer = 'r';
	char a [123];
	char b [123];
	char c [123];

/*no se puede abrir el archivo para escribirlo y luego querer tomar los dataos del archivo (fscanf) , no llega a escribir el archivo,
 * asi que una vez que lo escribimos tenemos que cerrarlo para guardarlo*/
	pArchivo = fopen("NuevoArchivo.txt", &leer);
	if(pArchivo != NULL)
	{
//		fprintf(pArchivo,"1,Juan,Perez,33\n2,Jose,Gonzales,45\n3,Carlos,Gomez,21\n");

//		do {
///*fscanf :  esta funcion nos permiste obtener los datos del archivo , pero tenemos que pasarle su regla :
// * la regla quiere decir como sigue la tomada de datos , en este caso primero empieza con un int (el id de la listaPersona), luego
// * sigue con %[^,] , representa un conjunto de caracteres ,'cualquier carácter menos los que están en este conjunto' , esto se lo denomina un conjunto negado ,
// * para ello indicamos el conjunto con un “^” delante, por ejemplo: “%[^,]” indica “cualquier carácter menos la coma”.*/
//			fscanf(pArchivo, "%d, %[^,] , %[^,] , %d", &listaPersonas[i].id , listaPersonas[i].nombre , listaPersonas[i].apellido, &listaPersonas[i].edad);
//			i ++;
//
//		} while (feof(pArchivo) == 0);

//EJEMPLO TODOS CADENAS

		do {
			if(fscanf(pArchivo, " %[^,],%[^,],%[^,\n]\n", a, b, c) == 3)
			{
				printf("\n %s-%s-%s", a , b ,c );
				//atof devuelve un flotante
				//atoi devuelve un entero

				auxAlumno = alumno_newParametros(b, atof(c), atoi(a));
				if(auxAlumno != NULL)
				{
					listaAlumno[i] = auxAlumno;
				}


			}
			i++;

		} while (feof(pArchivo) == 0);

		for (j = 0; j < CANTIDAD_PERSONA; ++j) {

			printf("\n%d, %s , %.2f", listaAlumno[j]->id , listaAlumno[j]->nombre , listaAlumno[j]->altura);
		}

//		for (j = 0; j < CANTIDAD_PERSONA; ++j) {
//
//			printf("\n%d, %s , %s , %d", listaPersonas[j].id , listaPersonas[j].nombre , listaPersonas[j].apellido, listaPersonas[j].edad);
//		}
//		pArchivo = fopen("NuevoArchivo.txt",&escribir);
//		if(pArchivo != NULL)
//		{
//			fprintf(pArchivo,"1,Tito,Gomez,2\n2,Raul,Campos,55\n3,Caren,Paez,31\n");
//
//
//		}


		fclose(pArchivo);
	}


	return EXIT_SUCCESS;
}
