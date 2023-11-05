#include "DevWindow.h"
#include <iostream>


int main(int argc, char *argv[])
{
   return DevWindow::get()->showWindow();
}



///cmake -G"Visual Studio 17 2022" -T"LLVM" ..