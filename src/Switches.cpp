#include "Switches.h"

RPG::DStringPtr RPG::Switches::name(int index)
{
    RPG::NamedCatalogPtr<RPG::Switch *> &n = (**reinterpret_cast<RPG::NamedCatalogPtr<RPG::Switch *> **>(0x4CE060));
    return n[index]->name;
}