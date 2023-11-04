#ifndef DEVSTYLE_H_DEFINED
#define DEVSTYLE_H_DEFINED
#include <cstdint.h>
#include <cstdlib>

namespace DevWorkSpace{
struct ControlStyle{
   uint32_t textsize;
   uint32_t background_color;
   uint32_t textstyle_color;
   uint32_t mouseover_color;
   uint32_t mouseover_text_color;
   uint32_t focus_color;
   uint32_t focus_text_style;
};

ControlStyle window_style;
ControlStyle menuBar_style;
ControlStyle bottomBarStyle;
///\ this style is for only the text-editor without coloring.
ControlStyle TextEditorStyle;

void initDefaultClearStyle();
void initDefaultDarkStyle();

}
#endif