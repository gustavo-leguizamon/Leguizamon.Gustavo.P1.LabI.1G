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

int inicializarAerolineas(eAerolinea aerolineas[], int lenAerolineas);

int mostrarAerolineas(eAerolinea aerolineas[], int lenAerolineas);

int cargarDescripcionAerolinea(eAerolinea aerolineas[], int lenAerolineas, int idAerolinea, char descripcion[]);


//VALIDACIONES
int validarIdAerolinea(eAerolinea aerolineas[], int lenAerolineas, int id);
