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
    char auxString[maxChar];
	int size;
    int returnal=-1;

    if (startMessage!=NULL && errorMessage!=NULL) {

		printf ("%s",startMessage);
		fflush (stdin);
		scanf("%[^\n]",auxString);
		size=strlen(auxString);

		checkString(auxString,size);

		while (checkString(auxString,size)==-1) {
			printf ("%s",errorMessage);
			fflush (stdin);
			scanf("%[^\n]",auxString);
			size=strlen(auxString);

			checkString(auxString,size);
		}
		strcpy(string,auxString);
		returnal=0;
    }
	return returnal;
}
int checkString(char* string,int len) {
	int i;
	int returnal=-1;

	if (len>1) {
		for (i=0;i<len-1;i++) {
			if ((isalpha(string[i])!=0) || string[i]==32) {
				returnal=0;
				break;
			}
		}
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

