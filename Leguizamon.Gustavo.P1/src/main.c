#include <stdio.h>
#include <stdlib.h>

#include "aerolinea.h"
#include "avion.h"
#include "tipo.h"
#include "destino.h"
#include "vuelo.h"
#include "menu.h"

#define LEN_AEROLINEAS 5
#define LEN_TIPOS      4
#define LEN_DESTINOS   4
#define LEN_AVIONES    1000
#define LEN_VUELOS     1000



int main(void) {
	setbuf(stdout, NULL);

	//HARDCODEOS
	eAerolinea aerolineas[LEN_AEROLINEAS] = {
			{ 1000, "Lan" },
			{ 1001,	"Iberia" },
			{ 1002, "Norwegian" },
			{ 1003, "American" },
			{ 1004,	"Austral" }
	};

	eTipo tipos[LEN_TIPOS] = {
			{ 3000, "Jet" },
			{ 3001,	"Helice" },
			{ 3002, "Planeador" },
			{ 3003, "Carga" }
	};

	eDestino destinos[LEN_DESTINOS] = {
			{ 5000, "Calafate", 22250 },
			{ 5001,	"Miami", 103000 },
			{ 5002, "Madrid", 84400 },
			{ 5003, "Amsterdam", 95600 }
	};

	eAvion aviones[LEN_AVIONES];
	eVuelo vuelos[LEN_VUELOS];
	int nextIdAvion = 2000;
	int seguir = 1;

	if (inicializarAviones(aviones, LEN_AVIONES) &&
		inicializarVuelos(vuelos, LEN_VUELOS) &&
		inicializarAerolineas(aerolineas, LEN_AEROLINEAS)){
		do{
			//system("clear");

			switch(menu()){
				case optAltaAvion:
					if (!altaAvion(aviones, LEN_AVIONES, aerolineas, LEN_AEROLINEAS, tipos, LEN_TIPOS, &nextIdAvion)){
						printf("No se pudo realizar el alta de avion\n");
					}
					else{
						printf("Alta de avion exitosa!!!\n\n");
					}
					break;
				case optModificarAvion:
					if (modificarAvion(aviones, LEN_AVIONES, aerolineas, LEN_AEROLINEAS, tipos, LEN_TIPOS)){
						puts("Modificacion de avion exitosa!!!");
					}
					else{
						puts("No se pudo modificar");
					}
					break;
				case optBajaAvion:
					if (!bajaAvion(aviones, LEN_AVIONES, aerolineas, LEN_AEROLINEAS, tipos, LEN_TIPOS)){
						puts("No se pude realizar la baja");
					}
					else{
						puts("Baja exitosa!!!\n");
					}
					break;
				case optListarAerolineas:
					mostrarAerolineas(aerolineas, LEN_AEROLINEAS);
					break;
				case optListarTipos:
					mostrarTipos(tipos, LEN_TIPOS);
					break;
				case optListarDestinos:
					mostrarDestinos(destinos, LEN_DESTINOS);
					break;
				case optSalirMainMenu:
					seguir = 0;
					break;
				default:
					puts("Opcion invalida");
					break;
			}

			system("pause");
		} while (seguir);
	}

	return EXIT_SUCCESS;
}
