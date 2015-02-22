#ifndef RODA_H
#define RODA_H

#include "Drawable.h"
#include "Pixel.h"
#include <stdio.h>
#include <unistd.h>
#include "Screen.h"

class Roda : public Drawable{
private:
	int radius;
	Point center;
	Color color;

public:
	Roda();
	int getRadius() const;
	void setRadius(int r);
	Point getCenter() const;
	void setCenter(Point mid);
	void bounce();
	vector<Pixel> getPixels() const;
	int getLeftMostX() const;
	int getTopMostY() const;
	void setColor(Color c) ;
	Color getColor() const;
	void translate(int dx, int dy);
	void rotate(int angle, int x0, int y0);
};

#endif