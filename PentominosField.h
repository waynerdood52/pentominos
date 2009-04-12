#ifndef PENTOMINOSFIELD_H
#define PENTOMINOSFIELD_H

#include <gtkmm/drawingarea.h>
#include "PentominosTable.h"

class PentominosField : Gtk::DrawingArea {
protected:
	virtual void on_size_request (Gtk::Requisition* requisition);
	virtual bool on_expose_event(GdkEventExpose* event);
public:
	PentominosTable table;

	PentominosField();
	virtual ~PentominosField();

};

#endif /*PENTOMINOSFIELD_H*/
