#include "../../idlib/precompiled.h"
#pragma hdrstop

#include "rgGameHandler.h"
#include "../Game_local.h"


rgGameHandler::rgGameHandler() {
	deadToNextWave = 99;
	killedThisWave = 0;
	waveNumber = 0;

	return;
}

void rgGameHandler::StartSpawn(int enemiestotal) {
	gameLocal.Printf("\n//////STARTING WAVE///////\n");

	idThread* thread = new idThread();
	thread->ReturnInt(rgGameLoop(enemiestotal));
	delete thread;
}


int rgGameHandler::rgGameLoop(int enemiestotal) {
	waveNumber += 1;
	// Init vals
	float difficulty = 1.0f;
	bool lvlDone = false;
	int enemiesSpawned = 0;
	idList<idVec3> spawnLocations;
	spawnLocations.Append(idVec3(-2916, 1481, 470));
	spawnLocations.Append(idVec3(-2997, -168, 280));
	spawnLocations.Append(idVec3(-156, -2981, 280));
	spawnLocations.Append(idVec3(-251, -1100, 88));
	spawnLocations.Append(idVec3(-2243, 137, 408));
	spawnLocations.Append(idVec3(-2911, -95, 280));
	spawnLocations.Append(idVec3(-1237, 1610, 334));
	spawnLocations.Append(idVec3(-1194, 1165, 378));
	

	for (enemiestotal; enemiestotal > enemiesSpawned; enemiesSpawned++) {
		const char* key, * value;
		int			i;
		idDict		dict;
		idStr enemyType;
		float  yaw = 0;

		

		idVec3 location = spawnLocations[gameLocal.random.RandomInt(7)];

		idVec2 offsetLoc(gameLocal.random.RandomFloat() * 10, gameLocal.random.RandomFloat() * 10);

		location.x += offsetLoc.x;
		location.y += offsetLoc.y;

		// Set location
		dict.Set("origin", location.ToString());
		key = "spawn";
		int enemyNum = gameLocal.random.RandomInt(100);
		if (enemyNum < 25) {
			enemyType = "monster_strogg_marine";
		}
		else if (enemyNum < 50) {
			enemyType = "monster_grunt";
		}
		else if (enemyNum < 80) {
			enemyType = "monster_failed_transfer";
		}
		else {
			enemyType = "monster_scientist";
		}
		gameLocal.Printf("enemynum = %i", enemyNum);

		dict.Set("classname", enemyType);
		dict.Set("angle", va("%f", yaw));
		value = enemyType;

		dict.Set(key, value);

		idEntity* newEnt = NULL;
		gameLocal.SpawnEntityDef(dict, &newEnt);

		if (newEnt) {
			gameLocal.Printf("\nSpawned entity '%s' at location %f, %f, %f", newEnt->name.c_str(), location.x, location.y, location.z);
		}
		deadToNextWave = gameLocal.random.RandomInt(5) + 10;
		killedThisWave = 0;

	}

	CheckBossReq();

	idPlayer* player = gameLocal.GetLocalPlayer();
	player->UpdateHud();
	
	return 0;
}

void rgGameHandler::checkNextWaveReq() {
	if (killedThisWave >= deadToNextWave) {
		rgGameLoop(gameLocal.random.RandomInt(10) + 25);
	}
	else {
		killedThisWave += 1;
	}
}

void rgGameHandler::CheckBossReq() {
	if (waveNumber % 3 == 0) {
		gameLocal.Printf("\n//////BOSS APPROACHING///////\n");
		
		const char* key, * value;
		int			i;
		idDict		dict;
		idStr enemyType;
		float  yaw = 253;

		

		idVec3 location = idVec3(321, 311, 223);

		// Set location
		dict.Set("origin", location.ToString());
		
		enemyType = "monster_makron";
		key = "spawn";
		dict.Set("classname", enemyType);
		dict.Set("angle", va("%f", yaw));
		value = enemyType;

		dict.Set(key, value);

		idEntity* newEnt = NULL;
		gameLocal.SpawnEntityDef(dict, &newEnt);

		if (newEnt) {
			gameLocal.Printf("\nSpawned boss entity '%s' at location %f, %f, %f", newEnt->name.c_str(), location.x, location.y, location.z);
		}
		
	}
}