#ifndef GAMEPLAY_H
#define GAMEPLAY_H

namespace SummerLab {
	
	
	class gameplay {
	private:
		bool _gameplayOn;
		bool _toMenu;
		bool _toCredits;
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