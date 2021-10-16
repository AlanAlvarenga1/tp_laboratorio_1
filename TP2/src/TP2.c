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
	int lastID;

	initEmployees(newCompany, maxEmployee);
	hardCodeEmployee(newCompany,&lastID,&employeeQuantity,3);

	while (option!=5) {
		showMenu (&option);

		switch (option) {
			case 1:
				if (checkAndAddEmployee (newCompany,&lastID,maxEmployee,maxChar)!=-1) {
					employeeQuantity++;
				}
				break;
			case 2:
				if (employeeQuantity>0) {
					printf ("Entering on the modification menu....");
					modifyEmployee (newCompany);
				}
				else {
					printf ("ERROR. There isn't any employee added. Use the first option and try again.");
				}
				break;
			case 3:
				if (employeeQuantity>0) {
					enterInt("Enter the ID of the employee: ","ERROR. You entered an illegal character. Try again\n",&idToRemove,1,6);
					if (removeEmployee (newCompany,maxEmployee,idToRemove)==0) {
						employeeQuantity--;
						printf ("The employee was deleted successfully");
					}
				}
				else {
					printf ("ERROR. There isn't any employee added. Use the first option and try again.");
				}
				break;
			case 4:
				if (employeeQuantity>0) {
					if (sortEmployees(newCompany, maxEmployee, 0)!=-1) {
						printEmployees(newCompany, maxEmployee);
						salaryChecker(newCompany,employeeQuantity,maxEmployee);
					}
					else {
						printf ("ERROR. Check the code, you must put 0(Up) or 1(Down) on order");
					}
				}
				else {
					printf ("ERROR. There isn't any employee added. Use the first option and try again.");
				}
				break;
			case 5:
				printf ("Thank you for using this program. Bye!");
				break;
		}
	}
}
