#include "music.h"


using namespace SummerLab;

namespace SummerLab {
	Sound mainTheme;
	Sound menuTheme;

	void loadThemes() {
		mainTheme = LoadSound("res/assets/snd/music/mainTheme.wav");
		menuTheme = LoadSound("res/assets/snd/music/menuTheme.wav");
	}

	void unloadThemes() {
		UnloadSound(mainTheme);
		UnloadSound(menuTheme);
	}
}