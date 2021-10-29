#include <stdio.h>
#include <stdlib.h>

#include "input.h"
//#include "swap.h"
#include "aerolinea.h"
#include "tipo.h"
#include "menu.h"

#ifndef AVION_H_
#define AVION_H_

typedef struct {
	int id;
	int idAerolinea;
	int idTipo;
	int capacidad;
	int isEmpty;
} eAvion;

#endif /* AVION_H_ */

/**
 * @brief Precarga varios aviones
 *
 * @param aviones eAvion* Array de aviones
 * @param lenAviones int Tamanio de array
 * @param cantidad int Cantidad de aviones a precargar
 * @param pId int* Puntero a variable donde almacear id
 * @return 1: Carga existosa - 0: No se pudo cargar
 */
int hardcodeAviones(eAvion aviones[], int lenAviones, int cantidad, int* pId);


/**
 * @brief Inicializa todos los elementos de aviones
 *
 * @param aviones eAvion* Array de aviones
 * @param lenAviones int Cantidad de elementos
 * @return 1: ok - 0: error
 */
int inicializarAviones(eAvion aviones[], int lenAviones);


/**
 * @brief Busca una posicion libre en el array de aviones
 *
 * @param aviones eAvion* Array de aviones
 * @param lenAerolineas int Cantidad de elementos
 * @return int -> Posicion libre - -1: No hay lugar
 */
int buscarPosicionLibreAvion(eAvion aviones[], int lenAviones);


/**
 * @brief Registra un nuevo avion
 *
 * @param aviones eAvion* Array de aviones
 * @param lenAviones int Cantidad de elementos aviones
 * @param aerolineas eAerolinea* Array de aerolineas
 * @param lenAerolineas int Cantidad de elementos aerolineas
 * @param tipos eTipo* Array de tipos
 * @param lenTipos Cantidad de elementos tipos
 * @param pIdAvion int* Puntero donde almacenar ID de avion
 * @return 1: Alta existosa - 0: No se pudo dar de alta
 */
int altaAvion(eAvion aviones[], int lenAviones, eAerolinea aerolineas[], int lenAerolineas, eTipo tipos[], int lenTipos, int* pIdAvion);


/**
 * @brief Modifica los datos de un avion
 *
 * @param aviones eAvion* Array de aviones
 * @param lenAviones int Cantidad de elementos aviones
 * @param aerolineas eAerolinea* Array de aerolineas
 * @param lenAerolineas int Cantidad de elementos aerolineas
 * @param tipos eTipo* Array de tipos
 * @param lenTipos Cantidad de elementos tipos
 * @return 1: Modificacion exitosa - 0: No se pudo modificar
 */
int modificarAvion(eAvion aviones[], int lenAviones, eAerolinea aerolineas[], int lenAerolineas, eTipo tipos[], int lenTipos);


/**
 * @brief Borrado logico de un avion
 *
 * @param aviones eAvion* Array de aviones
 * @param lenAviones int Cantidad de elementos aviones
 * @param aerolineas eAerolinea* Array de aerolineas
 * @param lenAerolineas int Cantidad de elementos aerolineas
 * @param tipos eTipo* Array de tipos
 * @param lenTipos Cantidad de elementos tipos
 * @return 1: Borrado exitoso - 0: No se pudo borrar
 */
int bajaAvion(eAvion aviones[], int lenAviones, eAerolinea aerolineas[], int lenAerolineas, eTipo tipos[], int lenTipos);


/**
 * @brief Muestra los datos de un avion
 *
 * @param avion eAvion Avion
 * @param aerolineas eAerolinea* Array de aerolineas
 * @param lenAerolineas int Cantidad de elementos aerolineas
 * @param tipos eTipo* Array de tipos
 * @param lenTipos Cantidad de elementos tipos
 */
void mostrarAvion(eAvion avion, eAerolinea aerolineas[], int lenAerolineas, eTipo tipos[], int lenTipos);


/**
 * @brief Muestra los datos de todos los aviones
 *
 * @param aviones eAvion* Array de aviones
 * @param lenAviones int Cantidad de elementos aviones
 * @param aerolineas eAerolinea* Array de aerolineas
 * @param lenAerolineas int Cantidad de elementos aerolineas
 * @param tipos eTipo* Array de tipos
 * @param lenTipos Cantidad de elementos tipos
 * @return 1: Se pudo mostrar los datos - 0: No se pudo mostrar los datos
 */
int mostrarAviones(eAvion aviones[], int lenAviones, eAerolinea aerolineas[], int lenAerolineas, eTipo tipos[], int lenTipos);


/**
 * @brief Busca el indice de un avion por su ID en un array
 *
 * @param aviones eAvion* Array de aviones
 * @param lenAviones int Cantidad de elementos aviones
 * @param id int ID avion
 * @return Posicion dentro de array - -1: si no existe
 */
int buscarAvionPorId(eAvion aviones[], int lenAviones, int id);


/**
 * @brief Ordena los aviones por aerolinea y tipo
 *
 * @param aviones eAvion* Array de aviones
 * @param lenAviones int Cantidad de elementos aviones
 * @param aerolineas eAerolinea* Array de aerolineas
 * @param lenAerolineas int Cantidad de elementos aerolineas
 * @param tipos eTipo* Array de tipos
 * @param lenTipos Cantidad de elementos tipos
 * @return 1: Se pudo ordenar - 0: No se pudo ordenar
 */
int ordenarAviones(eAvion aviones[], int lenAviones, eAerolinea aerolineas[], int lenAerolineas, eTipo tipos[], int lenTipos);




//INFORMES
int mostrarAvionesPorAerolinea(eAvion aviones[], int lenAviones, eAerolinea aerolineas[], int lenAerolineas, eTipo tipos[], int lenTipos);

int mostrarAvionesPorTipo(eAvion aviones[], int lenAviones, eAerolinea aerolineas[], int lenAerolineas, eTipo tipos[], int lenTipos);

int mostrarPorcentajeAvionesPorAerolinea(eAvion aviones[], int lenAviones, eAerolinea aerolineas[], int lenAerolineas, int idAerolinea, int idTipo);

int mostrarPorcentajeAvionesJetAerolineas(eAvion aviones[], int lenAviones, eAerolinea aerolineas[], int lenAerolineas);


int mostrarAerolineaConMenosAviones(eAvion aviones[], int lenAviones, eAerolinea aerolineas[], int lenAerolineas);



//VALIDACIONES

/**
 * @brief Indica si una capacidad es valida para un avion
 *
 * @param capacidad int
 * @return 1: Valida - 0: No valida
 */
int validarCapacidad(int capacidad);


/**
 * @brief Indica si un ID de avion existe
 *
 * @param aviones eAvion* Array de aviones
 * @param lenAviones int Cantidad de elementos aviones
 * @param id int ID avion
 * @return Posicion dentro del array - -1: No existe
 */
int validarIdAvion(eAvion aviones[], int lenAviones, int id);
