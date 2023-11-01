#pragma once
#include <Fl/Fl_Window.H>

#include "TopMenuOption.H"

namespace DevWorkSpace
{

class DevWindow{

   public:

      DevWindow getWindow();
      DevWindow show();
      DevWindow addMenuOption(const TopMenuOption *opt);
      int run(int argc, char **argv);

   protected:

   Fl_Window *window;

};







};