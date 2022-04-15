/*
 ============================================================================
 * Programa: TP_1
*
* Objetivo:
*
*Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerolíneas Argentinas
para ofrecerlos a sus clientes.
Se deberá ingresar por cada vuelo los km totales y el precio total del mismo.
El objetivo de la aplicación es mostrar las diferentes opciones de pagos a sus clientes.
*
*
* Version: 0.1 del 02 abril de 2022
* Autor: Gastón Gómez
 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include "ingDatos.h"
#include "calculos.h"
#include "mostrar.h"

int main() {

	int opcion; //guarda la opción seleccionada
	char confirm; //define si se decide salir o seguir en el menu
	float km; //guarda los km ingresados
	float precioAerolineas; //guarda el precio por aerolineas ingresado
	float precioLatam; //guarda el precio por Latam ingresado
	int flagKm; //define si la cantidad de km ingresados es correcta
	int flagAerolineas; //define si el precio por aerolineas ingresado es correcto
	float debitoAerolineas; //el precio por aerolineas usando tarjeta de debito
	float debitoLatam; //el precio por Latam usando tarjeta de debito
	float creditoAerolineas; //el precio por aerolineas usando tarjeta de credito
	float creditoLatam; //el precio por Latam usando tarjeta de credito
	float btcAerolineas; //el precio por aerolineas pagando en bitcoin
	float btcLatam; //el precio por Latam pagando en bitcoin
	float unitarioAerolineas; //el precio unitario por km por aerolineas
	float unitarioLatam; //el precio unitario por km por Latam
	float diferencia;//la diferencia de precio entre aerolineas y Latam
	int flagCalculo;//define si los datos fueron calculados


	flagKm = 0;
	flagAerolineas = 0;
	flagCalculo = 0;

	do{
		printf("1. Ingresar Kilometros");
		printf("\n2. Ingresar Precio de vuelos");
		printf("\n3. Calcular todos los costos");
		printf("\n4. Informar Resultados");
		printf("\n5. Carga forzada de datos");
		printf("\n6. Salir");
		printf("\nIngrese una opcion: ");
		scanf("%d", &opcion);
		switch(opcion){
		case 1:
			km = ingresarValor("Ingrese la cantidad de Km: ");
			while(km <= 0){
				km = ingresarValor("Cantidad incorrecta! Ingrese la cantidad de Km: ");
			}
			flagKm = 1;
		break;
		case 2:
			precioAerolineas = precioPorAerolinea(1);
			precioLatam = precioPorAerolinea(2);
			flagAerolineas = 1;
		break;
		case 3:
			if(flagKm == 0 || flagAerolineas == 0){
				printf("\nError! Faltan datos\n\n");
			}
			else{
				debitoAerolineas = calcularPrecio(precioAerolineas, km, 'a');
				debitoLatam = calcularPrecio(precioLatam, km, 'a');
				creditoAerolineas = calcularPrecio(precioAerolineas, km, 'b');
				creditoLatam = calcularPrecio(precioLatam, km, 'b');
				btcAerolineas = calcularPrecio(precioAerolineas, km, 'c');
				btcLatam = calcularPrecio(precioLatam, km, 'c');
				unitarioAerolineas = calcularPrecio(precioAerolineas, km, 'd');
				unitarioLatam = calcularPrecio(precioLatam, km, 'd');
				diferencia = calcularDiferencia(precioAerolineas, precioLatam);
				flagCalculo = 1;
				printf("\nDatos calculados con exito!\n\n");
			}
		break;
		case 4:
			if(flagCalculo == 0){
				printf("\nError! Datos sin calcular.\n\n");
			}
			else{
				printf("\nKMs Ingresados: %.2f km\n\n", km);
				printf("Precio aerolineas: $%.2f\n", precioAerolineas);
				mostrarTodo(debitoAerolineas,creditoAerolineas, btcAerolineas, unitarioAerolineas);
				printf("Precio Latam: $%.2f\n", precioLatam);
				mostrarTodo(debitoLatam,creditoLatam, btcLatam, unitarioLatam);
				printf("La diferencia de precio es: $%.2f\n\n", diferencia);
			}
		break;
		case 5:
			km = 7090;
			precioAerolineas = 162965;
			precioLatam = 159339;

			debitoAerolineas = calcularPrecio(precioAerolineas, km, 'a');
			debitoLatam = calcularPrecio(precioLatam, km, 'a');
			creditoAerolineas = calcularPrecio(precioAerolineas, km, 'b');
			creditoLatam = calcularPrecio(precioLatam, km, 'b');
			btcAerolineas = calcularPrecio(precioAerolineas, km, 'c');
			btcLatam = calcularPrecio(precioLatam, km, 'c');
			unitarioAerolineas = calcularPrecio(precioAerolineas, km, 'd');
			unitarioLatam = calcularPrecio(precioLatam, km, 'd');
			diferencia = calcularDiferencia(precioAerolineas, precioLatam);

			printf("\nKMs Ingresados: %.2f km\n\n", km);
			printf("Precio aerolineas: $%.2f\n", precioAerolineas);
			mostrarTodo(debitoAerolineas,creditoAerolineas, btcAerolineas, unitarioAerolineas);
			printf("Precio Latam: $%.2f\n", precioLatam);
			mostrarTodo(debitoLatam,creditoLatam, btcLatam, unitarioLatam);
			printf("La diferencia de precio es: $%.2f\n\n", diferencia);
		break;
		case 6:
			printf("Seguro que desea salir?(s/n): ");
			__fpurge(stdin);
			scanf("%c", &confirm);
		break;
		default:
			printf("Opcion inexistente!\n");
		break;
		}
	}while(confirm != 's');
	return 0;
}
