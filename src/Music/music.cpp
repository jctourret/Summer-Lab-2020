#include "music.h"


using namespace SummerLab;

namespace SummerLab {

	static bool gameMuted = false;

	Sound mainTheme;
	Sound menuTheme;

	void loadThemes() {
		mainTheme = LoadSound("res/assets/snd/music/mainTheme.ogg");
		menuTheme = LoadSound("res/assets/snd/music/menuTheme.ogg");
	}

	void muteAllSounds() {
		if (gameMuted == false) {
			gameMuted = true;
			SetMasterVolume(0.0f);
		}
		else if (gameMuted == true) {
			gameMuted = false;
			SetMasterVolume(0.02f);
		}
	}

	void unloadThemes() {
		UnloadSound(mainTheme);
		UnloadSound(menuTheme);
	}
}