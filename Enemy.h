#ifndef ENEMY_H
#define ENEMY_H

#include "Drawable.h"
#include "Line.h"
#include "Pixel.h"
#include <vector>
#include "CameraService.h"

class Enemy : public Drawable {
private:
	Color color;
	int radius;
	Point3D center;
public:
	Enemy(Point3D center, Color color);
	int getLeftMostX() const;
	int getTopMostY() const;
	int getBottomMostY() const;
	int getRightMostX() const;
	vector<Pixel> getPixels() const;
	void rotate(int angle,int x0,int y0);
	void setCenter(Point3D c);
	void beforeDraw();
	void afterDraw();
	void translate(double dx,double dy,double dz);
	Point3D getCenter() const;
};

#endif
