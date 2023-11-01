#include "DevWindow.h"
#include <iostream>

namespace DevWorkSpace
{

DevWindow DevWindow::getWindow(){ return *this;}

DevWindow DevWindow::show(){return *this;}
    
DevWindow DevWindow::addMenuOption(const DevWorkSpace::TopMenuOption *opt){return *this;}
    
int DevWindow::run(int argc, char **argv){
  std::cout <<"Remove me";
  return 0;
}



} // namespace DevWorkB


