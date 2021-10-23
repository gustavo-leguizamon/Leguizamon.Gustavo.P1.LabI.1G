#include <stdio.h>
#include <stdlib.h>

#include "output.h"

#ifndef AEROLINEA_H_
#define AEROLINEA_H_

typedef struct {
	int id;
	char descripcion[20];
} eAerolinea;

#endif /* AEROLINEA_H_ */


int mostrarAerolineas(eAerolinea aerolineas[], int lenAerolineas);

int cargarDescripcionAerolinea(eAerolinea aerolineas[], int lenAerolineas, int idAerolinea, char descripcion[]);


//VALIDACIONES
int validarIdAerolinea(eAerolinea aerolineas[], int lenAerolineas, int id);