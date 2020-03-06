#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "Objects/truck.h"
#include "Objects/building.h"
#include "Objects/Hydrant.h"
#include "Objects/Ambulance.h"

namespace SummerLab {
	
	
	class gameplay {
	private:
		bool _gameplayOn;
		bool _toMenu;
		bool _toCredits;
		bool _gameWon;
		truck* _truck;
		building* _building;
		Hydrant* _hydrant;
		Ambulance* _ambulanceLeft;
		Ambulance* _ambulanceRight;
		int _deadCivs;
		Texture2D _background;
	public:
		gameplay();
		~gameplay();
		void setToMenu(bool toMenu);
		void setToCredits(bool toCredits);
		bool getToMenu();
		bool getToCredits();
		bool getGameWon();
		void run();
		void update();
		void draw();
		void checkCiviliansBounce();
		void checkCivilianSaved();
		void bounceCivilians();
		void checkCivilianDeath();
		void runGameTimer(float timer);
		void gameResult();
	};
}
#endif