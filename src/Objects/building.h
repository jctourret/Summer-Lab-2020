#ifndef BUILDING_H
#define BUILDING_H

#include "raylib.h"
#include "Objects/window.h"
#include "Objects/Civilian.h"

namespace SummerLab {

	const int numberOfWindows = 9;

	class building {
	private:
		Rectangle _body;
		int _floors;
		int _columns;
		window* _windows[numberOfWindows];
		Civilian* _civilians[numberOfWindows];
		Color _color;
		float _civSpawnTimer;
		bool _firstFire;
	public:
		building(float height, float width, float x, float y, int floors, int columns);
		~building();
		void setCivBounceDirection(int i, Direction x);
		Rectangle getCivilianBody(int i);
		bool getCivIsAlive(int i);
		bool getCivIsSaved(int i);
		int getFloors();
		int getColumns();
		void playFire();
		void initFire();
		void growFireTimers();
		void dozeFireTimers(Rectangle rec);
		void spreadFireTimers();
		int countLargeFires();
		void spawnCiv();
		void civJumpTimers();
		void civBounce(int i);
		void resetCivBounce(int i);
		void killCivilians(int i);
		void saveCivilians(int i);
		void draw();
	};
}
#endif