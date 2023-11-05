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

#include "Tab.h"
 
static int menuIdx =0;


class DevWindow : public Fl_Double_Window{


    static DevWindow *window_instance;

    Fl_Menu_Bar* menu;
    Fl_Group* widgets;

protected:

    DevWindow(int x, int y, int w, int h): Fl_Double_Window(x,y,w,h){}

    static void MyMenuCallback(Fl_Widget *w, void *);

public:
   static DevWindow* get(){
      if(window_instance==nullptr)
         window_instance =  new DevWindow(0,0,Fl::w()/2, Fl::h()/2);
      return window_instance;
   }

   int  showWindow();
  
};





#endif