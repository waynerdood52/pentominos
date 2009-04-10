#include <gtkmm.h>
#include <hildonmm.h>

#include "mywindow.h"

/* Class constructor */
MyWindow::MyWindow() :
	m_main_exit("Exit"),
	m_main_about("About")
{
	/* Add items to the menu */
	m_main.append(m_main_about);
	m_main.append(m_main_exit);
	m_main.show_all();

	/* Attach the menu object to the application */
	set_menu(m_main);

	/* Attach the callback function to signal handler */
	m_main_exit.signal_activate().connect(sigc::mem_fun(*this, &MyWindow::on_menu_quit));
	m_main_about.signal_activate().connect(sigc::mem_fun(*this, &MyWindow::on_menu_helloworld));

	/* Make all menu widgets visible */
	show_all();
}

/* Class destructor */
MyWindow::~MyWindow(){}

/* Callback function for menu exit */
void MyWindow::on_menu_quit() {
	hide();
}

void MyWindow::on_menu_about() {
	/* Create and show a "Hello World" dialog */
	/*Hildon::Note helloworld_note(Hildon::NOTE_TYPE_INFORMATION, "Hello World!!!");
	helloworld_note.run();*/
}
