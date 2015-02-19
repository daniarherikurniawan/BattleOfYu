#ifndef BITMAP_H
#define BITMAP_H

#include "Drawable.h"
#include <vector>

class Bitmap : public Drawable{

private :
	vector <vector <Color> > bitmap;
	vector <Pixel> pixels;
	bool isPixelated;
	void pixelate();
	Point beginPoint;

public :
	Bitmap(int width,int height);
	Bitmap (const Bitmap &obj);
	virtual Bitmap* clone();
	virtual ~Bitmap();
	void setPixel(Pixel pixel); //Start from (0,0)
	void setPixel(Point point,Color color); //Start from (0,0)
	void setBeginPoint(Point p);
	Color getColor(Point point) const; //Start from (0,0)
	int getWidth() const;
	int getHeight() const;
	Point getBeginPoint();
	vector<Pixel> getPixels() const;
	virtual Bitmap rotate(int angle); // derajat
	int getLeftMostX() const;
	int getTopMostY() const;
};
#endif
