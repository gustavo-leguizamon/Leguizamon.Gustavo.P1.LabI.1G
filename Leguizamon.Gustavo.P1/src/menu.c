#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "input.h"

int menu(){
	int opcion;

	puts("     **** ABM de aviones ***          ");
	printf("%d-Alta avion\n", optAltaAvion);
	printf("%d-Modificar avion\n", optModificarAvion);
	printf("%d-Baja avion\n", optBajaAvion);
	printf("%d-Listar aviones\n", optListarAviones);
	printf("%d-Listar aerolineas\n", optListarAerolineas);
	printf("%d-Listar tipos\n", optListarTipos);
	printf("%d-Listar destinos\n", optListarDestinos);
	printf("%d-Salir\n\n", optSalirMainMenu);
	getInt("Ingrese una opcion: ", &opcion);

	return opcion;
}

int menuModificacion(){
	int opcion;

	puts("     **** MODIFICACION ***          ");
	printf("%d-Tipo\n", optTipo);
	printf("%d-Capacidad\n", optCapacidad);
	getInt("Ingrese una opcion: ", &opcion);

	return opcion;
}
