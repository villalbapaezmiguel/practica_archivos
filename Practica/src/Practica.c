/*
 ============================================================================
 Name        : Practica.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include "UTN.h"
#include "Alumno.h"
/*Modo                   Detalle
r  : Abre un archivo de texto para operaciones de lectura.
w  : Abre un archivo de texto para operaciones de escritura
a  : Abre un archivo de texto para añadir datos.
rb : Abre un archivo binario para operaciones de lectura.
wb : Abre un archivo binario para operaciones de escritura.
ab : Abre un archivo binario para añadir datos.
r+b : Abre un archivo binario para operaciones de lectura escritura.
w+b : Abre un archivo binario para operaciones de lectura escritura.
a+b : Abre un archivo binario para operaciones de lectura escritura.
r+ : Abre un archivo de texto para operaciones de lectura escritura.
w+ : Abre un archivo de texto para operaciones de lectura escritura*/

int main(void) {

	FILE* fp;

	eAlumno alumno ;

	fp = fopen("archivo.txt", "r");
	if(fp != NULL)
	{
//		alumno.altura = 1.70;
//		alumno.id = 127;
//		strcpy(alumno.nombre, "miguel");

//		int i = 127;
/*tenemos dos funciones en modo texto , una para leer y otra para escribir*/
//		fprintf(fp,"ID %d | Altura %.2f | nombre %s", alumno.id , alumno.altura , alumno.nombre);//ESCRIBIR TEXTO
//fwrite nos permite escribir en binario
//		fwrite(&i, sizeof(int) , 1 , fp);//ESCRIBIR BINARIO
//en modo texto (fprintf)va a pesar mas que en modo binario (fwrite)

//		fwrite(&alumno , sizeof(eAlumno), 1, fp);

//lo leemos y volvemos a volcar en la variable el contenido que tiene
		alumno.altura = 0.0;
		alumno.id = 0;
		strcpy(alumno.nombre, "oscar");

		fread(&alumno , sizeof(eAlumno), 1 , fp);

		printf("ID %d | Altura %.2f | nombre %s", alumno.id , alumno.altura , alumno.nombre);




		fclose(fp);
	}else{
		printf("\nERROR abriendo archivo");
	}


	return EXIT_SUCCESS;
}
