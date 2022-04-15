/*
 * calculos.c
 *
 *  Created on: Apr 9, 2022
 *      Author: gaston
 */

#include <stdio_ext.h>
#include <stdlib.h>

/*
 * \brief devuelve un precio dependiendo de la cuenta seleccionada
 * \param el precio del vuelo que se quiere calcular, la cantidad de km del vuelo y el calculo a realizar
 * \return El precio calculado
 *
 */
float calcularPrecio(float precioACalcular, int km, char calculo)
{
	float precioFinal;
	float descuento;
	float intereses;

		switch(calculo){
		case 'a':
			descuento = precioACalcular * 0.1;
			precioFinal = precioACalcular - descuento;
			break;
		case 'b':
			intereses = precioACalcular * 0.25;
			precioFinal = precioACalcular + intereses;
			break;
		case 'c':
			precioFinal = precioACalcular/4794272.97;
			break;
		case 'd':
			precioFinal = precioACalcular/km;
			break;
		}
	return precioFinal;
}

/*
 * \brief Toma 2 valores y calcula la diferencia entre ambos
 * \param Los valores entre los cuales se quiere hallar la diferencia
 * \return La diferencia entre los valores
 *
 */
float calcularDiferencia(float valor1, float valor2){
	float diferencia;

	if(valor1 > valor2){
		diferencia = valor1 - valor2;
	}
	else{
		diferencia = valor2 - valor1;
	}
	return diferencia;
}
