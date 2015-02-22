#ifndef RODA_H
#define RODA_H

#include "Drawable.h"
#include "Pixel.h"
#include <stdio.h>
#include <unistd.h>
#include "Screen.h"

class Roda : public Drawable{
private:
	int radius;
	Point center;
	Color color;

	bool finish;
	bool rolling;
	int velocity;
	int speed_reducer;
	int limit;
	int x_counter;

public:
	Roda();
	int getRadius() const;
	void setRadius(int r);
	Point getCenter() const;
	void setCenter(Point mid);
	bool bounce(); //return true jika masih mantul, false jika sudah berhenti
	vector<Pixel> getPixels() const;
	int getLeftMostX() const;
	int getTopMostY() const;
	void setColor(Color c) ;
	Color getColor() const;
	void translate(int dx, int dy);
	void rotate(int angle, int x0, int y0);
	int applyGravity(int velocity);
	void moveBy(int x, int y);
};

#endif
