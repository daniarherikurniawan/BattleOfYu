#include "Pixel.h"
#include "CameraService.h"

struct Point;
struct Color;

const double scale = 0.001;

Point Point3D::convertToPoint2D(){
	Point ret;
	ret.x = (int) (x / (z*scale + 1));
	ret.y = (int) (y / (z*scale + 1));
	return ret;
}

void Point::translate(int dx,int dy){
	x += dx; y += dy;
}

void Pixel::rotate(int angle){
	Point p = this->getPosition();
	p.rotate(angle);
	this->setPosition(p);
}

void Pixel::rotate(int angle,int x0,int y0){
	Point p = this->getPosition();
	p.rotate(angle,x0,y0);
	this->setPosition(p);
}

Pixel::Pixel(Point position,Color color) {
	mPosition = position;
	mColor = color;
}

Point Pixel:: getPosition() {
	return mPosition;
}

void Pixel::setPosition(Point position) {
	mPosition = position;
}

Color Pixel::getColor() {
	return mColor;
}

Point::Point() : x(0),y(0) {

}
Point::Point(int x,int y) : x(x),y(y) {

}

double Point::crossProduct(Point p,Point q,Point r){
	return (double) (r.x - q.x) * (p.y - q.y) - (r.y - q.y) * (p.x - q.x);
}

bool Point::ccwTurn(Point p,Point q,Point r){
	return Point::crossProduct(p,q,r) > 0.0;
}

double Point::angle(Point a,Point b,Point c){
	double ux = b.x - a.x, uy = b.y - a.y;
	double vx = c.x - a.x, vy = c.y - a.y;
	return acos((ux * vx + uy * vy) /
		sqrt((ux * ux + uy * uy) * (vx * vx + vy * vy)));
}

Point3D::Point3D(): x(0),y(0),z(0){};
Point3D::Point3D(double x,double y,double z): x(x),y(y),z(z){};


Color::Color() :red(0),green(0),blue(0) {

}
Color::Color(int red,int green,int blue,int alpha) : red(red),green(green),blue(blue),alpha(alpha) {

}

