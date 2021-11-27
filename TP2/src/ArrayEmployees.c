/*
 * funciones.c
 *
 *  Created on: 5 oct. 2021
 *      Author: Alan
 */

#include "ArrayEmployees.h"

int initEmployees(Employee* list, int len) {
	int i;

	for (i=0;i<len;i++) {
		list[i].isEmpty=TRUE;
	}

	return 0;
}

void hardCodeEmployee(Employee* list,int* newestID,int* numberOfEmployee,int lenEmployee) {
	int i;
	int ids[] = {1,2,3};
	char names[][maxChar] = {"Joan","Albert","Jessica"};
	char lastNames[][maxChar] = {"Smith","Johnston","Ferdinand"};
	float salary[] = {3999.01,2549.99,6000.01};
	int sector[] = {SECRETARY,SELLER,ACCOUNTANT};

	for (i=0;i<lenEmployee;i++) {
		list[i].id=ids[i];
		strcpy (list[i].name,names[i]);
		strcpy (list[i].lastName,lastNames[i]);
		list[i].salary=salary[i];
		list[i].sector=sector[i];
		list[i].isEmpty=FALSE;

		*newestID=list[i].id;
		*numberOfEmployee=*numberOfEmployee+1;
	}
}

int checkAndAddEmployee (Employee* list,int* newestID,int lenEmployee,int len) {
	int returnal=-1;
	int id;
	char name[len];
	char lastName[len];
	float salary;
	int sector;
	int confirm=1;

	while (confirm==1) {
		if (*newestID<lenEmployee) {
			id=*newestID+1;
			enterString("\n\nIngrese el nombre del empleado: ","ERROR. Has ingresado un caracter no valido. Intente nuevamente: ",name,len);
			enterString("Ingrese el apellido del empleado: ","ERROR. Has ingresado un caracter no valido. Intente nuevamente: ",lastName,len);
			enterFloat("Ingrese el salario del empleado: ","ERROR. Has ingresado un caracter no valido. Intente nuevamente: ",&salary,1000,200000);
			enterInt("Ingrese el sector del empleado. 1=Conserje 2=Vendedor 3=Secretario 4=Vigilante 5=Contador 6=Presidente: ","ERROR. Has ingresado un caracter no valido. Intente nuevamente: ",&sector,1,6);

			printf ("\n%-5s %-25s %-25s %-25s %-25s\n","ID","Nombre","Apellido","Salario","Sector");
			printf ("%-5d %-25s %-25s %-25.2f %-25d\n\n",id,name,lastName,salary,sector);
			enterInt ("Quieres agregar a este empleado? SI=0 NO=1 SALIR=-1: ","ERROR. Has ingresado un caracter no valido. Intente nuevamente: ",&confirm,-1,1);

			switch (confirm) {
				case -1:
					printf ("\n\nSaliendo.....\n\n");
					break;
				case 0:
					if (addEmployee(list, lenEmployee, id, name,lastName,salary,sector)!=-1) {
						returnal=0;
						*newestID=id;
					}
					break;
				case 1:
					printf ("\n\nReiniciando...\n\n");
					break;
			}
		}
	}
	return returnal;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector) {
	int returnal=-1;
	int i;

	if (list!=NULL && name!=NULL && lastName!=NULL) {
		for (i=0;i<len;i++) {
			if (list[i].isEmpty==TRUE) {
				list[i].id=id;
				strcpy(list[i].name,name);
				strcpy(list[i].lastName,lastName);
				list[i].salary=salary;
				list[i].sector=sector;
				list[i].isEmpty=FALSE;
				returnal=0;

				break;
			}
		}
	}

	return returnal;
}

void modifyEmployee (Employee* list) {
	int option=0;
	int id;
	int i=-1;
	int flag=-1; //-1=NO CHARGED 0=CHARGED
	char newName[maxChar];
	char newLastName[maxChar];
	float newSalary;
	int newSector;
	int confirm;

	while (option!=6) {
		if (flag!=-1) {
				printf("-------------------------------------EMPLEADO SELECCIONADO-------------------------------------\n");
				printf ("%-5s %-25s %-25s %-25s %s\n","ID","Nombre","Apellido","Salario","Sector");
				printf ("--------------------------------------------------------------------------------------------\n");
				printf("%-5d %-25s %-25s %-25.2f %d\n",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
				printf ("--------------------------------------------------------------------------------------------\n");
		}
		else {
			printEmployees(list, maxEmployee);
		}
		subMenuModification(&option);

		switch (option) {
			case 1:
				if ((enterInt("Ingrese el ID del empleado: ","ERROR. Has ingresado un caracter no valido. Intente nuevamente: ",&id,1,1000))==0) {
					i=findEmployeeById(list, maxEmployee,id);
					if (i!=-1) {
						printf("\n\nEmpleado encontrado con exito!\n");
						flag=0;
					}
				}
            	systemPause("Presiones ENTER para continuar");
				break;
			case 2:
				confirm=1;
				if (flag==-1) {
					printf ("ERROR. No has ingresado ningun ID. Utilice primero la opcion 1");
				}
				else {
					while (confirm==1) {
						enterString ("\nIngrese el nuevo nombre: ","ERROR. Has ingresado un caracter no valido. Intente nuevamente: ", newName, maxChar);
						printf ("\nDeseas cambiar el nombre de %s a %s? ",list[i].name,newName);
						enterInt ("SI=0 NO=1 SALIR=-1: ","ERROR. Has ingresado un caracter invalido. Intente nuevamente: ",&confirm,-1,1);

						switch (confirm) {
							case 0:
								strcpy(list[i].name,newName);
								printf ("\n\nEl nombre fue cambiado con exito\n");
								break;
							case 1:
								printf("\nReiniciando....\n");
								break;
							case -1:
								printf("\n\nSaliendo....\n");
								break;
						}
					}
				}
            	systemPause("Presiones ENTER para continuar");
				break;
			case 3:
				confirm=1;
				if (flag==-1) {
					printf ("\n\nERROR. No has ingresado ningun ID. Utilice primero la opcion 1\n");
				}
				else {
					while (confirm==1) {
						enterString ("\nIngrese el nuevo apellido: ","ERROR. Has ingresado un caracter no valido. Intente nuevamente: ", newLastName, maxChar);
						printf ("\nDeseas cambiar el apellido de %s a %s? ",list[i].lastName,newLastName);
						enterInt ("SI=0 NO=1 SALIR=-1: ","ERROR. Has ingresado un caracter invalido. Intente nuevamente: ",&confirm,-1,1);

						switch (confirm) {
							case 0:
								strcpy(list[i].lastName,newLastName);
								printf ("\n\nEl apellido fue cambiado con exito\n");
								break;
							case 1:
								printf("\nReiniciando....\n");
								break;
							case -1:
								printf("\n\nSaliendo....\n");
								break;
						}
					}
				}
				systemPause("Presiones ENTER para continuar");
				break;
			case 4:
				confirm=1;
				if (flag==-1) {
					printf ("\n\nERROR. No has ingresado ningun ID. Utilice primero la opcion 1\n");
				}
				else {
					while (confirm==1) {
						enterFloat("\n\nIngrese el nuevo salario: ","ERROR. Has ingresado un caracter no valido. Intente nuevamente: ", &newSalary,1000,200000);
						printf ("\nDeseas cambiar el salario de %.2f a %.2f? ",list[i].salary,newSalary);
						enterInt ("SI=0 NO=1 SALIR=-1: ","ERROR. Has ingresado un caracter invalido. Intente nuevamente: ",&confirm,-1,1);

						switch (confirm) {
							case 0:
								list[i].salary=newSalary;
								printf ("\n\nEl salario fue cambiado con exito\n");
								break;
							case 1:
								printf("\nReiniciando....\n");
								break;
							case -1:
								printf("\n\nSaliendo....\n");
								break;
						}
					}
				}
            	systemPause("Presiones ENTER para continuar");
				break;
			case 5:
				confirm=1;
				if (flag==-1) {
					printf ("\n\nERROR. No has ingresado ningun ID. Utilice primero la opcion 1\n");
				}
				else {
					while (confirm==1) {
						enterInt("Ingrese el nuevo sector. 1=Conserje 2=Vendedor 3=Secretario 4=Vigilante 5=Contador 6=Presidente: ","ERROR. Has ingresado un caracter no valido. Intente nuevamente: ", &newSector,1,6);
						printf ("\nDeseas cambiar el sector de %d a %d? ",list[i].sector,newSector);
						enterInt ("SI=0 NO=1 SALIR=-1: ","ERROR. Has ingresado un caracter invalido. Intente nuevamente: ",&confirm,-1,1);

						switch (confirm) {
							case 0:
								list[i].sector=newSector;
								printf ("\n\nEl sector fue cambiado con exito\n");
								break;
							case 1:
								printf("\nReiniciando....\n");
								break;
							case -1:
								printf("\n\nSaliendo....\n");
								break;
						}
					}
				}
				systemPause("Presiones ENTER para continuar");
				break;
			case 6:
				printf ("\n\nAbandonando programa....\n");
				break;
		}
	}
}

int removeEmployee(Employee* list, int len, int id) {
	int i;
	int confirm=-1;
	int returnal=-1;

	i=findEmployeeById(list, len,id);
	if (i!=-1) {
		printf ("\n\n%-5s %-25s %-25s %-25s %-25s\n","ID","Nombre","Apellido","Salario","Sector");
		printf ("%-5d %-25s %-25s %-25.2f %-25d\n\n",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);

		enterInt ("Deseas eliminar a este empleado? 0=SI 1=SALIR: ","ERROR. Has ingresado un caracter no valido. Intente nuevamente: ",&confirm,-1,1);

		switch (confirm) {
		case 0:
			list[i].isEmpty=TRUE;
			returnal=0;
			break;
		case 1:
			printf("\n\nVolviendo al menu principal....\n");
			break;
		}
	}
	else {
		printf ("\n\nERROR. El ID ingresado no esta registrado. Volviendo al menu principal...\n");
	}
	return returnal;
}

int findEmployeeById(Employee* list, int len,int id) {
	int i;
	int returnal = -1;

	for(i=0; i<len; i++) {
		if(list[i].id == id && list[i].isEmpty != TRUE) {
			returnal = i;
			break;
		}
	}

	return returnal;
}

int sortEmployees(Employee* list, int len, int order) {
	int returnal=-1;
	int i;
	int j;
	Employee aux;


	if (order==0) {
		for (i=0;i<len-1;i++) {
			for(j=i+1;j<len;j++) {
				if (list[i].isEmpty==FALSE && list[j].isEmpty==FALSE) {
					if (strcmp(list[i].lastName,list[j].lastName)>0) {
						aux=list[j];
						list[j]=list[i];
						list[i]=aux;
					}
					else if ((strcmp(list[i].lastName,list[j].lastName)==0) && (list[i].sector > list[j].sector)) {
						aux=list[i];
						list[i]=list[j];
						list[j]=aux;
					}
				}
			}
		}
		returnal=0;
	}
	else {
		for (i=0;i<len-1;i++) {
			for(j=i+1;j<len;j++) {
				if (list[i].isEmpty==FALSE && list[j].isEmpty==FALSE) {
					if (strcmp(list[i].lastName,list[j].lastName)<0) {
						aux=list[j];
						list[j]=list[i];
						list[i]=aux;
					}
					else if ((strcmp(list[i].lastName,list[j].lastName)==0) && (list[i].sector < list[j].sector)) {
						aux=list[i];
						list[i]=list[j];
						list[j]=aux;
					}
				}
			}
		}
		returnal=0;
	}
	return returnal;
}

int printEmployees(Employee* list, int length) {
	int returnal=-1;
	int i;

	if (length>0) {
		printf ("\n\n--------------------------------------------------------------------------------------------\n");
		printf ("%-5s %-25s %-25s %-25s %-25s\n","ID","Nombre","Apellido","Salario","Sector");
		printf ("--------------------------------------------------------------------------------------------\n");

		for (i=0;i<length;i++) {
			if (list[i].isEmpty==FALSE) {
				printf ("%-5d %-25s %-25s %-25.2f %-25d\n",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
			}
		}
		printf ("--------------------------------------------------------------------------------------------\n\n");
		returnal=0;
	}
	return returnal;
}

void salaryChecker(Employee* list,int quantity,int max) {
	int i;
	int amountHighSalary=0;
	float average;
	float sumOfSalaries=0;

	for (i=0;i<max;i++) {
		if (list[i].isEmpty==FALSE) {
			sumOfSalaries=sumOfSalaries+list[i].salary;
		}
	}
	average=sumOfSalaries/quantity;

	printf("\n\nSuma total de salarios: %.2f\n",sumOfSalaries);
	printf("Promedio de salarios: %.2f\n",average);

	printf ("\n--------------------LISTA DE EMPLEADOS CON SALARIO MAS ALTO AL PROMEDIO---------------------\n");
	printf ("%-5s %-25s %-25s %-25s %-25s\n","ID","Nombre","Apellido","Salario","Sector");
	printf ("--------------------------------------------------------------------------------------------\n");

	for (i=0;i<max;i++) {
		if (list[i].isEmpty==FALSE && list[i].salary>average) {
			printf ("%-5d %-25s %-25s %-25.2f %-25d\n",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
			amountHighSalary++;
		}
	}
	printf ("--------------------------------------------------------------------------------------------\n");

	printf("Cantidad total: %d",amountHighSalary);
}



