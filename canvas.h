#ifndef CANVAS_H_INCLUDED
#define CANVAS_H_INCLUDED



#endif // CANVAS_H_INCLUDED

#include <iostream>

using namespace std;
//This Class defines the rgb colors and the functions available to be performed on the canvas
class Canvas
{

private:
//Stores the rgb values the user defines on the color wheel
    struct rgb
    {
        int red;
        int green;
        int blue;
    };

public:
//Stores the user defined box selected in the current frame
    int width, height;
    std::vector<rgb> canvas;
    //Pixel manipulation of the box selected
    void canvas_resize(int width, int height);
    void box_shift_up(int topLeft, int botRight);
    void box_shift_down(int topLeft, int botRight);
    void box_shift_right(int topLeft, int botRight);
    void box_shift_left(int topLeft, int botRight);
    void box_color(int topLeft, int botRight, rgb color);

};

