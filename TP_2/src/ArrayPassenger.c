/*
 * ArrayPassenger.c
 *
 *  Created on: Apr 23, 2022
 *      Author: gaston
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassenger.h"

/**
* \brief Calcula el precio total de todos los pasajes activos
* \param el array con los pasajeros
* \param el tamaño del array de pasajeros
* \return el precio total
*
*/
float calcularTotalPasajes(ePassenger list[], int len){
	float total;
	int i;

	total = 0;

	for(i=0; i<len; i++){
		if(list[i].isEmpty==0){
			total+=list[i].price;
		}
	}

	return total;
}

/**
* \brief Calcula el precio promedio de todos los pasajes activos
* \param el array con los pasajeros
* \param el tamaño del array de pasajeros
* \param la cantidad de pasajeros activos
* \return el precio promedio
*
*/
float calcularPromedio(ePassenger list[], int len, int cont){
	float total;
	float promedio;

	total = calcularTotalPasajes(list, len);

	promedio = total/cont;

	return promedio;
}

/**
* \brief cuenta la cantidad de pasajeros que superan el precio promedio
* \param el array con los pasajeros
* \param el tamaño del array de pasajeros
* \param la cantidad de pasajeros activos
* \return la cantidad de pasajes con precios superior al promedio
*
*/
int superiorAlPromedio(ePassenger list[], int len, int cont){
	int superiores;
	int i;
	float promedio;

	promedio = calcularPromedio(list, len, cont);
	superiores = 0;

	for(i = 0; i<len; i++){
		if(list[i].isEmpty == 0 && list[i].price > promedio){
			superiores++;
		}
	}
	return superiores;
}

/**
* \brief Muestra la cantidad de pasajes superiores al promedio
* \param el array con los pasajeros
* \param el tamaño del array de pasajeros
* \param la cantidad de pasajeros activos
*
*/
void informarTotalSuperiorPromedio(ePassenger list[], int len, int cont){
	float total;
	int superior;
	float promedio;

	total = calcularTotalPasajes(list, len);
	superior = superiorAlPromedio(list, len, cont);
	promedio = calcularPromedio(list, len, cont);

	printf("El precio total es de $%.2f con un promedio de $%.2f por pasaje. %d pasajes tienen un precio superior al promedio.\n", total, promedio, superior);
}

/**
* \brief Transforma los apellidos a mayuscula
* \param el array con los pasajeros
* \param el tamaño del array de pasajeros
*
*/
void arrayMayusculasLastName(ePassenger arr[], int len){
    int i;
    int j;

    for(i = 0; i<len; i++){
        if(arr[i].isEmpty == 0){
            for(j = 0; arr[i].lastName[j]!='\0'; j++){
                 arr[i].lastName[j] = toupper(arr[i].lastName[j]);
            }
        }
    }
}

/**
* \brief Transforma los codigos de vuelo a mayuscula
* \param el array con los pasajeros
* \param el tamaño del array de pasajeros
*
*/
void arrayMayusculasFlyCode(ePassenger arr[], int len){
    int i;
    int j;

    for(i = 0; i<len; i++){
        if(arr[i].isEmpty == 0){
            for(j = 0; arr[i].flycode[j]!='\0'; j++){
                 arr[i].flycode[j] = toupper(arr[i].flycode[j]);
            }
        }
    }
}

/**
* \brief Muestra los tipos de dato por consola
* \param el array con los tipos de dato
*
*/
void printDatos(eDato list[]){
	int i;

	for(i = 0; i<5; i++){
		printf("%d- %s\n", list[i].id, list[i].descripcion);
	}
}

/**
* \brief Muestra los tipos de pasajero por consola
* \param el array con los tipos de pasajero
*
*/
void printTypePassenger(eTipoPasajero list[]){
	int i;

	for(i = 0; i<2; i++){
		printf("%d- %s\n", list[i].id, list[i].descripcion);
	}
}

/**
* \brief Inicializa el array pasajeros colocando todos los espacios como vacios y poniendo en true la variable sinPasajeros
* \param el array de pasajeros
* \param el tamaño del array pasajeros
* \return el estado de la variable sinPasajeros
*
*/
int initPassengers(ePassenger list[], int len){
	int i;
	for(i=0; i<len; i++){
		list[i].isEmpty = 1;
	}

	return 1;
}

/**
* \brief Pide los datos del pasajero
* \param el pasajero
* \param el id del pasajero
* \param el array con los tipos de pasajero
* \return el pasajero
*
*/
ePassenger askData(ePassenger pasajero, int numId, eTipoPasajero list2[]){
	pasajero.id = numId;
	printf("Ingrese nombre: ");
	scanf("%s", pasajero.name);
	printf("Ingrese apellido: ");
	scanf("%s", pasajero.lastName);
	printf("Ingrese precio: ");
	scanf("%f", &pasajero.price);
	printf("Ingrese el codigo de vuelo: ");
	scanf("%s", pasajero.flycode);
	printTypePassenger(list2);
	printf("Ingrese el tipo de pasajero: ");
	scanf("%d", &pasajero.typePassenger);
	pasajero.isEmpty = 0;

	return pasajero;
}

/**
* \brief Añade un pasajero al array
* \param el array de pasajeros
* \param el tamaño del array pasajeros
* \param el id del pasajero
* \param el array con los tipos de pasajero
* \return el estado de la variable sinPasajeros
*/
int addPassengers(ePassenger list[], int len, int numId, eTipoPasajero list2[]){
	int i;

	for(i=0; i<len; i++){
		if(list[i].isEmpty == 1){
			list[i] = askData(list[i], numId, list2);
			break;
		}
	}

	return 0;
}

/**
* \brief Imprime los datos de pasajeros activos por consola
* \param el array de pasajeros
* \param el tamaño del array de pasajeros
* \param el array con los tipos de pasajero
*/
void printPassengers(ePassenger list[], int len, eTipoPasajero list2[]){

	char tipo[51];

	for(int i = 0; i<len; i++){

		arrayMayusculasLastName(list, len);
		arrayMayusculasFlyCode(list, len);

		for(int j = 0; j<2; j++){
			if(list[i].typePassenger==list2[j].id){
				strcpy(tipo, list2[j].descripcion);
			}
		}


		if(list[i].isEmpty == 0){
		printf("%d\t%10s\t%10s\t%10.2f\t%10s\t%10s\n",list[i].id, list[i].name, list[i].lastName, list[i].price, list[i].flycode, tipo);
		}
	}
}

/**
* \brief Modifica los datos de un pasajero ingresando su id
* \param el array de pasajeros
* \param el tamaño del array de pasajeros
* \param el array con los tipos de dato
* \param el array con los tipos de pasajero
*/
void modPassengers(ePassenger list[], int len, eDato list2[], eTipoPasajero list3[]){
	int i;
	int modId;
	int datoId;

	printPassengers(list, len, list3);
	printf("Ingrese el id del pasajero que desea modificar: ");
	scanf("%d", &modId);

	for(i=0; i<len; i++){
		if(list[i].isEmpty == 0&&list[i].id == modId){
			printDatos(list2);
			printf("Ingrese el id del dato que desea modificar:");
			scanf("%d", &datoId);
			switch(datoId){
				case 1:
					printf("Ingrese el nombre nuevo: ");
					scanf("%s", list[i].name);
				break;
				case 2:
					printf("Ingrese el apellido nuevo: ");
					scanf("%s", list[i].lastName);
					arrayMayusculasLastName(list, len);
				break;
				case 3:
					printf("Ingrese el precio nuevo: ");
					scanf("%f", &list[i].price);
				break;
				case 4:
					printTypePassenger(list3);
					printf("Ingrese el tipo de pasajero nuevo: ");
					scanf("%d", &list[i].typePassenger);
				break;
				case 5:
					printf("Ingrese el codigo de vuelo nuevo: ");
					scanf("%s", list[i].flycode);
				break;
				default:
					printf("Error! Opcion no disponible!\n");
			}
			break;
		}
	}
}

/**
* \brief Elimina un pasajero ingresando su id
* \param el array de pasajeros
* \param el tamaño del array de pasajeros
* \param el array con los tipos de pasajero
*/
void removePassengers(ePassenger list[], int len, eTipoPasajero list2[]){
	int i;
	int deleteId;

	printPassengers(list, len, list2);
	printf("Ingrese el id del pasajero que desea eliminar: ");
	scanf("%d", &deleteId);

	for(i=0; i<len; i++){
		if(list[i].isEmpty == 0&&list[i].id == deleteId){
			list[i].isEmpty = 1;
		}
	}
}

/**
* \brief ordena el array pasajeros por apellido
* \param el array de pasajeros
* \param el tamaño del array de pasajeros
* \param el sentido de orden
*/
void sortPassengersByLastName(ePassenger list[], int len, int order){
	int i;
	int j;
	ePassenger aux;

	arrayMayusculasLastName(list, len);
	arrayMayusculasFlyCode(list, len);

	switch(order){
	case 1:
		for(i = 0; i<len; i++){
		  for(j = i+1; j<len; j++){
			 if(strcmp(list[i].lastName,list[j].lastName)>0){
		      aux=list[i];
		      list[i]=list[j];
		      list[j]=aux;
		     }
		  }
		}
	break;
	case 2:
		for(i = 0; i<len; i++){
		  for(j = i+1; j<len; j++){
			 if(strcmp(list[i].lastName,list[j].lastName)<0){
		      aux=list[i];
		      list[i]=list[j];
		      list[j]=aux;
		     }
		  }
		}
	break;
	}
}

/**
* \brief ordena el array pasajeros por tipo de pasajero
* \param el array de pasajeros
* \param el tamaño del array de pasajeros
* \param el sentido de orden
*/
void sortPassengersByTypePassenger(ePassenger list[], int len, int order){
	int i;
	int j;
	ePassenger aux;

	arrayMayusculasLastName(list, len);
	arrayMayusculasFlyCode(list, len);

	switch(order){
	case 1:
		for(i = 0; i<len; i++){
		  for(j = i+1; j<len; j++){
			 if(list[i].typePassenger>list[j].typePassenger){
		      aux=list[i];
		      list[i]=list[j];
		      list[j]=aux;
		     }
		  }
		}
	break;
	case 2:
		for(i = 0; i<len; i++){
		  for(j = i+1; j<len; j++){
			 if(list[i].typePassenger<list[j].typePassenger){
		      aux=list[i];
		      list[i]=list[j];
		      list[j]=aux;
		     }
		  }
		}
	break;
	}
}

/**
* \brief ordena el array pasajeros por codigo de vuelo
* \param el array de pasajeros
* \param el tamaño del array de pasajeros
* \param el sentido de orden
*/
void sortPassengersByFlycode(ePassenger list[], int len, int order){
	int i;
	int j;
	ePassenger aux;

	arrayMayusculasLastName(list, len);
	arrayMayusculasFlyCode(list, len);

	switch(order){
	case 1:
		for(i = 0; i<len; i++){
		  for(j = i+1; j<len; j++){
			 if(strcmp(list[i].flycode,list[j].flycode)>0){
		      aux=list[i];
		      list[i]=list[j];
		      list[j]=aux;
		     }
		  }
		}
	break;
	case 2:
		for(i = 0; i<len; i++){
		  for(j = i+1; j<len; j++){
			 if(strcmp(list[i].flycode,list[j].flycode)<0){
		      aux=list[i];
		      list[i]=list[j];
		      list[j]=aux;
		     }
		  }
		}
	break;
	}
}

/**
* \brief muestra opciones de informes para poder seleccionar una y mostrarla
* \param el array de pasajeros
* \param el tamaño del array de pasajeros
* \param la cantidad de usuarios activos
* \param el array con los tipos de pasajero
*/
void informar(ePassenger list[], int len, int cont, eTipoPasajero list2[]){
	int opcion;

	printf("1. Pasajeros por apellido y tipo de pasajero\n");
	printf("2. Total y promedio de precio y pasajes superiores al precio promedio\n");
	printf("3. Pasajeros activos por Codigo de vuelo\n");
	printf("Ingrese una opcion: ");
	scanf("%d", &opcion);

	switch (opcion){
	case 1:
		sortPassengersByTypePassenger(list, len, 1);
		sortPassengersByLastName(list, len, 1);
		printPassengers(list, len, list2);
	break;
	case 2:
		informarTotalSuperiorPromedio(list, len, cont);
	break;
	case 3:
		sortPassengersByFlycode(list, len, 1);
		printPassengers(list, len, list2);
	break;
	}
}

/**
* \brief realiza una carga forzada de 5 pasajeros
* \param el array de pasajeros
* \return el estado de la variable sinPasajeros
*/
int cargaForzada(ePassenger list[]){
	int i;
	ePassenger carga[5] = {{1,"Carlos", "Guerrero", 10000, "abc123", 1},{2,"Luis", "Salinas", 20000, "abc123", 1},{3,"Sergio", "Vergara", 30000, "xyz890", 2},{4,"Abel", "Guerrero", 40000, "xyz890", 2},{5,"Maria", "Gonzalez", 50000, "aaa111", 1}};

	for(i=0; i<5; i++){
		list[i] = carga[i];
	}

	return 0;
}
