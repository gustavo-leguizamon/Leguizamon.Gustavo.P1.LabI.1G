
#include "destino.h"

/*
int hardcodeDestinos(eDestino destinos[], int lenDestinos, int cantidad, int* pId){
	int contador = -1;

	if (destinos != NULL && lenDestinos > 0 && cantidad >= 0 && cantidad <= lenDestinos && pId != NULL){
		contador = 0;
		for (int i = 0; i < cantidad; i++){
			destinos[i].id = *pId;
			*pId += 1;
			strcpy(destinos[i].descripcion, nombreDestinos[i]);
			destinos[i].precio  = precioDestinos[i];
			destinos[i].isEmpty = 0;
			contador++;
		}
	}

	return contador;
}


int inicializarDestinos(eDestino destinos[], int lenDestinos){
	int exito = 0;

	if (destinos != NULL && lenDestinos > 0){
		for (int i = 0; i < lenDestinos; i++){
			destinos[i].isEmpty = 1;
		}

		exito = 1;
	}

	return exito;
}
*/

void mostrarDestino(eDestino destino){
	printf("| %04d | %-25s | $%11.2f |\n", destino.id,
										  destino.descripcion,
										  destino.precio);
}

int mostrarDestinos(eDestino destinos[], int lenDestinos){
	int success = 0;
	int lenColumns = 3;
	char columns[3][31] = { "ID", "DESTINO", "PRECIO" };
	int lengths[3] = { 6, 27, 14 };
	int hay = 0;

	if (destinos != NULL && lenDestinos > 0){
		printHeader(columns, lengths, lenColumns);
		for (int i = 0; i < lenDestinos; i++){
			if (!destinos[i].isEmpty){
				mostrarDestino(destinos[i]);
				printFooter(lengths, lenColumns);
				hay = 1;
			}
		}

		if (hay){
			puts(""); //DEJO ESPACIO EN BLANCO
		}
		else{
			puts("No hay destinos par mostrar\n");
		}

		success = 1;
	}

	return success;
}


int cargarDescripcionDestino(eDestino destinos[], int lenDestinos, int idDestino, char descripcion[]){
	int success = 0;
	int flag = 1;

	if (destinos != NULL && lenDestinos > 0 && descripcion != NULL){
		success = 1;
		for (int i = 0; i < lenDestinos; i++){
			if (destinos[i].id == idDestino){
				strcpy(descripcion, destinos[i].descripcion);
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



int validarIdDestino(eDestino destinos[], int lenDestinos, int id){
	int success = 0;

	if (destinos != NULL && lenDestinos > 0){
		for (int i = 0; i < lenDestinos; i++){
			if (destinos[i].id == id){
				success = 1;
				break;
			}
		}
	}

	return success;
}
