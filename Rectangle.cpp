#include "Rectangle.h"

Rectangle::Rectangle(Point start,int width,int height,Color color) {

	mPositionX = start.x;
	mPositionY = start.y;
	mWidth = width;
	mHeight = height;
	mColor = color;
}

vector<Pixel> Rectangle::getPixels() const{

	Point p1(mPositionX,mPositionY);
	Point p2(mPositionX+mWidth,mPositionY);
	Point p3(mPositionX,mPositionY+mHeight);
	Point p4(mPositionX+mWidth,mPositionY+mHeight);

	Line line1(p1,p2,mColor);
	Line line2(p2,p4,mColor);
	Line line3(p3,p4,mColor);
	Line line4(p1,p4,mColor);

	vector<Pixel> linePixels1 = line1.getPixels();
	vector<Pixel> linePixels2 = line2.getPixels();
	vector<Pixel> linePixels3 = line3.getPixels();
	vector<Pixel> linePixels4 = line4.getPixels();

	vector<Pixel> pixels;

	pixels.insert(pixels.end(),linePixels1.begin(),linePixels1.end());
	pixels.insert(pixels.end(),linePixels2.begin(),linePixels2.end());
	pixels.insert(pixels.end(),linePixels3.begin(),linePixels3.end());
	pixels.insert(pixels.end(),linePixels4.begin(),linePixels4.end());

	return pixels;
}

int Rectangle::getLeftMostX() const {
	return mPositionX;
}

int Rectangle::getTopMostY() const {
	return mPositionY;
}