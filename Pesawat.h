#ifndef PESAWAT_H
#define PESAWAT_H
#include "Drawable.h"
#include "MatrixDrawable.h"
#include "Pixel.h"
#include "Roda.h"
#include <vector>
#include <cmath>
#include <cstdio>



class Pesawat : public Drawable {
private:
	MatrixDrawable mBody;
	vector<MatrixDrawable> mInitialExplodedBody;
	vector<MatrixDrawable> mCurrentExplodedBody;
	bool mIsExploded;
	Point mExplosionCenter;
	void applyDisplacementToExplodedBody(int displacement);
public:
	Pesawat();
	void startExplode(Point centerPoint);
	void explode(float percentage);
	void finishExplode();
	int getLeftMostX() const;
	int getTopMostY() const;
	vector<Pixel> getPixels() const;
	bool isExploded();
	void rotate(int angle,int x0,int y0);
	//Roda roda;
	
};

#endif
