#ifndef SCENEGAMEOVER_H
#define SCENEGAMEOVER_H
namespace RPG {
	class Image;
	//! Not implemented yet
	typedef void AuroraBoard;

	/*! \brief The Game Over scene.
		\sa RPG::gameOver
	*/
	class SceneGameOver {
		public:
			void **vTable;
				AuroraBoard *AuroraBoard1; //!< Not even a little bit implemented...
				AuroraBoard *AuroraBoard2; //!< Not even a little bit implemented...
			bool initialized; //!< Has the game over scene initialized?
			Image *image; //!< The game over image itself. Only accessible if a game over has been triggered. (See RPG::Image)
	};

	/*! \ingroup game_objects
		\brief Access to the game over scene
	*/
	extern RPG::SceneGameOver *&gameOver;
}
#endif /* SCENEGAMEOVER_H */
