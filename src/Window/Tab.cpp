#include "Tab.h"

#include <Fl/Fl_Box.H>

Tab::Tab():Fl_Tabs(0,0, 400, 200)
{ 
        this->color(0xffff00ff);

        this->begin();
        this->add(new Fl_Box(0,0,w(), h()));
        this->end();
}