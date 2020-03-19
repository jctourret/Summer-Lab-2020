#ifndef GAME_STATES_H
#define GAME_STATES_H

namespace SummerLab {

	enum gamestate {
		closeGame,
		onMenu,
		onGameplay,
		onCredits,
	};

	extern gamestate gameState;

}

#endif