/*
 * inputs.c
 *
 *  Created on: 14 oct. 2021
 *      Author: Alan
 */

#include "inputs.h"


int enterInt (char* startMessage,char* errorMessage,int* number,int min,int max) {
    int checkvar;
    int returnal=-1;

	if (startMessage!=NULL && errorMessage!=NULL) {
		printf ("%s",startMessage);
		fflush (stdin);
		checkvar=scanf("%d",number);

		while (checkvar==0 || (*number<min || *number>max)) {
			printf ("%s",errorMessage);
			fflush (stdin);
			checkvar=scanf("%d",number);
		}
	}
	if (checkvar==1) {
		returnal=0;
	}

    return returnal;
}

int enterString (char* startMessage,char* errorMessage, char* string, int len) {
    int size;
    int i;
    int returnal=-1;

    if (startMessage!=NULL && errorMessage!=NULL) {
		printf ("%s",startMessage);
		fflush (stdin);
		fgets (string, len,stdin);
		size=strlen (string);
		string[size-1] = 32;

		for (i=0;i<size-1;i++) {
			while (isalpha(string[i])==0) {
				printf ("%s",errorMessage);
				fflush (stdin);
				fgets (string, len,stdin);
				size=strlen (string);
				string[size-1] = 32;

				i=0;
			}
		}
		returnal=0;
    }
	return returnal;
}

int enterFloat (char* startMessage,char* errorMessage,float* number,int min,int max) {
    float checkvar;
    int returnal;

	if (startMessage!=NULL && errorMessage!=NULL) {
		printf ("%s",startMessage);
		fflush (stdin);
		checkvar=scanf("%f",number);

		while (checkvar==0 || (*number<min || *number>max)) {
			printf ("%s",errorMessage);
			fflush (stdin);
			checkvar=scanf("%f",number);
		}
	}
	if (checkvar==1) {
		returnal=0;
	}

    return returnal;
}

