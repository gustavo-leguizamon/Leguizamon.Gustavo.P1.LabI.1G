#include <stdio.h>
#include <stdlib.h>

#include "output.h"

#ifndef TIPO_H_
#define TIPO_H_

typedef struct {
	int id;
	char descripcion[20];
} eTipo;

#endif /* TIPO_H_ */

int mostrarTipos(eTipo tipos[], int lenTipos);

int cargarDescripcionTipo(eTipo tipos[], int lenTipos, int idTipo, char descripcion[]);


//VALIDACIONES
int validarIdTipo(eTipo tipos[], int lenTipos, int id);
