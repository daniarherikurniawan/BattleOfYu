#include "Crosshair.h"

Crosshair::Crosshair(){
	for(int i = -CROSSHAIR_SIZE; i <= CROSSHAIR_SIZE; ++i){
		Point p(i,0);
		Point q(0,i);
		mPoints.push_back(p);
		mPoints.push_back(q);
	}
	Color color(66,242,144,0);
	mColor = color;
}

int Crosshair::getLeftMostX() const {
	return mPosition.x - CROSSHAIR_SIZE;
}

int Crosshair::getTopMostY() const {
	return mPosition.y - CROSSHAIR_SIZE;
}
vector<Pixel> Crosshair::getPixels() const{
	vector<Pixel> retval;
	for(int i = 0; i < getPointsSize(); ++i){
		Point p = mPoints[i];
		p.translate(getPosition().x,getPosition().y);
		
		Pixel pixel(p,mColor);
		retval.push_back(pixel);
	}
	return retval;
}

Point Crosshair::getPosition() const {
	return mPosition;
}

void Crosshair::setPosition(Point p) {
	mPosition = p;
}

int Crosshair::getPointsSize() const {
	return mPoints.size();
}


