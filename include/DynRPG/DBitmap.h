#ifndef DBBITMAP_H
#define DBBITMAP_H
#include <windef.h>
namespace RPG {
	//! Wrapper class for windows' HBITMAPs
	class DBitmap {
	public:
		void **vTable;

		//! Returns the HBITMAP
		inline HBITMAP getHBITMAP();

		//! Returns the HDC
		inline HDC getHDC();
	};
}

#endif // !DBBITMAP_H

