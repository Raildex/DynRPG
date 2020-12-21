#include "EventScriptData.h"
#include "CommonEvent.h"
RPG::EventScriptLine *getCommonEventLine(int id, int lineId)
{
    return RPG::commonEvents[id]->scriptLines->list->items[lineId];
}

