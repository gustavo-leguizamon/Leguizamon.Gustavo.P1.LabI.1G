#include <stdio.h>
#include <stdlib.h>

#include "output.h"

#ifndef DESTINO_H_
#define DESTINO_H_

typedef struct {
	int id;
	char descripcion[25];
	float precio;
} eDestino;

#endif /* DESTINO_H_ */


void mostrarDestino(eDestino destino);

int mostrarDestinos(eDestino destinos[], int lenDestinos);

