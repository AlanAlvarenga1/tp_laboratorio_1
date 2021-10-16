/*
 * inputs.h
 *
 *  Created on: 14 oct. 2021
 *      Author: Alan
 */

#ifndef INPUTS_H_
#define INPUTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/**
 * @fn int enterInt(char*, char*, int*, int, int)
 * @brief This function allows to enter an int
 *
 * @param startMessage Message that will appear at the beginning
 * @param errorMessage Message that will appear when an error occurs
 * @param number number that will be returned
 * @param min min number that can be entered
 * @param max max number that can be entered
 * @return It returns 0 if the funcion worked ok, or -1 if it has an error
 */
int enterInt (char* startMessage,char* errorMessage,int* number,int min,int max);
/**
 * @fn int enterString(char*, char*, char*, int)
 * @brief This function allows to enter an string
 *
 * @param startMessage Message that will appear at the beginning
 * @param errorMessage Message that will appear when an error occurs
 * @param string String that will be returned
 * @param len lenght max of the string
 * @return It returns 0 if the funcion worked ok, or -1 if it has an error
 */
int enterString (char* startMessage,char* errorMessage, char* string, int len);
/**
 * @fn int enterFloat(char*, char*, float*, int, int)
 * @brief This function allows to enter an float
 *
 * @param startMessage Message that will appear at the beginning
 * @param errorMessage Message that will appear when an error occurs
 * @param number number that will be returned
 * @param min min number that can be entered
 * @param max max number that can be entered
 * @return It returns 0 if the funcion worked ok, or -1 if it has an error
 */
int enterFloat (char* startMessage,char* errorMessage,float* number,int min,int max);



#endif /* INPUTS_H_ */
