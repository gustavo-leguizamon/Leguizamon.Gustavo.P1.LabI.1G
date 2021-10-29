#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "output.h"

#ifndef DESTINO_H_
#define DESTINO_H_

typedef struct {
	int id;
	char descripcion[25];
	float precio;
	int isEmpty;
} eDestino;

#endif /* DESTINO_H_ */

//int hardcodeDestinos(eDestino destinos[], int lenDestinos, int cantidad, int* pId);

/**
 * @brief Inicializa todos los elementos de destinos
 *
 * @param destinos
 * @param lenDestinos
 * @return
 */
int inicializarDestinos(eDestino destinos[], int lenDestinos);

void mostrarDestino(eDestino destino);

int mostrarDestinos(eDestino destinos[], int lenDestinos);

int cargarDescripcionDestino(eDestino destinos[], int lenDestinos, int idDestino, char descripcion[]);

int cargarPrecioDestino(eDestino destinos[], int lenDestinos, int idDestino, float* pPrecio);

int validarIdDestino(eDestino destinos[], int lenDestinos, int id);
