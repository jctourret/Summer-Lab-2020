#include "sound_general.h"

using namespace SummerLab;

namespace SummerLab {
	void loadAllSounds() {
		loadTruckSounds();
		loadFireSounds();
		loadScreams();
		loadThemes();
	}

	void unloadAllSounds() {
		unloadTruckSounds();
		unloadFireSounds();
		unloadScreams();
		unloadThemes();
	}
}