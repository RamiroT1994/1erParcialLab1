/*
 * inputs.h
 *
 *  Created on: 17 may. 2020
 *      Author: admin
 */

#ifndef INPUTS_H_
#define INPUTS_H_



#endif /* INPUTS_H_ */

/**
 * @brief Funcion para verificar ingreso de un entero correcto
 * @param puntero a cadena a validar
 * @param puntero validador de longitud de cadena
 * @return retorna un entero -1 si no logro validar
 * 							  0 si logro validar
 */
int myGets(char* cadena, int longitud);

/**
 * @brief transforma la cadena de caracteres a intero
 * @param puntero a cadena de caracteres
 * @return retorna un entero -1 si no logro transformar la cadena de caracteres a entero
 * 							  0 si logro hacerlo
 */
int getInt(int* pResultado);

/**
 * @brief funcion que valida si los caracteres ingresados estan en el rango de enteros segun la tabla ASCII
 * @param puntero a cadena de caracteres a validar
 * @return retorna un entero, 0 si encontro un caracter invalido
 * 							  1 si la cadena es valida.
 */
int esNumerica(char* cadena);

/**
 * @brief funcion que guarda una variable int
 * @param puntero a entero dodne se guardara el dato
 * @param puntero a cadena con mensaje
 * @param puntero a cadena con mensaje de error
 * @param int que indica el valor minimo apto
 * @param int que indica el valor maximo apto
 * @param int que indica la cantidad de intentos para ingresar un dato valido
 * @return retorna un entero -1 si no logro obtener el numero, 0 si logro hacerlo
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError,int minimo, int maximo, int reintentos);

/**
 * @brief funcion que guarda una cadena de caracteres en el primer parametro
 * @param puntero a cadena donde se guardara el dato ingresado si es valido
 * @param puntero a cadena con mensaje
 * @param puntero a cadena con mensaje de error
 * @param int con cantidad de intentos para ingreso de dato valido
 * @return retorna un entero. -1 si no logro obtener una cadena correcta, 0 si logro hacerlo
 */
int utn_getNombre(char* pCadena,char* mensaje,char* mensajeError, int reintentos);

/**
 * @brief Funcion que valida que los caracteres de una cadena esten en el rango de las letras segun la tabla ASCII
 * @param puntero a cadena a validar
 * @return retorna un entero. -1 si no es una cadena valida. 0 si es una cadena valida.
 */
int validarCadena(char* pCadena);

/**
 * @brief Funcion que corrije las cadena. Utilizada para pasar a mayusucla primer letra de nombres propios
 * @param puntero a cadena a corregir
 * @return void.
 */
void correcionCadena(char* pCadena);

/**
 * @brief Funcion que obtiene un numero de cuil
 * @param puntero a cadena donde se guardara el dato ingresado si es valido
 * @param puntero a cadena con mensaje.
 * @param puntero a cadena con mensaje de error.
 * @intentos entero que indica la cantidad de intentos para ingresar un dato
 * @return retorna un entero. -1 si no logro obtener el dato, 0 si logro obtenerlo.
 */
int utn_getCuil(char* pCadena,char* mensaje,char* mensajeError,int intentos);

/**
 * @brief Funcion que valida que el cuil ingresado tenga solo valores numericos
 * @param puntero a cadena a validar
 * @return retorna un entero. -1 si no es un dato valido. 0 si es un dato valido.
 */
int validarCuil(char* pCadena);

/**
 * @brief Funcion que corrije el cuil agregando los guiones en las posiciones correspondientes siguiendo el siguiente criterio XX-XXXXXXXX-XX
 * @param Puntero a cadena a corregir
 * @return retorna un entero. -1 si no pudo corregir el dato. 0 si logro hacerlo.
 */
int corregirCuil(char* pCadena);

/**
 * @brief Funcion que obtiene una cadena mas pequeñe desde otra cadenas de mayor longitud
 * @param puntero a cadena de origen de la cual se desea obtener una subcadena
 * @param puntero a cadena de destino donde se desea copiar la subcadena obtenida
 * @param entero que indica el subindice de la cadena de origen desde la cual se empezaran a copiar los caracteres
 * @param entero que indica el subindice de la cadena de origen hasta donde se tomaran caracteres.
 * @return retorna un entero. 0 si no logro obtener una subcadena. 1 si logro hacerlo.
 */
int obtenerSubCadena(char* pCadena, char* subCadena, int desde, int hasta);

/**
 * @brief Funcion que muestra un menu por pantalla
 * @return Devuelve un dato ingresado por pantalla
 */
int menu();


