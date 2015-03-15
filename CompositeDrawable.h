#ifndef COMPOSITEDRAWABLE_H
#define COMPOSITEDRAWABLE_H
#include "Drawable.h"
#include <fstream>
#include <string>
#include <iostream>
#include "Line.h"
using namespace std;

class CompositeDrawable : public Drawable{
private :
	vector<Drawable*> mDrawables;
	int mLeftMostX,mRightMostX;
	int mTopMostY,mBottomMostY;
	
public :
	CompositeDrawable();
	CompositeDrawable(string fileName);
	void add(Drawable *drawable);
	vector<Pixel> getPixels() const;
	~CompositeDrawable();
	int getLeftMostX() const;
	int getTopMostY() const;
	void rotate(int angle,int x0,int y0);
};

#endif

