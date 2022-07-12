/*
 * Persona.c
 *
 *  Created on: 11 jul. 2022
 *      Author: miguel
 */

#include "Persona.h"
static int nuevoId (void);
static int nuevoId (void)
{
	static int retorno = 0;
	return (retorno++);
}

int lista_Inicializar(Persona lista[], int tamanio )
{
	int retorno = -1;
	int i;

	if(tamanio >= 0)
	{
		retorno = 0;
		for (i = 0; i < tamanio; ++i) {

			lista[i].estado = VACIO;
		}

	}

	return retorno;
}

int lista_BuscarLugarLibre(Persona lista[], int tamanio )
{
	int lugarLibre = -1;
	int i;
	if(tamanio >= 0)
	{
		for (i = 0; i < tamanio; ++i) {

			if(lista[i].estado == VACIO)
			{
				lugarLibre = i;
				lista[i].estado = OCUPADO;
				break;
			}

		}

	}

	return lugarLibre;
}

int lista_Alta(Persona lista[], int tamanio , int lugarLibre)
{
	int retorno = -1;
	Persona auxLista ;

	if(tamanio >= 0 && lugarLibre >= 0)
	{

		if(utn_getNombre(auxLista.nombre, NOMBRE_LEN, "\nIngrese nombre :", "\nERROR", 2)  == 0 &&
				utn_pedirInt(&auxLista.edad, "\nIngrese edad :", "\nERROR", 1, 130, 2) == 0 &&
				utn_pedirFloat(&auxLista.altura, "\nIngreese altura :", "\nERROR ",1, 3, 2)== 0 &&
				utn_pedirInt(&auxLista.pFecha.dia, "\nIngrese dia :", "nERROR", 1, 30, 2) == 0 &&
				utn_pedirInt(&auxLista.pFecha.mes, "\nIngrese mes :", "nERROR", 1, 12, 2) == 0 &&
				utn_pedirInt(&auxLista.pFecha.anio, "\nIngrese año :", "nERROR", 1980, 2022, 2) == 0)
		{
			auxLista.id = nuevoId();
			lista[lugarLibre] = auxLista ;
			lista[lugarLibre].estado = OCUPADO;
			retorno = 0;

		}
	}

	return retorno;
}

void lista_Imprimir(Persona lista[], int tamanio )
{
	int i;
	if(tamanio >= 0)
	{
		for (i = 0; i < tamanio; ++i) {

			if(lista[i].estado == OCUPADO)
			{

				printf("\n %d ID - Nombre : %s - Edad : %d - Altura : %f - Fecha %d/%d/%d ", lista[i].id, lista[i].nombre, lista[i].edad, lista[i].altura, lista[i].pFecha.dia, lista[i].pFecha.mes, lista[i].pFecha.anio);
			}
		}
	}
}

int lista_BuscarPorID(Persona lista[], int tamanio , int* idBaja)
{
	int retorno = -1;
	int i;
	if(tamanio >= 0)
	{
		for (i = 0; i < tamanio; ++i) {

			if(*idBaja == lista[i].id)
			{
				retorno = i;
				break;
			}
		}

	}

	return retorno;
}


int lista_Baja(Persona lista[], int tamanio , int* idBaja)
{
	int retorno = -1;

	if(tamanio >= 0)
	{
		lista[*idBaja].estado = VACIO;
		retorno = 0;
	}

	return retorno;
}

void lista_AltaForzada(Persona lista[], int tamanio , int lugarLibre , char* nombre , int edad, float altura , int dia,int mes ,int anio)
{
	Persona auxLista ;

	strncpy(auxLista.nombre , nombre, sizeof(auxLista.nombre));
	auxLista.id = nuevoId()  ;
	auxLista.edad = edad ;
	auxLista.altura = altura;
	auxLista.pFecha.dia = dia;
	auxLista.pFecha.mes = mes ;
	auxLista.pFecha.anio = anio;
	lista[lugarLibre] = auxLista;
	lista[lugarLibre].estado = OCUPADO;
}

