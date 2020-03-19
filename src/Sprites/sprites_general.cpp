#include "sprites_general.h" 

#include "Sprites/ambulance_sprites.h" 
#include "Sprites/civilians_sprites.h" 
#include "Sprites/fire_sprites.h" 
#include "Sprites/truck_sprites.h" 
#include "Sprites/water_sprites.h" 
#include "Sprites/background_sprites.h"
#include "Sprites/pause_sprites.h"

using namespace SummerLab;

namespace SummerLab {

	void loadAllSprites() {
		loadAmbulanceSprites();
		loadCiviliansSprites();
		loadFireSprites();
		loadTruckSprites();
		loadWaterShotSprites();
		loadBackGroundSprites();
		loadPauseSprites();
	}

	void unloadAllSprites() {
		unloadAmbulanceSprites();
		unloadCiviliansSprites();
		unloadFireSprites();
		unloadTruckSprites();
		unloadWaterShotSprites();
		unloadBackGroundSprites();
		unloadPauseSprites();
	}

}