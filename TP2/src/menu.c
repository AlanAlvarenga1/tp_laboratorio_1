/*
 * menu.c
 *
 *  Created on: 27 sep. 2021
 *      Author: Alan
 */

#include "menu.h"


void showMenu (int* options) {

	printf ("\n\n-------------------MENU-------------------\n\n"
			"1) Añadir un empleado\n"
			"2) Modificar un empleado\n"
			"3) Eliminar un empleado\n"
			"4) Mostrar empleados\n"
			"5) Salir\n\n");

	enterInt("Ingrese la opcion que deseas utilizar: ","ERROR. Ingrese una opcion correcta. 1-5: ",options,1,5);

}

void subMenuModification(int *options) {

	printf ("1) Ingrese el ID del empleado a modificar\n"
			"2) Modificar el nombre\n"
			"3) Modificar el apellido\n"
			"4) Modificar el salario\n"
			"5) Modificar el sector\n"
			"6) Salir\n\n");

	enterInt("Ingrese la opcion que desesas utilizar: ","ERROR. Ingrese una opcion correcta. 1-6: ",options,1,6);
}
