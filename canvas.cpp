#include <iostream>
#include "canvas.h"

using namespace std;

Canvas::void canvas_resize (int width, int height)
{
    canvas.resize(width*height);
}

Canvas::void box_shift_up (int topLeft, int botRight)
{
    topRight = botright % width + topleft - topleft % width
	lines = botRight % height - topLeft % height // how many lines to shift after shifting first									line

	for(int i = 0; i <= lines; i++)
	{
		for(int j = (topLeft + i*width); j <= (topRight + i*width); j++)
		{
			if(j - width >= 0)
			{
				canvas[j - width] = canvas[j];
			}

			if(i == lines)
			{
				canvas[j].red = 0;
				canvas[j].green = 0;
				canvas[j].blue = 0;
			}
		}
	}
}

Canvas::void box_shift_down (int topLeft, int botRight)
{
   //topRight = botRight % width + topLeft - topLeft % width
	lines = botRight % height - topLeft % height // how many lines to shift after shifting first line
	botLeft = topLeft + lines * width;

	for(int i = lines; i <= 0; i--)
	{

		for(int j = botRight - ((lines - i) * width); j <= botLeft - ((lines - i) * width); j--)
		{
			if(j + width <= width * height)
			{
				canvas[j + width] = canvas[j];
			}

			if(i == 0)
			{
				canvas[j].red = 0;
				canvas[j].green = 0;
				canvas[j].blue = 0;
			}
		}
	}
}

Canvas::void box_shift_right (int topLeft, int botRight)
{
    //topRight = botRight % width + topLeft - topLeft % width
	lines = botRight % height - topLeft % height // how many lines to shift after shifting first line
	botLeft = topLeft + lines * width;

	for(int i = lines; i <= 0; i--)
	{

		for(int j = botRight - ((lines - i) * width); j <= botLeft - ((lines - i) * width); j--)
		{
			if((j % width) + 1 <= width)
			{
				canvas[j + 1] = canvas[j];
			}

			if(j == botLeft - ((lines - i) * width))
			{
				canvas[j].red = 0;
				canvas[j].green = 0;
				canvas[j].blue = 0;
			}
		}
	}
}

Canvas::void box_shift_left (int topLeft, int botRight)
{
    topRight = botright % width + topleft - topleft % width
	lines = botRight % height - topLeft % height // how many lines to shift after shifting first									line

	for(int i = 0; i <= lines; i++)
	{
		for(int j = (topLeft + i*width); j <= (topRight + i*width); j++)
		{
			if((j % width) - 1 >= 0)
			{
				canvas[j - 1] = canvas[j];
			}

			if(j == (topRight + i*width))
			{
				canvas[j].red = 0;
				canvas[j].green = 0;
				canvas[j].blue = 0;
			}
		}
	}
}

Canvas::void box_color(int topLeft, int botRight, rgb color)
{
	topRight = botright % width + topleft - topleft % width
	lines = botRight % height - topLeft % height // how many lines to shift after shifting first									line

	for(int i = 0; i <= lines; i++)
	{
		for(int j = (topLeft + i*width); j <= (topRight + i*width); j++)
		{
			canvas[j].red = color.red;
			canvas[j].green = color.green;
			canvas[j].blue = color.blue;
		}
	}
}
