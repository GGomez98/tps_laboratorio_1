/*
 * ingDatos.c
 *
 *  Created on: Apr 9, 2022
 *      Author: gaston
 */
#include <stdio_ext.h>
#include <stdlib.h>

/*
 * \brief Solicita un numero al usuario
 * \param el mensaje que se quiere mostrar
 * \return El número ingresado
 *
 */
float ingresarValor(char mensaje[])
{
	float valor;

	printf("%s", mensaje);
	scanf("%f", &valor);

	return valor;
}

/*
 * \brief Solicita un numero el cual representa una arolinea y dependiendo del numero muestra un mensaje el  	cual muestra un mensaje dependiendo de la aerolinea seleccionada y pide un precio
 * \param el numero de  aerolinea seleccionada
 * \return El precio ingresado
 *
 */
float precioPorAerolinea(int aerolinea)
{
	float precio;

	switch(aerolinea){
		case 1:
			precio = ingresarValor("Ingrese el precio del vuelo en Aerolíneas: ");
			while(precio <=0){
			precio = ingresarValor("Precio incorrecto! Ingrese el precio por Aerolineas: ");
			}
		break;
		case 2:
			precio = ingresarValor("Ingrese el precio del vuelo en Latam: ");
			while(precio <=0){
			precio = ingresarValor("Precio incorrecto! Ingrese el precio por Latam: ");
			}
		break;
	}

	return precio;
}
