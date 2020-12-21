#define DYNRPG_STATIC
#include "DynASM.h"
#include "Screen.h"
#include "DynRPG.h"

namespace RPG {
	HWND Screen::getCanvasHWND() {
		try {
			return (**reinterpret_cast<HWND ****>(0x4CE048))[25][96];
		} catch(...) {
			return NULL;
		}
	}

	RPG::ScreenEffect *&RPG::Screen::effect = (**reinterpret_cast<RPG::ScreenEffect ***>(0x4CDDA8));

	void Screen::setFPS(int fps) {
		millisecondsPerFrame = 1000.0 / (double)fps;
		maxFPS = fps;
	}

	void Screen::update(Scene scene) {
		asm volatile("call *%%esi" : "=a" (_eax) : "S" (0x48CD40), "a" (**sceneObjects[scene]) : "edx", "ecx", "cc", "memory");
	}

	void Screen::toggleFullScreen(bool fullScreen) {
		asm volatile("call *%%esi"
					 : "=a"(RPG::_eax), "=d"(RPG::_edx)
					 : "S"(0x46B29C), "a"(this), "d"(fullScreen)
					 : "ecx", "cc", "memory");
	}

	void RPG::Screen::toggleLargeWindow(bool largeWindow) {
		asm volatile("call *%%esi"
					 : "=a"(RPG::_eax), "=d"(RPG::_edx)
					 : "S"(0x46B400), "a"(this), "d"(largeWindow)
					 : "ecx", "cc", "memory");
	}

}
