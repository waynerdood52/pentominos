#include "PentominosTable.h"
#include <cairomm/context.h>

PentominosTable::PentominosTable(int width, int height) : 
	w(width),
	h(height)
{
	int x,y;
	t = new char[w][h];
	for (x=0; x<w; x++) {
		for (y=0; y<h; y++) {
			t[x][y] = '0';
		}
	}
}

PentominosTable::~PentominosTable() {
}
