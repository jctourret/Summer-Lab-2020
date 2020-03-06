#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include "Scenes/menu.h"
#include "Scenes/gameplay.h"
#include "System/screen.h"

namespace SummerLab {
	
	enum gamestate {
		onMenu,
		onGameplay,
	};
	
	class game_loop{
	private:
		bool _gameOn;
		gamestate _gamestate;
		screen* _screen;
		menu* _menu;
		gameplay* _gameplay;
	public:
		game_loop();
		~game_loop();
		void gameLoop();
	};
}
#endif