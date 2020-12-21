#include "DBitmap.h"

//! Returns the HDC


//! Returns the HBITMAP

inline HBITMAP RPG::DBitmap::getHBITMAP() {
	HBITMAP ret;
	asm volatile("call *%%esi" : "=a" (ret) : "S" (0x428140), "a" (this) : "edx", "ecx", "cc", "memory");
	return ret;
}

inline HDC RPG::DBitmap::getHDC() {
	HDC ret;
	asm volatile("call *%%esi; call *%%edi" : "=a" (ret) : "S" (0x4280F8), "D" (0x423634), "a" (this) : "edx", "ecx", "cc", "memory");
	return ret;
}
