#include <iostream>
#include "canvas.h"

using namespace std;

//This function creates the user defined size of the canvas
void Canvas::canvas_resize (int width, int height)
{
    canvas.resize(width*height);
}
//This function shifts every pixel up one position and overwrites what was written there before
void Canvas::box_shift_up (int topLeft, int botRight)
{
    //The top right position of the box selected
    topRight = botright % width + topleft - topleft % width;
    //The number of rows in the box selected
	lines = botRight % height - topLeft % height; // how many lines to shift after shifting first									line
    //Traversing the matrix defined by the box selected by user
	for(int i = 0; i <= lines; i++)
	{
		for(int j = (topLeft + i*width); j <= (topRight + i*width); j++)
		{
			if(j - width >= 0)  //Only copy value of rgb if the pixel is not at the top of the canvas
			{
				canvas[j - width] = canvas[j];
			}

			if(i == lines)  //Overwrite the bottom row to the default rgb color
			{
				canvas[j].red = 0;
				canvas[j].green = 0;
				canvas[j].blue = 0;
			}
		}
	}
}

//This function shifts every pixel up one position and overwrites what was written there before
void Canvas::box_shift_down (int topLeft, int botRight)
{
    //The number of rows in the box selected
	lines = botRight % height - topLeft % height;
	//The bottom left position of the box selected
	botLeft = topLeft + lines * width;
    //Traversing the matrix defined by the box selected by user
	for(int i = lines; i <= 0; i--)
	{

		for(int j = botRight - ((lines - i) * width); j <= botLeft - ((lines - i) * width); j--)
		{
			if(j + width <= width * height) //Only copy value of rgb if the pixel is not at the bottom of the canvas
			{
				canvas[j + width] = canvas[j];
			}

			if(i == 0)  //Overwrite the top row to the default rgb color
			{
				canvas[j].red = 0;
				canvas[j].green = 0;
				canvas[j].blue = 0;
			}
		}
	}
}

void Canvas::box_shift_right (int topLeft, int botRight)
{
    //The number of rows in the box selected
	lines = botRight % height - topLeft % height;
	//The bottom left position of the box selected
	botLeft = topLeft + lines * width;
    //Traversing the matrix defined by the box selected by user
	for(int i = lines; i <= 0; i--)
	{

		for(int j = botRight - ((lines - i) * width); j <= botLeft - ((lines - i) * width); j--)
		{
			if((j % width) + 1 <= width)    //Only copy value of rgb if the pixel is not in the rightmost column
			{
				canvas[j + 1] = canvas[j];
			}

			if(j == botLeft - ((lines - i) * width)) //Overwrite the left column to the default rgb color
			{
				canvas[j].red = 0;
				canvas[j].green = 0;
				canvas[j].blue = 0;
			}
		}
	}
}

void Canvas::box_shift_left (int topLeft, int botRight)
{
    //The top right position of the box selected
    topRight = botright % width + topleft - topleft % width;
    //The number of rows in the box selected
	lines = botRight % height - topLeft % height;
    //Traversing the matrix defined by the box selected by user
	for(int i = 0; i <= lines; i++)
	{
		for(int j = (topLeft + i*width); j <= (topRight + i*width); j++)
		{
			if((j % width) - 1 >= 0)    //Only copy value of rgb if the pixel is not in the leftmost column
			{
				canvas[j - 1] = canvas[j];
			}

			if(j == (topRight + i*width))   //Overwrite the leftmost column to the default rgb color
			{
				canvas[j].red = 0;
				canvas[j].green = 0;
				canvas[j].blue = 0;
			}
		}
	}
}

void Canvas::box_color(int topLeft, int botRight, rgb color)
{
    //The top right position of the box selected
	topRight = botright % width + topleft - topleft % width;
	//The number of rows in the box selected
	lines = botRight % height - topLeft % height;
	//Traversing the matrix defined by the box selected by user
	for(int i = 0; i <= lines; i++)
	{
	    //Change every pixel in the box selected to the user defined rgb color
		for(int j = (topLeft + i*width); j <= (topRight + i*width); j++)
		{
			canvas[j].red = color.red;
			canvas[j].green = color.green;
			canvas[j].blue = color.blue;
		}
	}
}
