#include "music.h"


using namespace SummerLab;

namespace SummerLab {
	Sound mainTheme;
	Sound menuTheme;

	void loadThemes() {
		mainTheme = LoadSound("res/assets/snd/s/helpMale");
		menuTheme = LoadSound("res/assets/snd/music/helpFemale");
	}

	void unloadThemes() {
		UnloadSound(mainTheme);
		UnloadSound(menuTheme);
	}
}