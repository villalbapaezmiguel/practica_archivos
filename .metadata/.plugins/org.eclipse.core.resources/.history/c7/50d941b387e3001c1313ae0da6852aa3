
/*
 * UTN.c
 *
 *  Created on: 28 abr. 2022
 *      Author: miguel
 */
#include "UTN.h"
static int getInt (int* pResultado);
static int myGets (char* cadena , int longitud);
static int esNumerica(char* cadena );
static int esNumericaVideo(char* cadena , int limite);
static int getNombre(char* pResultado, int longitud);
static int getString(char* cadena, int longitud);
static int esNombre(char* cadena,int longitud);

/*\brief Solicita un numero al usuario , lo valida , verifica y devuelve el resultado
 *\param pRespuesta Puntero al resultado alli se dejara el numero ingresado por el usuario
 *\param mensaje es El mensaje a ser mostrado
 *\param mensajeError Es el mensaje a ser mostrado en caso de error
 *\param minimo Valor minimo aceptado
 *\param maximo Valor maximo aceptado
 *\param reintentos Cantidad de reintentos en el caso de error
 *\return En caso de exito (0) , en caso de error (-1)
 */
int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError,int minimo, int maximo, int reintentos)
{

	//1ro no sfijamos que todos los puntero tienen que ser != NULL
	int bufferInt;
	int retorno = -1;

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0) {

		while (reintentos >= 0)
		{
			printf("%s", mensaje);
			//scanf("%d", &bufferInt); //quiero que scanf me deje en esat direccion lo que acaba de leer
			//el usuario recien ingreso algo , entonces tenemos que ver si ese algo es mayo o igual al minimo
			if (getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;

			}else{
				printf("\n%s", mensajeError);
				printf("\nle quedan : %d intentos ", reintentos);

			}
			reintentos--;
		}
	}
	return retorno;
}

static int getInt (int* pResultado)
{
	int retorno = -1;
	char buffer [4096];
	//scanf("%s",buffer); no lo usamos mas

	if(myGets(buffer, sizeof(buffer)) == 0 && esNumerica (buffer))
	{
		retorno  = 0;
		*pResultado = atoi(buffer);//lo que hace atoi es convertir una cadena en un entero
	}

	return retorno;
}

static int myGets (char* cadena , int longitud)
{
	__fpurge(stdin);
/*fgets : significa que lee un archivo (en este caso : stdin)
 * 1er parametro : en donde se va a dejar la informacion
 * 2do parametro : la longitud o cantidad
 * 3er parametro : el archivo*/
	fgets(cadena,longitud, stdin);
	cadena[strlen(cadena)-1] = '\0';

//	scanf("%s",buffer);
//	strncpy(cadena,buffer, longitud);//strncpy(su destino , la fuente , cantidad a copiar);
	return 0;
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
/*\brief Verifica si la cadena ingresada es numerica
 *\param cadena Cadena de caracteres a ser analizada
 *\return  Retorno 1(verdadero) si la cadena es numerica , 0(falso) si no lo es y -1 en caso de error */
static int esNumericaVideo(char* cadena , int limite)
{
	int retorno = -1;
	int i;

	if(cadena != NULL && limite >0)
	{
		retorno = 1;//verdadero
		for (i = 0; i < limite; ++i) {

			if(i == 0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}

			if(cadena[i] < '0' || cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
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

/*pedirTexto ()
 * Esta funcion lo que hace es pedirle un texto al usuario
 *param  char* pResultado : el la estructura que se pasa por parametro
 *param  int leng : es la longitud de la de estructura
 *param  char* mensaje : el mensaje que vera el usuario
 *param  char* mensajeError : es el mensaje de error que vera el usuario si algo salio mal
 *param  int reintentos : son las cantidades de reitentos que tiene
 *
 *return 0 si todo salio bien , de lo contrario -1
 **/
int pedirTexto(char* pResultado ,int leng, char* mensaje , char* mensajeError , int reintentos)
{
	int retorno = -1;

	for (int i = 0; i < reintentos; ++i) {

		if(pResultado != NULL && mensaje != NULL && mensajeError != NULL )
		{
			printf("%s", mensaje);
			__fpurge(stdin);

			if(fgets(pResultado,leng,stdin) != NULL)
			{
				retorno = 0;
				break;
			}else{
				printf("%s",mensajeError);
			}
		}
	}
	return retorno;
}

/**
 * \brief Solicita un nombre al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getNombre(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

/*\brief Solicita un numero al usuario , lo valida , verifica y devuelve el resultado
 *\param pLetra Puntero al resultado alli se dejara el char ingresado por el usuario
 *\param mensaje es El mensaje a ser mostrado
 *\param mensajeError Es el mensaje a ser mostrado en caso de error
 *\param minimo Valor minimo aceptado
 *\param maximo Valor maximo aceptado
 *\param reintentos Cantidad de reintentos en el caso de error
 *\return En caso de exito (0) , en caso de error (-1)
 */
int utn_pedirChar(char *pLetra , char *mensaje , char *mensajeError, int largo , int repeticiones)
{
//	char bufferChar [4030];
	int respuesta = -1;

	while(repeticiones >= 0)
	{
		if(pLetra != NULL && mensaje != NULL && mensajeError != NULL && largo > 0 && repeticiones >= 0)
		{
			printf("%s",mensaje);
			__fpurge(stdin);

			if(fgets(pLetra , largo , stdin) != NULL)
			{
				respuesta = 0;
				break;
			}else{
				printf("%s",mensajeError);
			}



//			if(sizeof(bufferChar) >= minimo && sizeof(bufferChar) <= maximo)
//			{
//				strncpy(*&pLetra , bufferChar , sizeof(*pLetra));
//				respuesta = 0;
//				break;
//			}else{
//				printf("%s",mensajeError);
//			}

		}
	}
	return respuesta;

}

/*\brief Solicita un numero al usuario , lo valida , verifica y devuelve el resultado
 *\param pNumero Puntero al resultado alli se dejara el int ingresado por el usuario
 *\param mensaje es El mensaje a ser mostrado
 *\param mensajeError Es el mensaje a ser mostrado en caso de error
 *\param minimo Valor minimo aceptado
 *\param maximo Valor maximo aceptado
 *\param reintentos Cantidad de reintentos en el caso de error
 *\return En caso de exito (0) , en caso de error (-1)
 */
int utn_pedirInt(int *pNumero , char *mensaje , char *mensajeError, int minimo , int maximo , int repeticiones)
{
	int bufferInt;
	int respuesta =-1;

	while(repeticiones >= 0)
	{
		if(pNumero != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && repeticiones >= 0)
		{
			printf("%s",mensaje);
			scanf("%d",&bufferInt);

			if(bufferInt >= minimo && bufferInt <= maximo)
			{
				*pNumero = bufferInt ;
				respuesta = 0;
				break ;

			}else{
				printf("%s",mensajeError);
			}

		}
	}
	return respuesta;
}
/*\brief Solicita un numero al usuario , lo valida , verifica y devuelve el resultado
 *\param pNumero Puntero al resultado alli se dejara el float ingresado por el usuario
 *\param mensaje es El mensaje a ser mostrado
 *\param mensajeError Es el mensaje a ser mostrado en caso de error
 *\param minimo Valor minimo aceptado
 *\param maximo Valor maximo aceptado
 *\param reintentos Cantidad de reintentos en el caso de error
 *\return En caso de exito (0) , en caso de error (-1)
 */
int utn_pedirFloat(float *pNumero , char *mensaje , char *mensajeError, float minimo , float maximo , int repeticiones)
{
	int bufferFloat;
	int respuesta = -1;

	while(repeticiones >= 0)
	{
		if(pNumero != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && repeticiones >=0)
		{
			printf("%s",mensaje);
			scanf("%d",&bufferFloat);

			if(bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pNumero = bufferFloat;
				respuesta = 0;
				break ;
			}else{
				printf("%s",mensajeError);
			}
		}
	}

	return respuesta;

}





