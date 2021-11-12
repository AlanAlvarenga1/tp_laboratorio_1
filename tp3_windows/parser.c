#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee) {
	int retorno=0;
	char id[10];
	char nombre[51];
	char horasTrabajadas[10];
	char sueldo[10];
	Employee* unEmpleado;

	if (pFile!=NULL && pArrayListEmployee!=NULL) {
		while (feof(pFile)==0) {
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]",id,nombre,horasTrabajadas,sueldo);
			if (feof(pFile)!=0) {
				break;
			}
			unEmpleado= employee_newParametros(id,nombre,horasTrabajadas,sueldo);

			if (unEmpleado!=NULL) {
				ll_add(pArrayListEmployee, unEmpleado);
			}
			unEmpleado=NULL;
		}
		retorno=1;
	}
	return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee) {
	int retorno=0;
	Employee* unEmpleado;

	if (pFile!=NULL && pArrayListEmployee!=NULL) {
		while (feof(pFile)==0) {
			unEmpleado=employee_new();

			if (fread(unEmpleado,sizeof(Employee),1,pFile)==1) {
				ll_add(pArrayListEmployee, unEmpleado);
			}

			unEmpleado=NULL;
		}
		retorno=1;
	}
	return retorno;
}
