#include "Line3D.h"

Line3D::Line3D(double x0,double y0,double z0,double x1,double y1,double z1){
	Point3D a(x0,y0,z0);
	Point3D b(x1,y1,z1);
	mBeginPoint = a; mEndPoint = b;
}

Line3D::Line3D(Point3D beginPoint,Point3D endPoint,Color color) {
	mBeginPoint = beginPoint;
	mEndPoint = endPoint;
	mWidth = abs(mBeginPoint.x-mEndPoint.x)+1;
	mHeight = abs(mBeginPoint.y-mEndPoint.y)+1;
	mPositionX = 0;
	mPositionY = 0;
	mColor = color;
}

//TBD
vector<Pixel> Line3D::getPixels() const{
	printf("Line3D::getPixels() not supported\n");
	vector<Pixel> pixels;
	return pixels;
}

int Line3D::getLeftMostX() const{
  int x0 = mBeginPoint.x;
  int x1 = mEndPoint.x;
  int leftX = (x0<x1) ? x0 : x1;
  return leftX + mPositionX;
}

int Line3D::getTopMostY() const{
  int y0 = mBeginPoint.y;
  int y1 = mEndPoint.y;
  int topY = (y0<y1) ? y0 : y1;
  return topY + mPositionY;
}

Color Line3D::getColor() const{
	return mColor;
}

void Line3D::rotate(int angle,int x0,int y0){
	printf("line3d rotation not supported\n");
}

Point3D Line3D::getBeginPoint() {
	return mBeginPoint;
}

Point3D Line3D::getEndPoint() {
	return mEndPoint;
}

void Line3D::setBeginPoint(Point3D mBegin){
	mBeginPoint = mBegin;
}

void Line3D::setEndPoint(Point3D mEnd){
	mEndPoint = mEnd;
}

void Line3D::translate(double x0,double y0,double z0){
	mBeginPoint.translate(x0,y0,z0);
	mEndPoint.translate(x0,y0,z0);
}

