/*
 * UTN.h
 *
 *  Created on: 28 abr. 2022
 *      Author: miguel
 */

#ifndef UTN_H_
#define UTN_H_
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError,int minimo, int maximo, int reintentos);
int pedirTexto(char* pResultado ,int leng, char* mensaje , char* mensajeError , int reintentos);
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int utn_pedirChar(char *pLetra , char *mensaje , char *mensajeError, int largo , int repeticiones);
int utn_pedirInt(int *pNumero , char *mensaje , char *mensajeError, int minimo , int maximo , int repeticiones);
int utn_pedirFloat(float *pNumero , char *mensaje , char *mensajeError, float minimo , float maximo , int repeticiones);



#endif /* UTN_H_ */
