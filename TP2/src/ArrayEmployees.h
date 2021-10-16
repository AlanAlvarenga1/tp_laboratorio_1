/*
 * funciones.h
 *
 *  Created on: 5 oct. 2021
 *      Author: Alan
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "inputs.h"
#include "menu.h"

#define maxEmployee 1000
#define maxChar 51

#define TRUE 1
#define FALSE 0

#define JANITOR 1
#define SELLER 2
#define SECRETARY 3
#define WATCHMAN 4
#define ACCOUNTANT 5
#define PRESIDENT 6

typedef struct {
	int id;
	char name[maxChar];
	char lastName[maxChar];
	float salary;
	int sector;
	int isEmpty;
}Employee;

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee* list, int len);
/**
 * @fn void hardCodeEmployee(Employee*, int*, int*, int)
 * @brief This function register the first 3 employees
 *
 * @param list List of employees
 * @param newestID This var allows the latest ID used
 * @param numberOfEmployee This var allows the sum of the registered employee
 * @param lenEmployee lenght max of employees that will be register on this function
 */
void hardCodeEmployee(Employee* list,int* newestID,int* numberOfEmployee,int lenEmployee);
/**
 * @fn int checkAndAddEmployee(Employee*, int*, int, int)
 * @brief This function starts the adding process
 *
 * @param list List of employees
 * @param newestID This var allows the latest ID used
 * @param lenEmployee Tam max of employees that will be register on this function
 * @param len lenght max of char
 * @return If it returns 0, the function worked OK, if it returns -1, there was an error or the function was aborted
 */
int checkAndAddEmployee (Employee* list,int* newestID,int lenEmployee,int len);
/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee* list of employees
* \param len int lenght max of employees
* \param id int id of the employee that will be registered
* \param name[] char name of the employee that will be registered
* \param lastName[] last name id of the employee that will be registered
* \param salary float salary of the employee that will be registered
* \param sector int sector of the employee that will be registered
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee* List of employees
* \param len int lenght max of employees
* \param id int id that wants to know its position
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len,int id);
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee* list of employees
* \param len int lenght max of employees
* \param id int id that wants to remove
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len, int id);
/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee* list of employees
* \param len int lenght max of employees
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* list, int len, int order);
/** \brief print the content of employees array
*
* \param list Employee* list of employees
* \param length int lenght max of employees
* \return int If it returns 0, the function worked OK, if it returns -1, there was an error or the function was aborted
*
*/
int printEmployees(Employee* list, int length);
/**
 * @fn void modifyEmployee(Employee*)
 * @brief This functions starts the process of modifying an employee
 *
 * @param list List of employees
 */
void modifyEmployee (Employee* list);
/**
 * @fn void salaryChecker(Employee*, int, int)
 * @brief It checks the salary of every employee and prints the average and the number of employees that has a higher salary than the average
 *
 * @param list list of employees
 * @param quantity Quantity of employees registered
 * @param max lenght max of employees
 */
void salaryChecker(Employee* list,int quantity,int max);

#endif /* ARRAYEMPLOYEES_H_ */
