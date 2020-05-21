/*
 * cliente.h
 *
 *  Created on: 17 may. 2020
 *      Author: admin
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_



#endif /* CLIENTE_H_ */

#define TAMC 50
#define TAMP 50

typedef struct
{
	int idPrestamo;
	int idCliente;
	float importe;
	int cuotas;
	int estado;

}ePrestamo;

typedef struct
{
	int id;
	char nombre[64];
	char apellido[64];
	char cuil[64];

	int isEmpty;

}eCliente;

/**
 * @brief Funcion que inicializa las posiciones de un array con el valor 1
 * @param Puntero a array del tipo de dato eCliente
 * @param Entero que indica la longitud del array de tipo de dato eCliente
 * @return void
 */
void inicializarArrayClientes(eCliente* arraryClientes, int tam);

/**
 * @brief Funcion que da de alta un cliente
 * @param Puntero a array del tipo de dato eCliente
 * @param Entero que indica la longitud del array de tipo de dato eCliente
 * @return retorna un entero. -1 si no logro dar de alta un cliente. 0 si lo logro.
 */
int altaCliente(eCliente* arrayClientes, int tam);

/**
 * @brief Funcion que se encarga de modificar los datos de un elemento en el array de tipo eCliente
 * @param Puntero a array del tipo de dato eCliente
 * @param Entero que indica la longitud del array de tipo de dato eCliente
 * @return retorna un entero. -1 si no logro modificar el campo. 0 si lo logro.
 */
int modificarCliente(eCliente* listaClientes, int tam);

/**
 * @brief Funcion que se encarga de dar de baja logica un cliente
 * @param Puntero a array del tipo de dato eCliente
 * @param Entero que indica la longitud del array de tipo eCliente
 * @param Puntero a array del tipo de dato ePrestamo
 * @param Entero que indica la longitud del array de tipo ePrestamo
 * @return Retorna un entero. -1 si no logro dar de baja al cliente. 0 si lo logro.
 */
int bajaCliente(eCliente* listaClientes, int tamc, ePrestamo* listaPrestamo, int tamp);

/**
 * @brief Funcion que se encarga de buscar una posicion libre en el array de tipo eCliente
 * @param Puntero a array del tipo eCliente donde se buscara el lugar libre
 * @param Entero que indica la longitud del array de tipo eCliente
 * @return Retorna un entero. -1 si no encontro lugar libre. En caso de que haya lugar retorna el indice de dicho lugar.
 */
int buscarLugarLibre(eCliente* listaClientes,int tam);

/**
 * @brief Funcion que muestra un elemento del tipo eCliente
 * @param Elemento del tipo de dato eCliente
 * @return Retorna un entero. -1 si no logro mostrar. 0 si logro mostrar.
 */
int mostrarUnElemento(eCliente unCliente);

/**
 * @brief Funcion que se encarga de mostrar mas de un elemento del tipo de dato eCliente
 * @param Puntero a array del tipo eCliente
 * @param Entero que indica la longitud del array de tipo eCliente
 * @return Retorna un entero. -1 si no logro mostrar elementos. 0 si logro mostrar elementos.
 */
int mostrarMuchosElementos(eCliente* arrayClientes, int tam);

/**
 * @brief Funcion que se encarga de generar un ID de manera autoincremental
 * @param Puntero a array del tipo de dato eCLiente.
 * @param Entero que indica la longitud del array de tipo eCLiente
 * @return Retorna un entero. -1 si no logro generar un id. Retorna un valor disponible como ID si logro generarlo.
 */
int generarId(eCliente* listaClientes, int tam);

/**
 * @brief Funcion que se encarga de buscar un cliente por su ID
 * @param Puntero a array del tipo eCliente.
 * @param Entero que indica la longitud del array de tipo eCLiente
 * @param Entero que indica el ID que se buscara.
 * @return Retorna entero. -1 si no logro encontrar un cliente con el ID ingresado.
 * 							Subindice del cliente que corresponda al ID por el cual se busco
 */
int buscarClientePorID(eCliente* listaClientes, int tam, int id);

/**
 * @brief Funcion de hardcodeo para pruebas
 * @param Puntero a array del tipo eCliente.
 * @param Entero que indica la longitud del array del tipo eCliente
 * @return void
 */
void hardcodearClientes(eCliente* listaClientes, int tam);

/**
 * @brief Funcion que se encarga de modificar los datos de un elemento en el array de tipo eCliente
 * @param Puntero a array del tipo de dato eCliente
 * @param Entero que indica la longitud del array de tipo de dato eCliente
 * @return retorna un entero. -1 si no logro modificar el campo. 0 si lo logro.
 */
int modificarCliente(eCliente* listaClientes, int tam);


/**
 * @brief Funcion que se encarga de listar clietnes con prestamos en estado activo
 * @param Puntero a array de tipo eCliente
 * @param Entero que indica la longitud del array de tipo eCliente
 * @param Puntero a array de tipo ePrestamo
 * @param Entero que indica la longitud del array de tipo ePrestamo
 * @return void
 */
void mostrarClientesConPrestamosActivos(eCliente* listaClientes,int tamc,ePrestamo* listaPrestamos,int tamp);

/**
 * @brief Funcion que se encarga de mostrar el cliente con mas transacciones en estado activo
 * @param Puntero a array de tipo eCliente
 * @param Entero que indica la longitud del array de tipo eCliente
 * @param Puntero a array de tipo ePrestamo
 * @param Entero que indica la longitud del array de tipo ePrestamo
 * return void
 */
void mostrarClientesConMasActivos(eCliente* listaClientes, int tamc, ePrestamo* listaPrestamos, int tamp);

/**
 * @brief Funcion que se encarga de mostrar el cliente con mas transacciones en estado saldado
 * @param Puntero a array de tipo eCliente
 * @param Entero que indica la longitud del array de tipo eCliente
 * @param Puntero a array de tipo ePrestamo
 * @param Entero que indica la longitud del array de tipo ePrestamo
 * return void
 */
void mostrarClientesConMasSaldados(eCliente* listaClientes, int tamc, ePrestamo* listaPrestamos, int tamp);

/*******************************************************************************************/


/**
 * @brief Funcion que se encarga de inicializar array de tipo ePrestamo
 * @param Puntero a array de tipo ePrestamo
 * @param Entero que indica la longitud del array de tipo ePrestamo
 * @return Void
 */
void inicializarArrayPrestamos(ePrestamo* listaPrestamos,int tam);

/**
 * @brief Funcion de hardcodeo de datos para pruebas
 * @param Puntero a array de tipo ePrestamo
 * @param Entero que indica la longitud del array de tipo ePrestamo
 * @return void
 */
void hardcodearPrestamos(ePrestamo* listaPrestamos,int tam);

/**
 * @brief Funcion que se encarga de mostrar todos los prestamos
 * @param Puntero a array de tipo ePrestamo
 * @param Entero que indica la longitud del array de tipo ePrestamo
 * @param Puntero a array de tipo eCliente
 * @param Entero que indica la longitud del array de tipo eCliente
 * @return Retorna un entero. -1 si no logro mostrar. 0 si logro mostrar.
 */
int mostrarMuchosPrestamos(ePrestamo* arrayPrestamos, int tamp, eCliente* arrayClientes, int tamc);
//int mostrarMuchosPrestamos(ePrestamo* arrayPrestamos, int tam);
//int mostrarUnPrestamo(ePrestamo unPrestamo);

/**
 * @brief Funcion que se encarga de mostrar un prestamo con el cuil del cliente al que pertenece
 * @param variable del tipo de dato ePrestamo
 * @param variable del tipo de dato eCliente
 * @return Retorna un entero. -1 si no logro mostrar. 0 si logro mostrar.
 */
int mostrarUnPrestamoConCuil(ePrestamo unPrestamo,eCliente unCliente);

/**
 * @brief Funcion que se encarga de buscar un prestamo por su ID
 * @param Puntero a array del tipo ePrestamo
 * @param Entero que indica la longitud del array de tipo ePrestamo
 * @param Entero con el ID que se busca.
 * @return Retorna un entero. -1 si no encuentra el prestamo con el ID ingresado. Subindice del prestamo con el ID ingresado.
 */
int buscarPrestamoPorID(ePrestamo* listaPrestamos, int tam, int id);

/**
 * @brief Funcion que se encarga de cambiar el estado de un prestamo a Saldado
 * @param Puntero a array de tipo ePrestamo
 * @param Entero que indica la longitud del array de tipo ePrestamo
 * @param Puntero a array de tipo eCliente
 * @param Entero que indica la longitud del array de tipo eCliente
 * @return Retorna un entero. -1 si no logro cambiar el estado. 0 si logro hacerlo.
 */
int saldarPrestamo(ePrestamo* listaPrestamos, int tamp, eCliente* listaClientes, int tamc);

/**
 * @brief Funcion que se encarga de cambiar el estado de un prestamo a reanudado
 * @param Puntero a array de tipo ePrestamo
 * @param Entero que indica la longitud del array de tipo ePrestamo
 * @param Puntero a array de tipo eCliente
 * @param Entero que indica la longitud del array de tipo eCliente
 * @return Retorna un entero. -1 si no logro cambiar el estado. 0 si logro hacerlo.
 */
int reanudarPrestamo(ePrestamo* listaPrestamos, int tamp, eCliente* listaClientes, int tamc);

/**
 * @brief Funcion que se encarga de mostrar los prestamos iguales al monto pasado como parametro, siempre y cuando sea mayor a 1000
 * @param Puntero a array de tipo ePrestamo
 * @param Entero que indica la longitud del array de tipo ePrestamo
 * @param Puntero a array de tipo eCliente
 * @param Entero que indica la longitud del array de tipo eCliente
 * @return Retorna un entero. -1 si no logro encontrar un prestamo. 0 si logro encontrar y mostrar.
 */
void informarPrestamosSiMayorMil(ePrestamo* listaPrestamos,int tamp,eCliente* listaClientes,int tamc);

/**
 * @brief Multiplica 2 matrices 3x3 y devuelve el resultado
 * @param Puntero a array de tipo ePrestamo
 * @param Entero que indica la longitud del array de tipo ePrestamo
 * @param Puntero a array de tipo eCliente
 * @param Entero que indica la longitud del array de tipo eCliente
 * @return Retorna entero. -1 si no puedo generar un nuevo prestamo. 0 si logro generarlo.
 */
int crearPrestamo(ePrestamo* listaPrestamo, int tamp, eCliente* listaClientes, int tamc);

/**
 * @brief Funcion que se encarga de buscar una posicion disponible en array de tipo ePrestamo
 * @param Puntero a array de tipo ePrestamo
 * @param Entero que indica la longitud del array de tipo ePrestamo
 * @return Retorna un entero. -1 si no logro encontrar un lugar disponible. Valor con subindice donde se puede generar un prestamo nuevo.
 */
int buscarLugarPrestamoLibre(ePrestamo* listaPrestamo,int tamp);

void mostrar12CuotasSaldados(ePrestamo* listaPrestamos, int tamp, eCliente* listaClientes, int tamc);
