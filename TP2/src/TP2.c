/*
 ============================================================================
 Name        : TP2.c
 Author      : Alan
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayEmployees.h"
#include "menu.h"


int main(void) {
	setbuf (stdout,NULL);
	Employee newCompany[maxEmployee];
	int option=0;
	int idToRemove;
	int employeeQuantity;
	int lastID=0;

	initEmployees(newCompany, maxEmployee);
	hardCodeEmployee(newCompany,&lastID,&employeeQuantity,3);

	while (option!=5) {
		showMenu (&option);

		switch (option) {
			case 1:
				if (checkAndAddEmployee (newCompany,&lastID,maxEmployee,maxChar)!=-1) {
					employeeQuantity++;
					printf ("Se ha cargado el empleado exitosamente\n\n");
				}
            	systemPause("Presiones ENTER para continuar");
				break;
			case 2:
				if (employeeQuantity>0) {
					printf ("\nEntrando en el menu de modificaciones....");
					modifyEmployee (newCompany);
				}
				else {
					printf ("\nNo hay empleados cargados. Utilice la primer opcion.");
				}
            	systemPause("Presiones ENTER para continuar");
				break;
			case 3:
				if (employeeQuantity>0) {
					printEmployees(newCompany,maxEmployee);

					enterInt("\n\nIngresa el ID a eliminar: ","ERROR. Has ingresado un caracter invalido. Intentelo nuevamente: ",&idToRemove,1,1500);
					if (removeEmployee (newCompany,maxEmployee,idToRemove)==0) {
						employeeQuantity--;
						printf ("\nEl empleado fue eliminado exitosamente");
					}
				}
				else {
					printf ("\nNo hay empleados cargados. Utilice la primer opcion.");
				}
            	systemPause("Presiones ENTER para continuar");
				break;
			case 4:
				if (employeeQuantity>0) {
					if (sortEmployees(newCompany, maxEmployee, 0)!=-1) {
						printEmployees(newCompany, maxEmployee);
						salaryChecker(newCompany,employeeQuantity,maxEmployee);
					}
					else {
						printf ("\nERROR. Chequea el codigo, debes poner 0(Ascendente) o 1(Descendente)");
					}
				}
				else {
					printf ("\nNo hay empleados cargados. Utilice la primer opcion.");
				}
            	systemPause("Presiones ENTER para continuar");
				break;
			case 5:
				printf ("\n\nGracias por utilizar este programa!");
				break;
		}
	}
}
