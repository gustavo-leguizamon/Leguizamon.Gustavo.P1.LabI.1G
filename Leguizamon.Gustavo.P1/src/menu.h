#ifndef MENU_H_
#define MENU_H_

enum optionsMenu{
	optAltaAvion = 1,
	optModificarAvion,
	optBajaAvion,
	optListarAviones,
	optListarAerolineas,
	optListarTipos,
	optListarDestinos,
	optAltaVuelo,
	optListarVuelos,
	optSalirMainMenu = 20
};


enum optionsMenuModificacion{
	optTipo = 1,
	optCapacidad
};

#endif /* MENU_H_ */



int menu();

int menuModificacion();