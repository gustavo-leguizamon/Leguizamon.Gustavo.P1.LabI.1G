#include <stdio.h>
#include <stdlib.h>

#include "input.h"
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

int hardcodeAviones(eAvion aviones[], int lenAviones, int cantidad, int* pId);

int inicializarAviones(eAvion aviones[], int lenAviones);

int buscarPosicionLibreAvion(eAvion personas[], int lenAviones);

int altaAvion(eAvion aviones[], int lenAviones, eAerolinea aerolineas[], int lenAerolineas, eTipo tipos[], int lenTipos, int* pIdAvion);

int modificarAvion(eAvion aviones[], int lenAviones, eAerolinea aerolineas[], int lenAerolineas, eTipo tipos[], int lenTipos);

int bajaAvion(eAvion aviones[], int lenAviones, eAerolinea aerolineas[], int lenAerolineas, eTipo tipos[], int lenTipos);

void mostrarAvion(eAvion avion, eAerolinea aerolineas[], int lenAerolineas, eTipo tipos[], int lenTipos);

int mostrarAviones(eAvion aviones[], int lenAviones, eAerolinea aerolineas[], int lenAerolineas, eTipo tipos[], int lenTipos);

int buscarAvionPorId(eAvion aviones[], int lenAviones, int id);

//VALIDACIONES
int validarCapacidad(int capacidad);

int validarIdAvion(eAvion aviones[], int lenAviones, int id);
