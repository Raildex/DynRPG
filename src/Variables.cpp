#include "Variables.h"
#include "Catalog.h"
/*! \brief Gets the name of a variable
\return The name of the variable
*/

RPG::DStringPtr RPG::Variables::name(int index) {
	RPG::NamedCatalogPtr<RPG::Variable *> &n = (**reinterpret_cast<RPG::NamedCatalogPtr<RPG::Variable *> **>(0x4CDFC4));
	return n[index]->name;
}
