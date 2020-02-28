#include "System/game_loop.h"

using namespace SummerLab;

int main() {
	game_loop* play = 0;

	play = new game_loop();

	if (play != 0) {
		play->gameLoop();
	}

	if (play != 0) {
		delete play;
	}
	return 0;
}