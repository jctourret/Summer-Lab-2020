#include "pause_sprites.h"

using namespace SummerLab;

namespace SummerLab {

	Texture2D pauseSprite;
	Texture2D resumeShineSprite;
	Texture2D muteShineSprite;
	Texture2D menuShineSprite;
	Texture2D exitShineSprite;

	void loadPauseSprites() {
		pauseSprite = LoadTexture("res/assets/img/pause/pause.png");
		resumeShineSprite = LoadTexture("res/assets/img/pause/resumeShine.png");
		muteShineSprite = LoadTexture("res/assets/img/pause/muteShine.png");
		menuShineSprite = LoadTexture("res/assets/img/pause/menuShine.png");
		exitShineSprite = LoadTexture("res/assets/img/pause/exitShine.png");
	}

	void unloadPauseSprites() {
		UnloadTexture(pauseSprite);
		UnloadTexture(resumeShineSprite);
		UnloadTexture(muteShineSprite);
		UnloadTexture(menuShineSprite);
		UnloadTexture(exitShineSprite);
	}

}
