/*
 * menu.h
 *
 *  Created on: Nov 4, 2021
 *      Author: Alan
 */

#ifndef SRC_MENU_H_
#define SRC_MENU_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "input.h"

/**
 * @fn void mostrarMenu(int*)
 * @brief Muestra el menu principal
 *
 * @param opciones Toma la opcion solicitada y la devuelve al main
 */
void mostrarMenu (int* opciones);
/**
 * @fn void subMenuModificacionEstadia(int*)
 * @brief Muestra el submenu de la opcion 2
 *
 * @param opciones Toma la opcion solicitada y la devuelve al main
 */
void subMenuModificacionEmpleado(int* opciones);

void subMenuOrdenamiento(int* opciones);

#endif /* SRC_MENU_H_ */
