#include "Line3D.h"
#include "CameraService.h"
Line3D::Line3D(double x0,double y0,double z0,double x1,double y1,double z1){
	Point3D a(x0,y0,z0);
	Point3D b(x1,y1,z1);
	mBeginPoint = a; mEndPoint = b;
	Color color(255,255,255,0); //whte
	mColor = color;
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

//dummy doang
vector<Pixel> Line3D::getPixels() const{
	vector<Pixel> pixels;
	return pixels;
}

//versi perspektif
Line Line3D::getLine2D() const{
	Point first, last;
	//scalenya dihardcode dulu
	double scale = 1;
	first.x = 400 * (getBeginPoint()).x / ((getBeginPoint()).z*scale + 100);
	first.y = 400 * (getBeginPoint()).y / ((getBeginPoint()).z*scale + 100);
	last.x =  400 * (getEndPoint()).x / ((getEndPoint()).z*scale + 100);
	last.y =  400 * (getEndPoint()).y / ((getEndPoint()).z*scale + 100);
	Color white(255,255,255,0);
	Line l(first,last,white);
	return l;
}

void Line3D::beforeDraw(){
	Point3D &cpos = CameraService::position;
	Point3D &p1 = mBeginPoint;
	Point3D &p2 = mEndPoint;
	this->translate(-cpos.x,-cpos.y,cpos.z);
	float PI = 3.14159265;
	float tethaHorizontalInRadian = CameraService::mCameraDegreeHorizontal*PI/180;
	p1.x = p1.x * cos(tethaHorizontalInRadian) + (p1.z * sin(tethaHorizontalInRadian));
	p1.z = p1.x * -1 * sin(tethaHorizontalInRadian) + (p1.z * cos(tethaHorizontalInRadian));
	p2.x = p2.x * cos(tethaHorizontalInRadian) + (p2.z * sin(tethaHorizontalInRadian));
	p2.z = p2.x * -1 * sin(tethaHorizontalInRadian) + (p2.z * cos(tethaHorizontalInRadian));
}

void Line3D::afterDraw(){
	Point3D &cpos = CameraService::position;
	Point3D &p1 = mBeginPoint;
	Point3D &p2 = mEndPoint;
	float PI = 3.14159265;
	float tethaHorizontalInRadian = -1 * CameraService::mCameraDegreeHorizontal*PI/180;
	p1.x = p1.x * cos(tethaHorizontalInRadian) + (p1.z * sin(tethaHorizontalInRadian));
	p1.z = p1.x * -1 * sin(tethaHorizontalInRadian) + (p1.z * cos(tethaHorizontalInRadian));
	p2.x = p2.x * cos(tethaHorizontalInRadian) + (p2.z * sin(tethaHorizontalInRadian));
	p2.z = p2.x * -1 * sin(tethaHorizontalInRadian) + (p2.z * cos(tethaHorizontalInRadian));
	this->translate(cpos.x,cpos.y,-cpos.z);
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

Point3D Line3D::getBeginPoint() const{
	return mBeginPoint;
}

Point3D Line3D::getEndPoint() const{
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
