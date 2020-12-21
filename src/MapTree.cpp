#include "MapTree.h"
#include "MapProperties.h"
/*! \brief Gets the map tree index of a map
\return The index of the requested map ID
*/

inline int RPG::MapTree::getTreeIndex(int mapId) {
	for (int i = 0; i<RPG::mapTree->properties.count(); i++) {
		if (mapTree->properties[i]->id == mapId) return i;
	}
	return -1;
}
