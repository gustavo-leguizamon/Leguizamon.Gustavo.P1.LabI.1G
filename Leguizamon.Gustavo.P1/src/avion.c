#include "avion.h"


int inicializarAviones(eAvion aviones[], int lenAviones){
	int exito = 0;

	if (aviones != NULL && lenAviones > 0){
		for (int i = 0; i < lenAviones; i++){
			aviones[i].isEmpty = 1;
		}

		exito = 1;
	}

	return exito;
}

int buscarPosicionLibreAvion(eAvion aviones[], int lenAviones){
	int posicionLibre = -1;

	if (aviones != NULL && lenAviones > 0){
		for (int i = 0; i < lenAviones; i++){
			if (aviones[i].isEmpty){
				posicionLibre = i;
				break;
			}
		}
	}

	return posicionLibre;
}

int altaAvion(eAvion aviones[], int lenAviones, eAerolinea aerolineas[], int lenAerolineas, eTipo tipos[], int lenTipos, int* pIdAvion){
	int exito = 0;
	int indiceLibre;
	eAvion auxAvion;

	if (aviones != NULL && lenAviones > 0 && aerolineas != NULL && lenAerolineas > 0 && tipos != NULL && lenTipos > 0 && pIdAvion != NULL){
		puts("     *** ALTA AVION ***          \n");

		indiceLibre = buscarPosicionLibreAvion(aviones, lenAviones);

		if (indiceLibre == -1){
			puts("No hay lugar\n");
		}
		else{
			auxAvion.id = *pIdAvion;
			*pIdAvion += 1;

			mostrarTipos(tipos, lenTipos);
			getInt("Ingresar ID Tipo: ", &auxAvion.idTipo);
			//PIDO TIPO HASTA TENER UNO VALIDO
			while (!validarIdTipo(tipos, lenTipos, auxAvion.idTipo)){
				getInt("Tipo invalido. Ingrese ID Tipo: ", &auxAvion.idTipo);
			}

			getInt("Ingresar capacidad entre 10 y 300: ", &auxAvion.capacidad);
			while (!validarCapacidad(auxAvion.capacidad)){
				getInt("Capacidad invalida. Ingrese capacidad entre 10 y 300: ", &auxAvion.capacidad);
			}

			mostrarAerolineas(aerolineas, lenAerolineas);
			getInt("Ingrese ID aerolinea: ", &auxAvion.idAerolinea);
			//PIDO AEROLINEA HASTA TENER UNA VALIDA
			while (!validarIdAerolinea(aerolineas, lenAerolineas, auxAvion.idAerolinea)){
				getInt("Aerolinea invalida. Ingrese ID aerolinea: ", &auxAvion.idAerolinea);
			}

			auxAvion.isEmpty = 0;

			aviones[indiceLibre] = auxAvion;
		}
	}

	return exito;
}


int modificarAvion(eAvion aviones[], int lenAviones, eAerolinea aerolineas[], int lenAerolineas, eTipo tipos[], int lenTipos){
	int exito = 0;
	int indiceAvion;
	int id;
	char confirma = 'n';

	if (aviones != NULL && lenAviones > 0 && aerolineas != NULL && lenAerolineas > 0 && tipos != NULL && lenTipos > 0){
		puts("     *** MODIFICAR AVION ***          \n");

		//MUESTRO LOS AVIONES PARA QUE EL USUARIO PUEDA VERLOS Y SABER CUAL MODIFICAR
		mostrarAviones(aviones, lenAviones, aerolineas, lenAerolineas, tipos, lenTipos);

		getInt("Ingrese el ID del avion: ", &id);
		/*
		while (!validarIdAvion(aviones, lenAviones, id)){
			getInt("ID invalido. Ingrese el ID del avion: ", &id);
		}
		*/

		indiceAvion = buscarAvionPorId(aviones, lenAviones, id);

		if (indiceAvion == -1){
			printf("No existe avion con id: %d\n", id);
		}
		else{
			mostrarAvion(aviones[indiceAvion], aerolineas, lenAerolineas, tipos, lenTipos);
			getChar("Confirma la modificacion? Ingrese s/n: ", &confirma);
			if (confirma == 's'){
				switch(menuModificacion()){
					case optTipo:
						mostrarTipos(tipos, lenTipos);
						getInt("Ingrese ID tipo: ", &aviones[indiceAvion].idTipo);
						while (!validarIdTipo(tipos, lenTipos, aviones[indiceAvion].idTipo)){
							getInt("ID invalido. Ingrese ID tipo: ", &aviones[indiceAvion].idTipo);
						}
						break;
					case optCapacidad:
						mostrarTipos(tipos, lenTipos);
						getInt("Ingresar nueva capacidad entre 10 y 300: ", &aviones[indiceAvion].capacidad);
						while (!validarCapacidad(aviones[indiceAvion].capacidad)){
							getInt("Capacidad invalida. Ingrese capacidad entre 10 y 300: ", &aviones[indiceAvion].capacidad);
						}
						break;
					default:
						puts("Opcion invalida");
						break;
				}

				exito = 1;
			}
			else{
				puts("Modificacion cancelada por el usuario");
			}
		}
	}

	return exito;
}


int bajaAvion(eAvion aviones[], int lenAviones, eAerolinea aerolineas[], int lenAerolineas, eTipo tipos[], int lenTipos){
	int exito = 0;
	int indiceAvion;
	int id;
	char confirma = 'n';

	if (aviones != NULL && lenAviones > 0 && aerolineas != NULL && lenAerolineas > 0 && tipos != NULL && lenTipos > 0){
		puts("     *** BAJA AVION ***          \n\n");

		//MUESTRO LOS AVIONES PARA QUE EL USUARIO PUEDA VERLOS Y SABER CUAL BORRAR
		mostrarAviones(aviones, lenAviones, aerolineas, lenAerolineas, tipos, lenTipos);

		getInt("Ingrese el ID del avion: ", &id);

		indiceAvion = buscarAvionPorId(aviones, lenAviones, id);

		if (indiceAvion == -1){
			printf("No existe avion con ID: %d\n", id);
		}
		else{
			mostrarAvion(aviones[indiceAvion], aerolineas, lenAerolineas, tipos, lenTipos);
			getChar("Confirma la BAJA? Ingrese s/n: ", &confirma);
			if (confirma == 's'){
				aviones[indiceAvion].isEmpty = 1;
				exito = 1;
			}
			else{
				puts("Baja cancelada por el usuario");
			}
		}
	}

	return exito;
}


void mostrarAvion(eAvion avion, eAerolinea aerolineas[], int lenAerolineas, eTipo tipos[], int lenTipos){
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

int mostrarAviones(eAvion aviones[], int lenAviones, eAerolinea aerolineas[], int lenAerolineas, eTipo tipos[], int lenTipos){
	int success = 0;
	int lenColumns = 4;
	char columns[4][31] = { "ID", "AEROLINEA", "TIPO", "CAPACIDAD" };
	int lengths[4] = { 6, 22, 22, 11 };
	int hay = 0;

	if (aviones != NULL && lenAviones > 0 && aerolineas != NULL && lenAerolineas > 0 && tipos != NULL && lenTipos > 0){
		printHeader(columns, lengths, lenColumns);
		for (int i = 0; i < lenAviones; i++){
			if (!aviones[i].isEmpty){
				mostrarAvion(aviones[i], aerolineas, lenAerolineas, tipos, lenTipos);
				printFooter(lengths, lenColumns);
				hay = 1;
			}
		}

		if (hay){
			puts(""); //DEJO ESPACIO EN BLANCO
		}
		else{
			puts("No hay aviones par mostrar\n");
		}

		success = 1;
	}

	return success;
}

/*
int ordenarAviones(eAvion aviones[], int lenAviones){
	int exito = 0;

	if (aviones != NULL && lenAviones > 0){
		for (int i = 0; i < lenAviones - 1; i++){
			for (int j = i + 1; j < lenAviones; j++){
				if ((aviones[i].sexo > aviones[j].sexo) ||
					(aviones[i].sexo == aviones[j].sexo && strcmp(aviones[i].nombre, aviones[j].nombre) > 0)){
					swapPersona(&aviones[i], &aviones[j]);
				}
			}
		}

		exito = 1;
	}

	return exito;
}
*/



int buscarAvionPorId(eAvion aviones[], int lenAviones, int id){
	int indiceEncontrado = -1;

	if (aviones != NULL && lenAviones > 0){
		for (int i = 0; i < lenAviones; i++){
			if (!aviones[i].isEmpty && aviones[i].id == id){
				indiceEncontrado = i;
				break;
			}
		}

		if (indiceEncontrado == -1){
			printf("No existe avion con ID: %d\n", id);
		}
	}

	return indiceEncontrado;
}


//VALIDACIONES
int validarCapacidad(int capacidad){
	return capacidad >= 10 && capacidad <= 300;
}

int validarIdAvion(eAvion aviones[], int lenAviones, int id){
	int success = 0;

	if (aviones != NULL && lenAviones > 0){
		for (int i = 0; i < lenAviones; i++){
			if (aviones[i].id == id){
				success = 1;
				break;
			}
		}
	}

	return success;
}
