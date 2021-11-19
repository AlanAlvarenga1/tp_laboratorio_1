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

/**
 * @fn int tomarInt(int*, char*, char*, int, int)
 * @brief Funcion que sirve para cargar un int, y devolverlo como int
 *
 * @param numeroADevolver Variable donde se cargara el entero
 * @param mensajeInicio Mensaje utilizado al incio de la funcion
 * @param mensajeError Mensaje utilizado cuando hay un error
 * @param min Numero minimo posible para la carga
 * @param max Numero maximo posible para la carga
 * @return retorna -1 si da error y 0 si esta bien
 */
int tomarInt(int* numeroADevolver, char* mensajeInicio, char* mensajeError, int min, int max);
/**
 * @fn int checkInt(char*,int, int, int)
 * @brief Chequea que el numero ingresado sea correcto
 *
 * @param stringNumbers Numero recibido
 * @param min numero minimo solicitado
 * @param max numero maximo solicitado
 * @param len cantidad de caracteres del numero
 * @return retorna 0 si salio bien, -1 si fallo
 */
int checkInt(char* stringNumbers,int min,int max,int len);
/**
 * @fn int tomarStringInt(char*, char*, char*, int, int)
 * @brief Funcion que sirve para cargar un int, y devolverlo como string
 *
 * @param numeroADevolver Variable donde se cargara el entero
 * @param mensajeInicio Mensaje utilizado al incio de la funcion
 * @param mensajeError Mensaje utilizado cuando hay un error
 * @param min Numero minimo posible para la carga
 * @param max Numero maximo posible para la carga
 * @return retorna -1 si da error y 0 si esta bien
 */
int tomarStringInt(char* numeroADevolver, char* mensajeInicio, char* mensajeError, int min, int max);
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
/**
 * @fn int tomarFloat(float*, char*, char*, int, int)
 * @brief Funcion que sirve para cargar un float, y devolverlo como float
 *
 * @param numeroADevolver Variable donde se cargara el entero
 * @param mensajeInicio Mensaje utilizado al incio de la funcion
 * @param mensajeError Mensaje utilizado cuando hay un error
 * @param min Numero minimo posible para la carga
 * @param max Numero maximo posible para la carga
 * @return retorna -1 si da error y 0 si esta bien
 */
int tomarFloat(float* numeroADevolver, char* mensajeInicio, char* mensajeError, int min, int max);
/**
 * @fn int checkFloat(char*,int, int, int)
 * @brief Chequea que el numero ingresado sea correcto
 *
 * @param stringNumbers Numero recibido
 * @param min numero minimo solicitado
 * @param max numero maximo solicitado
 * @param len cantidad de caracteres del numero
 * @return retorna 0 si salio bien, -1 si fallo
 */
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
