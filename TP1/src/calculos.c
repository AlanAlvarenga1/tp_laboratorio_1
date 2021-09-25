/*
 * calculos.c
 *
 *  Created on: 21 sep. 2021
 *      Author: Alan
 */

#include "calculos.h"

float pedirNumero (char *mensaje,char *mensajeError, int *flag,int *flagCalculado) {
	float numero; //Variable utilizada para retornar el numero ingresado por el usuario
	float chequeoTipoCaracter; //Variable utilizada para chequear que no se ingresen tipos de caracteres que no sean numeros float

	printf ("%s",mensaje);
	fflush (stdin);
	chequeoTipoCaracter= scanf ("%f",&numero);

	while (chequeoTipoCaracter==0) {
		printf ("%s\n",mensajeError);
		fflush (stdin);
		chequeoTipoCaracter= scanf ("%f",&numero);
	}

	*flag=1;
	*flagCalculado=0;

	return numero;
}

void calcularNumeros(char *mensajeInicio, char *mensajeError,char *mensajeCorrecto, float num1, float num2, float *suma, float *resta, float *multiplicacion, float *division, int *factorial1, int *factorial2, int flag1, int flag2, int *flag3) {
	if (flag1==1 && flag2==1) {
		printf ("%s \n",mensajeInicio);

		*suma= sumar(num1,num2);
		*resta= restar(num1,num2);
		*multiplicacion= multiplicar(num1,num2);
		*division= dividir(num1,num2);
		*factorial1=factorizar(num1);
		*factorial2=factorizar(num2);

		*flag3=1;
	}
	else {
		printf ("%s",mensajeError);
	}
}

float sumar (float num1,float num2) {
	float resultado; //Variable utilizada para retornar el resultado de la suma

	resultado=num1+num2;

	return resultado;
}


float restar (float num1,float num2) {
	float resultado; //Variable utilizada para retornar el resultado de la resta

	resultado=num1-num2;

	return resultado;
}


float multiplicar (float num1,float num2) {
	float resultado; //Variable utilizada para retornar el resultado de la multiplicacion

	resultado=num1*num2;

	return resultado;
}


float dividir (float num1,float num2) {
	float resultado; //Variable utilizada para retornar el resultado de la division

	resultado=num1/num2;

	return resultado;
}

int factorizar (float num) {
	int resultado; //Variable utilizada para retornar el resultado de la factorizacion
	int aux; //Variable que se iguala a num para luego utilizarse para verificar si el numero ingresado no contiene decimales
	aux=num;

	if ((aux-num)!=0 || num<0) {
		return 0;
	}
	else {
		if (num==0) {
			resultado=1;
		}
		else {
			resultado= num*factorizar(num-1);
		}
		return resultado;
	}
}
