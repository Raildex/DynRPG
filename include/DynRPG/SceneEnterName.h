#ifndef SCENEENTERNAME_H
#define SCENEENTERNAME_H
namespace RPG {
	class Window;
	class Image;
	//! Not implemented yet
	typedef void AuroraBoard;

	/*! \brief The Enter Hero Name scene.
		\sa RPG::enterName
	*/
	class SceneEnterName {
		public:
			void **vTable;
				AuroraBoard *AuroraBoard1; //!< Not even a little bit implemented...
				AuroraBoard *AuroraBoard2; //!< Not even a little bit implemented...
			bool initialized; //!< Has the enter hero name scene initialized?
			Window *winFace; //!< The window that contains the faceset
			Window *winName; //!< use winName->string to get the name string itself
			Window *winInput; //!< use winInput->fontSet to get the fontset used
			Image *faceImage; //!< The face image itself
			int heroId; //!< The ID of the hero
			int initialFontSet; //!< The initial font set
			bool keepDefaultName; //!< Keep the default name? (??)

	};

	/*! \ingroup game_objects
		\brief Access to the Enter Hero Name scene
	*/
	extern RPG::SceneEnterName *&enterName;

}
#endif /* SCENEENTERNAME_H */
