#include "Window.h"
#include "Catalog.h"
#include "Tileset.h"
#include "Monster.h"
#include "System.h"
#include "DBSystem.h"
#include "BattleSettings.h"
#include "DBClass.h"
#include "DBActor.h"
#include "Actor.h"
#include "DBMonster.h"
#include "DBMonsterGroup.h"
#include "Inventory.h"
#include "Input.h"
#include "Panorama.h"
#include "Picture.h"
#include "Animation2.h"
#include "Teleport.h"
#include "TeleportManagement.h"
#include "Terrain.h"
#include "Vocabulary.h"
#include "SceneDebug.h"
#include "SceneShop.h"
#include "SceneGameOver.h"
#include "SceneMenu.h"
#include "SceneFile.h"
#include "SceneEnterName.h"
#include "SceneTitle.h"
#include "BattleEvent.h"
#include "BattleData.h"
#include "Character.h"
#include "Condition.h"
#include "Screen.h"
#include "CommonEvent.h"
#include "Skill.h"
#include "Attribute.h"
#include "AnimationInBattle.h"
#include "Map.h"
#include "MapProperties.h"
namespace RPG {
    RPG::WindowMessage *&winMessage = (**reinterpret_cast<RPG::WindowMessage ***>(0x4CDEF4));
    RPG::DStringPtr *&vocabulary = (**reinterpret_cast<RPG::DStringPtr ***>(0x4CDCB4));
    RPG::NamedCatalogPtr<RPG::Tileset *> &tilesets = (**reinterpret_cast<RPG::NamedCatalogPtr<RPG::Tileset *> **>(0x4CDD0C));
    RPG::NamedCatalogPtr<RPG::Terrain *> &terrains = (**reinterpret_cast<RPG::NamedCatalogPtr<RPG::Terrain *> **>(0x4CDD80));
    RPG::TeleportManagement *&teleportManagement = (**reinterpret_cast<RPG::TeleportManagement ***>(0x4CDB50));
    RPG::Teleport *&teleport = (**reinterpret_cast<RPG::Teleport ***>(0x4CDC1C));
    RPG::System *&system = (**reinterpret_cast<RPG::System ***>(0x4CDC7C));
    RPG::NamedCatalogPtr<RPG::Skill *> &skills = (**reinterpret_cast<RPG::NamedCatalogPtr<RPG::Skill *> **>(0x4CDBC4));
    RPG::Screen *&screen = (**reinterpret_cast<RPG::Screen ***>(0x4CDB24));
    RPG::SceneMenu *&menu = (**reinterpret_cast<RPG::SceneMenu ***>(0x4CDC60));
    RPG::SceneShop *&shop = (**reinterpret_cast<RPG::SceneShop ***>(0x4CDE4C));
    RPG::SceneTitle *&title = (**reinterpret_cast<RPG::SceneTitle ***>(0x4CDB94));
    RPG::SceneGameOver *&gameOver = (**reinterpret_cast<RPG::SceneGameOver ***>(0x4CE008));
    RPG::SceneFile *&fileSaveLoad = (**reinterpret_cast<RPG::SceneFile ***>(0x4CDFCC));
    RPG::SceneEnterName *&enterName = (**reinterpret_cast<RPG::SceneEnterName ***>(0x4CDBF4));
    RPG::SceneDebug *&debug = (**reinterpret_cast<RPG::SceneDebug ***>(0x4CDD4C));
    NamedCatalogPtr<RPG::Picture *> &pictures = (**reinterpret_cast<RPG::NamedCatalogPtr<RPG::Picture *> **>(0x4CDF3C));
    RPG::CatalogPtr<RPG::Monster *> &monsters = (**reinterpret_cast<RPG::CatalogPtr<RPG::Monster *> **>(0x4CDE64));
    RPG::NamedCatalogPtr<RPG::Animation2 *> &battlerAnimations = (**reinterpret_cast<RPG::NamedCatalogPtr<RPG::Animation2 *> **>(0x4CDC90));
    RPG::NamedCatalogPtr<RPG::Actor *> &actors = (**reinterpret_cast<RPG::NamedCatalogPtr<RPG::Actor *> **>(0x4CDDC8));
    RPG::NamedCatalogPtr<RPG::Animation *> &battleAnimations = (**reinterpret_cast<RPG::NamedCatalogPtr<RPG::Animation *> **>(0x4CDDC4));
    RPG::NamedCatalogPtr<RPG::Attribute *> &attributes = (**reinterpret_cast<RPG::NamedCatalogPtr<RPG::Attribute *> **>(0x4CDE44));
    RPG::BattleData *&battleData = (**reinterpret_cast<RPG::BattleData ***>(0x4CDD38));
    RPG::BattleEvent *&battleEvents = (**reinterpret_cast<RPG::BattleEvent ***>(0x4CDB10));
    RPG::BattleSettings *&battleSettings = (**reinterpret_cast<RPG::BattleSettings ***>(0x4CDD60));
    RPG::Hero *&hero = (**reinterpret_cast<RPG::Hero ***>(0x4CDE54));
    RPG::Vehicle *&vehicleSkiff = (**reinterpret_cast<RPG::Vehicle ***>(0x4CE00C));
    RPG::Vehicle *&vehicleShip = (**reinterpret_cast<RPG::Vehicle ***>(0x4CE034));
    RPG::Vehicle *&vehicleAirship = (**reinterpret_cast<RPG::Vehicle ***>(0x4CDE68));
    RPG::NamedCatalogPtr<RPG::CommonEvent *> &commonEvents = (**reinterpret_cast<RPG::NamedCatalogPtr<RPG::CommonEvent *> **>(0x4CDF40));
    RPG::NamedCatalogPtr<RPG::Condition *> &conditions = (**reinterpret_cast<RPG::NamedCatalogPtr<RPG::Condition *> **>(0x4CDE84));
    RPG::NamedCatalogPtr<RPG::DBActor *> &dbActors = (**reinterpret_cast<RPG::NamedCatalogPtr<RPG::DBActor *> **>(0x4CDD54));
    RPG::NamedCatalogPtr<RPG::DBClass *> &dbClasses = (**reinterpret_cast<RPG::NamedCatalogPtr<RPG::DBClass *> **>(0x4CDD7C));
    RPG::NamedCatalogPtr<RPG::DBMonster *> &dbMonsters = (**reinterpret_cast<RPG::NamedCatalogPtr<RPG::DBMonster *> **>(0x4CDE0C));
    RPG::NamedCatalogPtr<RPG::DBMonsterGroup *> &dbMonsterGroups = (**reinterpret_cast<RPG::NamedCatalogPtr<RPG::DBMonsterGroup *> **>(0x4CDDC0));
    RPG::DBSystem *&dbSystem = (**reinterpret_cast<RPG::DBSystem ***>(0x4CDC0C));
    RPG::Input *&input = (**reinterpret_cast<RPG::Input ***>(0x4CDAEC));
    RPG::Inventory *&inventory = (**reinterpret_cast<RPG::Inventory ***>(0x4CDB74));
    RPG::NamedCatalogPtr<RPG::Item *> &items = (**reinterpret_cast<RPG::NamedCatalogPtr<RPG::Item *> **>(0x4CDB14));
    RPG::Panorama *&panorama = (**reinterpret_cast<RPG::Panorama ***>(0x4CDBBC));
    RPG::AnimationInBattle *&RPG::Monster::animData = (**reinterpret_cast<RPG::AnimationInBattle ***>(0x4CDE64));
    RPG::AnimationInBattle *&RPG::Actor::animData = (**reinterpret_cast<RPG::AnimationInBattle ***>(0x4CDDC8));
    RPG::MapProperties *&RPG::Map::properties = (**reinterpret_cast<RPG::MapProperties ***>(0x4CDD14));
    RPG::Map *&map = (**reinterpret_cast<RPG::Map ***>(0x4CDD74));
}

