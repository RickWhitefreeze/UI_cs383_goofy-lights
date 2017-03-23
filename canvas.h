#ifndef CANVAS_H_INCLUDED
#define CANVAS_H_INCLUDED



#endif // CANVAS_H_INCLUDED

#include <iostream>

using namespace std;


class Canvas
{

private:

    struct rgb
    {
        int red;
        int green;
        int blue;
    };

public:

    int width, height;
    std::vector<rgb> canvas;

    void canvas_resize(int width, int height);

    void box_shift_up(int topLeft, int botRight);
    void box_shift_down(int topLeft, int botRight);
    void box_shift_right(int topLeft, int botRight);
    void box_shift_left(int topLeft, int botRight);
    void box_color(int topLeft, int botRight, rgb color);

};

