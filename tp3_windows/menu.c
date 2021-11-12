/*
 * menu.c
 *
 *  Created on: Nov 4, 2021
 *      Author: Alan
 */
#include "menu.h"

void mostrarMenu (int* opciones) {

	printf ("\n\n-------------------MENU-------------------\n\n"
			"1) Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n"
			"2) Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n"
			"3) Alta de empleado\n"
			"4) Modificar datos del empleado\n"
			"5) Baja de empleado\n"
			"6) Listar empleados\n"
			"7) Ordenar empleados\n"
			"8) Guardar los datos de los empleados en el archivo data.csv (modo texto)\n"
			"9) Guardar los datos de los empleados en el archivo data.csv (modo binario)\n"
			"10) Salir del programa\n\n");

			tomarInt (opciones,"Ingrese la opcion que deseas utilizar: ","ERROR. Has ingresado una opcion incorrecta. 1-10: ",1, 10);
}

void subMenuModificacionEmpleado(int* opciones) {

	printf ("1) Ingrese el ID del empleado que desea modificar\n"
			"2) Modificar el nombre del empleado\n"
			"3) Modificar las horas de trabajo\n"
			"4) Modificar el sueldo del empleado\n"
			"5) Guardar cambios\n"
			"6) Salir del menu de modificar\n\n");

			tomarInt (opciones,"Ingrese la opcion que deseas utilizar: ","ERROR. Has ingresado una opcion incorrecta. 1-6: ",1, 6);
}

void subMenuOrdenamiento(int* opciones) {

	printf ("1) Ordenar por ID ascendiente\n"
			"2) Ordenar por ID descendiente\n"
			"3) Ordenar por nombre ascendiente\n"
			"4) Ordenar por nombre descendiente\n"
			"5) Ordenar por horas ascendientes\n"
			"6) Ordenar por horas descendientes\n"
			"7) Ordenar por sueldo ascendiente\n"
			"8) Ordenar por sueldo descendiente\n"
			"9) Salir del menu de modificar\n\n");

			tomarInt (opciones,"Ingrese la opcion que deseas utilizar: ","ERROR. Has ingresado una opcion incorrecta. 1-9: ",1, 9);
}
