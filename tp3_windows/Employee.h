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

/**
 * @fn Employee employee_new*()
 * @brief Crea un espacio para el array de empleados en el malloc
 *
 * @return Retorna el puntero creado
 */
Employee* employee_new();
/**
 * @fn Employee employee_newParametros*(char*, char*, char*, char*)
 * @brief Toma ciertos parametros para añadirlos al empleado ya creado en el malloc
 *
 * @param idStr Parametro de ID a añadir
 * @param nombreStr Parametro de nombre a añadir
 * @param horasTrabajadasStr Parametro de horasTrabajadas a añadir
 * @param sueldoStr Parametro de sueldo a añadir
 * @return Retorna al empleado con los datos ya cargados
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
/**
 * @fn void employee_delete(Employee*)
 * @brief Elimina un empleado auxiliar que no se encuentra en el malloc
 *
 * @param this Empleado a eliminar
 */
void employee_delete(Employee* this);
/**
 * @fn int employee_setId(Employee*, int)
 * @brief Inserta un ID a un empleado determinado
 *
 * @param this Empleado al que se le insertara el parametro
 * @param id ID a insertar
 * @return Devuelve 1 si se realizo con exito, y 0 si salio mal
 */
int employee_setId(Employee* this,int id);
/**
 * @fn int employee_getId(Employee*, int*)
 * @brief Obtiene el ID de un empleado
 *
 * @param this Empleado al que se le obtendra el ID
 * @param id  parametro que recibira el ID obtenido
 * @return Devuelve 1 si se realizo con exito, y 0 si salio mal
 */
int employee_getId(Employee* this,int* id);
/**
 * @fn int employee_setNombre(Employee*, char*)
 * @brief Inserta un nombre a un empleado determinado
 *
 * @param this Empleado al que se le insertara el parametro
 * @param nombre Nombre a insertar
 * @return Devuelve 1 si se realizo con exito, y 0 si salio mal
 */
int employee_setNombre(Employee* this,char* nombre);
/**
 * @fn int employee_getNombre(Employee*, char*)
 * @brief Obtiene el nombre de un empleado
 *
 * @param this Empleado al que se le obtendra el nombre
 * @param nombre parametro que recibira el nombre obtenido
 * @return Devuelve 1 si se realizo con exito, y 0 si salio mal
 */
int employee_getNombre(Employee* this,char* nombre);
/**
 * @fn int employee_setHorasTrabajadas(Employee*, int)
 * @brief Inserta las horasTrabajadas a un empleado determinado
 *
 * @param this Empleado al que se le insertara el parametro
 * @param horasTrabajadas Horas a insertar
 * @return Devuelve 1 si se realizo con exito, y 0 si salio mal
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
/**
 * @fn int employee_getHorasTrabajadas(Employee*, int*)
 * @brief Obtiene las horas trabajadas de un empleado
 *
 * @param this Empleado al que se le obtendra las horas
 * @param horasTrabajadas  parametro que recibira el horario obtenido
 * @return Devuelve 1 si se realizo con exito, y 0 si salio mal
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
/**
 * @fn int employee_setSueldo(Employee*, int)
 * @brief Inserta el sueldo a un empleado determinado
 *
 * @param this Empleado al que se le insertara el parametro
 * @param sueldo Sueldo a insertar
 * @return Devuelve 1 si se realizo con exito, y 0 si salio mal
 */
int employee_setSueldo(Employee* this,int sueldo);
/**
 * @fn int employee_getSueldo(Employee*, int*)
 * @brief Obtiene el sueldo de un empleado
 *
 * @param this Empleado al que se le obtendra el sueldo
 * @param sueldo parametro que recibira el sueldo obtenido
 * @return Devuelve 1 si se realizo con exito, y 0 si salio mal
 */
int employee_getSueldo(Employee* this,int* sueldo);

/**
 * @fn void printUnEmpleado(Employee*)
 * @brief Imprime un empleado
 *
 * @param this Empleado a imprimir
 */
void printUnEmpleado(Employee* this);
/**
 * @fn int employee_searchID(LinkedList*, int, int)
 * @brief Busca a un empleado por ID
 *
 * @param this Lista donde estan los empleados registrados
 * @param idABuscar ID ingresado para realizar la busqueda
 * @param len Tamaño maximo de la busqueda
 * @return Retorna la posicion del empleado en el LinkedList o -1 si no fue encontrado
 */
int employee_searchID(LinkedList* this,int idABuscar,int len);
/**
 * @fn void save_modification(Employee*, Employee*)
 * @brief Guarda las modificaciones en el menu de modificar
 *
 * @param empleadoConDatos Empleado que contiene los datos a guardar
 * @param empleadoAGuardar Empleado al que se le insertaran los datos a guardar
 */
void save_modification (Employee* empleadoConDatos,Employee* empleadoAGuardar);
/**
 * @fn void employee_searchLastID(int*)
 * @brief Busca el ultimo ID ingresado via el archivo lastID.txt
 *
 * @param id Variable que obtendra el ultimo ID ingresado
 */
void employee_searchLastID(int* id);
/**
 * @fn void employee_saveLastID(char*)
 * @brief Funcion que guardara el ultimo ID ingresado
 *
 * @param lastID Variable que contiene el ID a guardar
 */
void employee_saveLastID(char* lastID);

/**
 * @fn int employee_orderID(void*, void*)
 * @brief Funcion que chequeara si las estructuras ingresadas tienen un ID mayor, menor o iguales a la otra
 *
 * @param employeeOne primer empleado a comparar
 * @param employeeTwo segundo empleado a comprarar
 * @return retornara 1 si el primer empleado tiene un ID mas alto, 0 si tienen el mismo ID o -1 si el primer empleado tiene un ID menor
 */
int employee_orderID (void* employeeOne, void* employeeTwo);
/**
 * @fn int employee_orderName(void*, void*)
 * @brief Funcion que chequeara si las estructuras ingresadas tienen un nombre mayor, menor o iguales a la otra
 *
 * @param employeeOne primer empleado a comparar
 * @param employeeTwo segundo empleado a comprarar
 * @return retornara 1 si el primer empleado tiene un nombre mas alto, 0 si tienen el mismo nombre o -1 si el primer empleado tiene un nombre menor
 */
int employee_orderName (void* employeeOne, void* employeeTwo);
/**
 * @fn int employee_orderHours(void*, void*)
 * @brief Funcion que chequeara si las estructuras ingresadas tienen un horario mayor, menor o iguales a la otra
 *
 * @param employeeOne primer empleado a comparar
 * @param employeeTwo segundo empleado a comprarar
 * @return retornara 1 si el primer empleado tiene un horario mas alto, 0 si tienen el mismo horario o -1 si el primer empleado tiene un horario menor
 */
int employee_orderHours (void* employeeOne, void* employeeTwo);
/**
 * @fn int employee_orderSalary(void*, void*)
 * @brief Funcion que chequeara si las estructuras ingresadas tienen un salario mayor, menor o iguales a la otra
 *
 * @param employeeOne primer empleado a comparar
 * @param employeeTwo segundo empleado a comprarar
 * @return retornara 1 si el primer empleado tiene un salario mas alto, 0 si tienen el mismo salario o -1 si el primer empleado tiene un salario menor
 */
int employee_orderSalary (void* employeeOne, void* employeeTwo);



#endif // employee_H_INCLUDED
