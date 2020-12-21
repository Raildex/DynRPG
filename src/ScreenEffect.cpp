#include "ScreenEffect.h"
#include "DynASM.h"
void RPG::ScreenEffect::flash(int r, int g, int b, int intensity, int duration) {
	asm volatile("push %%eax" : : "a" (b));
	asm volatile("push %%eax" : : "a" (intensity));
	asm volatile("push %%eax" : : "a" (duration));	//duration in Frames
	asm volatile("push $0");						//? internally always zero
	asm volatile("call *%%esi"
		: "=a" (RPG::_eax), "=c" (RPG::_ecx), "=d" (RPG::_edx)
		: "S" (0x4C2D68), "a" (this), "c" (g), "d" (r)
		: "cc", "memory");
}