#pragma once
#include <FL/Fl_Window.H>

#include "TopMenuOption.h"

namespace DevWorkSpace
{

class DevWindow{

   public:

      DevWindow getWindow();
      DevWindow show();
      DevWindow addMenuOption(const DevWorkSpace::TopMenuOption *opt);
      int run(int argc, char **argv);

   protected:

   Fl_Window *window;

};







};