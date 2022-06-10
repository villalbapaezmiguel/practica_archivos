/*
 ============================================================================
 Name        : ejercicio_18-2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "UTN.h"

typedef struct {

	int legajo ;
	char nombre [51];
	int nota;

}Alumno;

int main(void) {

	Alumno listaAlumno[3];
	FILE* pArchivo ;
	int i;
	char array [510];

	listaAlumno[0].legajo = 18;
	strcpy(listaAlumno[0].nombre, "Belen");
	listaAlumno[0].nota = 7;

	listaAlumno[1].legajo = 19;
	strcpy(listaAlumno[1].nombre, "Alexis");
	listaAlumno[1].nota = 5;

	listaAlumno[2].legajo = 20;
	strcpy(listaAlumno[2].nombre, "Mica");
	listaAlumno[2].nota = 9;

	pArchivo = fopen("NuevoArchivo.txt", "r");
	if(pArchivo != NULL)
	{

//		for (i = 0; i < 3; ++i) {
//
//			fprintf(pArchivo,"%d , %s , %d \n", listaAlumno[i].legajo , listaAlumno[i].nombre , listaAlumno[i].nota);
//		}

//		for (i = 0; i < 3; ++i) {
//
//		}
//			fread(&array , sizeof(char) , 510 , pArchivo);

//		for (i = 0; i < 3; ++i) {
//			printf("\nhola");
//		}
			printf("%s \n", array);

		fclose(pArchivo);
	}

//	pArchivo = fopen("NuevoArchivo.txt", "r");
//	if(pArchivo != NULL)
//	{
//
//		for (i = 0; i < 3; ++i) {
//
//			fread(array[i] , sizeof(array) , 51 , pArchivo);
//		}
//
//		for (i = 0; i < 3; ++i) {
//
//			printf("\n %s", array[i]);
//		}
//
//		fclose(pArchivo);
//	}





	return EXIT_SUCCESS;
}
