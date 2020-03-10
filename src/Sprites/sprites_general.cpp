#include "sprites_general.h" 

#include "Sprites/ambulance_sprites.h" 
#include "Sprites/civilians_sprites.h" 
#include "Sprites/fire_sprites.h" 
#include "Sprites/truck_sprites.h" 
#include "Sprites/water_sprites.h" 
#include "Sprites/bakcground_sprites.h"

using namespace SummerLab;

namespace SummerLab {

	void loadAllSprites() {
		loadAmbulanceSprites();
		loadCiviliansSprites();
		loadFireSprites();
		loadTruckSprites();
		loadWaterShotSprites();
		loadBackGroundSprites();
	}

	void unloadAllSprites() {
		unloadAmbulanceSprites();
		unloadCiviliansSprites();
		unloadFireSprites();
		unloadTruckSprites();
		unloadWaterShotSprites();
		unloadBackGroundSprites();
	}

}