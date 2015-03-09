#ifndef __POLYGON_H
#define __POLYGON_H

#include "Line.h"
#include "Pixel.h"
#include <cmath>

//asumsi ini convex polygon

class Polygon: public Drawable {
	vector<Line> lines;
	int mColor;
	
public:
	Polygon();
	~Polygon();
	vector<Pixel> getPixels() const;
	
	void add(Line line);
	int getSize() const;
	int getLeftMostX() const;
	int getTopMostY() const;
	bool pointInPolygon(Point p) const;
	void translate(int dx,int dy);
	void printLines() const;
};
#endif
