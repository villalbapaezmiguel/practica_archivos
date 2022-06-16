/*
 ============================================================================
 Name        : practica_cargarArchivoCSV.c
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

typedef struct{

	int id ;
	char nombre[51];
	float altura ;
}Persona;
static int esNumerica(char* cadena );
static int getNombre(char* pResultado, int longitud);
static int getString(char* cadena, int longitud);
static int esNombre(char* cadena,int longitud);
static int esFlotante(char* cadena);
/*-------------------------------------------*/
void cargarPersonaForzada(Persona* lista , int limite ,int posicionLibre , int id , char* nombre , float altura);
int cargarArchivo(Persona* lista, int limite , char* pathArchivo);
int LeerArchivo(Persona* lista, int limite , char* pathArchivo);
/*---------------------------------------------*/
int persona_setId (Persona* this , char* id);
int persona_setNombre(Persona* this, char* nombre);
int persona_setAltura(Persona* this , char* altura);
int main(void) {


//	Persona arrayPersona[5];
	Persona auxLista[5];

//	cargarPersonaForzada(arrayPersona, 5, 0, 0,"Migue", 1.70);
//	cargarPersonaForzada(arrayPersona, 5, 1, 1,"Oscar", 1.75);
//	cargarPersonaForzada(arrayPersona, 5, 2, 2,"Abel", 1.68);
//	cargarPersonaForzada(arrayPersona, 5, 3, 3,"Adrian", 1.68);
//	cargarPersonaForzada(arrayPersona, 5, 4, 4,"Gustavo", 1.87);

//	int i ;
//	for (i = 0; i < 5; ++i) {
//
//		printf("\n %d - %s - %.2f", arrayPersona[i].id , arrayPersona[i].nombre , arrayPersona[i].altura);
//	}
//escribirlo en un archivo .csv  , pero en una funcion

//	cargarArchivo(arrayPersona, 5, "ArchivoNuevo.csv");

	LeerArchivo(auxLista, 5, "ArchivoNuevo.csv");
	int auxId ;
	char auxNombre[51];
	float auxAltura;
	int i ;
	for (i = 0; i < 5; ++i) {

		if(persona_setId(auxLista[i], &auxId) == 0 &&
			persona_setNombre(auxLista[i], auxNombre) == 0 &&
			persona_setAltura(auxLista[i], &auxAltura) == 0)
		{
			printf("\n %s - %s - %s", auxLista[i].id , auxLista[i].nombre , auxLista[i].altura);

		}

	}

	return EXIT_SUCCESS;
}

void cargarPersonaForzada(Persona* lista , int limite ,int posicionLibre , int id , char* nombre , float altura)
{
	Persona auxLista ;

	auxLista.id = id ;
	strcpy(auxLista.nombre, nombre);
	auxLista.altura = altura;

	lista[posicionLibre] = auxLista;

}

int cargarArchivo(Persona* lista, int limite , char* pathArchivo)
{
	int retorno = -1;
	FILE* pArchivo ;
	int i;

	pArchivo = fopen(pathArchivo, "w");
	if(pArchivo != NULL)
	{
		for (i = 0; i < limite; ++i) {

			fprintf(pArchivo, "%d , %s , %f\n", lista[i].id , lista[i].nombre , lista[i].altura);
		}
		fclose(pArchivo);

	}



	return retorno ;
}

int LeerArchivo(Persona* lista, int limite , char* pathArchivo)
{
	int retorno = -1;
	FILE* pArchivo ;


	pArchivo = fopen(pathArchivo, "r");
	if(pArchivo != NULL)
	{

		fread(lista, sizeof(Persona), 1, pArchivo);

		fclose(pArchivo);

	}



	return retorno ;
}

int persona_setId (Persona* this , char* id)
{
	int estado = -1;
	int auxId ;

	if(this != NULL && id != NULL)
	{
		if(esNumerica(id) == 0)
		{
			estado = 0;
			auxId = atoi(id);
			this->id = auxId;

		}
	}
	return estado ;
}

int persona_setNombre(Persona* this, char* nombre)
{

	int estado = -1;

	if(this != NULL && nombre != NULL)
	{
		if(esNombre(nombre, sizeof(nombre)) == 1)
		{
			estado = 0;
			strcpy(this->nombre, nombre);

		}
	}
	return estado ;

}

int persona_setAltura(Persona* this , char* altura)
{
	int estado = -1;
	int auxAltura ;

	if(this != NULL && altura != NULL)
	{
		if(esFlotante(altura) == 1)
		{
			estado = 0;
			auxAltura = atof(altura);
			this->id = auxAltura;

		}
	}
	return estado ;


}

static int esNumerica(char* cadena )
{
	int retorno = 1 ;
	int i = 0;

	if(cadena[0] == '-')
	{
		i = 1;
	}
	for (; cadena[i] != '\0'; ++i) {

		if(cadena[i] > '9' || cadena[i] < '0')
		{
			retorno = 0;
			break;
		}
	}
	return retorno ;
}
static int getNombre(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==0 &&
    		esNombre(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}
/**
 * \brief 	Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * 			un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */
static int getString(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[4096]; // *****************************

	if(cadena != NULL && longitud > 0)
	{
		__fpurge(stdin);
		//__fpurge(stdin); // Linux
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}
/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int esNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es
 *
 */
static int esFlotante(char* cadena)
{
	int i=0;
	int retorno = 1;
	int contadorPuntos=0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		for(i=0 ; cadena[i] != '\0'; i++)
		{
			if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9' )
			{
				if(cadena[i] == '.' && contadorPuntos == 0)
				{
					contadorPuntos++;
				}
				else
				{
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}
