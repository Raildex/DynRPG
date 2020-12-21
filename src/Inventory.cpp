#include "Inventory.h"
#include "DynASM.h"
int RPG::Inventory::getPartyIndex(int databaseId) {
	// Do not loop more times than the size of the party
	for (int i = 0; i<RPG::inventory->party.size; i++) {
		// if the party's id matches the database ID of the hero being checked for
		if (RPG::inventory->party[i] == databaseId) {
			return i;
		}
	}
	return -1;
}

/*! \brief Built-in RM2k3 function checks the inventory to see if an item is owned
\param id The database ID of the item
\return true if the item is owned, otherwise false
*/

inline bool RPG::Inventory::isItemOwned(int id) {
	int out;
	asm volatile("call *%%esi"
		: "=a" (out), "=d" (RPG::_edx)
		: "S" (0x4A6440), "a" (this), "d" (id)
		: "ecx", "cc", "memory");
	return out;
}

/*! \brief Built-in RM2k3 function that adds an item to the inventory
\param id The database ID of the item
\param amount Amount of the item to add
*/

inline void RPG::Inventory::addItem(int id, int amount) {
	asm volatile("call *%%esi"
		: "=a" (RPG::_eax), "=c" (RPG::_ecx), "=d" (RPG::_edx)
		: "S" (0x4A620C), "a" (this), "c" (amount), "d" (id)
		: "cc", "memory");
}

/*! \brief Built-in RM2k3 function that removes an item to the inventory
\param id The database ID of the item
\param amount Amount of the item to add
*/

inline void RPG::Inventory::removeItem(int id, int amount) {
	asm volatile("call *%%esi"
		: "=a" (RPG::_eax), "=c" (RPG::_ecx), "=d" (RPG::_edx)
		: "S" (0x4A6308), "a" (this), "d" (id), "c" (amount)
		: "cc", "memory");
}

/*! \brief Built-in RM2k3 function that increments an items use count by one if it's set to more than one use
\param id The database ID of the item
*/

inline void RPG::Inventory::incrementItemUses(int id) {
	asm volatile("call *%%esi"
		: "=a" (RPG::_eax), "=d" (RPG::_edx)
		: "S" (0x4A63BC), "a" (this), "d" (id)
		: "ecx", "cc", "memory");
}
