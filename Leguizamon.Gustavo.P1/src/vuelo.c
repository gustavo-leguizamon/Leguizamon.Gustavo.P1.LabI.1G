
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


int altaVuelo(eVuelo vuelos[], int lenVuelos, eAvion aviones[], int lenAviones, eAerolinea aerolineas[], int lenAerolineas, eTipo tipos[], int lenTipos, eDestino destinos[], int lenDestinos, int* pIdVuelo){
	int exito = 0;
	int indiceLibre;
	eVuelo auxVuelo;

	if (vuelos != NULL && lenVuelos > 0 && aviones != NULL && lenAviones > 0 && aerolineas != NULL && lenAerolineas > 0 && tipos != NULL && lenTipos > 0 && destinos != NULL && lenDestinos > 0 && pIdVuelo != NULL){
		puts("     *** ALTA VUELO ***          \n");

		indiceLibre = buscarPosicionLibreVuelo(vuelos, lenVuelos);

		if (indiceLibre == -1){
			puts("No hay lugar\n");
		}
		else{
			auxVuelo.id = *pIdVuelo;
			*pIdVuelo += 1;

			//SOLICITO FECHA
			getDate("Ingresar la fecha del vuelo en formato dd/mm/aaaa: ", &auxVuelo.fecha);
			//PIDO FECHA HASTA TENER UNA VALIDA
			while (!validarFecha(auxVuelo.fecha)){
				getDate("Fecha invalida. Ingresar la fecha del vuelo en formato dd/mm/aaaa: ", &auxVuelo.fecha);
			}

			puts("AVIONES DISPONIBLES");
			mostrarAviones(aviones, lenAviones, aerolineas, lenAerolineas, tipos, lenTipos);
			getInt("Ingresar ID avion: ", &auxVuelo.idAvion);
			//PIDO AVION HASTA TENER UNO VALIDO
			while (!validarIdAvion(aviones, lenAviones, auxVuelo.idAvion)){
				getInt("Avion invalido. Ingrese ID Avion: ", &auxVuelo.idAvion);
			}

			puts("");
			puts("DESTINOS DISPONIBLES");
			mostrarDestinos(destinos, lenDestinos);
			getInt("Ingresar ID Destino: ", &auxVuelo.idDestino);
			//PIDO DESTINO HASTA TENER UNO VALIDO
			while (!validarIdDestino(destinos, lenDestinos, auxVuelo.idDestino)){
				getInt("Destino invalido. Ingresar ID Destino: ", &auxVuelo.idDestino);
			}

			auxVuelo.isEmpty = 0;

			vuelos[indiceLibre] = auxVuelo;

			exito = 1;
		}
	}

	return exito;
}



void mostrarVuelo(eVuelo vuelo, eAvion aviones[], int lenAviones, eAerolinea aerolineas[], int lenAerolineas, eTipo tipos[], int lenTipos, eDestino destinos[], int lenDestinos){
	char descripcionAerolinea[20];
	char descripcionTipo[20];
	char descripcionDestino[20];
	int indiceAvion;

	indiceAvion = buscarAvionPorId(aviones, lenAviones, vuelo.idAvion);
	if (indiceAvion == -1){
		puts("No se encontro informacion del avion");
	}
	else{
		if (cargarDescripcionAerolinea(aerolineas, lenAerolineas, aviones[indiceAvion].idAerolinea, descripcionAerolinea) == 1 &&
			cargarDescripcionTipo(tipos, lenTipos, aviones[indiceAvion].idTipo, descripcionTipo) == 1 &&
			cargarDescripcionDestino(destinos, lenDestinos, vuelo.idDestino, descripcionDestino) == 1){
			printf("| %04d | %02d/%02d/%04d | %-20s | %-20s | %9d | %-20s |\n", vuelo.id,
																				vuelo.fecha.dia,
																				vuelo.fecha.mes,
																				vuelo.fecha.anio,
																			    descripcionAerolinea,
																			    descripcionTipo,
																			    aviones[indiceAvion].capacidad,
																				descripcionDestino);
			//puts("|_______|_______________________|_______|_______|__________|_______________________|");
		}
	}
}



int mostrarVuelos(eVuelo vuelos[], int lenVuelos, eAvion aviones[], int lenAviones, eAerolinea aerolineas[], int lenAerolineas, eTipo tipos[], int lenTipos, eDestino destinos[], int lenDestinos){
	int success = 0;
	int lenColumns = 6;
	char columns[6][31] = { "ID", "FECHA", "AEROLINEA", "TIPO AVION", "CAPACIDAD", "DESTINO" };
	int lengths[6] = { 6, 12, 22, 22, 11, 22 };
	int hay = 0;

	if (vuelos != NULL && lenVuelos > 0 && aviones != NULL && lenAviones > 0 && aerolineas != NULL && lenAerolineas > 0 && tipos != NULL && lenTipos > 0){
		printHeader(columns, lengths, lenColumns);
		for (int i = 0; i < lenAviones; i++){
			if (!vuelos[i].isEmpty){
				mostrarVuelo(vuelos[i], aviones, lenAviones, aerolineas, lenAerolineas, tipos, lenTipos, destinos, lenDestinos);
				printFooter(lengths, lenColumns);
				hay = 1;
			}
		}

		if (hay){
			puts(""); //DEJO ESPACIO EN BLANCO
		}
		else{
			puts("No hay vuelos par mostrar\n");
		}

		success = 1;
	}

	return success;
}

