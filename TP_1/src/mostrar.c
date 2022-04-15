/*
 * mostrar.c
 *
 *  Created on: Apr 10, 2022
 *      Author: gaston
 */

#include <stdio_ext.h>
#include <stdlib.h>

/*
 * \brief muestra los datos de precio
 * \param precios con debito, credito, bitcoin y por km
 *
 */
void mostrarTodo(float debito, float credito, float btc, float unitario){
	printf("a) Precio con tarjeta de debito: $%.2f\n", debito);
	printf("b) Precio con tarjeta de credito: $%.2f\n", credito);
	printf("c) Precio pagando con bitcoin: %.7f BTC\n", btc);
	printf("d) Mostrar precio unitario: $%.2f\n\n", unitario);
}
