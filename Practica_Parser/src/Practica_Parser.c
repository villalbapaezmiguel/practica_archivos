/*
 ============================================================================
 Name        : Practica_Parser.c
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

int main(void) {

	FILE* pArchivo ;
//	char buffer [128];
	int a,b,c,d;
	pArchivo = fopen("NuevoArchivo.txt", "rd");
	if(pArchivo != NULL)
	{

//		fgets(buffer, sizeof(buffer), pArchivo );
//		printf("\n %s", buffer);


//		fscanf(pArchivo, "%d,%d,%d,%d\n",&a, &b,&c,&d);//cuando encuentra el enter termino (\n)
//		printf("%d,%d,%d,%d\n",a, b,c,d);
//		fscanf(pArchivo, "%d,%d,%d,%d\n",&a, &b,&c,&d);//cuando encuentra el enter termino (\n)
//		printf("%d,%d,%d,%d\n",a, b,c,d);
//		fscanf(pArchivo, "%d,%d,%d,%d\n",&a, &b,&c,&d);//cuando encuentra el enter termino (\n)
//		printf("%d,%d,%d,%d\n",a, b,c,d);

//feof hay que llamarlo despues de que llamemos a una funcion de leectura fread
		do {
//			fscanf(pArchivo, "%d,%d,%d,%d\n",&a, &b,&c,&d);//cuando encuentra el enter termino (\n)/ retorna la cantidad datos que recibio

			if(fscanf(pArchivo, "%d,%d,%d,%d\n",&a, &b,&c,&d) == 4)
			{
				printf("%d,%d,%d,%d\n",a, b,c,d);

			}else{
				break;
			}

		} while (feof(pArchivo) == 0);

		fclose(pArchivo);

	}else{
		printf("\nNo se encontro el archivo");
	}




	return EXIT_SUCCESS;
}
