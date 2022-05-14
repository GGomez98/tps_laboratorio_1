/*
 * ingDatos.c
 *
 *  Created on: Apr 23, 2022
 *      Author: gaston
 */

#include <stdio.h>
#include <stdlib.h>

/**
* \brief ingresa un numero
* \return el numero ingresado
*/
int ingresarOpcionNumero(void){
	int num;

	printf("Ingrese una opcion: ");
	scanf("%d", &num);

	return num;
}
