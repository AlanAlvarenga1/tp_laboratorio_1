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
//	int retorno=0;

	if (this!=NULL) {
		free(this);
		//retorno=1;
	}

	//return retorno;
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
//	int auxID;
	Employee* aux;

	for (i=1;i<len;i++) {
		aux=(Employee*)ll_get(this,i);
		//employee_getId(aux,&auxID);

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
int employee_searchLastID(LinkedList* this,int len) {
	int retorno=0;
	int i;
	Employee* aux;

	for (i=1;i<len;i++) {
		aux=ll_get(this,i);
		retorno=aux->id;
	}

	return retorno;
}


