/*
 * menu.c
 *
 *  Created on: 27 sep. 2021
 *      Author: Alan
 */

#include "menu.h"


void showMenu (int* options) {

	printf ("\n\n-------------------MENU-------------------\n\n"
			"1) Add an employee\n"
			"2) Modify an employee\n"
			"3) Remove an employee\n"
			"4) Show employees\n"
			"5) Exit\n\n");

	enterInt("Enter the option you want to use: ","ERROR. Enter a correct option. 1-5: ",options,1,5);

}

void subMenuModification(int *options,int id) {
	int checkVar;

	printf ("\n\n-------------------MODIFICATION-------------------\n\n");
	if (id!=-1) {
		printf ("The selected employee has the following ID: %d\n",id+1);
	}
	printf ("1) Enter the employee ID\n"
			"2) Modify the name\n"
			"3) Modify the last name\n"
			"4) Modify the salary\n"
			"5) Modify the sector\n"
			"6) Exit\n\n"
			"Enter the option you want to use: ");
	fflush (stdin);
	checkVar=scanf ("%d",options);

	while (checkVar==0 || (*options<1 && *options>7)) {
		printf ("ERROR. Enter a correct option. 1-6: ");
		fflush (stdin);
		checkVar=scanf ("%d",options);
	}
}
