
#include "aerolinea.h"

/*
int hardcodeAerolineas(eAerolinea aerolineas[], int lenAerolineas, int cantidad, int* pId){
	int contador = -1;

	if (aerolineas != NULL && lenAerolineas > 0 && cantidad >= 0 && cantidad <= lenAerolineas && pId != NULL){
		contador = 0;
		for (int i = 0; i < cantidad; i++){
			aerolineas[i].id = *pId;
			*pId += 1;
			strcpy(aerolineas[i].descripcion, nombreAerolineas[i]);
			aerolineas[i].isEmpty = 0;
			contador++;
		}
	}

	return contador;
}

int inicializarAerolineas(eAerolinea aerolineas[], int lenAerolineas){
	int exito = 0;

	if (aerolineas != NULL && lenAerolineas > 0){
		for (int i = 0; i < lenAerolineas; i++){
			aerolineas[i].isEmpty = 1;
		}

		exito = 1;
	}

	return exito;
}
*/

int mostrarAerolineas(eAerolinea aerolineas[], int lenAerolineas){
	int success = 0;
	int lenColumns = 2;
	char columns[2][31] = { "ID", "AEROLINEA" };
	int lengths[2] = { 6, 22 };
	int hay = 0;

	if (aerolineas != NULL && lenAerolineas > 0){
		printHeader(columns, lengths, lenColumns);
		for (int i = 0; i < lenAerolineas; i++){
			if (!aerolineas[i].isEmpty){
				printf("| %4d | %-20s |\n", aerolineas[i].id, aerolineas[i].descripcion);
				printFooter(lengths, lenColumns);
				hay = 1;
			}
		}

		if (hay){
			puts(""); //DEJO ESPACIO EN BLANCO
		}
		else{
			puts("No hay aerolineas par mostrar\n");
		}

		success = 1;
	}

	return success;
}



int cargarDescripcionAerolinea(eAerolinea aerolineas[], int lenAerolineas, int idAerolinea, char descripcion[]){
	int success = 0;
	int flag = 1;

	if (aerolineas != NULL && lenAerolineas > 0 && descripcion != NULL){
		success = 1;
		for (int i = 0; i < lenAerolineas; i++){
			if (aerolineas[i].id == idAerolinea){
				strcpy(descripcion, aerolineas[i].descripcion);
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



//VALIDACIONES
int validarIdAerolinea(eAerolinea aerolineas[], int lenAerolineas, int id){
	int success = 0;

	if (aerolineas != NULL && lenAerolineas > 0){
		for (int i = 0; i < lenAerolineas; i++){
			if (aerolineas[i].id == id){
				success = 1;
				break;
			}
		}
	}

	return success;
}
