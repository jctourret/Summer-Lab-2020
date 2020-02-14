#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include "Scenes/creditos.h"
#include "Scenes/menu.h"
#include "Scenes/gameplay.h"
#include "System/pantalla.h"

namespace SummerLab {
	
	enum estado {
		enMenu,
		enGameplay,
		enCreditos,
	};
	
	class game_loop{
	private:
		bool _gameOn;
		estado _estado;
		pantalla* _pantalla;
		creditos* _creditos;
		menu* _menu;
		gameplay* _gameplay;
	public:
		game_loop();
		~game_loop();
		void gameLoop();
	};
}
#endif