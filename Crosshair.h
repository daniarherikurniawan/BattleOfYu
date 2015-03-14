#ifndef CROSSHAIR_MANAGER
#define CROSSHAIR_MANAGER
#include "Drawable.h"
#include "Pixel.h"
#include <vector>
#define CROSSHAIR_SIZE 15
using namespace std;

class Crosshair: public Drawable {
	Point mPosition;
	Color mColor;
	vector<Point> mPoints; //crosshair points
	
public:
	Crosshair();
	vector<Pixel> getPixels() const;
	int getLeftMostX() const;
	int getTopMostY() const;
	int getPointsSize() const;
	Point getPosition() const;
	void setPosition(Point p);
	void updateFromKeyboard();
};
#endif
