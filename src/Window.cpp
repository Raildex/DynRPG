#include "Window.h"
#include "DString.h"
RPG::Window::Window() {
	int n = 1;
	asm volatile("call *%%esi" : : "S" (0x4C6330), "a" (0x4C5F30), "d" (n) : "ecx", "cc", "memory");
}

void RPG::Window::create(int width, int height, int x, int y, bool startHidden) {
	asm volatile("push %%eax" : : "a" (width));
	asm volatile("push %%eax" : : "a" (height));
	asm volatile("push %%eax" : : "a" (startHidden));
	asm volatile("call *%%esi" : : "S" (0x4C63DC), "a" (this), "d" (x), "c" (y) : "cc", "memory"); // cc = condition codes
}

void RPG::Window::clear() {
	asm volatile("call *%%esi" : : "S" (0x4C63A0), "a" (this) : "edx", "ecx", "cc", "memory");
}

void RPG::Window::redraw() {
	asm volatile("call *%%esi" : : "S" (0x4C6CF8), "a" (this), "d" (width), "c" (height) : "cc", "memory");
}

void RPG::Window::updateCursor(int choice) {
	asm volatile("call *%%esi" : : "S" (0x4C6810), "a" (this), "d" (choice) : "ecx", "cc", "memory");
}

void RPG::Window::refresh() {
	asm volatile("call *%%esi" : : "S" (0x4C6640), "a" (this) : "edx", "ecx", "cc", "memory");
}

void RPG::Window::destroy() { // destroys the window and all of its members
	asm volatile("call *%%esi" : : "S" (0x4C66E4), "a" (this) : "edx", "ecx", "cc", "memory");
}

/*! \brief Built-in RM2k3 function that draws a string to a Window. (experimental)
*/

inline void RPG::Window::drawString(int x, int y, std::string text, int color, bool initialize)
{
	RPG::DStringPtr *par1 = new DStringPtr(text); // *cue holy music*
	asm volatile("push %%eax"
		:
	: "a" (par1->str));
	asm volatile("push %%eax"
		:
	: "a" (color));
	asm volatile("push %%eax"
		:
	: "a" (initialize));
	asm volatile("call *%%esi"
		: "=a" (RPG::_eax), "=c" (RPG::_ecx), "=d" (RPG::_edx)
		: "S" (0x4C6EA8), "a" (this), "c" (y), "d" (x)
		: "cc", "memory");
	delete par1;
}

RPG::Window::~Window() {
	int n = 1;
	asm volatile("call *%%esi" : : "S" (0x40376), "a" (this) : "edx", "ecx", "cc", "memory");
}

int RPG::Window::getSelected() {
	if (this->choiceActive) {
		return this->currentChoice;
	}
	else return -1;
}

RPG::WindowMessage::WindowMessage() {
	int n = 1;
	asm volatile("call *%%esi" : : "S" (0x4C712C), "a" (0x4C605C), "d" (n) : "cc", "memory"); // welp
}

RPG::WindowMessage::~WindowMessage() {
	int n = 1;
	asm volatile("call *%%esi" : : "S" (0x40376), "a" (this) : "cc", "memory");
}

void RPG::WindowMenuSkill::refreshSkills() {
	asm volatile("call *%%esi" : : "S" (0x4C9274), "a" (this) : "edx", "ecx", "cc", "memory");
}

inline std::string RPG::WindowMessageBox::getLine(int line) {
	return txt[line * 2].s_str();
}

inline void RPG::WindowMessageBox::setLine(int line, std::string text) {
	txt[line * 2] = text;
}

