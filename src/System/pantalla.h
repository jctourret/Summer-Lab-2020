#ifndef PANTALLA_H
#define PANTALLA_H

namespace SummerLab {

	const int Anchopantalla = 1280;
	const int Altopantalla = 720;

	struct Resolucion {
		int ancho;
		int alto;
	};

	class pantalla {
	private:
		Resolucion _resolucion;
	public:
		pantalla();
		~pantalla();
		void setAnchoPantalla(int ancho);
		void setAltoPantalla(int alto);
		int getAnchoPantalla();
		int getAltoPantalla();
	};
}
#endif