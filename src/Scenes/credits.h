#ifndef CREDITS_H
#define CREDITS_H

#include "raylib.h"

namespace SummerLab {
	class credits {
	private:
		float _onCreditsTimer;
		Texture2D _background;
	public:
		credits();
		~credits();
		void run();
		void update();
		void draw();
		void runCreditsTimer();
	};

}
#endif