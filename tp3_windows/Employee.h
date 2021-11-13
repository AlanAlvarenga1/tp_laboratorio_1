#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

#define maxChar 128

typedef struct
{
    int id;
    char nombre[maxChar];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
void employee_delete(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

void printUnEmpleado(Employee* this);
int employee_searchID(LinkedList* this,int idABuscar,int len);
void save_modification (Employee* empleadoConDatos,Employee* empleadoAGuardar);
int employee_searchLastID(void);
void employee_saveLastID(char* lastID);

int employee_orderByID (void* employeeOne, void* employeeTwo);
int employee_orderByName (void* employeeOne, void* employeeTwo);
int employee_orderByHours (void* employeeOne, void* employeeTwo);
int employee_orderBySalary (void* employeeOne, void* employeeTwo);



#endif // employee_H_INCLUDED
