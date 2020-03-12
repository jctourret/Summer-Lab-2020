#include "music.h"


using namespace SummerLab;

namespace SummerLab {
	Sound mainTheme;
	Sound menuTheme;

	void loadThemes() {
		mainTheme = LoadSound("res/assets/snd/music/mainTheme.ogg");
		menuTheme = LoadSound("res/assets/snd/music/menuTheme.ogg");
	}

	void unloadThemes() {
		UnloadSound(mainTheme);
		UnloadSound(menuTheme);
	}
}