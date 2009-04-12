#include "PentominosField.h"
#include <cairomm/context.h>

PentominosField::PentominosField() {
	#ifndef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
		signal_size_request().connect(sigc::mem_fun(*this, &TTTArea::on_size_request));
		signal_expose_event().connect(sigc::mem_fun(*this, &TTTArea::on_expose_event));
	#endif
}

PentominosField::~PentominosField() {
}

void PentominosField::on_size_request (Gtk::Requisition* requisition) {
	*requisition = Gtk::Requisition();
	requisition->height = 300;
	requisition->width = 300;
}

bool PentominosField::on_expose_event(GdkEventExpose* event) {
	Gtk::Allocation a = get_allocation();
	int w = a.get_width();
	int h = a.get_height();
	int top,left,width,height;

	Cairo::RefPtr<Cairo::Context> cr = get_window()->create_cairo_context();

	//Clipping event area
	cr->rectangle(event->area.x, event->area.y, event->area.width, event->area.height);
	cr->clip();

	//Calculating aspect ratio, size, etc
	if (double(w)/table.w < double(h)/table.h) {
		//vertical: width is the less
		width = w;
		height = h * (double(w)/h);
		top = h - height;
		left = 0;
	} else {
		height = h;
		width = w * (double(h)/w);
		top = 0;
		left = w - width;
	}

	//Drawing field
	cr->set_line_width(1);
	cr->set_source_rgb(0, 0, 0);
	cr->rectangle(0, 0, w, h);
	cr->set_source_rgb(1, 1, 1);
	cr->set_fill_rule(Cairo::FILL_RULE_WINDING);
	cr->rectangle(0, 0, w, h);
	/*for (int x=0; x<8; x++) {
		cr->move_to(x*w/8, 0);
		cr->line_to(x*w/8, h);
	}
	for (int y=0; y<8; y++) {
		cr->move_to(0, y*h/);
		cr->line_to(w, y);
	}*/

	cr->stroke();
	return true;
}
