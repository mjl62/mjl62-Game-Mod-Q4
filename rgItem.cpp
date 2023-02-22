/*
A Risk of Rain 2 inspired mod for Quake 4
by Matthew LiDonni for Game Mod Dev: IT 266-002 at NJIT

This file is the base for items that can be picked up, they work like powerups but you can pick up unlimited
amounts, boosting your stats to the fuckin moon.

*/
/*
#include "idlib/precompiled.h"
#pragma hdrstop

#include "game/Game_local.h"
#include "rgItem.h"

// init
rgItem::rgItem() {
	
	rgItemName = NULL;
	rgAllItemNames.Append("fungus");
	rgAllItemNames.Append("behemoth");
	rgAllItemNames.Append("adrenaline");
	rgAllItemNames.Append("topaz");
	rgAllItemNames.Append("feather");

}


void rgItem::GetPosition(idVec3& origin) {
	origin = GetPhysics()->GetOrigin();
}

// 
void rgItem::Spawn()
{
	// TODO define
	// TODO find out how to run when created, if its not already going to do so.
}

// Getters/Setters
idStr rgItem::rgGetItemName()
{
	return rgItemName;
}

idStr rgItem::rgGetItemDisplayName()
{
	return displayName;
}

idList<idStr> rgGetItemList() 
{

}

bool rgItem::Pickup( idPlayer* player )
{

	if (player->inventory.rgItemsCount.FindKey(rgItemName) != NULL) 
	{
		player->inventory.rgItemsCount.Set(rgItemName, player->inventory.rgItemsCount.FindKey(rgItemName)->GetValue() + 1);
	}
	return true;

}

*/
