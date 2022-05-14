/*
 ============================================================================
 Name        : TP_2.c
 Author      : Gastón Gómez
 Description : Una aerolínea requiere un sistema para administrar los pasajeros de cada vuelo.
 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "mostrar.h"
#include "ingDatos.h"
#include "ArrayPassenger.h"
#define MAX 2000

int main(void) {
	int opcion;
	ePassenger arrayPasajeros[MAX];
	eDato datosDePasajeros[5] = {{1, "Nombre"}, {2, "Apellido"}, {3, "Precio"}, {4, "Tipo de pasajero"}, {5, "Codigo de vuelo"}};
	eTipoPasajero tiposDePasajero[2] = {{1, "Economic"}, {2, "Premium"}};
	int initId;
	int sinPasajeros;
	int contador;
	char confirm;

	initId = 1;
	contador = 0;

	sinPasajeros = initPassengers(arrayPasajeros, MAX);

	do{
		mostrarMenu();
		opcion = ingresarOpcionNumero();

		switch(opcion){
		case 1:
			sinPasajeros = addPassengers(arrayPasajeros, MAX, initId, tiposDePasajero);
			initId++;
			contador++;
			printPassengers(arrayPasajeros, MAX, tiposDePasajero);
		break;
		case 2:
			if(sinPasajeros == 1){
				printf("No hay pasajeros!\n");
			}
			else{
				modPassengers(arrayPasajeros, MAX, datosDePasajeros, tiposDePasajero);
			}
		break;
		case 3:
			if(sinPasajeros == 1){
				printf("No hay pasajeros!\n");
			}
			else{
				removePassengers(arrayPasajeros, MAX, tiposDePasajero);
				contador--;
				if(contador == 0){
					sinPasajeros = 1;
				}
			}
		break;
		case 4:
			if(sinPasajeros == 1){
				printf("No hay pasajeros!\n");
			}
			else{
				informar(arrayPasajeros, MAX, contador, tiposDePasajero);
			}
		break;
		case 5:
			if(sinPasajeros == 0){
				printf("Ya hay pasajeros cargados!\n");
			}
			else{
				sinPasajeros = cargaForzada(arrayPasajeros);
				printPassengers(arrayPasajeros, MAX, tiposDePasajero);
				initId = 6;
				contador = 5;
			}
		break;
		case 6:
			printf("Seguro que desea salir[s/n]?");
			__fpurge(stdin);
			scanf("%c", &confirm);
		break;
		default:
			printf("No existe esa opcion!\n");
		break;
		}
	}while(confirm!='s');

	return 0;
}
