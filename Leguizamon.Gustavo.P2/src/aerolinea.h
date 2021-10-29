#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "output.h"

#ifndef AEROLINEA_H_
#define AEROLINEA_H_

typedef struct {
	int id;
	char descripcion[20];
	int isEmpty;
} eAerolinea;

#endif /* AEROLINEA_H_ */

//int hardcodeAerolineas(eAerolinea aerolineas[], int lenAerolineas, int cantidad, int* pId);


/**
 * @brief Inicializa todos los elementos de aerolineas
 *
 * @param aerolineas eAerolinea* Array de aerolineas
 * @param lenAerolineas int Cantidad de elementos
 * @return 1: ok - 0: error
 */
int inicializarAerolineas(eAerolinea aerolineas[], int lenAerolineas);


/**
 * @brief Imprime todas las aerolineas
 *
 * @param aerolineas eAerolinea* Array de aerolineas
 * @param lenAerolineas int Cantidad de elementos
 * @return 1: ok - 0: error
 */
int mostrarAerolineas(eAerolinea aerolineas[], int lenAerolineas);


/**
 * @brief Carga la descripcion de una aerolinea
 *
 * @param aerolineas eAerolinea* Array de aerolineas
 * @param lenAerolineas int Cantidad de elementos
 * @param idAerolinea int ID aerolinea
 * @param descripcion char* Puntero donde almacenar la descripcion
 * @return 1: Existe aerolinea - 0: error NULL o tamanio de arrays - -1: No existe aerolinea
 */
int cargarDescripcionAerolinea(eAerolinea aerolineas[], int lenAerolineas, int idAerolinea, char descripcion[]);



//VALIDACIONES

/**
 * @brief Indica si existe una aerolinea segun du ID
 *
 * @param aerolineas eAerolinea* Array de aerolineas
 * @param lenAerolineas int Cantidad de elementos
 * @param id int ID de aerolinea
 * @return 1: Si existe - 0: No existe
 */
int validarIdAerolinea(eAerolinea aerolineas[], int lenAerolineas, int id);
