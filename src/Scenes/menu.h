#ifndef MENU_H
#define MENU_H

namespace SummerLab {
	
	class menu {
	private:
		bool _menuOn;
		bool _toGameplay;
		bool _toCredits;
	public:
		menu();
		~menu();
		void setToGameplay(bool toGameplay);
		void setToCredits(bool toCreditos);
		bool getToGameplay();
		bool getToCredits();
		void run();
		void update();
		void draw();
	};
}
#endif
