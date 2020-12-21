#include "Teleport.h"

void RPG::teleportHero(int mapId, int x, int y, RPG::TeleportDirection dir)
{
    teleport->mapId = mapId;
    teleport->mapX = x;
    teleport->mapY = y;
    teleport->facingDirection = dir;
    teleport->teleportTrigger = true;
}