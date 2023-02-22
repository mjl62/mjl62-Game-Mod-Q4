#ifndef __RGITEM_H__
#define __RGITEM_H__

#include "game/Game_local.h"

// Look to item.h and item.cpp and how idItemPowerups are made, hopefully similar

class rgItem : public idItem {


public:

	// identifying items
	idStr					rgItemName;
	idStr					displayName;
	idList<idStr>			rgAllItemNames;
	idDict					rgItemIndex;

	// Init
	void					Spawn();

	// get identification info
	idStr					rgGetItemName();
	idStr					rgGetItemDisplayName();
	idList<idStr>			rgGetItemList();		//For confirming if mentioned item is a valid item


	// item player interaction
	virtual bool			Pickup( idPlayer *player );

	// worldspace
	virtual void			GetPosition(idVec3& origin);

	// spawning and despawn
	void					rgSpawnItem(rgItem item, idVec3& origin); // Spawn (item) at position (origin, which has an x, y and z float)
	void					rgDespawnItem(void);

};

#endif
