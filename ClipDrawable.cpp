#include "ClipDrawable.h"

ClipDrawable::ClipDrawable(int width,int height,int windowWidth,int windowHeight) {
	mWidth = width;
	mHeight = height;
	mWindowWidth = windowWidth;
	mWindowHeight = windowHeight;
	mScale = 1;
}

void ClipDrawable::setWorldMap(WorldMap worldMap) {
	mWorldMap = worldMap;
}

void ClipDrawable::setWindowPosition(Point windowPosition) {
	mWindowPosition = windowPosition;
}

void ClipDrawable::panBy(int displacementX,int displacementY) {
	mWindowPosition.x += displacementX;
	mWindowPosition.y += displacementY;
}

void ClipDrawable::zoomBy(float scale) {
	int newWidth = mWindowWidth / scale;
	int newHeight = mWindowHeight / scale;

	if (newWidth>5 && newHeight>5) {
		mWindowPosition.x += ((mWindowWidth-newWidth)/2);
		mWindowPosition.y += ((mWindowHeight-newHeight)/2);

		mWindowWidth =  newWidth;
		mWindowHeight = newHeight;
	}
}

Line ClipDrawable::scaleLineToView(Line windowLine) const{
	int windowX0 = windowLine.getLeftMostX();
	int windowY0 = windowLine.getTopMostY();
	int windowX1 = windowX0 + windowLine.getWidth() -1;
	int windowY1 = windowY0 + windowLine.getHeight() -1;

	int viewX0 = mPositionX + (windowX0 - mWindowPosition.x) * mWidth/mWindowWidth;
	int viewY0 = mPositionY + (windowY0 - mWindowPosition.y) * mHeight/mWindowHeight;
	int viewX1 = mPositionX + (windowX1 - mWindowPosition.x) * mWidth/mWindowWidth;
	int viewY1 = mPositionY + (windowY1 - mWindowPosition.y) * mHeight/mWindowHeight;

	Line newLine(Point(viewX0,viewY0),Point(viewX1,viewY1),windowLine.getColor());

	return newLine;

}

vector<Pixel> ClipDrawable::getPixels() const{
	vector<Pixel> pixels;

	Point viewPortStart(mPositionX,mPositionY);
	Point viewPortEnd(mPositionX+mWidth,mPositionY+mHeight);

	Rectangle border(viewPortStart,mWidth,mHeight,Color(255,0,0,0));
	vector<Pixel> borderPixel = border.getPixels();
	pixels.insert(pixels.end(),borderPixel.begin(),borderPixel.end());

	vector<Line> lines = mWorldMap.getLines();
	for (int i=0;i<lines.size();i++) {
		Line lineInView = CohenShutterlandAlgorithm::getLineInView(scaleLineToView(lines[i]),viewPortStart,viewPortEnd);
		vector<Pixel> linePixels = lineInView.getPixels();
		pixels.insert(pixels.end(),linePixels.begin(),linePixels.end());
	}

	for (int i=0;i<pixels.size();i++) {
		Point initialPosition = pixels[i].getPosition();
		Point endPosition(initialPosition.x+mPositionX,initialPosition.y+mPositionY);
		pixels[i].setPosition(endPosition);
	}

	return pixels;
}

int ClipDrawable::getLeftMostX() const{
	return mPositionX;
}

int ClipDrawable::getTopMostY() const{
	return mPositionY;
}

void ClipDrawable::rotate(int angle,int x0,int y0) {
	return;
}

int CohenShutterlandAlgorithm::computeOutcode(Point point,Point viewPortStart,Point viewPortEnd) {
	int outcode = INSIDE;
	if (point.y<viewPortStart.y)
		outcode |= TOP;
	else if (point.y>viewPortEnd.y)
		outcode |= BOTTOM;
	if (point.x<viewPortStart.x)
		outcode |= LEFT;
	else if (point.x>viewPortEnd.x)
		outcode |= RIGHT;
	return outcode;
}


Line CohenShutterlandAlgorithm::getLineInView(Line line,Point viewPortStart,Point viewPortEnd) {
	int x0 = line.getLeftMostX();
	int y0 = line.getTopMostY();
	int x1 = x0 + line.getWidth() - 1;
	int y1 = y0 + line.getHeight() - 1;

	Point point1(x0,y0);
	Point point2(x1,y1);

	
	int outcode1 = computeOutcode(point1,viewPortStart,viewPortEnd);
	int outcode2 = computeOutcode(point2,viewPortStart,viewPortEnd);
	while(true) {

		int outcodeOut = outcode1 ? outcode1 : outcode2;
		if (!(outcode1|outcode2)){
			return Line(Point(x0,y0),Point(x1,y1),line.getColor());	
		}	
		else if (outcode1 & outcode2){
			return Line(Point(0,0),Point(0,0),Color(0,0,0,0));
		}
		else {
			int x,y;
			if ( outcodeOut & TOP ) {
				x = x0 + (x1-x0) * (viewPortStart.y - y0) / (y1-y0) ;
				y = viewPortStart.y;
			} else if (outcodeOut & BOTTOM) {
				x = x0 + (x1-x0) * (viewPortEnd.y - y0) / (y1-y0);
				y = viewPortEnd.y;
			} else if (outcodeOut & LEFT ) {
				y = y0 + (y1-y0) * (viewPortStart.x - x0) / (x1-x0);
				x = viewPortStart.x;
			} else if (outcodeOut & RIGHT) {
				y = y0 + (y1-y0) * (viewPortEnd.x - x0 ) / (x1-x0);
				x = viewPortEnd.x;
			}
			
			if (outcodeOut == outcode1) {
				x0 = x;
				y0 = y;
				outcode1 = computeOutcode(Point(x0,y0),viewPortStart,viewPortEnd);
			}
			else {
				x1 = x;
				y1 = y;
				outcode2 = computeOutcode(Point(x1,y1),viewPortStart,viewPortEnd);
			}
		}
	}
}


