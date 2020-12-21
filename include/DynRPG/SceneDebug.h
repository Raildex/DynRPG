#ifndef SCENEDEBUG_H
#define SCENEDEBUG_H
namespace RPG {
	class Window;
	//! Not implemented yet
	typedef void AuroraBoard;

	/*! \brief The Debug scene upon pressing F9 in test play mode.
		\sa RPG::debug
	*/
	class SceneDebug {
		public:
			void **vTable;
				AuroraBoard *AuroraBoard1; //!< Not even a little bit implemented...
				AuroraBoard *AuroraBoard2; //!< Not even a little bit implemented...
			Window *winLeftDebug; //!< The window object for Left side of the window. Can only be called after it's been drawn.
			Window *winRightDebug; //!< The window object for Right side of the window. Can only be called after it's been drawn.
			Window *winSetValue; //!< The window object for when a value has been set? Not so sure about this one...
			bool initialized;
	};

	/*! \ingroup game_objects
		\brief Access to the debug scene (because why not?!)
	*/
	extern RPG::SceneDebug *&debug;

}
#endif /* SCENEDEBUG_H */
