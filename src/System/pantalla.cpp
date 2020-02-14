#include "Pantalla.h"

using namespace SummerLab;

namespace SummerLab {

	pantalla::pantalla() {
		_resolucion.alto = Altopantalla;
		_resolucion.ancho = Anchopantalla;
	}

	pantalla::~pantalla() {

	}
	void pantalla::setAnchoPantalla(int ancho) {
		_resolucion.ancho = ancho;
	}
	void pantalla::setAltoPantalla(int alto) {
		_resolucion.alto = alto;
	}
	int pantalla::getAnchoPantalla() {
		return _resolucion.ancho;
	}
	int pantalla::getAltoPantalla() {
		return _resolucion.alto;
	}
}
