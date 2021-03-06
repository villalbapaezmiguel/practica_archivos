/*
 * Alumno.c
 *
 *  Created on: May 26, 2020
 *      Author: Mauro
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Alumno.h"

static int isValidNombre(char* cadena,int longitud);
static int esNumerica(char* cadena, int limite);
static int esFlotante(char* cadena);

Alumno* alumno_new(void)
{
	Alumno* auxiliarP = NULL;
	auxiliarP = (Alumno*) malloc(sizeof(Alumno));
	return auxiliarP;
}

//devulve un puntero a una direccion de memoria si salio todo bien , de lo contrario devulve NULL
Alumno* alumno_newParametros(char* nombre,float altura,int id)
{
	Alumno* this = NULL;
	this = alumno_new();

	if(this != NULL && nombre != NULL)
	{
				if(alumno_setAltura(this, altura) == -1  )
				{
					printf("\n setAltura salio mal");
				}

				if(alumno_setId(this, id) == -1  )
				{
					printf("\n setId salio mal");
				}
				if(alumno_setNombre(this, nombre) == -1 )
				{
					printf("\n setNombre salio mal");
				}


		if( alumno_setNombre(this, nombre) == -1 ||//si algunos de los set salio mal , vamos a elimonar el alumno
			alumno_setAltura(this, altura) == -1 ||
			alumno_setId(this, id) == -1 )
		{
			alumno_delete(this);//esta funcion libera espacio , peor aun sigue apuntando en una direccion de memoria
			//entonces hacemos que this apunte a NULL
			this = NULL;

		}
	}
	return this;
}

Alumno* alumno_newParametrosChar(char* nombre,char* altura,char* id)
{
	Alumno* this = NULL;
	this = alumno_new();

	if(this != NULL && nombre != NULL && altura != NULL && id != NULL)
	{
//		if(alumno_setNombre(this, nombre) == -1 )
//		{
//			printf("\n setNombre salio mal");
//		}
//		if(alumno_setAlturaTxt(this, altura) == -1 )
//		{
//			printf("\n setAltura salio mal");
//		}
//
//		if(alumno_setIdTxt(this, id) == -1 )
//		{
//			printf("\n setId salio mal");
//		}

		if( alumno_setNombre(this, nombre) == -1 ||//si algunos de los set salio mal , vamos a elimonar el alumno
			alumno_setAlturaTxt(this, altura) == -1 ||
			alumno_setIdTxt(this, id) == -1 )
		{
			alumno_delete(this);//esta funcion libera espacio , peor aun sigue apuntando en una direccion de memoria
			//entonces hacemos que this apunte a NULL
			this = NULL;
//			printf("\nalguno de los set salio mal");

		}
	}
	return this;
}

void alumno_delete(Alumno* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int alumno_setNombre(Alumno* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		if(isValidNombre(nombre,NOMBRE_LEN) == 0)
		{
			retorno = 0;
			strncpy(this->nombre,nombre,NOMBRE_LEN);
		}
	}
	return retorno;
}

int alumno_getNombre(Alumno* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		retorno = 0;
		strncpy(nombre,this->nombre,NOMBRE_LEN);
	}
	return retorno;
}

int alumno_setIdTxt(Alumno* this,char* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		if(esNumerica(id,10))
		{
			retorno = 0;
			this->id = atoi(id);
		}
	}
	return retorno;
}
//hola
int alumno_setId(Alumno* this,int id)
{
	int retorno = -1;
	if(this != NULL && id >= 0)
	{
		retorno = 0;
		this->id = id;
	}
	return retorno;
}

int alumno_getIdTxt(Alumno* this,char* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		retorno = 0;
		sprintf(id,"%d",this->id);//lo tranforma a texto
	}
	return retorno;
}

int alumno_getId(Alumno* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		retorno = 0;
		*id = this->id ;
	}
	return retorno;
}

int alumno_setAltura(Alumno* this,float altura)
{
	int retorno = -1;
	if(this != NULL && altura >= 0)
	{
		retorno = 0;
		this->altura = altura;
	}
	return retorno;
}
int alumno_setAlturaTxt(Alumno* this,char* altura)
{
	int retorno = -1;
	float auxAltura ;

	if(this != NULL && altura >= 0)
	{
		if(esFlotante(altura)== 0)
		{
			auxAltura = atof(altura);//lo tranfomarmos en un flotante

			if(auxAltura >= 0) //porque capaz nos llega una altura negativa
			{
				retorno = 0;
				this->altura = auxAltura;

			}
		}
	}
	return retorno;
}

int alumno_getAltura(Alumno* this,float* altura)
{
	int retorno = -1;
	if(this != NULL && altura != NULL)
	{
		retorno = 0;
		*altura = this->altura;
	}
	return retorno;
}
/**********************************************************************/

/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int isValidNombre(char* cadena,int longitud)
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
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es numerica, 0 (falso) si no lo es y -1 en caso de error
 *
 */
static int esNumerica(char* cadena, int limite)
{
	int retorno = -1; // ERROR
	int i;
	if(cadena != NULL && limite > 0)
	{
		retorno = 1; // VERDADERO
		for(i=0;i<limite && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] < '0'||cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
			//CONTINUE
		}
		//BREAK
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

/**********************************************************************/


int alumno_deleteIndexInArray(Alumno* arrayPunteros[],int limite, int indice)
{
	int retorno=-1;
	if(arrayPunteros != NULL && indice >= 0 && indice < limite && arrayPunteros[indice] != NULL )
	{
		retorno = 0;
		alumno_delete(arrayPunteros[indice]);
		arrayPunteros[indice] = NULL;
	}
	return retorno;
}


int alumno_initArray(Alumno* arrayPunteros[],int limite)
{
	int retorno=-1;
	int i;
	if(arrayPunteros != NULL && limite > 0)
	{
		retorno = 0;
		for(i=0;i<limite;i++)
		{
			arrayPunteros[i] = NULL;
		}
	}
	return retorno;
}

int alumno_buscarLibreArray(Alumno* arrayPunteros[],int limite)
{
	int retorno=-1;
	int i;
	if(arrayPunteros != NULL && limite > 0)
	{
		retorno = -2;
		for(i=0;i<limite;i++)
		{
			if(arrayPunteros[i] == NULL)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int alumno_imprimirArray(Alumno* arrayPunteros[],int limite)
{
	int retorno=-1;
	int i;
	if(arrayPunteros != NULL && limite > 0)
	{
		printf("\n-----LISTA ALUMNOS-----\n");
		for(i=0;i<limite;i++)
		{
			if(arrayPunteros[i] != NULL)
			{
				printf("Dir: %p - Nombre: %s- ID: %d - Altura: %f\n", arrayPunteros[i],arrayPunteros[i]->nombre,arrayPunteros[i]->id,arrayPunteros[i]->altura);
			}
		}
	}
	return retorno;
}

int alumno_buscarPorIdArray(Alumno* arrayPunteros[],int limite, int id)
{
	int retorno=-1;
	int i;
	if(arrayPunteros != NULL && limite > 0 && id >= 0)
	{
		retorno = -2;
		for(i=0;i<limite;i++)
		{
			if(arrayPunteros[i] != NULL && arrayPunteros[i]->id == id)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int alumno_agregarAlumnoArray(Alumno* arrayPunteros[],int limite, char* nombre, float altura, int id)
{
	int retorno=-1;
	int indiceLibre;
	Alumno* auxAlumno ;
	if(arrayPunteros != NULL && limite > 0 && nombre != NULL && id >= 0)
	{
		indiceLibre = alumno_buscarLibreArray(arrayPunteros,limite);
		if(indiceLibre >= 0)
		{
			auxAlumno = alumno_newParametros(nombre,altura,id);
			if(auxAlumno != NULL )
			{
				printf("\nllegue hasta aca");
				arrayPunteros[indiceLibre] = auxAlumno;
				retorno = indiceLibre;

			}
		}
	}
	return retorno;
}

int alumno_agregarAlumnoArrayTxt(Alumno* arrayPunteros[],int limite, char* nombre, char* altura, char* id)
{
	int retorno=-1;
	int indiceLibre;
	Alumno* auxAlumno;
	if(arrayPunteros != NULL && limite > 0 && nombre != NULL && id != NULL)
	{
		indiceLibre = alumno_buscarLibreArray(arrayPunteros,limite);
		if(indiceLibre >= 0)
		{

			auxAlumno = alumno_newParametrosChar(nombre, altura, id);
			if(auxAlumno != NULL)
			{
				arrayPunteros[indiceLibre] = auxAlumno;
				retorno = indiceLibre;

			}

		}
	}
	return retorno;
}
int alumno_borrarPorIdArray(Alumno* arrayPunteros[],int limite, int id)
{
	int retorno=-1;
	int indiceBorrar;
	if(arrayPunteros != NULL && limite > 0 && id >= 0)
	{
		indiceBorrar = alumno_buscarPorIdArray(arrayPunteros,limite,id);
		if(indiceBorrar >= 0)
		{
			if(!alumno_deleteIndexInArray(arrayPunteros,limite,indiceBorrar))
			{
				retorno=0;
			}
		}
	}
	return retorno;
}


int alumno_ordenarArray(Alumno* arrayPunteros[],int limite)
{
	int retorno=-1;
	int i;
	int flagSwap;
	Alumno* bufferPunteroAlumno;
	if(arrayPunteros != NULL && limite > 0)
	{
		retorno=0;
		do
		{
			flagSwap = 0;
			for(i=0;i<limite-1;i++)
			{

				if(	arrayPunteros[i] != NULL &&
					arrayPunteros[i+1] != NULL &&
					strncmp(arrayPunteros[i]->nombre,arrayPunteros[i+1]->nombre,NOMBRE_LEN) > 0)
				{
					bufferPunteroAlumno = arrayPunteros[i];
					arrayPunteros[i] = arrayPunteros[i+1];
					arrayPunteros[i+1] = bufferPunteroAlumno;
					flagSwap=1;
				}
			}
		}while(flagSwap);
	}
	return retorno;
}

int alumno_calcularAlturaPromedioArray(Alumno* arrayPunteros[],int limite, float* promedio)
{
	int retorno=-1;
	int i;
	int cantidadAlumnos = 0;
	float acumuladorAlturas=0;
	if(arrayPunteros != NULL && limite > 0 && promedio != NULL)
	{
		retorno=0;
		for(i=0;i<limite;i++)
		{
			if(arrayPunteros[i] != NULL)
			{
				cantidadAlumnos++;
				acumuladorAlturas = acumuladorAlturas + arrayPunteros[i]->altura;
			}
		}
		*promedio = acumuladorAlturas / cantidadAlumnos;
	}
	return retorno;
}

int alumno_calcularAlturaMaximaArray(Alumno* arrayPunteros[],int limite, int* indice)
{
	int retorno=-1;
	int i;
	int indiceMaximo;
	float alturaMaxima;
	int flagOnes = 0;

	if(arrayPunteros != NULL && limite > 0 && indice != NULL)
	{
		retorno=0;
		for(i=0;i<limite;i++)
		{
			if(arrayPunteros[i] != NULL)
			{
				if(!flagOnes)
				{
					indiceMaximo = i;
					alturaMaxima = arrayPunteros[i]->altura;
					flagOnes = 1;
				}
				else if(arrayPunteros[i]->altura > alturaMaxima)
				{
					indiceMaximo = i;
					alturaMaxima = arrayPunteros[i]->altura;
				}
			}
		}
		*indice = indiceMaximo;

	}
	return retorno;
}

int alumno_guardarArrayEnArchivo(Alumno* arrayPunteros[],int limite , char* pathArchivo)
{

	int retorno=-1;
	int i;
	FILE* pArchivo ;
	int auxId;
	char auxNombre [NOMBRE_LEN];
	float auxAltura;

	if(arrayPunteros != NULL && limite > 0 && pathArchivo != NULL)
	{
		//abrimos el archivo
		pArchivo = fopen(pathArchivo , "w");
		if (pArchivo != NULL) {

			retorno  = 0;

			for(i=0;i<limite;i++)
			{
				if(arrayPunteros[i] != NULL)
				{
					if(!alumno_getId(arrayPunteros[i], &auxId) &&
							!alumno_getNombre(arrayPunteros[i], auxNombre) &&
							!alumno_getAltura(arrayPunteros[i], &auxAltura))
					{

						fprintf(pArchivo,"%d, %s , %f \n",auxId, auxNombre , auxAltura);

					}

//					fprintf(pArchivo, "%d,%s,%f\n", arrayPunteros[i]->id , arrayPunteros[i]->nombre , arrayPunteros[i]->altura);//de esta forma ya no la hacemos mas

				}
			}
			fclose(pArchivo);
		}
	}
	return retorno;


}


int alumno_leerArrayEnArchivo(Alumno* arrayPunteros[],int limite , char* pathArchivo , int* proximoId)
{

	int retorno=-1;
	FILE* pArchivo ;
	char auxId[510];
	char auxNombre [510];
	char auxAltura[510] ;


	if(arrayPunteros != NULL && limite > 0 && pathArchivo != NULL)
	{

		pArchivo = fopen(pathArchivo, "r");
		if(pArchivo != NULL)
		{
			retorno = 0;

			do {

				if(fscanf(pArchivo, "%[^,],%[^,],%[^,\n]\n",auxId, auxNombre, auxAltura)== 3)
				{
					printf("\n%s-%s-%s",auxId, auxNombre, auxAltura );

					if(alumno_agregarAlumnoArrayTxt(arrayPunteros, limite, auxNombre, auxAltura, auxId) > 0)
					{
						printf("\nAlta ok");

						if(atoi(auxId) >= *proximoId)
						{
							*proximoId = atoi(auxId)+1;
						}

					}
				}

			} while (feof(pArchivo) == 0);


			fclose(pArchivo);
		}
	}


	return retorno;
}





