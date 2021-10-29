
#include "vuelo.h"


int inicializarVuelos(eVuelo vuelos[], int lenVuelos){
	int exito = 0;

	if (vuelos != NULL && lenVuelos > 0){
		for (int i = 0; i < lenVuelos; i++){
			vuelos[i].isEmpty = 1;
		}

		exito = 1;
	}

	return exito;
}

int buscarPosicionLibreVuelo(eVuelo vuelos[], int lenVuelos){
	int posicionLibre = -1;

	if (vuelos != NULL && lenVuelos > 0){
		for (int i = 0; i < lenVuelos; i++){
			if (vuelos[i].isEmpty){
				posicionLibre = i;
				break;
			}
		}
	}

	return posicionLibre;
}


int altaVuelo(eVuelo vuelos[], int lenVuelos, eAvion aviones[], int lenAviones, eAerolinea aerolineas[], int lenAerolineas, eTipo tipos[], int lenTipos, eDestino destinos[], int lenDestinos, int* pIdAvion){
	int exito = 0;
	int indiceLibre;
	eVuelo auxVuelo;

	if (vuelos != NULL && lenVuelos > 0 && aviones != NULL && lenAviones > 0 && aerolineas != NULL && lenAerolineas > 0 && tipos != NULL && lenTipos > 0 && destinos != NULL && lenDestinos > 0 && pIdAvion != NULL){
		puts("     *** ALTA AVION ***          \n");

		indiceLibre = buscarPosicionLibreVuelo(vuelos, lenVuelos);

		if (indiceLibre == -1){
			puts("No hay lugar\n");
		}
		else{
			auxVuelo.id = *pIdAvion;
			*pIdAvion += 1;

			mostrarAviones(aviones, lenAviones, aerolineas, lenAerolineas, tipos, lenTipos);
			getInt("Ingresar ID avion: ", &auxVuelo.idAvion);
			//PIDO AVION HASTA TENER UNO VALIDO
			while (!validarIdAvion(aviones, lenAviones, auxVuelo.idAvion)){
				getInt("Avion invalido. Ingrese ID Avion: ", &auxVuelo.idAvion);
			}

			mostrarDestinos(destinos, lenDestinos);
			getInt("Ingresar ID Destino: ", &auxVuelo.idDestino);
			while (!validarIdDestino(destinos, lenDestinos, auxVuelo.idDestino)){
				getInt("Destino invalido. Ingresar ID Destino: ", &auxVuelo.idDestino);
			}

			auxVuelo.isEmpty = 0;

			vuelos[indiceLibre] = auxVuelo;
		}
	}

	return exito;
}


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
