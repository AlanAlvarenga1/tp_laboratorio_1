/*
 * funciones.h
 *
 *  Created on: 15 sep. 2021
 *      Author: Alan
 */

#ifndef MENU_H_
#define MENU_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @fn int iniciarMenu(float, float, int, int, int, float, float, float, float, int, int)
 * @brief Esta funcion se encarga de iniciar el menu, contiene en ella las funciones que desplegan las diferentes opciones. Finalmente toma la opcion deseada por el usuario
 *
 * @param num1 Contiene el primer numero ingresado
 * @param num2 Contiene el segundo numero ingresado
 * @param primerFlag Este flag se encarga de indicar si se utilizo la primera opcion. 0=NO, 1=SI
 * @param segundoFlag Este flag se encarga de indicar si se utilizo la segunda opcion. 0=NO, 1=SI
 * @param flagCalculacion Este flag se encarga de indicar si el numero se calculo, y si fue mostrado. 0=NO, 1=CALCULADO, 2=MOSTRADO
 * @param suma Contiene la suma de num1 y num2
 * @param resta Contiene la resta de num1 y num2
 * @param multiplicacion Contiene la multiplicacion de num1 y num2
 * @param division Contiene la division de num1 y num2
 * @param factorial1 Contiene el factorial de num1
 * @param factorial2 Contiene el factorial de num2
 * @return Retorna el numero de opcion que el usuario desea utilizar
 */
int iniciarMenu (float num1,float num2,int primerFlag, int segundoFlag, int flagCalculacion,float suma,float resta,float multiplicacion,float division,int factorial1,int factorial2);

/**
 * @fn void mostrarOpcion1(float, int)
 * @brief Muestra la opcion 1. Cambia dependiendo si se ingreso o no el num1
 *
 * @param num1 Contiene el primer numero ingresado
 * @param primerFlag Este flag se encarga de indicar si se utilizo la primera opcion. 0=NO, 1=SI. Segun el estado, cambiara el menu
 */
void mostrarOpcion1 (float num1,int primerFlag);

/**
 * @fn void mostrarOpcion2(float, int)
 * @brief Muestra la opcion 2. Cambia dependiendo si se ingreso o no el num2
 *
 * @param num2 Contiene el segundo numero ingresado
 * @param segundoFlag Este flag se encarga de indicar si se utilizo la segunda opcion. 0=NO, 1=SI. Segun el estado, cambiara el menu
 */
void mostrarOpcion2 (float num2,int segundoFlag);

/**
 * @fn void mostrarOpcion3(float, float)
 * @brief Muestra la opcion 3. Cambia dependiendo si se ingresaron o no las variables num1 y num2
 *
 * @param num1 Contiene el primer numero ingresado
 * @param num2 Contiene el segundo numero ingresado
 */
void mostrarOpcion3 (float num1,float num2);

/**
 * @fn void mostrarOpcion4(float, float, int, float, float, float, float, int, int)
 * @brief
 *
 * @param num1 Contiene el primer numero ingresado
 * @param num2 Contiene el segundo numero ingresado
 * @param flagCalculacion Este flag se encarga de indicar si el numero se calculo, y si fue mostrado. 0=NO, 1=CALCULADO, 2=MOSTRADO. Segun el estado, cambiara el menu
 * @param suma Contiene la suma de num1 y num2
 * @param resta Contiene la resta de num1 y num2
 * @param multiplicacion Contiene la multiplicacion de num1 y num2
 * @param division Contiene la division de num1 y num2
 * @param factorial1 Contiene el factorial de num1
 * @param factorial2 Contiene el factorial de num2
 */
void mostrarOpcion4 (float num1,float num2, int flagCalculacion,float suma,float resta,float multiplicacion,float division,int factorial1,int factorial2);

/**
 * @fn int mostrarOpcion5YSeleccion(void)
 * @brief Muestra la opcion 5 y se encarga de tomar la opcion que el usuario desea utilizar
 *
 * @return Retorna la opcion que el usuario desea utilizar
 */
int mostrarOpcion5YSeleccion (void);
#endif /* MENU_H_ */
