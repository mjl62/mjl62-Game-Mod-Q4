#ifndef __RG_GAMEHANDLER__
#define __RG_GAMEHANDLER__

#include "../../idlib/precompiled.h"

class rgGameHandler {

public:

	// Variables
	idDict items;

	// Methods
	void PickupItem(idStr);

	idStr GetItemCount();

	void StartSpawn();

	void Init();
	
};

class rgItem {

public:
	idDict items;
	int id;
	idStr displayName;
};
#endif

