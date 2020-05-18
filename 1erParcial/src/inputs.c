/*
 * inputs.c
 *
 *  Created on: 17 may. 2020
 *      Author: admin
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "inputs.h"
#include "cliente.h"

int myGets(char* cadena, int longitud)
{
	if(cadena != NULL && longitud >0 && fgets(cadena,longitud,stdin) == cadena)
	{
		fflush(stdin);
		if(cadena[strlen(cadena)-1] == '\n')
		{
			cadena[strlen(cadena)-1] = '\0';
		}
		return 0;
	}
	return -1;
}

int getInt(int* pResultado)
{
	int retorno = -1;
	char buffer[64];

	if(pResultado != NULL)
	{
		if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer))
		{
			*pResultado = atoi(buffer);
			retorno = 0;
		}

	}

	return retorno;
}

int esNumerica(char* cadena)
{
	int i = 0;
	int retorno = 1;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if(cadena[i] < '0' || cadena[i] > '9' )
			{
				retorno = 0;
				break;
			}
			i++;
		}
	}

	return retorno;
}

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError,int minimo, int maximo, int reintentos)
{
	int bufferInt;
	int retorno = -1;

	while(reintentos > 0)
	{
		reintentos--;
		printf("%s",mensaje);

		if(getInt(&bufferInt) == 0)
		{
			if(bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
		}

		printf("%s",mensajeError);
	}
	return retorno;
}

int utn_getNombre(char* pCadena,char* mensaje,char* mensajeError, int reintentos)
{
	int retorno = -1;
	char buffer[64];

	if(pCadena != NULL && reintentos > 0)
	{
		while(reintentos > 0)
		{
			reintentos--;
			printf("%s",mensaje);
			fflush(stdin);
			gets(buffer);

			if(validarCadena(buffer) == 0)
			{
				correcionCadena(buffer);

				strcpy(pCadena,buffer);
				retorno = 0;
				break;
			}

			printf("%s",mensajeError);

		}
	}

	return retorno;
}

int validarCadena(char* pCadena)
{
	int retorno = -1;
	int lenCadena;
	int i;
	int auxFlag = 0;

	char buffer[64];

	if(pCadena != NULL)
	{
		strcpy(buffer,pCadena);
		strlwr(buffer);

		lenCadena = strlen(buffer);

		for(i=0;i<lenCadena;i++)
		{
			if( buffer[i] < 97 || buffer[i] > 122  )
			{
				if(buffer[i] != ' ')
				{
					auxFlag = -1;
					break;
				}
			}
		}

		if(auxFlag == 0)
		{
			strcpy(pCadena, buffer);
			retorno = 0;
		}


	}

	return retorno;

}

void correcionCadena(char* pCadena)
{
	int len;
	int i;

	if(pCadena != NULL)
	{
		len = strlen(pCadena);

		for(i=0;i<len;i++)
		{
			if(i == 0)
			{
				*pCadena = toupper(pCadena[i]);
				continue;
			}

			//VALIDACION PARA QUE SI EL NOMBRE TIENE "del", "de", la siguiente palabra este en mayuscula
			//EJEMPLO: Soledad del Valle
			/*if(pCadena[i] == ' ')
			{
				*pCadena = toupper(pCadena[i+1]);
			}*/
		}
	}
}

int utn_getCuil(char* pCadena,char* mensaje,char* mensajeError,int intentos)
{
	int retorno = -1;
	int auxRetorno;
	char buffer[64];

	if(pCadena != NULL && mensaje != NULL && mensaje != NULL && intentos > 0)
	{
		while(intentos > 0)
		{
			intentos--;

			printf("%s",mensaje);
			fflush(stdin);
			gets(buffer);

			auxRetorno = validarCuil(buffer);

			if(auxRetorno != -1)
			{
				auxRetorno = corregirCuil(buffer);

				if(auxRetorno != -1)
				{
					strcpy(pCadena, buffer);
					retorno = 0;
				}

				break;
			}
		}
	}

	return retorno;
}

int validarCuil(char* pCadena)
{
	int retorno = -1;
	int i;
	int lenCadena;
	int flagValidacion = 0;

	if(pCadena != NULL)
	{
		lenCadena = strlen(pCadena);

		if(lenCadena == 11)
		{
			for(i=0;i<lenCadena;i++)
			{
				if(pCadena[i] < 48 || pCadena[i] > 57)
				{
					flagValidacion = -1;
					break;
				}
			}
		}
		else
		{

			flagValidacion = -1;
		}


		if(flagValidacion == -1)
		{
			retorno = -1;
		}
		else if(flagValidacion == 0)
		{
			retorno = 0;
		}
	}

	return retorno;
}

int corregirCuil(char* pCadena)
{
	int retorno = -1;

	int auxRetorno;

	char auxGuion[2] = {'-'};
	char auxFinCadena[2] = {'\0'};
	char auxCadenaUno[20];
	char auxCadenaDos[20];
	char auxCadenaTres[20];

	if(pCadena != NULL)
	{
		auxRetorno = obtenerSubCadena(pCadena,auxCadenaUno,0,1);

		if(auxRetorno != 0)
		{
			auxRetorno = obtenerSubCadena(pCadena,auxCadenaDos,2,9);
		}

		if(auxRetorno != 0)
		{
			auxRetorno = obtenerSubCadena(pCadena,auxCadenaTres,10,10);
		}

		strcat(auxCadenaUno,auxGuion);
		strcat(auxCadenaUno,auxCadenaDos);
		strcat(auxCadenaUno,auxGuion);
		strcat(auxCadenaUno,auxCadenaTres);
		strcat(auxCadenaUno,auxFinCadena);

		strcpy(pCadena, auxCadenaUno);

		retorno = 0;
	}

	return retorno;
}

int obtenerSubCadena(char* Cad, char* SubCad, int ini, int fin)
{
	int iC, iS;

	if( (ini > fin ) || (ini<0) || (fin>=strlen(Cad)))
	{
		return 0;
	}

	iS = 0;
	for(iC = ini; iC <=fin; iC++)
	{
		SubCad[iS] = Cad[iC];
		iS++;
	}

	SubCad[iS] = '\0';

	return 1;
	/*int iC,iS;
	int retorno = -1;

	if(pCadena != NULL && subCadena != NULL && desde < hasta && desde < 0 && hasta >= strlen())
	{

	}
	*/



	/*
	int retorno = -1;
	int i;
	int iSC = 0; //indice subCadena;

	if(pCadena != NULL && desde > hasta)
	{
		for(i=desde;i<=hasta;i++)
		{
			subCadena[iSC] = pCadena[i];
			iSC++;
		}

		subCadena[iSC] = '\0';

		retorno = 0;
	}

	return retorno;*/
}

int menu()
{
	int retorno;

	printf("1-Alta cliente\n");
	printf("2-Modificar cliente\n");
	printf("3-Baja cliente\n");
	printf("4-Crear prestamo\n");
	printf("5-Saldar prestamo\n");
	printf("6-Reanudar prestamo\n");
	printf("7-Imprimir clientes\n");
	printf("8-Imprimir prestamos\n");
	printf("9-Informar clientes con mas activos y pasivos\n");
	printf("10-Informar prestamos si son activos y mayores a 1000\n");

	printf("\n11-Salir\n");

	printf("\nSeleccione una opcion: \n");
	scanf("%d",&retorno);

	return retorno;
}




