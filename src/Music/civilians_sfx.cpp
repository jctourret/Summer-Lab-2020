#include "civilians_sfx.h"

using namespace SummerLab;

namespace SummerLab {
	
	Sound helpMale;
	Sound helpFemale;

	void loadScreams() {
		helpMale = LoadSound("res/assets/snd/civilians/helpMale.ogg");
		helpFemale = LoadSound("res/assets/snd/civilians/helpFemale.ogg");
	}

	void unloadScreams() {
		UnloadSound(helpMale);
		UnloadSound(helpFemale);
	}
}