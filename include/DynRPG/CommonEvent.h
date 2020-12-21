#ifndef COMMONEVENT_H
#define COMMONEVENT_H
#include "DString.h"
#include "Catalog.h"
namespace RPG {
	class EventScriptList;
	//! Possible values for the RPG::CommonEvent::trigger member
	enum CommonEventTrigger {
		CET_AUTO_START = 3,
		CET_PARALLEL_PROCESS,
		CET_CALL
	};

	//! One-byte version of RPG::CommonEventTrigger
	typedef unsigned char CommonEventTrigger_T;

	/*! \brief Access to the common events.
		\sa RPG::commonEvents
		\sa RPG::CommonEventTrigger
	*/
	class CommonEvent {
		public:
			void **vTable;
			int id; //!< The ID of the common event
			DStringPtr name; //!< The name of the common event
				int _unknown_0C;
				int _unknown_10;
			EventScriptList *scriptLines; //!< The event script lines
			CommonEventTrigger_T trigger; //!< The trigger condition for the common event
			bool switchActivated; //!< Is the common event activated via switch?
			int switchId; //!< The switch ID if activated via switch

	};

	/*! \ingroup game_objects
		\brief Access to the common events.
	*/
	extern RPG::NamedCatalogPtr<RPG::CommonEvent *> &commonEvents;

	/*! \brief Easily returns a common event line.

		Allows you to write <tt>RPG::getCommonEventLine(12,1)->command</tt> instead of <tt>RPG::commonEvents[12]->scriptLines->list->items[1]->command</tt> which gets the 2nd line of common event 12.

		\param id The common event ID (one-based)
		\param lineId The line ID (zero-based)

		\sa RPG::CommonEvent
	*/
	RPG::EventScriptLine *getCommonEventLine(int id, int lineId);
}
#endif /* COMMONEVENT_H */
