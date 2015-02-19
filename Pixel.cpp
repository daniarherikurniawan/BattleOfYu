#include "Pixel.h"

struct Point;
struct Color;
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

Color::Color() :red(0),green(0),blue(0) {

}
Color::Color(int red,int green,int blue,int alpha) : red(red),green(green),blue(blue),alpha(alpha) {

}

