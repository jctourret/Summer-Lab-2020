#ifndef CREDITS_H
#define CREDITS_H

namespace SummerLab {
	class credits {
	private:
		bool _creditsOn;
		bool _toMenu;
		bool _toGameplay;
	public:
		credits();
		~credits();
		void setToMenu(bool toMenu);
		void setToGameplay(bool toGameplay);
		bool getToMenu();
		bool getToGameplay();
		void run();
		void update();
		void draw();
	};

}
#endif