#include "PentominosTable.h"
#include <cairomm/context.h>

PentominosTable::PentominosTable(int width, int height) : 
	w(width),
	h(height)
{
	int i;
	t = new char[w*h];
	for (i=0; i<w*h; i++) {
		t[i] = '0';
	}
}

PentominosTable::~PentominosTable() {
}

char& PentominosTable::at(int x, int y) {
	return t[y*w+x];
}