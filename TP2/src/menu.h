/*
 * menu.h
 *
 *  Created on: 27 sep. 2021
 *      Author: Alan
 */

#ifndef MENU_H_
#define MENU_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "inputs.h"

/**
 * @fn void showMenu(int*)
 * @brief It shows the main menu
 *
 * @param options This var will return the option that the user wants to use
 */
void showMenu (int* options);
/**
 * @fn void subMenuModification(int*, int)
 * @brief It shows the main menu
 *
 * @param options This var will return the option that the user wants to use
 * @param id This id will be showed to the user, to know what employee is editing
 * @param flag This var indicates if the ID was entered
 */
void subMenuModification(int *options,int id,int flag);


#endif /* MENU_H_ */
