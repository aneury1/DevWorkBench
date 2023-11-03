#ifndef DEVWINDOW_DEFINED
#define DEVWINDOW_DEFINED

#pragma once
#include <vector>
#include <memory>
#include <Fl/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Double_Window.H>
#include <Fl/Fl_Menu.H>
#include <Fl/Fl_Menu_Bar.H>
#include <stdio.h>			// fprintf()
#include <stdlib.h>			// exit()
#include <string.h>			// strcmp()
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/filename.H>		// fl_open_uri()
#include <sstream>

namespace DevWorkSpace
{
static int menuIdx =0;

// This callback is invoked whenever the user clicks an item in the menu bar

class DevWindow : public Fl_Double_Window{


    static DevWindow *window_instance;

    Fl_Menu_Bar* menu;
    Fl_Group* widgets;

protected:

    DevWindow(int x, int y, int w, int h): Fl_Double_Window(x,y,w,h){}


static void MyMenuCallback(Fl_Widget *w, void *) {
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







public:
   static DevWindow* get(){
      if(window_instance==nullptr)
         window_instance =  new DevWindow(0,0,Fl::w()/2, Fl::h()/2);
      return window_instance;
   }


   int showWindow(){
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
      this->end();
      this->show();
      return Fl::run();
   }

};



};

#endif