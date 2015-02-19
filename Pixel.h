#ifndef PIXEL_H
#define PIXEL_H
#include <string>

using namespace std;
struct Point {
	int x;
	int y;
	Point();
	Point(int x,int y);
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
	
};

#endif
