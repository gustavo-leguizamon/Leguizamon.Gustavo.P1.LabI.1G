#include "avion.h"

#include "data.h"
#include "swap.h"


int hardcodeAviones(eAvion aviones[], int lenAviones, int cantidad, int* pId){
	int contador = -1;

	if (aviones != NULL && lenAviones > 0 && cantidad >= 0 && cantidad <= lenAviones && pId != NULL){
		contador = 0;
		for (int i = 0; i < cantidad; i++){
			aviones[i].id = *pId;
			*pId += 1;
			aviones[i].idAerolinea  = idAerolineas[i];
			aviones[i].idTipo = idTipos[i];
			aviones[i].capacidad = capacidades[i];
			aviones[i].isEmpty = 0;
			contador++;
		}
	}

	return contador;
}

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

			exito = 1;
		}
	}

	return exito;
}


int modificarAvion(eAvion aviones[], int lenAviones, eAerolinea aerolineas[], int lenAerolineas, eTipo tipos[], int lenTipos){
	int exito = 0;
	int indiceAvion;
	int id;
	char confirma = 'n';
	int lenColumns = 4;
	char columns[4][31] = { "ID", "AEROLINEA", "TIPO", "CAPACIDAD" };
	int lengths[4] = { 6, 22, 22, 11 };

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
			printHeader(columns, lengths, lenColumns);
			mostrarAvion(aviones[indiceAvion], aerolineas, lenAerolineas, tipos, lenTipos);
			printFooter(lengths, lenColumns);
			getChar("Confirma la modificacion? Ingrese s/n: ", &confirma);
			if (confirma == 's'){
				puts("");
				switch(menuModificacion()){
					case optTipo:
						mostrarTipos(tipos, lenTipos);
						getInt("Ingrese ID tipo: ", &aviones[indiceAvion].idTipo);
						while (!validarIdTipo(tipos, lenTipos, aviones[indiceAvion].idTipo)){
							getInt("ID invalido. Ingrese ID tipo: ", &aviones[indiceAvion].idTipo);
						}
						exito = 1;
						break;
					case optCapacidad:
						mostrarTipos(tipos, lenTipos);
						getInt("Ingresar nueva capacidad entre 10 y 300: ", &aviones[indiceAvion].capacidad);
						while (!validarCapacidad(aviones[indiceAvion].capacidad)){
							getInt("Capacidad invalida. Ingrese capacidad entre 10 y 300: ", &aviones[indiceAvion].capacidad);
						}
						exito = 1;
						break;
					default:
						puts("Opcion invalida");
						break;
				}
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
	int lenColumns = 4;
	char columns[4][31] = { "ID", "AEROLINEA", "TIPO", "CAPACIDAD" };
	int lengths[4] = { 6, 22, 22, 11 };

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
			printHeader(columns, lengths, lenColumns);
			mostrarAvion(aviones[indiceAvion], aerolineas, lenAerolineas, tipos, lenTipos);
			printFooter(lengths, lenColumns);
			getChar("Confirma la BAJA? Ingrese s/n: ", &confirma);
			if (confirma == 's'){
				aviones[indiceAvion].isEmpty = 1;
				exito = 1;
			}
			else{
				puts("Baja cancelada por el usuario\n");
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
		printf("| %04d | %-20s | %-20s | %9d |\n", avion.id,
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
		ordenarAviones(aviones, lenAviones, aerolineas, lenAerolineas, tipos, lenTipos);

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


int ordenarAviones(eAvion aviones[], int lenAviones, eAerolinea aerolineas[], int lenAerolineas, eTipo tipos[], int lenTipos){
	int exito = 0;
	char aerolineaAviones[lenAviones][20];
	char tipoAviones[lenAviones][20];
	eAvion aux;


	if (aviones != NULL && lenAviones > 0 && aerolineas != NULL && lenAerolineas > 0 && tipos != NULL && lenTipos > 0){
		for (int i = 0; i < lenAviones; i++){
			if (!aviones[i].isEmpty){
				cargarDescripcionAerolinea(aerolineas, lenAerolineas, aviones[i].idAerolinea, aerolineaAviones[i]);
				cargarDescripcionTipo(tipos, lenTipos, aviones[i].idTipo, tipoAviones[i]);
			}
		}

		for (int i = 0; i < lenAviones - 1; i++){
			for (int j = i + 1; j < lenAviones; j++){
				if (!aviones[i].isEmpty){
					if ((strcmp(aerolineaAviones[i], aerolineaAviones[j]) > 0) ||
						(strcmp(aerolineaAviones[i], aerolineaAviones[j]) == 0 && strcmp(tipoAviones[i], tipoAviones[j]) < 0)){
						aux = aviones[i];
						aviones[i] = aviones[j];
						aviones[j] = aux;
					}
				}
			}
		}

		exito = 1;
	}

	return exito;
}




int buscarAvionPorId(eAvion aviones[], int lenAviones, int id){
	int indiceEncontrado = -1;

	if (aviones != NULL && lenAviones > 0){
		for (int i = 0; i < lenAviones; i++){
			if (!aviones[i].isEmpty && aviones[i].id == id){
				indiceEncontrado = i;
				break;
			}
		}
	}

	return indiceEncontrado;
}

/*
int cargarCapacidadAvion(eAvion aviones[], int lenAvion, int idAvion, int* pCapacidad){
	int success = 0;
	int flag = 1;

	if (aviones != NULL && lenAvion > 0 && pCapacidad != NULL){
		success = 1;
		for (int i = 0; i < lenAvion; i++){
			if (aviones[i].id == idAvion){
				*pCapacidad = aviones[i].capacidad;
				flag = 0;
				break;
			}
		}
		if (flag){
			success = -1;
		}
	}

	return success;
}
*/

/*
int obtenerAvionPorId(eAvion aviones[], int lenAviones, int idAvion, eAvion* pAvion){
	int exito = 0;

	if (aviones != NULL && lenAviones > 0 && pAvion != NULL){
		for (int i = 0; i < lenAviones; i++){
			if (!aviones[i].isEmpty && aviones[i].id == idAvion){
				*pAvion = aviones[i];
			}
		}

		exito = 1;
	}

	return exito;
}
*/



//INFORMES
int mostrarAvionesPorAerolinea(eAvion aviones[], int lenAviones, eAerolinea aerolineas[], int lenAerolineas, eTipo tipos[], int lenTipos){
	int success = 0;
	int lenColumns = 4;
	char columns[4][31] = { "ID", "AEROLINEA", "TIPO", "CAPACIDAD" };
	int lengths[4] = { 6, 22, 22, 11 };
	int hay = 0;
	int idAerolinea;
	char descripcionAerolinea[20];

	if (aviones != NULL && lenAviones > 0 && aerolineas != NULL && lenAerolineas > 0 && tipos != NULL && lenTipos > 0){

		mostrarAerolineas(aerolineas, lenAerolineas);

		getInt("Ingrese ID de Aerolinea: ", &idAerolinea);
		while (!validarIdAerolinea(aerolineas, lenAerolineas, idAerolinea)){
			getInt("ID invalido. Ingrese ID de Aerolinea: ", &idAerolinea);
		}

		printHeader(columns, lengths, lenColumns);
		for (int i = 0; i < lenAviones; i++){
			if (!aviones[i].isEmpty && aviones[i].idAerolinea == idAerolinea){
				mostrarAvion(aviones[i], aerolineas, lenAerolineas, tipos, lenTipos);
				printFooter(lengths, lenColumns);
				hay = 1;
			}
		}

		if (hay){
			puts(""); //DEJO ESPACIO EN BLANCO
		}
		else{
			cargarDescripcionAerolinea(aerolineas, lenAerolineas, idAerolinea, descripcionAerolinea);
			printf("No hay aviones para mostrar en la aerolinea: %s\n", descripcionAerolinea);
		}

		success = 1;
	}

	return success;
}


int mostrarAvionesPorTipo(eAvion aviones[], int lenAviones, eAerolinea aerolineas[], int lenAerolineas, eTipo tipos[], int lenTipos){
	int success = 0;
	int lenColumns = 4;
	char columns[4][31] = { "ID", "AEROLINEA", "TIPO", "CAPACIDAD" };
	int lengths[4] = { 6, 22, 22, 11 };
	int hay = 0;
	int idTipo;
	char descripcionTipo[20];

	if (aviones != NULL && lenAviones > 0 && aerolineas != NULL && lenAerolineas > 0 && tipos != NULL && lenTipos > 0){

		mostrarTipos(tipos, lenTipos);

		getInt("Ingrese ID de Tipo: ", &idTipo);
		while (!validarIdTipo(tipos, lenTipos, idTipo)){
			getInt("ID invalido. Ingrese ID de Tipo: ", &idTipo);
		}

		printHeader(columns, lengths, lenColumns);
		for (int i = 0; i < lenAviones; i++){
			if (!aviones[i].isEmpty && aviones[i].idTipo == idTipo){
				mostrarAvion(aviones[i], aerolineas, lenAerolineas, tipos, lenTipos);
				printFooter(lengths, lenColumns);
				hay = 1;
			}
		}

		if (hay){
			puts(""); //DEJO ESPACIO EN BLANCO
		}
		else{
			cargarDescripcionAerolinea(aerolineas, lenAerolineas, idTipo, descripcionTipo);
			printf("No hay aviones para mostrar con el tipo: %s\n", descripcionTipo);
		}

		success = 1;
	}

	return success;
}



int mostrarPorcentajeAvionesPorAerolinea(eAvion aviones[], int lenAviones, eAerolinea aerolineas[], int lenAerolineas, int idAerolinea, int idTipo){
	int success = 0;
	char descripcionAerolinea[20];
	int contadorAvionesDelTipo = 0;
	int contadorAvionesDeAerolinea = 0;
	float porcentaje;

	if (aviones != NULL && lenAviones > 0 && aerolineas != NULL && lenAerolineas > 0){
		for (int i = 0; i < lenAviones; i++){
			if (!aviones[i].isEmpty && aviones[i].idAerolinea == idAerolinea){
				contadorAvionesDeAerolinea++;
				if (aviones[i].idTipo == idTipo){
					contadorAvionesDelTipo++;
				}
			}
		}

		cargarDescripcionAerolinea(aerolineas, lenAerolineas, idAerolinea, descripcionAerolinea);
		if (contadorAvionesDelTipo > 0 && contadorAvionesDeAerolinea > 0){
			porcentaje = (float)contadorAvionesDelTipo / contadorAvionesDeAerolinea * 100;
			printf("Porcentaje de aviones JET en %s: %.2f porciento\n\n", descripcionAerolinea, porcentaje);
		}
		else{
			printf("No hay aviones JET en la aerolinea: %s\n\n", descripcionAerolinea);
		}

		success  = 1;
	}

	return success;
}


//3
int mostrarPorcentajeAvionesJetAerolineas(eAvion aviones[], int lenAviones, eAerolinea aerolineas[], int lenAerolineas){
	int success = 0;
	int idTipoJet = 3000;

	if (aviones != NULL && lenAviones > 0 && aerolineas != NULL && lenAerolineas > 0){

		puts("    *** PORCENTAJE AVIONES JET POR AEROLINEA ***     ");
		for (int i = 0; i < lenAerolineas; i++){
			if (!aerolineas[i].isEmpty){
				mostrarPorcentajeAvionesPorAerolinea(aviones, lenAviones, aerolineas, lenAerolineas, aerolineas[i].id, idTipoJet);
			}
		}

		success  = 1;
	}

	return success;
}


//5
int mostrarAerolineaConMasPasajeros(eAvion aviones[], int lenAviones, eAerolinea aerolineas[], int lenAerolineas){
	int exito = 0;
	int cantidades[lenAerolineas];
	int mayorCantidad = 0;

	if (aviones != NULL && lenAviones > 0 && aerolineas != NULL && lenAerolineas > 0){
		puts("    *** AEROLINEA CON MAS PASAJEROS ***     ");

		for (int i = 0; i < lenAerolineas; i++){
			cantidades[i] = 0;

			for (int j = 0; j < lenAviones; j++){
				if (!aviones[j].isEmpty && aviones[j].idAerolinea == aerolineas[i].id && aviones[j].capacidad > cantidades[i]){
					cantidades[i] += aviones[j].capacidad;
				}
			}
		}

		for (int i = 0; i < lenAerolineas; i++){
			if (i == 0 || cantidades[i] > mayorCantidad){
				mayorCantidad = cantidades[i];
			}
		}

		//YA TENGO LA CANTIDAD MENOR
		for (int i = 0; i < lenAerolineas; i++){
			if (cantidades[i] == mayorCantidad){
				printf("Aerolinea: %s\n", aerolineas[i].descripcion);
			}
		}
		puts("");

		exito  = 1;
	}

	return exito;
}



//6
int mostrarAerolineaConMenosAviones(eAvion aviones[], int lenAviones, eAerolinea aerolineas[], int lenAerolineas){
	int exito = 0;
	int cantidades[lenAerolineas];
	int menorCantidad = 0;

	if (aviones != NULL && lenAviones > 0 && aerolineas != NULL && lenAerolineas > 0){
		puts("    *** AEROLINEA CON MENOS AVIONES ***     ");

		for (int i = 0; i < lenAerolineas; i++){
			cantidades[i] = 0;

			for (int j = 0; j < lenAviones; j++){
				if (!aviones[j].isEmpty && aviones[j].idAerolinea == aerolineas[i].id){
					cantidades[i]++;
				}
			}
		}

		for (int i = 0; i < lenAerolineas; i++){
			if (i == 0 || cantidades[i] < menorCantidad){
				menorCantidad = cantidades[i];
			}
		}

		//YA TENGO LA CANTIDAD MENOR
		for (int i = 0; i < lenAerolineas; i++){
			if (cantidades[i] == menorCantidad){
				printf("Aerolinea: %s\n", aerolineas[i].descripcion);
			}
		}
		puts("");

		exito  = 1;
	}

	return exito;
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
