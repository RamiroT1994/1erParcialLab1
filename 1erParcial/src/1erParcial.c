/*
 ============================================================================
 Name        : 1erParcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"
#include "cliente.h"
#include "prestamo.h"

int main(void) {
	setbuf(stdout,NULL);

	int opcion;
	char seguir = 's';
	eCliente listaClientes[TAMC];
	ePrestamo listaPrestamos[TAMP];

	inicializarArrayClientes(listaClientes,TAMC);
	inicializarArrayPrestamos(listaPrestamos,TAMP);
	hardcodearClientes(listaClientes,5);
	hardcodearPrestamos(listaPrestamos,10);

	while(seguir == 's')
	{
		opcion = menu();

		switch(opcion)
		{
		case 1:
			system("cls");
			altaCliente(listaClientes,TAMC);
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			modificarCliente(listaClientes,TAMC);
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			bajaCliente(listaClientes,TAMC,listaPrestamos,TAMP);
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			crearPrestamo(listaPrestamos,TAMP,listaClientes,TAMC);
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			saldarPrestamo(listaPrestamos,TAMP,listaClientes,TAMC);
			printf("\n");
			system("pause");
			system("cls");
			break;
		case 6:
			system("cls");
			reanudarPrestamo(listaPrestamos,TAMP,listaClientes,TAMC);
			printf("\n");
			system("pause");
			system("cls");
			break;
		case 7:
			system("cls");
			mostrarClientesConPrestamosActivos(listaClientes,TAMC,listaPrestamos,TAMP);
			system("pause");
			system("cls");
			break;
		case 8:
			system("cls");
			mostrarMuchosPrestamos(listaPrestamos,TAMP,listaClientes,TAMC);
			printf("\n");
			system("pause");
			system("cls");
			break;
		case 9:
			system("cls");
			mostrarClientesConMasActivos(listaClientes,TAMC,listaPrestamos,TAMP);
			mostrarClientesConMasSaldados(listaClientes,TAMC,listaPrestamos,TAMP);
			system("pause");
			system("cls");
			break;
		case 10:
			system("cls");
			informarPrestamosSiMayorMil(listaPrestamos,TAMP,listaClientes,TAMC);
			system("pause");
			system("cls");
			break;
		case 11:
			seguir = 'n';
			break;
		default:
			system("cls");
			printf("\n\nOpcion invalida reintente\n\n");
			system("pause");
			system("cls");
			break;

		}
	}

	return EXIT_SUCCESS;
}


