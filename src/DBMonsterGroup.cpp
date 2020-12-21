#include "DBMonsterGroup.h"
#include "BattleEventPage.h"
#include "EventScriptData.h"
RPG::EventScriptLine *getBattleEventLine(int monsterGroup, int battleEventPage, int lineId) {
    return RPG::dbMonsterGroups[monsterGroup]->battleEventPages[battleEventPage]->scriptLines->list->items[lineId];
}