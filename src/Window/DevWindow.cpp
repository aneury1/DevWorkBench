#include "DevWindow.h"
#include <iostream>

#include <FL/Fl.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Menu.H>



DevWindow* DevWindow::window_instance = nullptr;
 


void DevWindow::MyMenuCallback(Fl_Widget *w, void *) {
  Fl_Menu_Bar *bar = (Fl_Menu_Bar*)w;				// Get the menubar widget
 
   menuIdx++;
   std::stringstream str;
   str<<"Menu call ccd"<< menuIdx;
 
   bar->add(str.str().c_str());
   bar->redraw();
 
  const Fl_Menu_Item *item = bar->mvalue();			// Get the menu item that was picked

  char ipath[256]; bar->item_pathname(ipath, sizeof(ipath));	// Get full pathname of picked item

  fprintf(stderr, "callback: You picked '%s'", item->label());	// Print item picked
  fprintf(stderr, ",atat item_pathname() is '%s'", ipath);		// ..and full pathname

  if ( item->flags & (FL_MENU_RADIO|FL_MENU_TOGGLE) ) {		// Toggle or radio item?
    fprintf(stderr, ", value is %s", item->value()?"on":"off");	// Print item's value
  }
  fprintf(stderr, "\n");
  if ( strcmp(item->label(), "Google") == 0 ) { fl_open_uri("http://google.com/"); }
  if ( strcmp(item->label(), "&Quit") == 0 ) { exit(0); }
}


 int DevWindow::showWindow(){
      Fl::scheme("gtk+");
     	
      this->widgets = new Fl_Group(0,0,w(), h());
      Fl_Menu_Bar *menu = new Fl_Menu_Bar(0,0,Fl::w(),25);		// Create menubar, items..
      menu->color(0x434343FF);
      menu->textcolor(0xffffffff);
      menu->textsize(32);
      this->color(0x434343FF);
      menu->add("&File/&Open",  "^o", MyMenuCallback);
      menu->add("&File/&Save",  "^s", MyMenuCallback, 0, FL_MENU_DIVIDER);
      menu->add("&File/&Quit",  "^q", MyMenuCallback);
      menu->add("&Edit/&Copy",  "^c", MyMenuCallback);
      menu->add("&Edit/&Paste", "^v", MyMenuCallback, 0, FL_MENU_DIVIDER);
      menu->add("&Edit/Radio 1",   0, MyMenuCallback, 0, FL_MENU_RADIO);
      menu->add("&Edit/Radio 2",   0, MyMenuCallback, 0, FL_MENU_RADIO|FL_MENU_DIVIDER);
      menu->add("&Edit/Toggle 1",  0, MyMenuCallback, 0, FL_MENU_TOGGLE);			// Default: off 
      menu->add("&Edit/Toggle 2",  0, MyMenuCallback, 0, FL_MENU_TOGGLE);			// Default: off
      menu->add("&Edit/Toggle 3",  0, MyMenuCallback, 0, FL_MENU_TOGGLE|FL_MENU_VALUE);	// Default: on
      menu->add("&Help/Google",    0, MyMenuCallback);
        // Example: show how we can dynamically change the state of item Toggle #2 (turn it 'on')
      {
            Fl_Menu_Item *item = (Fl_Menu_Item*)menu->find_item("&Edit/Toggle 2");	// Find item
            if ( item ) item->set();							// Turn it on
            else fprintf(stderr, "'Toggle 2' item not found?!\n");			// (optional) Not found? complain!
      }
      this->resizable(this);
      widgets->resizable(this);
      widgets->end();
      
     auto r = new Tab();
      
  
      this->end();
      this->show();
      return Fl::run();
   }
