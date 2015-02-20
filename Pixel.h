#ifndef PIXEL_H
#define PIXEL_H
#include <string>
#include <cmath>
#include <cstdio>
const float PI = 3.1415926f;
using namespace std;
struct Point {
	int x;
	int y;
	Point();
	Point(int x,int y);
	void translate(int dx,int dy){
		x += dx; y += dy;
	}
	void rotate(int degree){
		double rad = 2.0*PI*degree/360.0;
		double _x = x*cos(rad) - y*sin(rad);
		double _y = x*sin(rad) + y*cos(rad);
		x = (int) round(_x);
		y = (int) round(_y);
	}
	void rotate(int degree,int x0,int y0){
		x -= x0; y -= y0;
		rotate(degree);
		x += x0; y += y0;
	}
};

struct Color {
	int red;
	int green;
	int blue;
	int alpha;
	Color();
	Color(int red,int green,int blue,int alpha);
	
};

class Pixel {

private :
	Point mPosition;
	Color mColor;
	
public :
	Pixel(Point position,Color color);
	Point getPosition();
	void setPosition(Point position);
	Color getColor();
	void translate(int dx,int dy);
	void rotate(int angle);
	void rotate(int angle,int x0,int y0);
};

#endif
