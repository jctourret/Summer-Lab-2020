#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "Objects/truck.h"
#include "Objects/building.h"

namespace SummerLab {
	
	
	class gameplay {
	private:
		bool _gameplayOn;
		bool _toMenu;
		bool _toCredits;
		truck* _truck;
		building* _building;

	public:
		gameplay();
		~gameplay();
		void setToMenu(bool toMenu);
		void setToCredits(bool toCredits);
		bool getToMenu();
		bool getToCredits();
		void run();
		void update();
		void draw();
	};
}
#endif