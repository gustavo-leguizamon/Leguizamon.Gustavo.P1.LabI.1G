
#include "vuelo.h"

/*
void mostrarVuelo(eVuelo vuelos, eAerolinea aerolineas[], int lenAerolineas, eTipo tipos[], int lenTipos, eAvion aviones[], int lenAviones){
	char descripcionAerolinea[20];
	char descripcionTipo[20];

	if (cargarDescripcionAerolinea(aerolineas, lenAerolineas, avion.idAerolinea, descripcionAerolinea) == 1 &&
		cargarDescripcionTipo(tipos, lenTipos, avion.idTipo, descripcionTipo) == 1){
		printf("| %04d | %-20s | %-20s | %3d |\n", avion.id,
												   descripcionAerolinea,
											       descripcionTipo,
												   avion.capacidad);
		//puts("|_______|_______________________|_______|_______|__________|_______________________|");
	}
}
*/

/*
int mostrarAviones(eAvion aviones[], int lenAviones, eAerolinea aerolineas[], int lenAerolineas, eTipo tipos[], int lenTipos){
	int success = 0;
	int lenColumns = 4;
	char columns[4][31] = { "ID", "AEROLINEA", "TIPO", "CAPACIDAD" };
	int lengths[4] = { 6, 22, 22, 5 };

	if (aviones != NULL && lenAviones > 0 && aerolineas != NULL && lenAerolineas > 0 && tipos != NULL && lenTipos > 0){
		printHeader(columns, lengths, lenColumns);
		for (int i = 0; i < lenAviones; i++){
			//printf("| %4d | %-20s | %-20s | %3d |\n", aviones[i].id, aviones[i].descripcion);
			mostrarAvion(aviones[i], aerolineas, lenAerolineas, tipos, lenTipos);
		}
		printFooter(lengths, lenColumns);

		success = 1;
	}

	return success;
}
*/
