/*
 * Alumno.c
 *
 *  Created on: 26 may. 2022
 *      Author: miguel
 */
#include "Alumno.h"
static int isValidarNombre(char* cadena,int longitud);
static int esNumericaVideo(char* cadena , int limite);
/*construimos un alumno en memoria */
eAlumno* alumno_new(void)
{
//	eAlumno* pAuxiliar ;

	//cuanta memoria vamos a reservar?
//	pAuxiliar = (eAlumno*)malloc(sizeof(eAlumno));// nos reserva espacio para UN alumno

	return (eAlumno*)malloc(sizeof(eAlumno));// nos retorna espacio para UN alumno
}
/*ya tenemos un constructor que nos construye a alumnos*/
eAlumno* alumno_newParametros(char* nombre, float altura , int id)
{
	eAlumno* punteroAlumno = NULL;
	punteroAlumno = alumno_new();//reservamos un alumno en memoria

	if(punteroAlumno != NULL)
	{
		strcpy(punteroAlumno->nombre, nombre);//como es un puntero a alumonos usamos el operador flecha
		punteroAlumno->altura = altura;
		punteroAlumno->id = id;
	}

	return punteroAlumno;
}
//*****************************************************************************
void alumno_delete(eAlumno* this)
{
	if(this != NULL )
	{
		free(this);
	}
}
int alumno_setAltura(eAlumno* this,float altura)
{
	int retorno = -1;

	if(this != NULL && altura > 0)
	{
		retorno = 0;
		this->altura = altura;
	}
	return retorno;
}
int alumno_getAltura(eAlumno* this,float* altura)
{
	int retorno = -1;

	if(this != NULL && altura !=NULL)
	{
		retorno = 0;
//a traves del puntero que resivi a la altura , voy a asignar lo que tengo en this->altura
		*altura = this->altura;
	}
	return retorno;
}


/*este es el cuerpo de un set:
 * valido los parametros y aparte verifico que este bien lo que le este por asignar en este campo
 * este va a ser el unico lugar de mi codigo en el cual voy a acceder de manera directa al campo thi->nombre */
int alumno_setNombre(eAlumno* this, char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		if(isValidarNombre(nombre, NOMBRE_LEN) == 1)
		{
			retorno = 0;
			strcpy(this->nombre, nombre);
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
static int isValidarNombre(char* cadena,int longitud)
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

/*devolvemos el dato que nos estan asignando */
int alumno_getNombre(eAlumno* this, char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
			retorno = 0;
			strcpy(nombre , this->nombre);
	}
	return retorno;
}

/**/
int alumno_setTxt(eAlumno* this, char* id)
{
	int retorno = -1;

	if(this != NULL && id != NULL)
	{
		if(esNumericaVideo(id, 10))//si es numerico pasa
		{
			this->id = atoi(id);//la funcion atoi devuelve lo que le pasmos como  texto a numero
			retorno = 0;
		}

	}
	return retorno;
}

int alumno_setId(eAlumno* this, int id)
{
	int retorno = -1;

	if(this != NULL && id >= 0)
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

int alumno_getIdTxt(eAlumno* this, char* id)
{
	int retorno = -1;

	if(this != NULL && id >= 0)
	{
		sprintf(id, "%d", this->id);//lo primero que resive es en donde lo quiero imprimir y despues es iguala la printf
		retorno = 0;
	}
	return retorno;
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
//*****************************************************************************

int alumno_deleteIndexArray(eAlumno* arrayPunteros[], int limite, int indice)
{
	int estado = -1;

	if(arrayPunteros != NULL && limite >= 0 && arrayPunteros[indice] != NULL)
	{
		estado = 0;

		free(arrayPunteros[indice]);//liberamos el espacio de memoria o liberas RAM/sirve para lo del malloc
		arrayPunteros[indice] = NULL; //igualamos a null porque sino lo igualamos a null nos vamos a estar creyendo de que sigue ocupado, en otras palabras en algun momento del programa va a comenzar a mostrar basura
/*osea el free y el igual a NULL  van juntas :
 * tenes que liberar la memoria que reservaste con malloc , pero despues tenes que dejar de apuntarla*/
	}

	return estado;
}


int alumno_initArray(eAlumno* arrayPunteros[], int limite)// arrayPunteros[] asi es un array de punteros a alumnos / de la otra manera es un array a alumnos
{
	int estado = -1;
	int  i;

	if(arrayPunteros != NULL && limite > 0)
	{
		estado = 0;
		for (i = 0; i < limite; ++i) {

			arrayPunteros[i] = NULL;//este es uno de los cambios/ en el momento de dar un alta vamos a remplazar ese NULL por la direccion de memoria de ese alumno
		}
	}
	return estado ;
}

int alumno_buscarLugarLibretArray(eAlumno* arrayPunteros[], int limite)// arrayPunteros[] asi es un array de punteros a alumnos / de la otra manera es un array a alumnos
{
	int estado = -1;
	int  i;
/*si tenemos un array , en cada posicion tenemos un alumno
 * AHORA si tenemos un array A PUNTEROS de array , en cada poscion vas a tener una direccion de memoria de donde esta el array y asi se accede com el operador flecha*/
	if(arrayPunteros != NULL && limite > 0)
	{
		for (i = 0; i < limite; ++i) {

			if(arrayPunteros[i] == NULL)
			{
				estado = i;
				break;
			}
		}
	}
	return estado ;
}


void alumno_imprimirArray(eAlumno* arrayPunteros[], int limite)
{
	int i;

	if(arrayPunteros != NULL && limite > 0)
	{
		printf("\n---Listas Alumnos----");
		for (i = 0; i < limite; ++i) {

			if(arrayPunteros[i] != NULL)
			{
				printf("\nID : %d || NOMBRE : %s  || ALTURA : %.2f ", arrayPunteros[i]->id , arrayPunteros[i]->nombre , arrayPunteros[i]->altura);//si trabajos con punteros accedemos a los campos del arraay a traves del operador flecha
			}
		}
	}
}


int alumno_buscarPorIdArray(eAlumno* arrayPunteros[], int limite, int id)
{
	int retorno  = -1;
	int  i;
	if(arrayPunteros != NULL && limite > 0 && id >= 0)
	{
		for (i = 0; i < limite; ++i) {

			if(arrayPunteros[i] != NULL && arrayPunteros[i]->id == id)
			{
				retorno  = i;
				break;
			}
		}
	}
	return retorno  ;
}


int alumno_agregarAlumnoArray(eAlumno* arrayPunteros[], int limite,char* nombre, float altura , int id)
{
	int retorno  = -1;
	int indiceLibre ;
	if(arrayPunteros != NULL && limite > 0 && id >= 0 && nombre != NULL )
	{
		indiceLibre = alumno_buscarLugarLibretArray(arrayPunteros, limite);
		if(indiceLibre >= 0)
		{
			arrayPunteros[indiceLibre] = alumno_newParametros(nombre, altura, id);
			retorno = indiceLibre;
		}
	}
	return retorno  ;

}


int alumno_borrarPorIdArray(eAlumno* arrayPunteros[], int limite, int idBorrar)
{
	int retorno  = -1;
	int indiceBorrar ;
	if(arrayPunteros != NULL && limite > 0 && idBorrar >= 0 )
	{
		indiceBorrar = alumno_buscarPorIdArray(arrayPunteros, limite, idBorrar);
		if(indiceBorrar >= 0)
		{
			free(arrayPunteros[indiceBorrar]);
			arrayPunteros[indiceBorrar] = NULL;
			retorno = 0;
		}
	}
	return retorno  ;

}

int alumno_ordenarArray(eAlumno* arrayPunteros[], int limite)
{
	int i;
	int retorno = -1;
	int flagSwap;
	//como estoy ordenando un array que dentro tiene punteros , lo que voy a necesitar temporalmente es guardar una direccion de memoria
	eAlumno* bufferPunteroAlumno ;

	if(arrayPunteros != NULL && limite > 0)
	{
		retorno = 0;
		do {
			flagSwap = 0;//falsa
			for (i = 0; i < limite; ++i)
			{
				if(arrayPunteros[i] != NULL &&
					arrayPunteros[i+1] != NULL &&
					strncmp(arrayPunteros[i]->nombre, arrayPunteros[i+1]->nombre, NOMBRE_LEN) > 0)//si existe una difencia
				{//hacer un swap es en este caso , intercambiar lo punteros

					bufferPunteroAlumno = arrayPunteros[i] ;//me guarde el puntero que esta en i en un buffer
					arrayPunteros[i] = arrayPunteros[i+1];//en esa posicion que tengo bacapeada , escribo en lo que hay array i +1
					arrayPunteros[i+1] = bufferPunteroAlumno;// y lo que en esta en i+1 pongo lo que originalmente estaba en el buffer
					flagSwap = 1;//lo pongo en 1 para esto pase una vez mas
				}
			}
		} while (flagSwap);
	}

	return retorno;
}

int alumno_calcularAlturaPromedioArray(eAlumno* arrayPunteros[], int limite, float* promedio )
{
	int i;
	int retorno = -1;
	int cantidadAlumnos = 0;
	float acumuladorAlturas = 0;

	if(arrayPunteros != NULL && limite > 0)
	{
		for (i = 0; i < limite; ++i) {

			if(arrayPunteros[i] != NULL)//si encontre un alumno que sea distinto de null pasa
			{
				cantidadAlumnos++;//lo incremento porque ya encontre un alumno
				acumuladorAlturas = acumuladorAlturas + arrayPunteros[i]->altura;//voy a acuumular lo que el acumulador tiene + lo que tenien de altura ese alumno en particular

			}
		}
		*promedio = acumuladorAlturas/cantidadAlumnos;
		retorno = 0;
	}
	return retorno;
}

int alumno_calcularAlumnoMasAltoArrayMigue(eAlumno* arrayPunteros[], int limite, float* alturaMayor)
{
	int i;
	int retorno = -1;
	float flagAltura = -1;
	float auxalturaMayor ;

	if(arrayPunteros != NULL && limite > 0)
	{
		for (i = 0; i < limite; ++i) {

			if(arrayPunteros[i] != NULL)//SIEMPŔE QUE TRABAJEMOS CON PUNTEROS A ARRAY TENEMOS QUE VERIFICAR SI EL ARRAY DE PUNTEROS EN X POSICION ES DISTINTO DE NULL
			{
				if(flagAltura == -1)
				{
					auxalturaMayor = arrayPunteros[i]->altura;
					flagAltura = 0;
				}

				if(auxalturaMayor < arrayPunteros[i]->altura)
				{
					auxalturaMayor = arrayPunteros[i]->altura;
				}


			}
		}
		*alturaMayor = auxalturaMayor;
		retorno = 0;
	}
	return retorno;
}

int alumno_calcularAlturaMaximaArray(eAlumno* arrayPunteros[], int limite, int* indice )
{
	int retorno = -1;
	int i;
	int indiceMaximo ;
	int alturaMaxima ;
	int flagones = 0;

	if(arrayPunteros != NULL && limite > 0)
	{
		for (i = 0; i < limite; ++i) {

			if(arrayPunteros[i] != NULL)//si encontre un alumno que sea distinto de null pasa
			{
				if(flagones == 0)
				{
					indiceMaximo = i;
					alturaMaxima = arrayPunteros[i]->altura;
					flagones = 1;

				}else if(arrayPunteros[i]->altura  > alturaMaxima){

					indiceMaximo = i;
					alturaMaxima = arrayPunteros[i]->altura;
				}

			}
		}
		*indice = indiceMaximo;
		retorno = 0;
	}
	return retorno;
}
