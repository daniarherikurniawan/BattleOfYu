#ifndef CLIP_DRAWABLE_H
#define CLIP_DRAWABLE_H

#include "Drawable.h"
#include "Line.h"
#include "Pixel.h"
#include <vector>

class ClipDrawable : public Drawable {
private:
	vector<Line> mLines;
	int mWindowWidth,mWindowHeight;
	
public:
	ClipDrawable(int width,int height,int windowWidth,int windowHeight);
	virtual int getLeftMostX() const;
	virtual int getTopMostY() const;
	vector<Pixel> getPixels();
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