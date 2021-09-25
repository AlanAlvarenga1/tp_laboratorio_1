/*
 * funciones.c
 *
 *  Created on: 15 sep. 2021
 *      Author: Alan
 */

#include "menu.h"

int iniciarMenu (float num1,float num2,int primerFlag, int segundoFlag, int flagCalculacion,float suma,float resta,float multiplicacion,float division,int factorial1,int factorial2) {
	int opcion; //Variable que toma la opcion seleccionada por el usuario

	mostrarOpcion1 (num1,primerFlag);
	mostrarOpcion2 (num2,segundoFlag);
	mostrarOpcion3 (num1,num2);
	mostrarOpcion4 (num1,num2,flagCalculacion,suma,resta,multiplicacion,division,factorial1,factorial2);
	opcion= mostrarOpcion5YSeleccion ();

	return opcion;
}

void mostrarOpcion1 (float num1,int primerFlag) {
	if (primerFlag==0) {
		printf ("\n---------------MENU---------------\n"
				"1) Ingresar el primer operando (A=x)\n");
	}
	else {
		printf ("\n---------------MENU---------------\n"
				"1) Ingresar el primer operando (A=%.2f)\n", num1);
	}
}

void mostrarOpcion2 (float num2,int segundoFlag) {
	if (segundoFlag==0) {
		printf ("2) Ingresar el segundo operando (A=x)\n");
	}
	else {
		printf ("2) Ingresar el segundo operando (A=%.2f)\n", num2);
	}
}

void mostrarOpcion3 (float num1,float num2) {

		printf ("3) Calcular todas las operaciones\n");
		printf ("	a) Calcular la suma (%.2f + %.2f)\n",num1,num2);
		printf ("	b) Calcular la resta (%.2f - %.2f)\n",num1,num2);
		printf ("	c) Calcular la division (%.2f / %.2f)\n",num1,num2);
		printf ("	d) Calcular la multiplicacion (%.2f * %.2f)\n",num1,num2);
		printf ("	e) Calcular el factorial A (%.2f!)\n",num1);
		printf ("	f) Calcular el factorial B (%.2f!)\n",num2);
}

void mostrarOpcion4 (float num1,float num2, int flagCalculacion,float suma,float resta,float multiplicacion,float division,int factorial1,int factorial2) {
	int auxFactorial1; //Variable que se iguala a num1 para luego utilizarse para verificar si el numero ingresado no contiene decimales
	int auxFactorial2; //Variable que se iguala a num2 para luego utilizarse para verificar si el numero ingresado no contiene decimales
	auxFactorial1=num1;
	auxFactorial2=num2;

	if (flagCalculacion==0) {
			printf ("4) Informar resultados\n");
			printf ("	a) El resultado de %.2f + %.2f es: -Aun no se calculo-\n",num1,num2);
			printf ("	b) El resultado de %.2f - %.2f es: -Aun no se calculo-\n",num1,num2);
			printf ("	c) El resultado de %.2f / %.2f es: -Aun no se calculo-\n",num1,num2);
			printf ("	d) El resultado de %.2f * %.2f es: -Aun no se calculo-\n",num1,num2);
			printf ("	e) El factorial de %.2f es: -Aun no se calculo-\n",num1);
			printf ("	f) El factorial de %.2f es: -Aun no se calculo-\n",num2);
		}
		else if (flagCalculacion==1) {
			printf ("4) Informar resultados\n");
			printf ("	a) El resultado de %.2f + %.2f es: -Calculado-\n",num1,num2);
			printf ("	b) El resultado de %.2f - %.2f es: -Calculado-\n",num1,num2);
			printf ("	c) El resultado de %.2f / %.2f es: -Calculado-\n",num1,num2);
			printf ("	d) El resultado de %.2f * %.2f es: -Calculado-\n",num1,num2);
			printf ("	e) El factorial de %.2f es: -Calculado-\n",num1);
			printf ("	f) El factorial de %.2f es: -Calculado-\n",num2);
		}
		else {
			printf ("4) Informar resultados\n");
			printf ("	a) El resultado de %.2f + %.2f es: %.2f\n",num1,num2,suma);
			printf ("	b) El resultado de %.2f - %.2f es: %.2f\n",num1,num2,resta);

			if (num2==0) {
				printf ("	c) ERROR. Es imposible dividir por cero\n");
			}
			else {
				printf ("	c) El resultado de %.2f / %.2f es: %.2f\n",num1,num2,division);
			}

			printf ("	d) El resultado de %.2f * %.2f es: %.2f\n",num1,num2,multiplicacion);

			if (num1<0) {
				printf ("	e) ERROR. Es imposible factorizar un numero negativo\n");
			}
			else if ((auxFactorial1-num1)!=0) {
				printf ("	e) ERROR. Es imposible factorizar un numero con decimales\n");
			}
			else {
				printf ("	e) El factorial de %.2f es: %d\n",num1,factorial1);
			}


			if (num2<0) {
				printf ("	f) ERROR. Es imposible factorizar un numero negativo\n");
			}
			else if ((auxFactorial2-num2)!=0) {
				printf ("	f) ERROR. Es imposible factorizar un numero con decimales\n");
			}
			else {
				printf ("	f) El factorial de %.2f es: %d\n",num2,factorial2);
			}
		}
}

int mostrarOpcion5YSeleccion (void) {
	int chequeoTipoCaracter; //Variable utilizada para chequear que no se ingresen tipos de caracteres que no sean numeros int
	int seleccion; //Variable utilizada para retornar la opcion seleccionada por el usuario

	printf("5) Salir\n\n");
	printf ("Ingrese la opcion: ");
	fflush (stdin);
	chequeoTipoCaracter=scanf ("%d",&seleccion);

	while ((seleccion<1 || seleccion>5)  || chequeoTipoCaracter==0) {
		printf ("ERROR. Ingrese una opcion valida. 1-5: ");
		fflush (stdin);
		chequeoTipoCaracter=scanf ("%d",&seleccion);
	}

	return seleccion;
}
