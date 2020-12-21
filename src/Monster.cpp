#include "Monster.h"
#include "DynASM.h"
void RPG::Monster::transform(int monsterId) {
	asm volatile("call *%%esi"
		: "=a" (RPG::_eax), "=d" (RPG::_edx)
		: "S" (0x4BDDD8), "a" (this), "d" (monsterId)
		: "ecx", "cc", "memory");
}

void RPG::Monster::loadMonsterGroup(int id) {
	asm volatile("call *%%esi"
		: "=a" (RPG::_eax), "=d" (RPG::_edx)
		: "S" (0x4BE8E0), "a" (RPG::monsters.ptr), "d" (id)
		: "ecx", "cc", "memory");
}