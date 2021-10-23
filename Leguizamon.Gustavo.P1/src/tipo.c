
#include "tipo.h"


int mostrarTipos(eTipo tipos[], int lenTipos){
	int success = 0;
	int lenColumns = 2;
	char columns[2][31] = { "ID", "TIPO" };
	int lengths[2] = { 6, 22 };

	if (tipos != NULL && lenTipos > 0){
		printHeader(columns, lengths, lenColumns);
		for (int i = 0; i < lenTipos; i++){
			printf("| %4d | %-20s |\n", tipos[i].id, tipos[i].descripcion);
		}
		printFooter(lengths, lenColumns);

		success = 1;
	}

	return success;
}


int cargarDescripcionTipo(eTipo tipos[], int lenTipos, int idTipo, char descripcion[]){
	int success = 0;
	int flag = 1;

	if (tipos != NULL && lenTipos > 0 && descripcion != NULL){
		success = 1;
		for (int i = 0; i < lenTipos; i++){
			if (tipos[i].id == idTipo){
				strcpy(descripcion, tipos[i].descripcion);
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
int validarIdTipo(eTipo tipos[], int lenTipos, int id){
	int success = 0;

	if (tipos != NULL && lenTipos > 0){
		for (int i = 0; i < lenTipos; i++){
			if (tipos[i].id == id){
				success = 1;
				break;
			}
		}
	}

	return success;
}
