#include "Line.h"

Line::Line(Point beginPoint,Point endPoint,Color color) {
	mBeginPoint = beginPoint;
	mEndPoint = endPoint;
	mWidth = abs(mBeginPoint.x-mEndPoint.x)+1;
	mHeight = abs(mBeginPoint.y-mEndPoint.y)+1;
	mPositionX = 0;
	mPositionY = 0;
	mColor = color;
}
vector<Pixel> Line::getPixels() const{
	int x1 = mBeginPoint.x;
	int x0 = mEndPoint.x;
	int y1 = mBeginPoint.y;
	int y0 = mEndPoint.y;
	int dx =  abs(x1-x0), sx = x0<x1 ? 1 : -1;
  	int dy = -abs(y1-y0), sy = y0<y1 ? 1 : -1; 
   	int err = dx+dy, e2; /* error value e_xy */
 
 	vector<Pixel> pixels;
	for(;;){  /* loop */
		Point position(x0,y0);
		Pixel pixel(position,mColor);
	 	pixels.push_back(pixel);
	  	if (x0==x1 && y0==y1) break;
	  	e2 = 2*err;
	  	if (e2 >= dy) { err += dy; x0 += sx; } /* e_xy+e_x > 0 */
	  	if (e2 <= dx) { err += dx; y0 += sy; } /* e_xy+e_y < 0 */
	}
	for (int i=0;i<pixels.size();i++) {
		Point initialPosition = pixels[i].getPosition();
		Point endPosition(initialPosition.x+mPositionX,initialPosition.y+mPositionY);
		pixels[i].setPosition(endPosition);
	}
	return pixels;
}

int Line::getLeftMostX() const{
  int x0 = mBeginPoint.x;
  int x1 = mEndPoint.x;
  int leftX = (x0<x1) ? x0 : x1;
  return leftX + mPositionX;
}

int Line::getTopMostY() const{
  int y0 = mBeginPoint.y;
  int y1 = mEndPoint.y;
  int topY = (y0<y1) ? y0 : y1;
  return topY + mPositionY;
}

Color Line::getColor() const{
	return mColor;
}

void Line::rotate(int angle,int x0,int y0){
	mBeginPoint.rotate(angle,x0,y0);
	mEndPoint.rotate(angle,x0,y0);
	mWidth = abs(mBeginPoint.x-mEndPoint.x + 1);
	mHeight = abs(mBeginPoint.y-mEndPoint.y + 1);
	mPositionX = 0;
	mPositionY = 0;
}

void Line::translate(int dx,int dy){
	mBeginPoint.translate(dx,dy);
	mEndPoint.translate(dx,dy);
	mWidth = abs(mBeginPoint.x-mEndPoint.x + 1);
	mHeight = abs(mBeginPoint.y-mEndPoint.y + 1);
}

Point Line::getBeginPoint() const {
	return mBeginPoint;
}

Point Line::getEndPoint() const{
	return mEndPoint;
}

void Line::setBeginPoint(Point mBegin){
	mBeginPoint = mBegin;
}

void Line::setEndPoint(Point mEnd){
	mEndPoint = mEnd;
}


