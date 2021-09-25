/*
Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
	1. Ingresar 1er operando (A=x)
	2. Ingresar 2do operando (B=y)
	3. Calcular todas las operaciones
		a) Calcular la suma (A+B)
		b) Calcular la resta (A-B)
		c) Calcular la division (A/B)
		d) Calcular la multiplicacion (A*B)
		e) Calcular el factorial (A!)
	4. Informar resultados
		a) “El resultado de A+B es: r”
		b) “El resultado de A-B es: r”
		c) “El resultado de A/B es: r” o “No es posible dividir por cero”
		d) “El resultado de A*B es: r”
		e) “El factorial de A es: r1 y El factorial de B es: r2”
	5. Salir

• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.
• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
• Deberán contemplarse los casos de error (división por cero, etc)
• Documentar todas las funciones
 */

#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "calculos.h"

int main(void) {
	setbuf (stdout,NULL);

	int opcion=0; //Inicializado en cero. Toma la opcion seleccionada por el usuario
	int flagPaso1=0; // 0=Sin activar 1=Activado
	int flagPaso2=0; // 0=Sin activar 1=Activado
	int flagResultados=0; // 0=Sin activar 1=Calculado 2=Se mostró
	float numero1; //Variable que almacena el primer numero
	float numero2; //Variable que almacena el segundo numero
	float rSuma; //Variable que almacena la suma de los numeros
	float rResta; //Variable que almacena la division de los numeros
	float rMultiplicacion; //Variable que almacena la multiplicacion de los numeros
	float rDivision; //Variable que almacena la division de los numeros
	int rFactorialA; //Variable que almacena el factorial del primer numero
	int rFactorialB; //Variable que almacena el factorial del segundo numero

	while (opcion!=5) {
		opcion=iniciarMenu (numero1,numero2,flagPaso1,flagPaso2,flagResultados,rSuma,rResta,rMultiplicacion,rDivision,rFactorialA,rFactorialB);
		switch (opcion) {
			case 1:
				numero1=pedirNumero("Ingrese el numero 'x': ","ERROR. No se ha ingresado un caracter valido. Intentelo nuevamente: ",&flagPaso1,&flagResultados);
			break;

			case 2:
				numero2=pedirNumero("Ingrese el numero 'y': ","ERROR. No se ha ingresado un caracter valido. Intentelo nuevamente: ",&flagPaso2,&flagResultados);
			break;

			case 3:
				calcularNumeros("Calculando....\n","ERROR. Has olvidado ingresar un numero \n\n","Se ha realizado el calculo con exito!!",numero1,numero2,&rSuma,&rResta,&rMultiplicacion,&rDivision,&rFactorialA,&rFactorialB,flagPaso1,flagPaso2,&flagResultados);
			break;

			case 4:
				if (flagResultados==1) {
					flagResultados=2;
				}
				else {
					printf ("ERROR. No has calculado las operaciones\n\n");
				}
			break;
		}
	}
	printf ("Gracias por haber usado esta super calculadora!");
}
