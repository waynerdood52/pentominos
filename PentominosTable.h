#ifndef PENTOMINOSTABLE_H
#define PENTOMINOSTABLE_H

#include <gtkmm/drawingarea.h>

class PentominosTable {
private:
	int w,h;
	char* t;
public:
	PentominosTable(int width = 8, int height = 8);
	virtual ~PentominosTable();
};

#endif /*PENTOMINOSTABLE_H*/
