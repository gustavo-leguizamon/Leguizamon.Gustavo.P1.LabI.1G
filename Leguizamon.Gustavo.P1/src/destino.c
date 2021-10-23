
#include "destino.h"


void mostrarDestino(eDestino destino){
	printf("| %04d | %-25s | $%8.2f |\n", destino.id,
										  destino.descripcion,
										  destino.precio);
}

int mostrarDestinos(eDestino destinos[], int lenDestinos){
	int success = 0;
	int lenColumns = 3;
	char columns[3][31] = { "ID", "DESTINO", "PRECIO" };
	int lengths[3] = { 6, 27, 14 };

	if (destinos != NULL && lenDestinos > 0){
		printHeader(columns, lengths, lenColumns);
		for (int i = 0; i < lenDestinos; i++){
			//printf("| %4d | %-20s | %-20s | %3d |\n", aviones[i].id, aviones[i].descripcion);
			mostrarDestino(destinos[i]);
		}
		printFooter(lengths, lenColumns);

		success = 1;
	}

	return success;
}
