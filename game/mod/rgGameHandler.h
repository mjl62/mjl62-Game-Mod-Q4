#ifndef __RG_GAMEHANDLER__
#define __RG_GAMEHANDLER__

#include "../../idlib/precompiled.h"

class rgGameHandler {
		
public:
	rgGameHandler();

	// Variables
	idDict items;
	idThread* th_spawn;
	idList<idVec3> spawnLocations;

	int deadToNextWave;
	int killedThisWave;
	int waveNumber;
	// Methods


	void CheckBossReq();
	void StartSpawn(int);
	void checkNextWaveReq();


	int rgGameLoop(int);	
	
};

class rgItem {

public:
	idDict items;
	int id;
	idStr displayName;
};
#endif

