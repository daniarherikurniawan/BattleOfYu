#include "Pixel.h"

struct Point;
struct Color;

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

Point3D::Point3D(): x(0),y(0),z(0){};
Point3D::Point3D(double x,double y,double z): x(x),y(y),z(z){};


Color::Color() :red(0),green(0),blue(0) {

}
Color::Color(int red,int green,int blue,int alpha) : red(red),green(green),blue(blue),alpha(alpha) {

}

