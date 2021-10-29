#include <stdio.h>
#include <stdlib.h>

#include "fecha.h"
#include "avion.h"
#include "aerolinea.h"
#include "destino.h"

#ifndef VUELO_H_
#define VUELO_H_

typedef struct {
	int id;
	int idAvion;
	int idDestino;
	eFecha fecha;
	int isEmpty;
} eVuelo;

#endif /* VUELO_H_ */

int inicializarVuelos(eVuelo vuelos[], int lenVuelos);

int buscarPosicionLibreVuelo(eVuelo vuelos[], int lenVuelos);

int altaVuelo(eVuelo vuelos[], int lenVuelos, eAvion aviones[], int lenAviones, eAerolinea aerolineas[], int lenAerolineas, eTipo tipos[], int lenTipos, eDestino destinos[], int lenDestinos, int* pIdVuelo);

void mostrarVuelo(eVuelo vuelo, eAvion aviones[], int lenAviones, eAerolinea aerolineas[], int lenAerolineas, eTipo tipos[], int lenTipos, eDestino destinos[], int lenDestinos);

int mostrarVuelos(eVuelo vuelos[], int lenVuelos, eAvion aviones[], int lenAviones, eAerolinea aerolineas[], int lenAerolineas, eTipo tipos[], int lenTipos, eDestino destinos[], int lenDestinos);
