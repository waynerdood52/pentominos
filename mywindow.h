#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <gtkmm.h>
#include <hildonmm.h>

class MyWindow : public Hildon::Window
{
public:
	MyWindow();
	virtual ~MyWindow();

protected:
	/* Signal handlers */
	void on_menu_quit();
	void on_menu_about();

	/* Menu object */
	Gtk::Menu m_main;

	/* The menu items */
	Gtk::MenuItem m_main_exit;
	Gtk::MenuItem m_main_about;
};

#endif /* MYWINDOW_H */
