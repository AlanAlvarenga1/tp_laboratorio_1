/*
 * calculos.h
 *
 *  Created on: 21 sep. 2021
 *      Author: Alan
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

#include <stdio.h>
#include <stdlib.h>

/**
 * @fn float pedirNumero(char*, char*, int*, int*)
 * @brief Esta funcion se encarga de tomar los numeros de las opciones 1 y 2.
 *
 * @param mensaje Este mensaje indica la instruccion al usuario
 * @param mensajeError Este mensaje indica el error que se cometio al ingresar el numero
 * @param flag Este flag corresponde al de la opcion 1 o 2. Indica si se cargo correctamente el numero. 0=NO, 1=SI
 * @param flagCalculado Este flag indica si deben mostrarse los resultados. Por defecto se carga con un 0. 0=NO, 1=CALCULADO, 2=MOSTRADO
 * @return La funcion retorna el numero ingresado por el usuario
 */
float pedirNumero (char *mensaje,char *mensajeError,int *flag,int *flagCalculado);

/**
 * @fn void calcularNumeros(char*, char*, char*, float, float, float*, float*, float*, float*, int*, int*, int, int, int*)
 * @brief Esta funcion se encarga de calcular las diferentes cuentas utilizadas en la calculadora
 *
 * @param mensajeInicio Mensaje que se muestra al inicio de la funcion
 * @param mensajeError Mensaje que se muestra en el caso de que no se haya ingresado el num1 o num2
 * @param mensajeCorrecto Mensaje que se muestra si las operaciones se hicieron correctamente
 * @param num1 Esta variable contiene el numero uno
 * @param num2 Esta variable contiene el numero dos
 * @param suma Esta variable contiene el resultado de la suma de num1 y num2
 * @param resta Esta variable contiene el resultado de la resta de num1 y num2
 * @param multiplicacion Esta variable contiene el resultado de la multiplicacion de num1 y num2
 * @param division Esta variable contiene el resultado de la division de num1 y num2
 * @param factorial1 Esta variable contiene el resultado de la factorizacion de num1
 * @param factorial2 Esta variable contiene el resultado de la factorizacion de num2
 * @param flag1 Esta variable se encarga de chequear si se ingreso el num1
 * @param flag2 Esta variable se encarga de chequear si se ingreso el num2
 * @param flag3 Esta variable cambia el flag que indica si deben mostrarse los resultados. Por defecto cambia a 1. 0=NO, 1=CALCULADO, 2=MOSTRADO
 */
void calcularNumeros(char *mensajeInicio, char *mensajeError,char *mensajeCorrecto, float num1, float num2, float *suma, float *resta, float *multiplicacion, float *division, int *factorial1, int *factorial2, int flag1, int flag2, int *flag3);

/**
 * @fn float sumar(float, float)
 * @brief Esta funcion se encarga de sumar los numeros
 *
 * @param num1 Esta variable contiene el primer numero
 * @param num2 Esta variable contiene el segundo numero
 * @return Se retorna el resultado de la cuenta
 */
float sumar (float num1,float num2);

/**
 * @fn float restar(float, float)
 * @brief Esta funcion se encarga de restar los numeros
 *
 * @param num1 Esta variable contiene el primer numero
 * @param num2 Esta variable contiene el segundo numero
 * @return Se retorna el resultado de la cuenta
 */
float restar (float num1,float num2);

/**
 * @fn float multiplicar(float, float)
 * @brief Esta funcion se encarga de multiplicar los numeros
 *
 * @param num1 Esta variable contiene el primer numero
 * @param num2 Esta variable contiene el segundo numero
 * @return Se retorna el resultado de la cuenta
 */
float multiplicar (float num1,float num2);

/**
 * @fn float dividir(float, float)
 * @brief Esta funcion se encarga de dividir los numeros
 *
 * @param num1 Esta variable contiene el primer numero
 * @param num2 Esta variable contiene el segundo numero
 * @return Se retorna el resultado de la cuenta
 */
float dividir (float num1,float num2);

/**
 * @fn int factorizar(float)
 * @brief Esta funcion se encarga de factorizar un numero
 *
 * @param num Esta variable contiene el numero a factorizar
 * @return Se retorna el resultado de la cuenta
 */
int factorizar (float num);

#endif /* CALCULOS_H_ */
