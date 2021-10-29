#include <stdio.h>
#include <stdlib.h>

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

int inicializarDestinos(eDestino destinos[], int lenDestinos);

void mostrarDestino(eDestino destino);

int mostrarDestinos(eDestino destinos[], int lenDestinos);

int validarIdDestino(eDestino destinos[], int lenDestinos, int id);
