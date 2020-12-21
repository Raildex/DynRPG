#define DYNRPG_STATIC
#include "Map.h"
#include "DynASM.h"
#include "EventScriptData.h"
#include "EventData.h"
#include "DynRPG.h"
#include "Character.h"

namespace RPG {
	int Map::getCameraX() {
		return cameraSubX / 16;
	}

	int Map::getCameraY() {
		return cameraSubY / 16;
	}

	void Map::setCamera(int x, int y) {
		x *= 16;
		y *= 16;
		int *p = (**(int ***)(0x4CDE54));
		p[43] += x - cameraSubX;
		p[44] += y - cameraSubY;
		p[45] += x - cameraSubX;
		p[46] += y - cameraSubY;
	}

	void Map::moveCamera(int offsetX, int offsetY, int speed) {
		int *p = (**(int ***)(0x4CDE54));
		p[45] += offsetX * 16;
		p[46] += offsetY * 16;
		p[47] = speed;
	}

	int Map::getWidth() {
		return (**(int ***)(0x4CDD14))[5];
	}

	int Map::getHeight() {
		return (**(int ***)(0x4CDD14))[6];
	}

	void Map::updateEvents() {
		asm volatile("call *%%esi" : "=a" (_eax) : "S" (0x4AB8B4), "a" (events.ptr) : "edx", "ecx", "cc", "memory");
	}

	/*! \brief Gets the tile ID for the lower layer tile at the specified coordinate
	\param map The map being checked. For now, just RPG::map is supported as it's not (yet?) possible to check maps the player isn't on
	\param x The Y coordinate of the tile
	\param y The Y coordinate of the tile
	\sa RPG::Tileset::lowerTilePassability
	*/

	inline int Map::getLowerLayerTileId(int x, int y) {
		int out;
		asm volatile("call *%%esi"
			: "=a" (out), "=c" (RPG::_ecx), "=d" (RPG::_edx)
			: "S" (0x4A80CC), "a" (this), "c" (y), "d" (x)
			: "cc", "memory");
		return out;
	}

	/*! \brief Gets the tile ID for the upper layer tile at the specified coordinate
	\param map The map being checked. For now, just RPG::map is supported as it's not (yet?) possible to check maps the player isn't on
	\param x The Y coordinate of the tile
	\param y The Y coordinate of the tile
	\sa RPG::Tileset::upperTilePassability
	*/

	inline int Map::getUpperLayerTileId(int x, int y) {
		int out;
		asm volatile("call *%%esi"
			: "=a" (out), "=c" (RPG::_ecx), "=d" (RPG::_edx)
			: "S" (0x4A80F4), "a" (this), "c" (y), "d" (x)
			: "cc", "memory");
		return out;
	}

	/*! \brief Gets the terrain ID for the tile ID specified
	\param tileId The tile's id
	\sa RPG::Tileset::lowerTileTerrainId
	*/

	inline int Map::getTerrainId(int tileId) {
		int out;
		asm volatile("movl 20(%%eax), %%eax; call *%%esi"
			: "=a" (out), "=d" (RPG::_edx)
			: "S" (0x47D038), "a" (this), "d" (tileId)
			: "ecx", "cc", "memory");
		return out;
	}

	/*! \brief Gets the event ID at the position specified, or
	\param x The Y coordinate of the event
	\param y The Y coordinate of the event
	\return The event ID, or 0 if no event was found
	*/

	inline int Map::getEventAt(int x, int y) {
		// Since the map->events array goes by event ID, create a counter that increments
		// when an event is not found at a specific array location, thus ensuring
		// all events get checked
		// example: events 1 and 10 exist on the map, while 2-9 were deleted at some point
		int counter = RPG::map->events.count();
		for (int i = 1; i <= counter; i++) {
			// Ensures the event exists
			if (RPG::map->events[i]) {
				// Checks the x & y coordinates
				if (RPG::map->events[i]->x == x && RPG::map->events[i]->y == y) {
					// Return the event's ID
					return i;
				}
			}
			else {
				counter++;
			}
		}
		return 0;
	}

	/*! \brief Easily returns an event line.

	Allows you to write <tt>RPG::getBattleEventLine(6,2,0)->command</tt> instead of <tt>RPG::mapCurrent->events[6]->pages[3]->scriptLines->list->items[0]->command</tt> which gets the first line on the 3rd page of the event 6.

	\param eventId The monster group ID (one-based)
	\param pageId The monster group's battle event page ID (zero-based)
	\param lineId The line ID (zero-based)

	\sa RPG::MapEventPage
	*/
	RPG::EventScriptLine * getEventLine(int eventId, int pageId, int lineId) {
		return map->events[eventId]->data->pages[pageId]->scriptLines->list->items[lineId];
	}
}
