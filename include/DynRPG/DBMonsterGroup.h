#ifndef DBMONSTERGROUP_H
#define DBMONSTERGROUP_H
#include "Catalog.h"
#include "DArray.h"
#include "DString.h"
namespace RPG {
	class BattleEventPage;
	class MonsterGroupPosition;
	class EventScriptLine;

	enum MonsterAlignment
	{
		MA_MANUAL,
		MA_AUTO,
	};

	/*! \brief Used for the default data of monster groups which are defined in the
		database

		\sa RPG::dbMonsterGroups
		\sa RPG::MonsterAlignment
		\sa RPG::BattleEventPage
		\sa RPG::MonsterGroupPosition
		\sa RPG::getBattleEventLine(int monsterGroup, int battleEventPage, int lineId)
	*/

	class DBMonsterGroup {
		public:
			void **vTable;
			int id; //!< ID of the monster group
			DStringPtr name; //!< Name of the monster group
			CatalogPtr<MonsterGroupPosition *> monsterList; //!< The current monsters in the grouping, along with their position
			DArray<bool, 1> habitatTerrain; //!< The array of "Habitats" for this monster group
			CatalogPtr<BattleEventPage *> battleEventPages; //!< The battle event pages associated to this monster group
			bool randomizeHidden; //!< 50% chance for hidden flag
			MonsterAlignment alignment;
	};

	/*! \ingroup game_objects
		\brief Array of monsters from the database, used for default values and
		properties which are not supposed to be changed in-game.

		Use the database ID as index for accessing a monster.

		Example:
		\code
int monCrit = RPG::dbMonsterGroups[1]->critPercentage;
		\endcode
	*/
	extern RPG::NamedCatalogPtr<RPG::DBMonsterGroup *> &dbMonsterGroups;

	/*! \brief Easily returns a battle event line.

		Allows you to write <tt>RPG::getBattleEventLine(23,1,1)->command</tt> instead of <tt>RPG::dbMonsterGroups[23]->battleEventPages[1]->scriptLines->list->items[1]->command</tt> which gets the 2nd line on the 2nd page of monster group 23.

		\param monsterGroup The monster group ID (one-based)
		\param battleEventPage The monster group's battle event page ID (zero-based)
		\param lineId The line ID (zero-based)

		\sa RPG::BattleEventPage
	*/
	RPG::EventScriptLine *getBattleEventLine(int monsterGroup, int battleEventPage, int lineId);
}
#endif /* DBMONSTERGROUP_H */
