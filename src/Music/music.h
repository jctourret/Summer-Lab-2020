#ifndef MUSIC_H
#define MUSIC_H

#include "raylib.h"

namespace SummerLab {
	extern Sound _mainTheme;
	extern Sound _menuTheme;

	void loadThemes();
	void unloadThemes();
}
#endif