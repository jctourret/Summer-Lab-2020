#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "Objects/truck.h"
#include "Objects/building.h"
#include "Objects/Hydrant.h"
#include "Objects/Ambulance.h"
#include "Objects/pause.h"

namespace SummerLab {

	class gameplay {
	private:
		bool _hoseGame;
		bool _keyboardGame;
		bool _gameWon;
		bool _gameLost;
		bool _playCollapseOnce;
		bool _playMotorOnOnce;
		bool _playMotorOffOnce;
		bool _buildingLittlyDamaged;
		bool _buildingModeratelyDamaged;
		bool _buildingDamaged;
		bool _buildingVeryDamaged;
		bool _buildingSeverelyDamaged;
		int _deadCivs;
		Pause* _pause;
		truck* _truck;
		building* _building;
		Hydrant* _hydrant;
		Ambulance* _ambulanceLeft;
		Ambulance* _ambulanceRight;
		Texture2D _background[8];
		Texture2D _skiesSprites[6];
		Texture2D _gameOverBurn[3];
		Texture2D _gameOverDead[3];
		Texture2D _gameOverDeadExtra[3];
		Texture2D _gameOverWin[3];
		Texture2D _killCount[3];
		Texture2D _buildingCracks[5];
		Texture2D _buildingCollapsing[16];
	public:
		gameplay(bool keyboard, bool hose);
		~gameplay();
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
		void playMainTheme();
	};
}
#endif