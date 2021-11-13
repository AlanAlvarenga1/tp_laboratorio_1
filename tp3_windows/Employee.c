#include "Employee.h"

Employee* employee_new() {
	Employee* empleadoARetornar = NULL;
	empleadoARetornar= (Employee*) malloc (sizeof(Employee));
	return empleadoARetornar;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr) {
	Employee* empleado = NULL;
	empleado= employee_new();

	int id=atoi(idStr);
	int horasTrabajadas=atoi(horasTrabajadasStr);
	int sueldo=atoi(sueldoStr);

	employee_setId(empleado,id);
	employee_setNombre(empleado,nombreStr);
	employee_setHorasTrabajadas(empleado,horasTrabajadas);
	employee_setSueldo(empleado,sueldo);

	return empleado;
}
void employee_delete(Employee* this) {
	free(this);
	this=NULL;
}

int employee_setId(Employee* this,int id) {
	int retorno=0;
	if (this!=NULL) {
		this->id=id;
		retorno=1;
	}
	return retorno;
}
int employee_getId(Employee* this,int* id) {
	int retorno=0;
	if (this!=NULL) {
		*id=this->id;
		retorno=1;
	}
	return retorno;
}

int employee_setNombre(Employee* this,char* nombre) {
	int retorno=0;
	if (this!=NULL && nombre!=NULL) {
		strcpy(this->nombre, nombre);
		retorno=1;
	}
	return retorno;
}
int employee_getNombre(Employee* this,char* nombre) {
	int retorno=0;
	if (this!=NULL && nombre!=NULL) {
		strcpy(nombre,this->nombre);
		retorno=1;
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas) {
	int retorno=0;
	if (this!=NULL) {
		this->horasTrabajadas= horasTrabajadas;
		retorno=1;
	}
	return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas) {
	int retorno=0;
	if (this!=NULL) {
		*horasTrabajadas=this->horasTrabajadas;
		retorno=1;
	}
	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo) {
	int retorno=0;
	if (this!=NULL) {
		this->sueldo= sueldo;
		retorno=1;
	}
	return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo) {
	int retorno=0;
	if (this!=NULL) {
		*sueldo=this->sueldo;
		retorno=1;
	}
	return retorno;
}
void printUnEmpleado(Employee* this) {

	//if (this!=NULL) {
		printf ("%-10d %-25s %-25d %d\n",this->id,this->nombre,this->horasTrabajadas,this->sueldo);
	//}
}
int employee_searchID(LinkedList* this,int idABuscar,int len) {
	int i;
	int retorno=-1;
	Employee* aux;

	for (i=1;i<len;i++) {
		aux=(Employee*)ll_get(this,i);

		if (aux->id==idABuscar) {
			retorno=i;
			break;
		}
	}

	return retorno;
}
void save_modification (Employee* empleadoConDatos,Employee* empleadoAGuardar) {
	empleadoAGuardar->id=empleadoConDatos->id;
	strcpy(empleadoAGuardar->nombre,empleadoConDatos->nombre);
	empleadoAGuardar->horasTrabajadas=empleadoConDatos->horasTrabajadas;
	empleadoAGuardar->sueldo=empleadoConDatos->sueldo;
}
void employee_searchLastID(int* id) {
	FILE* fileID;
	char stringId[10];

	fileID=fopen("lastID.txt","w");

	fprintf(fileID,"%s","1000");
	fclose(fileID);

	fileID=fopen("lastID.txt","r");

	fscanf(fileID,"%[^\n]",stringId);
	*id=atoi(stringId);

	fclose(fileID);
}
void employee_saveLastID(char* lastID) {
	FILE* fileID;
	fileID=fopen("lastID.txt","w");

	fprintf(fileID,"%s",lastID);
	fclose(fileID);
}

int employee_orderID (void* employeeOne, void* employeeTwo) {
	int retorno;

	if (employeeOne!=NULL && employeeTwo!=NULL) {
		int employeeOne_ID;
		int employeeTwo_ID;
		employee_getId(employeeOne,&employeeOne_ID);
		employee_getId(employeeTwo,&employeeTwo_ID);

		if (employeeOne_ID>employeeTwo_ID) {
			retorno=1;
		}
		else if (employeeOne_ID<employeeTwo_ID) {
			retorno=-1;
		}
		else {
			retorno=0;
		}
	}

	return retorno;
}

int employee_orderName (void* employeeOne, void* employeeTwo) {
	int retorno;

	if (employeeOne!=NULL && employeeTwo!=NULL) {
		char employeeOne_Name[maxChar];
		char employeeTwo_Name[maxChar];
		employee_getNombre(employeeOne,employeeOne_Name);
		employee_getNombre(employeeTwo,employeeTwo_Name);

		retorno=strcmp(employeeOne_Name,employeeTwo_Name);
	}

	return retorno;
}

int employee_orderHours (void* employeeOne, void* employeeTwo) {
	int retorno;

	if (employeeOne!=NULL && employeeTwo!=NULL) {
		int employeeOne_Hours;
		int employeeTwo_Hours;
		employee_getHorasTrabajadas(employeeOne,&employeeOne_Hours);
		employee_getHorasTrabajadas(employeeTwo,&employeeTwo_Hours);

		if (employeeOne_Hours>employeeTwo_Hours) {
			retorno=1;
		}
		else if (employeeOne_Hours<employeeTwo_Hours) {
			retorno=-1;
		}
		else {
			retorno=0;
		}
	}

	return retorno;
}

int employee_orderSalary (void* employeeOne, void* employeeTwo) {
	int retorno;

	if (employeeOne!=NULL && employeeTwo!=NULL) {
		int employeeOne_Salary;
		int employeeTwo_Salary;
		employee_getSueldo(employeeOne,&employeeOne_Salary);
		employee_getSueldo(employeeTwo,&employeeTwo_Salary);

		if (employeeOne_Salary>employeeTwo_Salary) {
			retorno=1;
		}
		else if (employeeOne_Salary<employeeTwo_Salary) {
			retorno=-1;
		}
		else {
			retorno=0;
		}
	}

	return retorno;
}

