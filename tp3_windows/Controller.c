#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "input.h"
#include "menu.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee) {
	int retorno=0;
	FILE* pFile;

	if (path!=NULL && pArrayListEmployee!=NULL) {
		pFile= fopen(path,"r");

		if (parser_EmployeeFromText(pFile , pArrayListEmployee)==1) {
			retorno=1;
		}
		fclose(pFile);
	}

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee) {
	int retorno=0;
	FILE* pFile;

	if (path!=NULL && pArrayListEmployee!=NULL) {
		pFile= fopen(path,"rb");

		if (parser_EmployeeFromBinary(pFile , pArrayListEmployee)==1) {
			retorno=1;
		}
		fclose(pFile);
	}
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee) {
	int retorno=0;
	Employee* nuevoEmpleado;
	int intID;
	char id[10];
	char nombre[maxChar];
	char horasTrabajadas[10];
	char sueldo[10];
	int confirmar=0;

	if (pArrayListEmployee!=NULL) {
		intID=employee_searchLastID();

		while (confirmar==0) {
			itoa(intID+1,id,10);
			tomarString ("\n\nIngrese el nombre del empleado: ","ERROR. Has ingresado un caracter invalido. Intente nuevamente: ", nombre, maxChar);
			tomarStringInt(horasTrabajadas,"Ingrese la cantidad de horas trabajadas: ","ERROR. Has ingresado un caracter invalido. Intente nuevamente: ",0,168);
			tomarStringInt(sueldo,"Ingrese el sueldo del empleado: ","ERROR. Has ingresado un caracter invalido. Intente nuevamente: ",1000,100000);

			printf ("------------------------------------------------------------------------------------------------------------------------------\n");
			printf ("%-10s %-25s %-25s %s","ID","Nombre","Horas laborales","Sueldo");
			printf ("\n------------------------------------------------------------------------------------------------------------------------------\n");
			printf ("%-10s %-25s %-25s %s\n",id,nombre,horasTrabajadas,sueldo);
			printf ("------------------------------------------------------------------------------------------------------------------------------\n\n");
			printf ("Desea cargar este empleado?\n");
			tomarInt(&confirmar,"SI=1 NO=0 SALIR=-1: ","ERROR. Has ingresado un caracter invalido. Intente nuevamente: ",-1,1);

			switch (confirmar) {
				case 1:
					nuevoEmpleado=employee_new();
					nuevoEmpleado=employee_newParametros(id,nombre,horasTrabajadas,sueldo);
					ll_add(pArrayListEmployee,nuevoEmpleado);
					employee_saveLastID(id);
					retorno=1;
					break;
				case 0:
					printf ("\n\nReiniciando.....\n");
					break;
				case -1:
					printf ("\n\nSaliendo.....\n");
					break;
			}
		}
	}

    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee) {
	int retorno=0;
	int opcion=0;
	int flag=-1; //-1 SIN CARGA		0 CARGADO		1 CON CAMBIOS		2 GUARDADO
	int seguir;
	int posicionEmployee;

	int id;
	char nuevoNombre[maxChar];
	int nuevasHoras;
	int nuevoSueldo;

	char nombreAModificar[maxChar];
	int horasAModificar;
	int sueldoAModificar;

	int lastID=employee_searchLastID();
	Employee* empleadoAModificar;
	Employee aux;

	if (pArrayListEmployee!=NULL) {
		do {
			if (flag!=-1) {
				printf ("------------------------------------------------------------------------------------------------------------------------------\n");
				printf ("%-10s %-25s %-25s %s","ID","Nombre","Horas laborales","Sueldo");
				printf ("\n----------------------------------------EMPLEADO A MODIFICAR----------------------------------------------\n");
				printUnEmpleado (empleadoAModificar);
				if (flag==1) {
					printf ("-----------------------------------EMPLEADO CON MODIFICACIONES--------------------------------------------\n");
					printUnEmpleado (&aux);
				}
				printf ("------------------------------------------------------------------------------------------------------------------------------\n\n");
			}

			employee_getNombre(empleadoAModificar,nombreAModificar);
			employee_getHorasTrabajadas(empleadoAModificar,&horasAModificar);
			employee_getSueldo(empleadoAModificar,&sueldoAModificar);

			subMenuModificacionEmpleado(&opcion);

			switch (opcion) {
			case 1:
				seguir=0;

				while (seguir==0) {
					tomarInt(&id,"Ingrese el ID del empleado que desea buscar: ","ERROR. Has ingresado un caracter incorrecto. Intente nuevamente: ",1,lastID);
					posicionEmployee=employee_searchID(pArrayListEmployee,id,lastID);

					empleadoAModificar=(Employee*) ll_get(pArrayListEmployee,posicionEmployee);

					if (empleadoAModificar!=NULL) {
						printf ("------------------------------------------------------------------------------------------------------------------------------\n");
						printf ("%-10s %-25s %-25s %s","ID","Nombre","Horas laborales","Sueldo");
						printf ("\n------------------------------------------------------------------------------------------------------------------------------\n");
						printUnEmpleado (empleadoAModificar);
						printf ("------------------------------------------------------------------------------------------------------------------------------\n\n");
						tomarInt(&seguir,"¿Desea modificar este empleado?: SI=1 NO=0: ","ERROR. Has ingresado una opcion invalida. Intente nuevamente: ",0,1);

						if (seguir==1) {
							printf ("\n\nSe ha cargado con exito el empleado!!\n\n");
							aux=*empleadoAModificar;
							flag=0;
						}
						else {
							printf("\n\nReiniciando.....\n\n");
						}
					}
					else {
						tomarInt(&seguir,"No se ha encontrado al empleado, ¿Desea volver a intentarlo?: SI=0 NO=1: ","ERROR. Has ingresado una opcion invalida. Intente nuevamente: ",0,1);
						if (seguir==1) {
							printf("\n\nSaliendo.......\n");
						}
					}
				}
            	systemPause("Presiones ENTER para continuar");
				break;

			case 2:
				if (flag!=-1) {
					seguir=0;

					while (seguir==0) {
						tomarString ("Ingrese el nuevo nombre: ","ERROR. Has ingresado un caracter invalido. Intente nuevamente: ", nuevoNombre, maxChar);
						printf ("Desea cambiar el nombre de %s a %s?",nombreAModificar, nuevoNombre);

						tomarInt(&seguir,"\nSI=1 NO=0 SALIR=-1: ","ERROR. Has ingresado una opcion invalida. Intente nuevamente: ",-1,1);
						if (seguir==1) {
							if (employee_setNombre(&aux,nuevoNombre)==1) {
								printf ("\n\nNombre cambiado con exito!\n");
								flag=1;
							}
							else {
								printf ("Ops, ha ocurrido un error, chequee el codigo");
							}
						}
						else if (seguir==0 ){
							printf("\n\nReiniciando.....\n\n");
						}
						else {
							printf ("\n\nSaliendo.....\n");
						}
					}
				}
				else {
					printf ("ERROR. No has ingresado ningun empleado. Utilice la primer opcion e intente nuevamente\n");
				}
            	systemPause("Presiones ENTER para continuar");
				break;

			case 3:
				if (flag!=-1) {
					seguir=0;

					while (seguir==0) {
						tomarInt (&nuevasHoras,"Ingrese el nuevo horario: ","ERROR. Has ingresado un caracter invalido. Intente nuevamente: ", 0, 168);
						printf ("Desea cambiar las horas de %d a %d?",horasAModificar, nuevasHoras);

						tomarInt(&seguir,"\nSI=1 NO=0 SALIR=-1: ","ERROR. Has ingresado una opcion invalida. Intente nuevamente: ",-1,1);
						if (seguir==1) {
							if (employee_setHorasTrabajadas(&aux,nuevasHoras)==1) {
								printf ("\n\nHoras cambiadas con exito!\n");
								flag=1;
							}
							else {
								printf ("Ops, ha ocurrido un error, chequee el codigo\n");
							}
						}
						else if (seguir==0) {
							printf("\n\nReiniciando.....\n\n");
						}
						else {
							printf ("\n\nSaliendo....\n");
						}
					}
				}
				else {
					printf ("ERROR. No has ingresado ningun empleado. Utilice la primer opcion e intente nuevamente\n");
				}
            	systemPause("Presiones ENTER para continuar");
				break;

			case 4:
				if (flag!=-1) {
					seguir=0;

					while (seguir==0) {
						tomarInt (&nuevoSueldo,"\nIngrese el nuevo sueldo: ","\nERROR. Has ingresado un caracter invalido. Intente nuevamente: ", 1000, 100000);
						printf ("Desea cambiar el sueldo de %d a %d?",sueldoAModificar, nuevoSueldo);

						tomarInt(&seguir,"\nSI=1 NO=0 SALIR=-1: ","\nERROR. Has ingresado una opcion invalida. Intente nuevamente: ",-1,1);
						if (seguir==1) {
							if (employee_setSueldo(&aux,nuevoSueldo)==1) {
								printf ("\n\nSueldo cambiado con exito!\n");
								flag=1;
							}
							else {
								printf ("Ops, ha ocurrido un error, chequee el codigo\n");
							}
						}
						else if (seguir==0) {
							printf("\n\nReiniciando.....\n\n");
						}
						else {
							printf("\n\nSaliendo.....\n");
						}
					}
				}
				else {
					printf ("ERROR. No has ingresado ningun empleado. Utilice la primer opcion e intente nuevamente\n");
				}
            	systemPause("Presiones ENTER para continuar");
				break;

			case 5:
				if (flag!=-1) {
					seguir=0;

					printf ("\n\nDesea guardar los cambios hechos hasta el momento?");
					tomarInt(&seguir,"\nSI=1 NO=0: ","ERROR. Has ingresado una opcion invalida. Intente nuevamente: ",0,1);

					if (seguir==1) {
						save_modification(&aux,empleadoAModificar);
						flag=2;
						retorno=1;
						printf ("\n\nCambios hechos con exito!\n\n");
					}
					else {
						printf ("\n\nCancelando guardado....\n");
					}
				}
				else if (flag==0) {
					printf ("ERROR. No tienes cambios por guardar.\n");
				}
				else {
					printf ("ERROR. No has ingresado ningun empleado. Utilice la primer opcion e intente nuevamente\n");
				}

				systemPause("Presiones ENTER para continuar");
				break;
			case 6:
				if (flag==1) {
					seguir=0;

					printf ("¿Deseas salir? Tienes cambios sin guardar");
					tomarInt(&seguir,"\nSI=1 NO=0: ","\nERROR. Has ingresado una opcion invalida. Intente nuevamente: ",0,1);

					if (seguir==0) {
						printf ("\n\nAbortando salida\n");
						opcion=0;
					}
					else {
						printf ("\n\nSaliendo.....\n");
					}
				}
				else {
					printf ("\n\nSaliendo.....\n");
				}
				break;
			}
		}while (opcion!=6);

	}

	return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee) {
	int retorno=0;
	int id;
	int lastID=employee_searchLastID();
	int confirmacion=0; //-1 SALIR	0 NO	1 SI
	int posicionEmployee;
	Employee* empleadoAEliminar;

	if (pArrayListEmployee!=NULL) {
		while (confirmacion==0) {
			tomarInt(&id,"Ingrese el ID del empleado que desea buscar: ","ERROR. Has ingresado un caracter incorrecto. Intente nuevamente: ",1,lastID);
			posicionEmployee=employee_searchID(pArrayListEmployee,id,lastID);

			if (posicionEmployee!=-1) {
				empleadoAEliminar=(Employee*) ll_get(pArrayListEmployee,posicionEmployee);

				printf ("------------------------------------------------------------------------------------------------------------------------------\n");
				printf ("%-10s %-25s %-25s %s","ID","Nombre","Horas laborales","Sueldo");
				printf ("\n------------------------------------------------------------------------------------------------------------------------------\n");
				printUnEmpleado (empleadoAEliminar);
				printf ("------------------------------------------------------------------------------------------------------------------------------\n\n");
				printf ("Desea eliminar este empleado?\n");

				tomarInt(&confirmacion,"1=SI 0=NO -1=SALIR: ","ERROR. Has ingresado un ID incorrecto, vuelva a intentarlo: ",1,lastID);
				if (confirmacion==1) {
					ll_remove(pArrayListEmployee,posicionEmployee);
					retorno=1;
				}
				else if (confirmacion==0) {
					printf ("\n\nReiniciando....\n");
				}
				else {
					printf ("\n\nSaliendo del programa....\n");
				}
			}
			else {
				printf ("ERROR. Has ingresado un ID inexistente. Desea volver a intentarlo?\n");
				tomarInt(&confirmacion,"0=SI 1=NO: ","ERROR. Has ingresado un ID incorrecto, vuelva a intentarlo: ",1,lastID);
				if (confirmacion==1) {
					printf ("\n\nReiniciando....\n");
				}
				else {
					printf("\n\nSaliendo del programa....\n");
				}
			}
		}
	}
	return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee) {
    int llTam=ll_len(pArrayListEmployee);
	int i;
	Employee* aux;

	if (pArrayListEmployee!=NULL) {

		printf ("------------------------------------------------------------------------------------------------------------------------------\n");
		printf ("%-10s %-25s %-25s %s","ID","Nombre","Horas laborales","Sueldo");
		printf ("\n------------------------------------------------------------------------------------------------------------------------------\n");
		for (i=0;i<llTam;i++) {
    		aux=(Employee*)ll_get(pArrayListEmployee,i);
    		printf ("%-10d %-25s %-25d %d\n",aux->id,aux->nombre,aux->horasTrabajadas,aux->sueldo);
		}
		printf ("------------------------------------------------------------------------------------------------------------------------------\n\n");
	}


	return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee) {
	int retorno=0;
	int opcion=0;
	int (*pFunc) (void*,void*);
	int tipoDeOrden;

	if (pArrayListEmployee!=NULL) {
		while (opcion!=5) {
			subMenuOrdenamiento(&opcion);

			switch (opcion) {
				case 1:
					pFunc=&employee_orderByID;
					tomarInt(&tipoDeOrden,"\n\nDesea ordenarlo de manera ascendente o descendente? 1=ASCENDENTE 0=DESCENDENTE: ","\nERROR. Has ingresado un caracter invalido. Intente nuevamente: ",0,1);
					if (ll_sort(pArrayListEmployee,pFunc,tipoDeOrden)==0) {
						printf("\nSe ha ordenado la lista con exito!\n");
						retorno=1;
					}
	            	systemPause("Presiones ENTER para continuar");
					break;
				case 2:
					pFunc=&employee_orderByName;
					tomarInt(&tipoDeOrden,"\n\nDesea ordenarlo de manera ascendente o descendente? 1=ASCENDENTE 0=DESCENDENTE: ","\nERROR. Has ingresado un caracter invalido. Intente nuevamente: ",0,1);
					if (ll_sort(pArrayListEmployee,pFunc,tipoDeOrden)==0) {
						printf("\nSe ha ordenado la lista con exito!\n");
						retorno=1;
					}
	            	systemPause("Presiones ENTER para continuar");
					break;
				case 3:
					pFunc=&employee_orderByHours;
					tomarInt(&tipoDeOrden,"\n\nDesea ordenarlo de manera ascendente o descendente? 1=ASCENDENTE 0=DESCENDENTE: ","\nERROR. Has ingresado un caracter invalido. Intente nuevamente: ",0,1);
					if (ll_sort(pArrayListEmployee,pFunc,tipoDeOrden)==0) {
						printf("\nSe ha ordenado la lista con exito!\n");
						retorno=1;
					}
	            	systemPause("Presiones ENTER para continuar");
					break;
				case 4:
					pFunc=&employee_orderBySalary;
					tomarInt(&tipoDeOrden,"\n\nDesea ordenarlo de manera ascendente o descendente? 1=ASCENDENTE 0=DESCENDENTE: ","\nERROR. Has ingresado un caracter invalido. Intente nuevamente: ",0,1);
					if (ll_sort(pArrayListEmployee,pFunc,tipoDeOrden)==0) {
						printf("\nSe ha ordenado la lista con exito!\n");
						retorno=1;
					}
	            	systemPause("Presiones ENTER para continuar");
					break;
				case 5:
					printf("\n\nSaliendo......\n");
					break;
			}
		}
	}
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee) {
    int retorno=0;
    FILE* pFile;
    int llTam=ll_len(pArrayListEmployee);
    Employee* aux;

	int id;
	char nombre[51];
	int horasTrabajadas;
	int sueldo;

    if (path!=NULL && pArrayListEmployee!=NULL) {
    	pFile=fopen(path,"w");

    	fprintf (pFile,"%s\n","id,nombre,horasTrabajadas,sueldo");

    	for (int i=0;i<llTam;i++) {
    		aux=(Employee*)ll_get(pArrayListEmployee,i);

    		employee_getId(aux,&id);
    		employee_getNombre(aux,nombre);
    		employee_getHorasTrabajadas(aux,&horasTrabajadas);
    		employee_getSueldo(aux,&sueldo);

        	fprintf (pFile,"%d,%s,%d,%d\n",id,nombre,horasTrabajadas,sueldo);
    	}
    	fclose(pFile);
    	retorno=1;
   }

	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee) {
    int retorno=0;
    FILE* pFile;
    int llTam=ll_len(pArrayListEmployee);
    Employee* aux;

    if (path!=NULL && pArrayListEmployee!=NULL) {
    	pFile=fopen(path,"wb");

    	for (int i=0;i<llTam;i++) {
    		aux=(Employee*)ll_get(pArrayListEmployee,i);
    		fwrite(aux,sizeof(Employee),1,pFile);
    	}
    	fclose(pFile);
    	retorno=1;
    }

	return retorno;
}

