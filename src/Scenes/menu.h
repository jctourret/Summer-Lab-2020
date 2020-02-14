#ifndef MENU_H
#define MENU_H

namespace SummerLab {
	
	class menu {
	private:
		bool _menuOn;
		bool _aGameplay;
		bool _aCreditos;
	public:
		menu();
		~menu();
		void
		void setAGameplay();
		void setACreditos();
		bool getAGameplay();
		bool getACreditos();
		void run();
		void update();
		void draw();
	};
}
#endif
