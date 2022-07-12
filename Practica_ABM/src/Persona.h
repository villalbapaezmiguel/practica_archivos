/*
 * Persona.h
 *
 *  Created on: 11 jul. 2022
 *      Author: miguel
 */

#ifndef PERSONA_H_
#define PERSONA_H_
#define NOMBRE_LEN 500
#define VACIO 0
#define OCUPADO 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UTN.h"

typedef struct{

	int dia ;
	int mes ;
	int anio ;

}Fecha;

typedef struct{

	char nombre [NOMBRE_LEN];
	int id ;
	int edad ;
	float altura ;
	Fecha pFecha ;
	int estado ;

}Persona;

int lista_Inicializar(Persona lista[], int tamanio );
int lista_BuscarLugarLibre(Persona lista[], int tamanio );
int lista_Alta(Persona lista[], int tamanio , int lugarLibre);
void lista_Imprimir(Persona lista[], int tamanio );
int lista_BuscarPorID(Persona lista[], int tamanio , int* idBaja);
int lista_Baja(Persona lista[], int tamanio , int* idBaja);
void lista_AltaForzada(Persona lista[], int tamanio , int lugarLibre , char* nombre , int edad, float altura , int dia,int mes ,int anio);


#endif /* PERSONA_H_ */
