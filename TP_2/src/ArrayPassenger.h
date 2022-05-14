/*
 * ArrayPassenger.h
 *
 *  Created on: Apr 23, 2022
 *      Author: gaston
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int isEmpty;
}ePassenger;

typedef struct
{
	int id;
	char descripcion[51];
}eDato;

typedef struct
{
	int id;
	char descripcion[51];
}eTipoPasajero;

int initPassengers(ePassenger list[], int len);
int addPassengers(ePassenger list[], int len, int numId, eTipoPasajero list2[]);
void printPassengers(ePassenger list[], int len, eTipoPasajero list2[]);
void modPassengers(ePassenger list[], int len, eDato list2[], eTipoPasajero list3[]);
void removePassengers(ePassenger list[], int len, eTipoPasajero list2[]);
void sortPassengersByLastName(ePassenger list[], int len, int order);
void informar(ePassenger list[], int len, int cont, eTipoPasajero list2[]);
int cargaForzada(ePassenger list[]);

#endif /* ARRAYPASSENGER_H_ */
