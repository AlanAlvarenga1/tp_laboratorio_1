/*
 * input.c
 *
 *  Created on: 11 oct. 2021
 *      Author: Alan
 */

#include "input.h"

int tomarInt(int* numeroADevolver, char* mensajeInicio, char* mensajeError, int min, int max) {
	int retorno = -1;
	char auxStrNumber[200];
	int stringTam;
	int check;

	if(numeroADevolver != NULL && mensajeInicio != NULL && mensajeError!=NULL && min < max) {
		printf ("%s",mensajeInicio);
		fflush (stdin);
		scanf("%[^\n]",auxStrNumber);

		stringTam=strlen(auxStrNumber);
		check= checkInt(auxStrNumber,min,max,stringTam);

		while (check!=0) {
			printf ("%s",mensajeError);
			fflush (stdin);
			scanf("%[^\n]",auxStrNumber);

			stringTam=strlen(auxStrNumber);
			check= checkInt(auxStrNumber,min,max,stringTam);
		}
		*numeroADevolver = atoi(auxStrNumber);
	}

	return retorno;
}

int tomarStringInt(char* numeroADevolver, char* mensajeInicio, char* mensajeError, int min, int max) {
	int retorno = -1;
	char auxStrNumber[200];
	int stringTam;
	int check;

	if(numeroADevolver != NULL && mensajeInicio != NULL && mensajeError!=NULL && min < max) {
		printf ("%s",mensajeInicio);
		fflush (stdin);
		scanf("%[^\n]",auxStrNumber);

		stringTam=strlen(auxStrNumber);
		check= checkInt(auxStrNumber,min,max,stringTam);

		while (check!=0) {
			printf ("%s",mensajeError);
			fflush (stdin);
			scanf("%[^\n]",auxStrNumber);

			stringTam=strlen(auxStrNumber);
			check= checkInt(auxStrNumber,min,max,stringTam);
		}
		strcpy(numeroADevolver,auxStrNumber);
	}

	return retorno;
}

int checkInt(char* stringNumbers,int min,int max,int len) {
	int retorno=0;
	int auxNumber;
	int i;

	for (i=0;i<len;i++) {
		if (isdigit(stringNumbers[i])==0 && stringNumbers[i]!='-') {
			retorno=-1;
			break;
		}
	}
	if (retorno!=-1) {
		auxNumber=atoi(stringNumbers);
		if (auxNumber<min || auxNumber>max) {
			retorno=-1;
		}
	}

	return retorno;
}

int tomarString (char* mensajeInicio,char* mensajeError, char* string, int tamChar) {
    char auxString[tamChar];
	int tam;
    int check;
    int retorno=-1;

    if (mensajeInicio!=NULL && mensajeError!=NULL) {
		printf ("%s",mensajeInicio);
		fflush (stdin);
		scanf("%[^\n]",auxString);
		tam=strlen(auxString);

		check=checkString(auxString,tam);

		while (check==-1) {
			printf ("%s",mensajeError);
			fflush (stdin);
			scanf("%[^\n]",auxString);
			tam=strlen(auxString);

			check=checkString(auxString,tam);
		}

		strcpy(string,auxString);
		retorno=0;
    }

    return retorno;
}

int checkString(char* string,int tamMax) {
	int i;
	int retorno=0;

	for (i=0;i<tamMax-1;i++) {
		if ((isalpha(string[i])==0) && string[i]!=32) {
			retorno=-1;
			break;
		}
	}

	return retorno;
}

int tomarFloat(float* numeroADevolver, char* mensajeInicio, char* mensajeError, int min, int max) {
	int retorno = -1;
	char auxStrNumber[200];
	float stringTam;
	int check;

	if(numeroADevolver != NULL && mensajeInicio != NULL && mensajeError!=NULL && min < max) {
		printf ("%s",mensajeInicio);
		fflush (stdin);
		scanf("%[^\n]",auxStrNumber);

		stringTam=strlen(auxStrNumber);
		check= checkFloat(auxStrNumber,min,max,stringTam);

		while (check!=0) {
			printf ("%s",mensajeError);
			fflush (stdin);
			scanf("%[^\n]",auxStrNumber);

			stringTam=strlen(auxStrNumber);
			check= checkFloat(auxStrNumber,min,max,stringTam);
		}

		*numeroADevolver = atof(auxStrNumber);
	}

	return retorno;
}

int checkFloat(char* stringNumbers,int min,int max,int len) {
	int retorno=0;
	float auxNumber;
	int i;

	for (i=0;i<len;i++) {
		if (isdigit(stringNumbers[i])==0 && stringNumbers[i]!=44 && stringNumbers[i]!=46 && stringNumbers[i]!='-') {
			retorno=-1;
			break;
		}
	}
	if (retorno!=-1) {
		auxNumber=atof(stringNumbers);
		if (auxNumber<min || auxNumber>max) {
			retorno=-1;
		}
	}

	return retorno;
}

int systemPause(char* message) {
	int ret=-1;
	if(message!=NULL)
	{
		fflush(stdin);
		printf("\n%s",message);
		getchar();
		ret=0;
	}
	return ret;
}
