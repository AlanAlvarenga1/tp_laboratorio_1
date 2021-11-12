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

	printf ("\n\n-------------------MODIFICAR-------------------\n\n"
			"1) Ingrese el ID del empleado que desea modificar\n"
			"2) Modificar el nombre del empleado\n"
			"3) Modificar las horas de trabajo\n"
			"4) Modificar el sueldo del empleado\n"
			"5) Guardar cambios\n"
			"6) Salir del menu de modificar\n\n");

			tomarInt (opciones,"Ingrese la opcion que deseas utilizar: ","ERROR. Has ingresado una opcion incorrecta. 1-6: ",1, 6);
}

void subMenuOrdenamiento(int* opciones) {

	printf ("\n\n-------------------ORDENAMIENTO-------------------\n\n"
			"1) Ordenar por ID \n"
			"2) Ordenar por nombre\n"
			"3) Ordenar por horas\n"
			"4) Ordenar por sueldo\n"
			"5) Salir del menu de modificar\n\n");

			tomarInt (opciones,"Ingrese la opcion que deseas utilizar: ","ERROR. Has ingresado una opcion incorrecta. 1-9: ",1, 9);
}
