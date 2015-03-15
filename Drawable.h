#ifndef DRAWABLE_H
#define DRAWABLE_H

#include<vector>
#include "Pixel.h"
class Drawable {
protected:
	int mPositionX,mPositionY;
	int mWidth,mHeight;
public:
	Drawable(){}
	virtual ~Drawable();
	virtual vector<Pixel> getPixels() const=0;
	virtual void rotate(int angle,int x0,int y0);
	virtual int getLeftMostX() const =0;
	virtual int getTopMostY() const =0;
	int getWidth() const;
	int getHeight() const;
	void setPosition(int positionX,int positionY);
	void moveBy(int offsetX,int offsetY);
	Point getPosition() const;
	
	//fungsi ini digunakan untuk mengadjust objek berdasarkan perspektif kamera
	//fungsi ini harus dioverride
	//kalo enggak hasil drawnya gak sesuai keinginan
	virtual void beforeDraw();
	virtual void afterDraw();
};

#endif
