/*******************************************************************************
 * Copyright (c) 2007-2008 INdT.
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.

 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/*
 ============================================================================
 Name        : main.cpp
 Author      : MacGuru
 Version     : 0.1
 Description : CPP Hello Example
 ============================================================================
 */

#include <hildonmm.h>
#include <iostream>

#include "mywindow.h"

int main(int argc, char *argv[])
{
	/* Initialize gtkmm and checks the arguments passed to your application */
	Gtk::Main main_loop(&argc, &argv);

	/* Initialize the hildomm libraries */
	Hildon::init();

	/* Initialize libosso environment */
	osso_context_t* osso_context = osso_initialize("helloworld", "1.0.0", TRUE, 0);
	if(!osso_context)
		std::cerr << "osso_initialize() failed." << std::endl;

	/* Set the application name */
	Glib::set_application_name("Hello World!!!");

	/* Create an object for the main Window and attach it to the program */
	MyWindow window;
	Hildon::Program::get_instance()->add_window(window);

	/* Begin the main application */
	main_loop.run(window);

	/* Clean the libosso environment */
	osso_deinitialize(osso_context);

	return 0;
}
