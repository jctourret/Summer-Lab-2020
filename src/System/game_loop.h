#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include "Scenes/menu.h"
#include "Scenes/gameplay.h"
#include "Scenes/credits.h"
#include "System/screen.h"


namespace SummerLab {
	
	enum gamestate {
		onMenu,
		onGameplay,
		onCredits,
	};
	
	class game_loop{
	private:
		bool _gameOn;
		bool _keyboardGame;
		bool _hoseGame;
		gamestate _gamestate;
		screen* _screen;
		menu* _menu;
		gameplay* _gameplay;
		credits* _credits;
	public:
		game_loop();
		~game_loop();
		void gameLoop();
	};
}
#endif