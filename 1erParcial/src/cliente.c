/*
 * cliente.c
 *
 *  Created on: 17 may. 2020
 *      Author: admin
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "cliente.h"
#include "inputs.h"

int altaCliente(eCliente* arrayClientes, int tam)
{
	int retorno = -1;
	int auxRetorno;
	int continuarCarga;

	char auxNombre[50];
	char auxApellido[50];
	char auxCuil[20];
	int auxId = 100;

	if(arrayClientes != NULL && tam > 0)
	{
		auxRetorno = buscarLugarLibre(arrayClientes,tam);

		if(auxRetorno != -1)
		{
			printf("\n\nSe ha encontrado una posicion libre!\n\n");
			continuarCarga = utn_getNombre(auxNombre,"\nIngrese nombre de nuevo cliente:","\nError en el dato ingresado.",1);

			if(continuarCarga != -1)
			{
				continuarCarga = utn_getNombre(auxApellido,"\nIngrese apellido de nuevo cliente:","\nError en el dato ingresado.",1);

				if(continuarCarga != -1)
				{
					continuarCarga = utn_getCuil(auxCuil,"\nIngrese CUIL de nuevo cliente (Sin los guiones '-'): ","\nError en el dato ingresado.",1);

					if(continuarCarga != -1)
					{
						auxId = generarId(arrayClientes,TAMC);

						if(auxId != -1)
						{
							strcpy(arrayClientes[auxRetorno].nombre,auxNombre);
							strcpy(arrayClientes[auxRetorno].apellido,auxApellido);
							strcpy(arrayClientes[auxRetorno].cuil,auxCuil);
							arrayClientes[auxRetorno].id = auxId;
							arrayClientes[auxRetorno].isEmpty = 0;

							printf("\n\nSe ha dado de alta con exito al siguiente cliente:\n\n");
							mostrarUnElemento(arrayClientes[auxRetorno]);
							printf("\n");

							retorno = 0;
						}
					}
					else
					{
						printf("Carga de nuevo cliente interrumpida por error en el ingreso de datos.");
					}
				}
				else
				{
					printf("Carga de nuevo cliente interrumpida por error en el ingreso de datos.");
				}
			}
			else
			{
				printf("Carga de nuevo cliente interrumpida por error en el ingreso de datos.");
			}

		}
		else
		{
			printf("\n\nNo se ha encontrado espacio para cargar un cliente nuevo\n\n");
		}

	}

	return retorno;
}



int buscarLugarLibre(eCliente* listaClientes,int tam)
{
	int retorno = -1;
	int i;

	if(listaClientes != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			if(listaClientes[i].isEmpty == 1)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}


void inicializarArrayClientes(eCliente* arraryClientes, int tam)
{
	int i;

	if(arraryClientes != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			arraryClientes[i].isEmpty = 1;
		}
	}
}

int mostrarMuchosElementos(eCliente* arrayClientes, int tam)
{
	int retorno = -1;
	int auxCabeceras = -1;
	int i;

	char auxHeader0 [20] = {"ID EMPLEADO"};
	char auxHeader1 [20] = {"NOMBRE"};
	char auxHeader2 [20] = {"APELLIDO"};
	char auxHeader3 [20] = {"CUIL"};

	if(arrayClientes != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			if(arrayClientes[i].isEmpty == 0)
			{
				auxCabeceras = 0;
				break;
			}
		}

		if(auxCabeceras == 0)
		{
			printf("%-10s %10s %14s %16s\n",auxHeader0,auxHeader1,auxHeader2,auxHeader3);

		}


		for(i=0;i<tam;i++)
		{
			if(arrayClientes[i].isEmpty == 0)
			{

				mostrarUnElemento(arrayClientes[i]);
			}
		}
	}
	return retorno;

}


int mostrarUnElemento(eCliente unCliente)
{
	int retorno = -1;

		printf("%-10d %11s %14s %16s\n",unCliente.id,unCliente.nombre,unCliente.apellido,unCliente.cuil);

	retorno = 0;

	return retorno;
}


int generarId(eCliente* listaClientes, int tam)
{
	int retorno = -1;
	int auxId;
	int i;

	if(listaClientes != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			if(listaClientes[i].isEmpty != 1)
			{
				auxId = listaClientes[i].id + 1;
			}
		}

		retorno = auxId;
	}

	return retorno;
}

int modificarCliente(eCliente* listaClientes, int tam)
{
	int retorno = -1;
	int auxId; //Se utiliza para guardar el ID que se ingresa del cliente que se desea modificar
	int auxiliarPosicion; //Se utiliza porque auxRetorno se pisa con otro valor, y en caso de que traiga la posicion ne que deseo modificar no pierda el hilo de la funcion
	int auxRetorno;
	char auxConfirmacion;
	char auxCadena[64];

	int opcion;

	if(listaClientes != NULL && tam > 0)
	{
		mostrarMuchosElementos(listaClientes,tam);
		fflush(stdin);
		auxRetorno = utn_getNumero(&auxId,"\nIngrese ID del cliente que desea modificar: ","\n\nError en el ingreso de datos. Reintente.\n",100,999,2);

		if(auxRetorno != -1)
		{
			auxRetorno = buscarClientePorID(listaClientes,tam,auxId);

			if(auxRetorno != -1)
			{
				system("cls");
				auxiliarPosicion = auxRetorno;
				printf("Se ha encontrado el siguiente cliente:\n\n");
				mostrarUnElemento(listaClientes[auxiliarPosicion]);
				fflush(stdin);
				auxRetorno = utn_getNumero(&opcion,"\n\nQue desea modificar?\n1-Nombre\n2-Apellido\n3-CUIT\n4-Cancelar Modificacion\n","Error en el ingreso de la opcion.",1,4,4);

				if(auxRetorno != -1)
				{
					switch(opcion)
					{
						case 1:
							system("cls");
							fflush(stdin);
							auxRetorno = utn_getNombre(auxCadena,"\nIngrese el nuevo nombre: ","\nError en el ingreso del nombre.\n",1);

							if(auxRetorno != -1)
							{
								printf("\nDesea confirmar el nuevo nombre '%s'? S/N", auxCadena);
								fflush(stdin);
								scanf("%c",&auxConfirmacion);
								auxConfirmacion = toupper(auxConfirmacion);

								printf("\n\nTOME LA LETRA. ES UNA %c\n\n",auxConfirmacion);

								while(auxConfirmacion != 'S' && auxConfirmacion != 'N')
								{
									printf("\nRespuesta invalida. Desea confirmar el nuevo nombre '%s'? S/N", auxCadena);
									fflush(stdin);
									scanf("%c",&auxConfirmacion);
									auxConfirmacion = toupper(auxConfirmacion);

								}

								if(auxConfirmacion == 'S')
								{
									printf("\nModificacion realizada con exito!\n");
									strcpy(listaClientes[auxiliarPosicion].nombre,auxCadena);
									retorno = 0;
								}
								else if (auxConfirmacion == 'N')
								{
									printf("\n\nModificacion cancelada\n\n");
								}

							}

							break;
						case 2:
							system("cls");
							fflush(stdin);
							auxRetorno = utn_getNombre(auxCadena,"\nIngrese el nuevo apellido: ","\nError en el ingreso del apellido.\n",1);

							if(auxRetorno != -1)
							{
								printf("\nDesea confirmar el nuevo apellido '%s'? S/N", auxCadena);
								fflush(stdin);
								scanf("%c",&auxConfirmacion);
								auxConfirmacion = toupper(auxConfirmacion);

								while(auxConfirmacion != 'S' && auxConfirmacion != 'N')
								{
									printf("\nRespuesta invalida. Desea confirmar el nuevo apellido '%s'? S/N", auxCadena);
									fflush(stdin);
									scanf("%c",&auxConfirmacion);
									auxConfirmacion = toupper(auxConfirmacion);

								}

								if(auxConfirmacion == 'S')
								{
									printf("\nModificacion realizada con exito!\n");
									strcpy(listaClientes[auxiliarPosicion].apellido,auxCadena);
									retorno = 0;
								}
								else if (auxConfirmacion == 'N')
								{
									printf("\n\nModificacion cancelada\n\n");
								}

							}
							break;
						case 3:
							system("cls");
							fflush(stdin);
							auxRetorno = utn_getCuil(auxCadena,"Ingrese nuevo CUIL: ","Error en el ingreso del dato.",1);

							if(auxRetorno != -1)
							{
								printf("\nDesea confirmar el nuevo cuil '%s'? S/N", auxCadena);
								fflush(stdin);
								scanf("%c",&auxConfirmacion);
								auxConfirmacion = toupper(auxConfirmacion);

								while(auxConfirmacion != 'S' && auxConfirmacion != 'N')
								{
									printf("\nRespuesta invalida. Desea confirmar el nuevo cuil '%s'? S/N", auxCadena);
									fflush(stdin);
									scanf("%c",&auxConfirmacion);
									auxConfirmacion = toupper(auxConfirmacion);

								}

								if(auxConfirmacion == 'S')
								{
									printf("\nModificacion realizada con exito!\n");
									strcpy(listaClientes[auxiliarPosicion].cuil,auxCadena);
									retorno = 0;
								}
								else if (auxConfirmacion == 'N')
								{
									printf("\n\nModificacion cancelada\n\n");
								}

							}
							break;
						case 4:
							printf("\nModificacion cancelada\n");
							break;
						default:
							printf("\nOpcion ingresada invalida\n");
							break;
					}

				}
				else
				{
					printf("\n\nError al seleccionar la opcion. Modificacion cancelada");
				}
			}
			else
			{
				printf("\n\nNo se ha encontrado un cliente con el ID introducido\n\n");
			}
		}
		else
		{
			printf("\n\nError en el ingrese de ID.\n\n");
		}
	}

	return retorno;

}

int buscarClientePorID(eCliente* listaClientes, int tam, int id)
{
	int retorno = -1;
	int i;

	if(listaClientes != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			if(listaClientes[i].isEmpty != 1 && listaClientes[i].id == id)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

void hardcodearClientes(eCliente* listaClientes, int tam)
{
	int i;

	int auxId[5] = {100,101,102,103,104};
	char auxNombre[5][64] = {"Maria","Pedro","Miguel","Luis","Carla"};
	char auxApellido[5][64] = {"Paez","Gimenez","Prediger","Saez","Asado"};
	char auxCuit[5][64] = {"27-11111111-9","20-22222222-8","20-33333333-7","20-44444444-6","27-55555555-6"};

	for(i=0;i<tam;i++)
	{
		listaClientes[i].id = auxId[i];
		strcpy(listaClientes[i].nombre,auxNombre[i]);
		strcpy(listaClientes[i].apellido,auxApellido[i]);
		strcpy(listaClientes[i].cuil,auxCuit[i]);

		listaClientes[i].isEmpty = 0;
	}

}

void mostrarClientesConPrestamosActivos(eCliente* listaClientes, int tamc, ePrestamo* listaPrestamos, int tamp)
{
	int i,j;
	int auxContador = 0;

	if(listaClientes != NULL && tamc > 0 && listaPrestamos != NULL && tamp > 0)
	{
		for(i=0;i<tamc;i++)
		{
			auxContador = 0;

			if(listaClientes[i].isEmpty != 1)
			{
				for(j=0;j<tamp;j++)
				{
					if(listaClientes[i].id == listaPrestamos[j].idCliente)
					{
						if(listaPrestamos[j].estado == 3)
						{
							auxContador++;
						}
					}
				}

				mostrarUnElemento(listaClientes[i]);
				printf("Cantidad de prestamos en ACTIVO: %d\n\n",auxContador);
			}
		}

	}
}


void mostrarClientesConMasActivos(eCliente* listaClientes, int tamc, ePrestamo* listaPrestamos, int tamp)
{
	int i,j;
	int contadorActivos = 0;
	int max;
	int auxPosicion;

	if(listaClientes != NULL && tamc > 0 && listaPrestamos != NULL && tamp > 0)
	{
		for(i=0;i<tamc;i++)
		{
			contadorActivos = 0;

			if(listaClientes[i].isEmpty != 1)
			{
				for(j=0;j<tamp;j++)
				{
					if(listaClientes[i].id == listaPrestamos[j].idCliente)
					{
						if(listaPrestamos[j].estado == 3)
						{
							contadorActivos++;
						}
					}
				}

				if(i == 0)
				{
					auxPosicion = i;
					max = contadorActivos;
				}
				else if(contadorActivos > max)
				{
					auxPosicion = i;
					max = contadorActivos;
				}
			}
		}

		printf("\n\nEl cliente con la mayor cantidad de prestamos activos es: \n");
		mostrarUnElemento(listaClientes[auxPosicion]);
		printf("\n");

	}
}

void mostrarClientesConMasSaldados(eCliente* listaClientes, int tamc, ePrestamo* listaPrestamos, int tamp)
{
	int i,j;
	int contadorActivos = 0;
	int max;
	int auxPosicion;

	if(listaClientes != NULL && tamc > 0 && listaPrestamos != NULL && tamp > 0)
	{
		for(i=0;i<tamc;i++)
		{
			contadorActivos = 0;

			if(listaClientes[i].isEmpty != 1)
			{
				for(j=0;j<tamp;j++)
				{
					if(listaClientes[i].id == listaPrestamos[j].idCliente)
					{
						if(listaPrestamos[j].estado == 2)
						{
							contadorActivos++;
						}
					}
				}

				if(i == 0)
				{
					auxPosicion = i;
					max = contadorActivos;
				}
				else if(contadorActivos > max)
				{
					auxPosicion = i;
					max = contadorActivos;
				}
			}
		}

		printf("\n\nEl cliente con la mayor cantidad de prestamos saldados es: \n");
		mostrarUnElemento(listaClientes[auxPosicion]);
		printf("\n");

	}
}

int bajaCliente(eCliente* listaClientes, int tamc, ePrestamo* listaPrestamo, int tamp)
{
	int i;
	int retorno = -1;
	int auxRetorno;
	int auxId;
	int auxPosicion;
	char auxConfirmacion;

	if(listaClientes != NULL && tamc > 0 && listaPrestamo != NULL && tamp > 0)
	{
		mostrarMuchosElementos(listaClientes,tamc);
		fflush(stdin);
		auxRetorno = utn_getNumero(&auxId,"\nIngrese ID de cliente que desea dar de baja: ","\nError en el ingreso de datos.\n",100,999,2);

		if(auxRetorno != -1)
		{
			auxPosicion = buscarClientePorID(listaClientes,tamc,auxId);

			if(auxPosicion != -1)
			{
				printf("\nSe ha encontrado el siguiente cliente:\n");
				mostrarUnElemento(listaClientes[auxPosicion]);

				printf("\nCon los siguientes prestamos:\n");

				for(i=0;i<tamp;i++)
				{
					if(listaPrestamo[i].idCliente == auxId)
					{
						mostrarUnPrestamoConCuil(listaPrestamo[i],listaClientes[auxPosicion]);
					}
				}

				printf("Desea confirmar la baja de este cliente y sus prestamos? S/N");
				fflush(stdin);
				scanf("%c",&auxConfirmacion);
				auxConfirmacion = toupper(auxConfirmacion);

				while(auxConfirmacion != 'S' && auxConfirmacion != 'N')
				{
					printf("\nRespuesta invalida. Desea confirmar la baja de este cliente y sus prestamos? S/N");
					fflush(stdin);
					scanf("%c",&auxConfirmacion);
					auxConfirmacion = toupper(auxConfirmacion);

				}

				if(auxConfirmacion == 'S')
				{
					for(i=0;i<tamp;i++)
					{
						if(listaPrestamo[i].idCliente == auxId)
						{
							listaPrestamo[i].estado = 1;
						}
					}

					listaClientes[auxPosicion].isEmpty = 1;

					printf("\n\nBaja realizada con exito!\n\n");

					retorno = 0;
				}
				else if (auxConfirmacion == 'N')
				{
					printf("\nBaja cancelada\n\n");
				}
			}
			else
			{
				printf("No se ha encontrado un cliente con el ID ingresado\n\n");
			}
		}

	}


	return retorno;
}


/********************************* APARTADO DE FUNCIONES PARA PRESTAMOS ***********************************************************/

void inicializarArrayPrestamos(ePrestamo* listaPrestamos, int tam)
{
	int i;

	if(listaPrestamos != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
		  listaPrestamos[i].estado = 1;
		}
	}
}

void hardcodearPrestamos(ePrestamo* listaPrestamos,int tam)
{
	int i;

	if(listaPrestamos != NULL && tam > 0)
	{
		int auxId[10] = {1000,1001,1002,1003,1004,1006,1007,1008,1009,1010};
		int auxIdCliente[10] = {104,101,102,103,104,100,104,104,100,101};
		int auxEstado[10] = {2,3,3,2,2,3,2,2,3,2};
		float auxImporte[10] = {25000,15000,18000,10000,35000,15345,22000,11750,9750,40000};
		int auxCuotas[10] = {6,12,6,6,3,18,3,12,3,18};


		for(i=0;i<tam;i++)
		{
			listaPrestamos[i].idPrestamo = auxId[i];
			listaPrestamos[i].idCliente = auxIdCliente[i];
			listaPrestamos[i].importe = auxImporte[i];
			listaPrestamos[i].cuotas = auxCuotas[i];
			listaPrestamos[i].estado = auxEstado[i];
		}
	}
}

int mostrarMuchosPrestamos(ePrestamo* arrayPrestamos, int tamp, eCliente* arrayClientes, int tamc)
{
	int retorno = -1;
	int auxCabeceras = -1;
	int i;
	int j;

	char auxHeader0 [20] = {"ID PRESTAMO"};
	char auxHeader4 [20] = {"CUIL CLIENTE"};
	char auxHeader1 [20] = {"IMPORTE"};
	char auxHeader2 [20] = {"CUOTAS"};
	char auxHeader3 [20] = {"ESTADO"};

	if(arrayPrestamos != NULL && tamp > 0)
	{
		for(i=0;i<tamp;i++)
		{
			if(arrayPrestamos[i].estado != 1)
			{
				auxCabeceras = 0;
				break;
			}
		}

		if(auxCabeceras == 0)
		{
			printf("%10s %15s %11s %10s %9s\n\n",auxHeader0,auxHeader4,auxHeader1,auxHeader2,auxHeader3);

		}


		for(i=0;i<tamp;i++)
		{
			if(arrayPrestamos[i].estado != 1)
			{
				for(j=0;j<tamc;j++)
				{
					if(arrayClientes[j].isEmpty != 1)
					{
						if(arrayPrestamos[i].idCliente == arrayClientes[j].id)
						{
							mostrarUnPrestamoConCuil(arrayPrestamos[i],arrayClientes[j]);
						}
					}
				}
			}
		}
	}

	return retorno;
}


int mostrarUnPrestamoConCuil(ePrestamo unPrestamo,eCliente unCliente)
{
	int retorno = -1;
	char auxEstado[64];

	switch(unPrestamo.estado)
	{
	case 2:
		strcpy(auxEstado,"Saldado");
		break;
	case 3:
		strcpy(auxEstado,"Activo");
		break;
	}

	printf("%d %23s %15.2f %6d %10s\n",unPrestamo.idPrestamo,unCliente.cuil,unPrestamo.importe,unPrestamo.cuotas,auxEstado);

	retorno = 0;

	return retorno;
}


int saldarPrestamo(ePrestamo* listaPrestamos, int tamp, eCliente* listaClientes, int tamc)
{
	int retorno = -1;
	int auxId;
	int auxIdentificadorCliente;
	int auxRespuesta;
	int auxPosicion;
	int i;
	char auxConfirmacion;

	if(listaPrestamos != NULL && listaClientes != NULL && tamp > 0 && tamc > 0)
	{
		mostrarMuchosPrestamos(listaPrestamos,tamp,listaClientes,tamc);
		fflush(stdin);
		auxRespuesta = utn_getNumero(&auxId,"\nIngrese ID de Prestamos que desea saldar: ","Error en el ingreso del dato.",1000,9999,2);

		if(auxRespuesta != -1)
		{
			auxPosicion = buscarPrestamoPorID(listaPrestamos,tamp,auxId);

			if(auxPosicion != -1)
			{

				if(listaPrestamos[auxPosicion].estado != 2)
				{
					printf("El prestamo con el ID %d pertenece al siguiente cliente:\n\n",auxId);

					auxIdentificadorCliente = listaPrestamos[auxPosicion].idCliente;

					for(i=0;i<tamc;i++)
					{
						if(listaClientes[i].id == auxIdentificadorCliente)
						{
							mostrarUnElemento(listaClientes[i]);
							break;
						}
					}

					printf("\nDesea confirmar el cambio de estado a SALDADO? S/N");
					fflush(stdin);
					scanf("%c",&auxConfirmacion);
					auxConfirmacion = toupper(auxConfirmacion);

					while(auxConfirmacion != 'S' && auxConfirmacion != 'N')
					{
						printf("\nRespuesta invalida. Desea confirmar el cambio de estado a SALDADO? S/N");
						fflush(stdin);
						scanf("%c",&auxConfirmacion);
						auxConfirmacion = toupper(auxConfirmacion);
					}

					if(auxConfirmacion == 'S')
					{
						listaPrestamos[auxPosicion].estado = 2;
						printf("\nCambio de estado realizado con exito!\n");

						retorno = 0;
					}
					else if (auxConfirmacion == 'N')
					{
						printf("\n\nModificacion de estado cancelada\n\n");
					}
				}
				else if (listaPrestamos[auxPosicion].estado == 2)
				{
					printf("\nEl prestamo que ha ingresado ya se encuentra en estado SALDADO\n");
				}

			}
			else
			{
				printf("\n\nNo se ha encontrado prestamo con el ID ingresado\n\n");
			}
		}
	}

	return retorno;

}

int buscarPrestamoPorID(ePrestamo* listaPrestamos, int tam, int id)
{
	int retorno = -1;
	int i;

	if(listaPrestamos != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			if(listaPrestamos[i].estado != 1 && listaPrestamos[i].idPrestamo == id)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

int reanudarPrestamo(ePrestamo* listaPrestamos, int tamp, eCliente* listaClientes, int tamc)
{
	int retorno = -1;
	int auxId;
	int auxIdentificadorCliente;
	int auxRespuesta;
	int auxPosicion;
	int i;
	char auxConfirmacion;

	if(listaPrestamos != NULL && listaClientes != NULL && tamp > 0 && tamc > 0)
	{
		mostrarMuchosPrestamos(listaPrestamos,tamp,listaClientes,tamc);
		fflush(stdin);
		auxRespuesta = utn_getNumero(&auxId,"\nIngrese ID de Prestamos que desea reanudar: ","Error en el ingreso del dato.",1000,9999,2);

		if(auxRespuesta != -1)
		{
			auxPosicion = buscarPrestamoPorID(listaPrestamos,tamp,auxId);

			if(auxPosicion != -1)
			{

				if(listaPrestamos[auxPosicion].estado != 3)
				{
					printf("El prestamo con el ID %d pertenece al siguiente cliente:\n\n",auxId);

					auxIdentificadorCliente = listaPrestamos[auxPosicion].idCliente;

					for(i=0;i<tamc;i++)
					{
						if(listaClientes[i].id == auxIdentificadorCliente)
						{
							mostrarUnElemento(listaClientes[i]);
							break;
						}
					}

					printf("\nDesea confirmar el cambio de estado a ACTIVO? S/N");
					fflush(stdin);
					scanf("%c",&auxConfirmacion);
					auxConfirmacion = toupper(auxConfirmacion);

					while(auxConfirmacion != 'S' && auxConfirmacion != 'N')
					{
						printf("\nRespuesta invalida. Desea confirmar el cambio de estado a ACTIVO? S/N");
						fflush(stdin);
						scanf("%c",&auxConfirmacion);
						auxConfirmacion = toupper(auxConfirmacion);
					}

					if(auxConfirmacion == 'S')
					{
						listaPrestamos[auxPosicion].estado = 3;
						printf("\nCambio de estado realizado con exito!\n");

						retorno = 0;
					}
					else if (auxConfirmacion == 'N')
					{
						printf("\n\nModificacion de estado cancelada\n\n");
					}
				}
				else if (listaPrestamos[auxPosicion].estado == 3)
				{
					printf("\nEl prestamo que ha ingresado ya se encuentra en estado ACTIVO\n");
				}

			}
			else
			{
				printf("\n\nNo se ha encontrado prestamo con el ID ingresado\n\n");
			}
		}
	}

	return retorno;

}

void informarPrestamosSiMayorMil(ePrestamo* listaPrestamos, int tamp,eCliente* listaClientes, int tamc)
{
	int i;
	float auxMonto;
	int flag = 0;

	if(listaPrestamos != NULL && tamp > 0)
	{
		printf("Ingrese el monton que se desea buscar: ");
		scanf("%f",&auxMonto);

		for(i=0;i<tamp;i++)
		{
			if(listaPrestamos[i].estado == 3 && listaPrestamos[i].importe == auxMonto)
			{
				flag = 1;
				mostrarUnPrestamoConCuil(listaPrestamos[i],listaClientes[i]);
			}
		}

		if(flag == 0)
		{
			printf("\nNo hay prestamos coincidentes con el monto ingresado\n");
		}

	}
}

int generarIdPrestamo(ePrestamo* listaPrestamos, int tam)
{
	int retorno = -1;
	int auxId;
	int i;

	if(listaPrestamos != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			if(listaPrestamos[i].estado != 1)
			{
				auxId = listaPrestamos[i].idPrestamo + 1;
			}
		}

		retorno = auxId;
	}

	return retorno;
}

int crearPrestamo(ePrestamo* listaPrestamo, int tamp, eCliente* listaClientes, int tamc)
{
	int retorno = -1;
	int auxId;
	int auxRetorno;
	int auxPosicion;
	int auxInt;
	float auxImporte;
	char auxConfirmacion;
	int auxiliarCliente;
	int auxNuevaPosicion;

	if(listaPrestamo != NULL && tamp > 0 && listaClientes != NULL &&  tamc > 0)
	{
		mostrarMuchosElementos(listaClientes,tamc);
		fflush(stdin);
		auxRetorno = utn_getNumero(&auxId,"\nIngrese ID de cliente al que se le asignara el nuevo prestamo: ","Error en el ingreso del dato.",100,999,3);

		if(auxRetorno != -1)
		{
			auxPosicion = buscarClientePorID(listaClientes,tamc,auxId);

			if(auxPosicion != -1)
			{
				printf("\n\nSe ha encontrado al cliente!\n\n");
				mostrarUnElemento(listaClientes[auxPosicion]);
				auxiliarCliente = auxId;

				auxRetorno = buscarLugarPrestamoLibre(listaPrestamo,tamp);

				if(auxRetorno != -1)
				{
					auxNuevaPosicion = auxRetorno;

					printf("\n\nSe ha encontrado lugar para generar nuevo prestamo!\n\n");

					printf("\nIngrese importe de prestamo: ");
					scanf("%f",&auxImporte);

					fflush(stdin);
					auxRetorno = utn_getNumero(&auxInt,"\nIngrese cantidad de cuotas(3-6-12-18): ","Error en el ingreso del dato.",3,18,4);

					while(auxInt != 3 && auxInt != 6 && auxInt != 12 && auxInt != 18)
					{
						fflush(stdin);
						auxRetorno = utn_getNumero(&auxInt,"\nCantidad de cuotas ingresada es invalida. Reintente. Ingrese cantidad de cuotas(3-6-12-18): ","\nError en el ingreso del dato.\n\n",3,18,4);
					}

					printf("\nDesea confirmar el nuevo prestamo con los siguientes datos IMPORTE:%.2f CUOTAS:%d ? S/N",auxImporte,auxInt);
					fflush(stdin);
					scanf("%c",&auxConfirmacion);
					auxConfirmacion = toupper(auxConfirmacion);

					while(auxConfirmacion != 'S' && auxConfirmacion != 'N')
					{
						printf("\nRespuesta invalida. Desea confirmar el nuevo prestamo con los siguientes datos IMPORTE:%.2f CUOTAS:%d ? S/N",auxImporte,auxInt);
						fflush(stdin);
						scanf("%c",&auxConfirmacion);
						auxConfirmacion = toupper(auxConfirmacion);
					}

					if(auxConfirmacion == 'S')
					{
						auxId = generarIdPrestamo(listaPrestamo,tamp);

						listaPrestamo[auxNuevaPosicion].idPrestamo = auxId;
						listaPrestamo[auxNuevaPosicion].importe = auxImporte;
						listaPrestamo[auxNuevaPosicion].cuotas = auxInt;
						listaPrestamo[auxNuevaPosicion].estado = 3;
						listaPrestamo[auxNuevaPosicion].idCliente = auxiliarCliente;

						printf("\nCambio de estado realizado con exito!\n");

						retorno = 0;
					}
					else if (auxConfirmacion == 'N')
					{
						printf("\nCreacion de prestamo cancelada\n\n");
					}

				}
				else
				{
					printf("\n\nNo hay lugar para generar nuevo prestamo\n\n");
				}
			}
			else
			{
				printf("\nNo se ha encontrado un cliente con el ID ingresado\n");
			}
		}
		else
		{
			printf("\n\nError en el ingreso del ID de Cliente. Creacion de prestamo cancelada\n\n");
		}

	}

	return retorno;
}

int buscarLugarPrestamoLibre(ePrestamo* listaPrestamo,int tamp)
{
	int i;
	int retorno = -1;

	if(listaPrestamo != NULL && tamp > 0)
	{
		for(i=0;i<tamp;i++)
		{
			if(listaPrestamo[i].estado == 1)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;

}
