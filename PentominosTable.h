#ifndef PENTOMINOSTABLE_H
#define PENTOMINOSTABLE_H

#include <gtkmm/drawingarea.h>

class PentominosTable {
private:
	char* t;
public:
	int w,h;

	PentominosTable(int width = 8, int height = 8);
	virtual ~PentominosTable();

	inline char& at(int x, int y);
};

#endif /*PENTOMINOSTABLE_H*/
