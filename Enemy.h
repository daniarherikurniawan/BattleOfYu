#ifndef ENEMY_H
#define ENEMY_H

#include "Drawable.h"
#include "Line.h"
#include "Pixel.h"
#include <vector>

class Enemy : public Drawable {
private:
	Color color;
	int radius;
	Point center;
public:
	Enemy(Point center, Color color);
	int getLeftMostX() const;
	int getTopMostY() const;
	int getRightMostX() const;
	int getBottomMostY() const;
	vector<Pixel> getPixels() const;
	void rotate(int angle,int x0,int y0);
	void setCenter(Point c);
	Point getCenter() const;
};

#endif