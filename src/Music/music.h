#ifndef MUSIC_H
#define MUSIC_H

#include "raylib.h"

namespace SummerLab {
	extern Sound mainTheme;
	extern Sound menuTheme;

	void loadThemes();
	void muteAllSounds();
	void unloadThemes();
}

#endif