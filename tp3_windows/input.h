/*
 * input.h
 *
 *  Created on: 11 oct. 2021
 *      Author: Alan
 */

#ifndef INPUT_H_
#define INPUT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int tomarInt(int* numeroADevolver, char* mensajeInicio, char* mensajeError, int min, int max);
/**
 * @fn int checkInt(int, int, int)
 * @brief Chequea que el numero ingresado sea correcto
 *
 * @param numero numero recibido
 * @param min numero minimo solicitado
 * @param max numero maximo solicitado
 * @return retorna 0 si salio bien, -1 si fallo
 */

int tomarStringInt(char* numeroADevolver, char* mensajeInicio, char* mensajeError, int min, int max);


int checkInt(char* stringNumbers,int min,int max,int len);

/**
 * @fn void tomarString(char*, char*, char*, int)
 * @brief Funcion que sirve para tomar un string
 *
 * @param mensajeInicio Mensaje mostrado al inicio de la funcion
 * @param mensajeError Mensaje mostrado al momento en el que haya un error
 * @param string String que sera devuelto
 * @param tamChar Tamaño maximo del string
 */
int tomarString (char* mensajeInicio,char* mensajeError, char* string, int tamChar);
/**
 * @fn int checkString(char*, int)
 * @brief Chequea si el string ingresado no tiene un caracter invalido
 *
 * @param string string a analizar
 * @param tamMax tamaño maximo del string
 * @return retorna 0 si salio bien, -1 si fallo
 */
int checkString(char* string,int tamMax);

int tomarFloat(float* numeroADevolver, char* mensajeInicio, char* mensajeError, int min, int max);

int checkFloat(char* stringNumbers,int min,int max,int len);
/**
 * @fn int systemPause(char*)
 * @brief Pausa el sistema para solicitar que se toque ENTER para continuar
 *
 * @param message Mensaje impreso al momento de frenar el sistema
 * @return Retorna 1 si salio mal, 0 si salio bien
 */
int systemPause(char* message);


#endif /* INPUT_H_ */
