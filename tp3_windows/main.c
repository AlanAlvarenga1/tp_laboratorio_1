#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menu.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf (stdout,NULL);

    int option = 0;
    int flag=0; //0=SIN CARGAR 1=CARGADO 2=MODIFICADO 3=GUARDADO
    int confirmarSalida;

    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
    	mostrarMenu(&option);

        switch(option)
        {
            case 1:
            	if (flag==0) {
                    if (controller_loadFromText("data.csv", listaEmpleados)==1) {
                    	flag=1;
                    	printf ("\n\nLa lista ha sido cargada satisfactoriamente\n");
                    }
                    else {
                    	printf ("\n\nHa ocurrido un error. Intente nuevamente\n");
                    }
            	}
            	else {
            		printf ("\n\nERROR. Ya has cargado la lista de empleados\n");
            	}
            	systemPause("Presiones ENTER para continuar");
                break;
            case 2:
            	if (flag==0) {
                	if (controller_loadFromBinary("dataBinary.csv", listaEmpleados)==1) {
                		flag=1;
                    	printf ("\n\nLa lista ha sido cargada satisfactoriamente\n");
                    }
                    else {
                    	printf ("\n\nHa ocurrido un error. Intente nuevamente\n");
                    }
            	}
            	else {
            		printf ("\n\nERROR. Ya has cargado la lista de empleados\n");
            	}
            	systemPause("Presiones ENTER para continuar");
                break;
            case 3:
            	if (flag!=0) {
            		if (controller_addEmployee(listaEmpleados)==1) {
            			flag=2;
            			printf ("\n\nEl empleado se ha añadido con exito\n");
            		}
            	}
            	else {
            		printf ("\n\nERROR. No has cargado ninguna lista. Vuelva a intentar mas tarde\n");
            	}
            	systemPause("Presiones ENTER para continuar");
                break;
            case 4:
            	if (flag!=0) {
                	if (controller_editEmployee(listaEmpleados)==1) {
                		flag=2;
                	}
            	}
            	else {
            		printf ("\n\nERROR. No has cargado ninguna lista. Vuelva a intentar mas tarde\n");
            	}
            	systemPause("Presiones ENTER para continuar");
            	break;
            case 5:
            	if (flag!=0) {
            		if (controller_removeEmployee(listaEmpleados)==1) {
            			printf ("\n\nSe ha eliminado exitosamente el empleado\n");
                		flag=2;
            		}
            	}
            	else {
            		printf ("\n\nERROR. No has cargado ninguna lista. Vuelva a intentar mas tarde\n");
            	}
            	systemPause("Presiones ENTER para continuar");
            	break;
            case 6:
            	if (flag!=0) {
					controller_ListEmployee(listaEmpleados);
            	}
            	else {
            		printf ("\n\nERROR. No has cargado ninguna lista. Vuelva a intentar mas tarde\n");
            	}
            	systemPause("Presiones ENTER para continuar");
            	break;
            case 7:
            	if (flag!=0) {
            		controller_sortEmployee(listaEmpleados);
            		flag=2;
            	}
            	else {
            		printf ("\n\nERROR. No has cargado ninguna lista. Vuelva a intentar mas tarde\n");
            	}
            	systemPause("Presiones ENTER para continuar");
            	break;
            case 8:
            	if (flag!=0) {
                	if (controller_saveAsText("data.csv", listaEmpleados)==1) {
                		printf ("\n\nSe han guardado con exito los cambios");
                		flag=3;
                	}
                    else {
                    	printf ("\n\nHa ocurrido un error. Intente nuevamente\n");
                    }
            	}
            	else {
            		printf ("\n\nERROR. No has cargado ninguna lista. Vuelva a intentar mas tarde\n");
            	}
            	systemPause("Presiones ENTER para continuar");
                break;
            case 9:
            	if (flag!=0) {
                	if (controller_saveAsBinary("dataBinary.csv", listaEmpleados)==1) {
                		printf ("\n\nSe han guardado con exito los cambios");
                		flag=3;
                	}
                    else {
                    	printf ("\n\nHa ocurrido un error. Intente nuevamente\n");
                    }
            	}
            	else {
            		printf ("\n\nERROR. No has cargado ninguna lista. Vuelva a intentar mas tarde\n");
            	}
            	systemPause("Presiones ENTER para continuar");
                break;
            case 10:
            	if (flag==2) {
            		printf ("\n\nDeseas salir? Tienes cambios sin guardar");
            		tomarInt(&confirmarSalida,"\nSI=1 NO=0: ","ERROR. Has ingresado un caracter invalido. Intente nuevamente: ",0,1);

            		if (confirmarSalida==0) {
            			printf ("\n\nAbortando salida...\n");
            			option=0;
                    	systemPause("Presiones ENTER para continuar");
            		}
            		else {
                    	ll_deleteLinkedList(listaEmpleados);
                    	printf ("\n\nMuchas gracias por usar este programa!!");
            		}
            	}
            	else {
                	ll_deleteLinkedList(listaEmpleados);
                	printf ("\n\nMuchas gracias por usar este programa!!");
            	}
            	break;
        }
    }while(option != 10);
    return 0;
}

