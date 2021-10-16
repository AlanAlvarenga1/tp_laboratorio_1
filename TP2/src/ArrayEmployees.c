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
		list[i].id=i+1;
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

		*newestID=i+1;
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
			enterString("Enter the employee name: ","ERROR. You entered an illegal character. Try again: ",name,len);
			enterString("Enter the employee last name: ","ERROR. You entered an illegal character. Try again: ",lastName,len);
			enterFloat("Enter the salary of the employee: ","ERROR. You entered an illegal character. Try again: ",&salary,1000,20000);
			enterInt("Enter the sector of the employee. 1=JANITOR 2=SELLER 3=SECRETARY 4=WATCHMAN 5=ACCOUNTANT 6=PRESIDENT: ","ERROR. You entered an illegal character. Try again: ",&sector,1,6);

			printf ("%-5s %-25s %-25s %-25s %-25s\n","ID","Name","Last Name","Salary","Sector");
			printf ("%-5d %-25s %-25s %-25.2f %-25d\n",id,name,lastName,salary,sector);
			enterInt ("Do you want to add this employee? 0=YES 1=RESET -1=EXIT: ","ERROR. You entered an illegal character. Try again: ",&confirm,-1,1);

			switch (confirm) {
				case -1:
					printf ("Exiting.....\n\n");
					break;
				case 0:
					if (addEmployee(list, lenEmployee, id, name,lastName,salary,sector)!=-1) {
						returnal=0;
						*newestID=id;

						printf ("The employee was added!");
					}
					break;
				case 1:
					printf ("Restarting...\n");
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
			if (list[i].isEmpty==TRUE && list[i].id==id) {
				strcpy(list[i].name,name);
				strcpy(list[i].lastName,lastName);
				list[i].salary=salary;
				list[i].sector=sector;
				list[i].isEmpty=FALSE;
				returnal=0;
			}
		}
	}

	return returnal;
}

void modifyEmployee (Employee* list) {
	int option=0;
	int id;
	int i=-1;

	while (option!=6) {
		subMenuModification(&option,i);

		switch (option) {
			case 1:
				if ((enterInt("Enter the ID of the employee: ","ERROR. You entered an illegal character. Try again: ",&id,1,1000))==0) {
					i=findEmployeeById(list, maxEmployee,id);
				}
				break;
			case 2:
				if (i==-1) {
					printf ("ERROR. You didn't enter an ID. First use the option 1");
				}
				else {
					enterString ("Enter the new name: ","ERROR. You put an illegal character. Try again: ", list[i].name, maxChar);
				}
				break;
			case 3:
				if (i==-1) {
					printf ("ERROR. You didn't enter an ID. First use the option 1");
				}
				else {
					enterString ("Enter the new last name: ","ERROR. You put an illegal character. Try again: ", list[i].lastName, maxChar);
				}
				break;
			case 4:
				if (i==-1) {
					printf ("ERROR. You didn't enter an ID. First use the option 1");
				}
				else {
					enterFloat("Enter the new salary: ","ERROR. You put an illegal character. Try again: ",&list[i].salary,1000,20000);
				}
				break;
			case 5:
				if (i==-1) {
					printf ("ERROR. You didn't enter an ID. First use the option 1");
				}
				else {
					enterInt("Enter the new sector. 1=JANITOR 2=SELLER 3=SECRETARY 4=WATCHMAN 5=ACCOUNTANT 6=PRESIDENT: ","ERROR. You entered an illegal character. Try again: ",&list[i].sector,1,6);
				}
				break;
			case 6:
				printf ("\n\nLeaving the program....");
				break;
		}
	}
}

int removeEmployee(Employee* list, int len, int id) {
	int i;
	int confirm=1;
	int returnal=-1;

	while (confirm==1) {
		for (i=0;i<len;i++) {
			if (list[i].isEmpty==FALSE && list[i].id==id) {
				printf ("%-5s %-25s %-25s %-25s %-25s\n","ID","Name","Last Name","Salary","Sector");
				printf ("%-5d %-25s %-25s %-25.2f %-25d\n",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);

				enterInt ("Do you want to add this employee? 0=YES 1=RESET -1=EXIT: ","ERROR. You entered an illegal character. Try again: ",&confirm,-1,1);

				switch (confirm) {
					case -1:
						printf ("Exiting.....\n\n");
						break;
					case 0:
						list[i].isEmpty=TRUE;
						returnal=0;
						break;
					case 1:
						printf ("Restarting...\n");
						enterInt("Enter the ID of the employee: ","ERROR. You entered an illegal character. Try again: ",&id,1,6);
						break;
				}
			}
		}


	}
	return returnal;
}

int findEmployeeById(Employee* list, int len,int id) {
	int i;
	int returnal = -1;

	for(i=0; i<len; i++) {
		if(list[i].isEmpty != TRUE && list[i].id == id) {
			returnal = i;
			break;
		}
	}
	if (returnal==-1) {
			printf ("ERROR. The id you entered doesn't exist or isn't used. Try again");
	}

	return returnal;
}

int sortEmployees(Employee* list, int len, int order) {
	int returnal=-1;
	int i;
	int limit;
	int flagSwap;
	Employee aux;

	limit=len-1;
	if (order==0) {
		do {
			flagSwap=0;
			for (i=0;i<limit;i++) {
				if (strcmp(list[i].lastName,list[i+1].lastName)>0) {
					aux=list[i];
					list[i]=list[i+1];
					list[i+1]=aux;
					flagSwap=1;
				}
				else if ((strcmp(list[i].lastName,list[i+1].lastName)==0) && (list[i].sector > list[i+1].sector)) {
					aux=list[i];
					list[i]=list[i+1];
					list[i+1]=aux;
					flagSwap=1;
				}
			}
			limit--;
		}while (flagSwap);
		returnal=0;
	}
	else if (order==1) {
		do {
			flagSwap=0;
			for (i=0;i<limit;i++) {
				if (strcmp(list[i].lastName,list[i+1].lastName)<0) {
					aux=list[i];
					list[i]=list[i+1];
					list[i+1]=aux;
					flagSwap=1;
				}
				else if ((strcmp(list[i].lastName,list[i+1].lastName)==0) && (list[i].sector < list[i+1].sector)) {
					aux=list[i];
					list[i]=list[i+1];
					list[i+1]=aux;
					flagSwap=1;
				}
			}
			limit--;
		}while (flagSwap);
		returnal=0;
	}

	return returnal;
}

int printEmployees(Employee* list, int length) {
	int returnal=-1;
	int i;

	if (length>0) {
		printf ("%-5s %-25s %-25s %-25s %-25s\n","ID","Name","Last Name","Salary","Sector");

		for (i=0;i<length;i++) {
			if (list[i].isEmpty==FALSE) {
				printf ("%-5d %-25s %-25s %-25.2f %-25d\n",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
			}
		}
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

	for (i=0;i<max;i++) {
		if (list[i].isEmpty==FALSE && list[i].salary>average) {
			amountHighSalary++;
		}
	}

	printf ("\nThe average of salaries is %.2f and %d employees have a higher salary than the average\n",average,amountHighSalary);

}



