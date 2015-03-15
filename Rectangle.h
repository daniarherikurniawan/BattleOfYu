#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Drawable.h"
#include "Line.h"
#include "Pixel.h"
#include <vector>

class Rectangle : public Drawable{
private:
	Color mColor;
public:
	Rectangle(Point start,int width,int height,Color color);
	int getLeftMostX() const;
	int getTopMostY() const;
	vector<Pixel> getPixels() const;
	void rotate(int angle,int x0,int y0);
};

#endif