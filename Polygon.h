#ifndef __POLYGON_H
#define __POLYGON_H

#include "Line.h"
#include "Pixel.h"
#include <cmath>
#include <algorithm>
using namespace std;


//asumsi ini convex polygon

class Polygon: public Drawable {
	vector<Line> lines;
	Color mColor;
	
public:
	Polygon();
	~Polygon();
	vector<Pixel> getPixels() const;
	vector<Point> getPointsInside() const;
	void add(Line line);
	int getSize() const;
	Point getTopLeft() const;
	Point getBottomRight() const;
	int getLeftMostX() const;
	int getTopMostY() const;
	bool pointInPolygon(Point p) const;
	void translate(int dx,int dy);
	void printLines() const;
};
#endif
