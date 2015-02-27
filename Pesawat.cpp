#include "Pesawat.h"

Pesawat::Pesawat() : mBody("plane.txt") {
	CompositeDrawable bird("bird.txt");
	MatrixDrawable birdMatrix(&bird);
	Point floodFillPosition(mBody.getWidth()/2,mBody.getHeight()/2);
	mBody.fillWithFloodFill(floodFillPosition,&birdMatrix);
	mIsExploded = false;

	mWidth = mBody.getWidth();
	mHeight = mBody.getHeight();

	//roda.setRadius(10);
	//roda.setCenter(Point(150,300));
}

void Pesawat::startExplode(Point centerPoint) {
	mIsExploded = true;
	vector<MatrixDrawable> matrices = mBody.split(6,16);
	mInitialExplodedBody.insert(mInitialExplodedBody.end(),matrices.begin(),matrices.end());
	mCurrentExplodedBody.insert(mCurrentExplodedBody.end(),matrices.begin(),matrices.end());
	mExplosionCenter = centerPoint;
}

void Pesawat::explode(float percentage) {
	float initialVelocity = 1;
	float acceleration = 0.01;
	float endVelocity = percentage * acceleration * 100 + initialVelocity;
	float averageVelocity = (initialVelocity + endVelocity) /2;

	int displacement = averageVelocity * percentage * 100;
	applyDisplacementToExplodedBody(displacement);
}

void Pesawat::applyDisplacementToExplodedBody(int displacement) {
	for (int i=0;i<mInitialExplodedBody.size();i++) {
		int distanceX = mInitialExplodedBody[i].getPosition().x - mExplosionCenter.x;
		int distanceY = mInitialExplodedBody[i].getPosition().y - mExplosionCenter.y;
		float hipotenuse = sqrt(distanceX*distanceX+distanceY*distanceY);

		int endX = mInitialExplodedBody[i].getPosition().x + (((float)displacement/hipotenuse) * distanceX);
		int endY = mInitialExplodedBody[i].getPosition().y + (((float)displacement/hipotenuse) * distanceY);
		//printf("%d %d %d %d %d %d\n",i,mInitialExplodedBody[i].getPosition().x,mInitialExplodedBody[i].getPosition().y,displacement,endX,endY);
		mCurrentExplodedBody[i].setPosition(endX,endY);
	}
}

void Pesawat::finishExplode() {
	mIsExploded = false;
	mInitialExplodedBody.clear();
	mCurrentExplodedBody.clear();
}

vector<Pixel> Pesawat::getPixels() const {
	vector<Pixel> pixels;
	if (mIsExploded) {
		for (int i=0;i<mInitialExplodedBody.size();i++){
			vector<Pixel> nextPixels = mCurrentExplodedBody[i].getPixels();
			pixels.insert(pixels.end(),nextPixels.begin(),nextPixels.end());
		}
	} else {
		pixels = mBody.getPixels();
	}

	for (int i=0;i<pixels.size();i++) {
		Point initialPosition = pixels[i].getPosition();
		Point endPosition(initialPosition.x+mPositionX,initialPosition.y+mPositionY);
		pixels[i].setPosition(endPosition);
	}

	//vector<Pixel> rodPixel = roda.getPixels();
	//pixels.insert(pixels.end(),rodPixel.begin(),rodPixel.end());
	
	return pixels;
}

int Pesawat::getLeftMostX() const {
	return mBody.getLeftMostX();
}

int Pesawat::getTopMostY() const {
	return mBody.getTopMostY();
}

bool Pesawat::isExploded() {
	return mIsExploded;
}

void Pesawat::rotate(int angle,int x0,int y0) {
	return;
}
