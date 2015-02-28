#include "ClipDrawable.h"

ClipDrawable::ClipDrawable(int width,int height,int windowWidth,int windowHeight) {
	mWidth = width;
	mHeight = mHeight;
	mWindowWidth = windowWidth;
	mWindowHeight = windowHeight;
}

vector<Pixel> ClipDrawable::getPixels() {
	vector<Pixel> pixels;

	Point viewPortStart(mPositionX,mPositionY);
	Point viewPortEnd(mPositionX+mWidth,mPositionY+mHeight);

	

	for (int i=0;i<mLines.size();i++) {
		Line lineInView = CohenShutterlandAlgorithm::getLineInView(mLines[i],viewPortStart,viewPortEnd);
		vector<Pixel> linePixels = linInView.getPixels();
		pixels.insert(pixels.end(),linePixels.start(),linePixels.end());
	}

	return pixels;
}

int ClipDrawable::getLeftMostX() const{
	return mPositionX;
}

int ClipDrawable::getTopMostY() const{
	return mPositionY;
}

int CohenShutterlandAlgorithm::computeOutcode(Point point,Point viewPortStart,Point viewPortEnd) {
	int outcode = INSIDE;
	if (point.y<viewPortStart.y)
		point |= TOP;
	else if (point.y>viewPortEnd.y)
		point |= BOTTOM;
	if (point.x<viewPortStart.x)
		point |= LEFT;
	else if (point.x>viewPortEnd.x)
		point |= RIGHT;
	return outcode;
}


Line CohenShutterlandAlgorithm::getLineInView(Line line,Point viewPortStart,Point viewPortEnd) {
	int x0 = line.getLeftMostX();
	int y0 = line.getTopMostY();
	int x1 = x0 + line.getWidth();
	int y1 = y0 + line.getHeight();

	Point point1(x0,y0);
	Point point2(x1,y1);

	int outcode1 = computeOutcode(point1,viwPortstart,viewPortEnd);
	int outcode2 = computeOutcode(point2,viewPortStart,viewPortEnd);

	int outcodeOut = outcode1 ? outcode1 ? outcode2;
	if (! (outcode1|outcode2))
		return line;
	else (outcode1 & outcode2)
		return Line(Point(0,0),Point(0,0),Color(0,0,0,0));
	else {
		int x,y;
		if ( outcodeOut & TOP ) {
			x = x0 + (x1-x0) * (viewPortStart.y - y0) / (y1-y0) ;
			y = viewPortStart.y;
		} else if (outcodeOut & BOTTOM) {
			x = x0 + (x1-x0) * (viewPortEnd.y = y0) / (y1-y0);
			y = viewPortEnd.y;
		} else if (outcodeOut & LEFT ) {
			y = y0 + (y1-y0) * (viewPortStart.x - x0) / (x1-x0);
			x = viewPortStart.x;
		} else if (outcodeOut & RIGHT) {
			y = y0 + (y1-y0) * (viewPortEnd.x = x0 ) / (x1-x0);
			x = viewPortEnd.x;
		}
		if (outcodeOut == outcode1) {
			x0 = x;
			y0 = y;
		}
		else {
			x1 = x;
			y1 = y;
		}
		Line nextLine (Point(x0,y0),Point(x1,y1),line.getColor());
		return getLineInView(nextLine,viewPortStart,viewPortEnd);
	}
}


