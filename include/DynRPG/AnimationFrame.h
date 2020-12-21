#ifndef ANIMATIONFRAME_H
#define ANIMATIONFRAME_H
#include "Catalog.h"

namespace RPG
{
	class AnimationFrameCel;
	/*! \brief Used to define an animation's frame and its cels.
		\sa RPG::AnimationFrameCel
		\sa RPG::Animation
		\sa RPG::battleAnimations

	*/
	class AnimationFrame
	{
	public:
		void **vTable;
		int id; //!< ID of the frame
		int _unknown_08;
		CatalogPtr<AnimationFrameCel *> cels; //!< Pointer to the RPG::AnimationFrameCel array
	};
} // namespace RPG
#endif
