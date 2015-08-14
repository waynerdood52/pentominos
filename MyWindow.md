# Introduction #
As a subclass of `Hildon::Window`, his class actually the main (and only) window for the application. It holds a [PentominosField](PentominosField.md) (`pfield`), and generates and handles the application menu.

# Functions #
### Menu handlers ###
```
void on_menu_quit();
void on_menu_about();
void on_menu_help();
void on_menu_restart();
```
Each handles the corresponding menu, connected by `signal_activate().connect()`.

### Fullscreen button handler ###
```
virtual bool on_key_press_event(GdkEventKey* event);
```

### Tables menu generation ###
```
void buildTablesMenu();
```
This function allocates memory for an array of [PentominosMenuItem](PentominosMenuItem.md), then initalizes them.