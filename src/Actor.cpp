#define DYNRPG_STATIC
#include "Actor.h"
#include "DBActor.h"
#include "DynASM.h"
namespace RPG {
	std::string Actor::getDegree() {
		if(degree.s_str() == "\x01") return dbActors[id]->degree;
		return degree;
	}

	std::string Actor::getCharsetFilename() {
		if(charsetFilename.s_str() == "") return dbActors[id]->charsetFilename;
		return charsetFilename;
	}

	int Actor::getCharsetId() {
		if(charsetFilename.s_str() == "") return dbActors[id]->charsetId;
		return charsetId;
	}

	int Actor::getCharsetTransparency() {
		if(charsetFilename.s_str() == "") return dbActors[id]->charsetTransparent ? 3 : 0;
		return charsetTransparency;
	}

	std::string Actor::getFacesetFilename() {
		if(facesetFilename.s_str() == "") return dbActors[id]->facesetFilename;
		return facesetFilename;
	}

	int Actor::getFacesetId() {
		if(facesetFilename.s_str() == "") return dbActors[id]->facesetId;
		return facesetId;
	}

	int Actor::getBattleGraphicId() {
		if(battleGraphicId == 0) return dbActors[id]->battleGraphicId;
		return battleGraphicId;
	}

	int Actor::getBattleCommand(int index) {
		if(!customBattleCommands) return dbActors[id]->battleCommands[index];
		return battleCommands[index];
	}

	Actor *Actor::partyMember(int index) {
		Actor *ret = NULL;
		asm volatile("call *%%esi" : "=a" (ret), "=d" (_edx) : "S" (0x4A6014), "a" (**(void ***)0x4CDB74), "d" (index) : "ecx", "cc", "memory"); // GetPartyMember
		return ret;
	}

	/*! \brief Returns the agility value if actor has two weapons equipped (one weapon is ignored)
	\return Agility value when normally attacking with two weapons (see RPG::Actor::usedWeaponSlot)
	*/


	/*! \brief Built-in RM2k3 function that tests if a hero already knows a certain skill
	\param id The database ID of the skill
	*/


	/*! \brief Built-in RM2k3 function that removes a skill from a hero
	\param id The database ID of the skill
	*/


	/*! \brief Built-in RM2k3 function that adds a skill to a hero
	\param id The database ID of the skill
	*/

		inline void Actor::addSkill(int skillId) {
		asm volatile("call *%%esi"
			:
		: "S" (0x4B7884), "a" (this), "d" (skillId)
			: "ecx", "cc", "memory");
	}

	inline void Actor::removeSkill(int skillId) {
		asm volatile("call *%%esi"
			:
		: "S" (0x4B7928), "a" (this), "d" (skillId)
			: "ecx", "cc", "memory");
	}

	inline bool Actor::isSkillKnown(int skillId) {
		bool out;
		asm volatile("call *%%esi"
			: "=a" (out)
			: "S" (0x4B798C), "a" (this), "d" (skillId)
			: "ecx", "cc", "memory");
		return out;
	}

	inline int Actor::getTwoWeaponAgility() {
		int out;
		asm volatile("call *%%esi"
			: "=a" (out)
			: "S" (0x4B760C), "a" (this)
			: "ecx", "edx", "cc", "memory");
		return out;
	}
}
