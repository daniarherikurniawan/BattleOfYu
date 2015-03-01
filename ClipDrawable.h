#ifndef CLIP_DRAWABLE_H
#define CLIP_DRAWABLE_H

#include "Drawable.h"
#include "Line.h"
#include "Pixel.h"
#include "WorldMap.h"
#include "Rectangle.h"
#include <vector>
#include <iostream>
using namespace std;

class ClipDrawable : public Drawable{
private:
	Point mWindowPosition;
	int mWindowWidth,mWindowHeight;
	WorldMap mWorldMap;
	Line scaleLineToView(Line line) const;
	float mScale;
public:
	ClipDrawable(int width,int height,int windowWidth,int windowHeight);
	void setWorldMap(WorldMap worlMap);
	void setWindowPosition(Point windowPosition);
	void panBy(int displcamentX,int displacementY);
	void zoomBy(float scale);
	void rotate(int angle,int x0,int y0);
	int getLeftMostX() const;
	int getTopMostY() const;
	vector<Pixel> getPixels() const;
	Rectangle getWindowPort() const;
};


class CohenShutterlandAlgorithm {
	private:
		static const int INSIDE = 0;
		static const int LEFT = 1;
		static const int RIGHT = 2;
		static const int BOTTOM = 4;
		static const int TOP = 8;
		static int computeOutcode(Point point,Point viewPortStart,Point viewPortEnd);
	public:
		static Line getLineInView(Line line,Point viewPortStart,Point viewPortEnd);
};



#endif