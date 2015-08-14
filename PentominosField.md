# Introduction #
This is the actual game field. This draws the table onto the screen, and handles tapping  events (highlighting a cell, pressing the button of an element). PentominosField is a subclass of `Gtk::DrawingArea`.

# Functions #
### Event handlers ###
```
virtual void on_size_request (Gtk::Requisition* requisition);
virtual bool on_expose_event(GdkEventExpose* event); // drawing to the screen
virtual bool on_button_press_event(GdkEventButton* event);// clicks/taps
```

### Color for a pentomino ###
```
void setColorByName(Cairo::RefPtr<Cairo::Context> cr, char name);
```
This function is used to set the drawing color for the passed `cr` `Cairo::Contect`. Called by the `on_expose_event()`.

### Click on a cell ###
```
void cellClicked(int x, int y);
```
Called by `on_button_press_event()` to mark the cell as selected, if it's possible, and maintain the count of selected cells, etc.

### Click on a button ###
```
void buttonClicked(int id);
```
Called by `on_button_press_event()` to put down a pentomino on the table, or remove it.

### Game over ###
```
void endGame();
```
Called by `buttonClicked()`, when all the 12 pentominoes are on the field. It displays a `Hildon::Banner`.

### Restart ###
```
void Restart();
```
Called by the Restart menu item, to clear the table and reset each button to their 'up' position.

### Switching table ###
```
void LoadTable(PentominosTable& t);
```
Called by a [PentominosMenuItem](PentominosMenuItem.md), this function replaces the playing table with the given one, and resets the buttons.