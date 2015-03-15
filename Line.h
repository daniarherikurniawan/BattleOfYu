#ifndef LINE_H
#define LINE_H

#include "Drawable.h"
#include <cstdlib>
#include <cstdio>

class Line : public Drawable{
private :
	Point mBeginPoint;
	Point mEndPoint;
	Color mColor;
	
public :
	Line(Point beginPoint,Point endPoint,Color color);
	vector<Pixel> getPixels() const;
	int getLeftMostX() const;

	int getTopMostY() const;
	
	void translate(int dx,int dy);
	void rotate(int angle,int x0,int y0);
	Color getColor() const;
	Point getBeginPoint() const;
	Point getEndPoint() const;

	void setBeginPoint(Point mBegin);
	void setEndPoint(Point mEnd);
};

#endif
