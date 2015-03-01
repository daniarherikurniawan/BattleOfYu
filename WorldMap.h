#ifndef WORLD_MAP_H
#define WORLD_MAP_H

#include <string>
#include <iostream>
#include <fstream>

#include "Line.h"
#include "Drawable.h"
#include "Pixel.h"
#include "Rectangle.h"

class WorldMap : public Drawable{
private:
	vector<Line> mLines; 
	Rectangle mWindowPort;
public:
	WorldMap();
	WorldMap(string inputFile);
	void setWindowPort(Rectangle windowPort);
	vector<Line> getLines() const;

	vector<Pixel> getPixels() const;
	void rotate(int angle,int x0,int y0);
	int getLeftMostX() const;
	int getTopMostY() const;
};

#endif