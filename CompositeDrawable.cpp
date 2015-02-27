#include "CompositeDrawable.h"

CompositeDrawable::CompositeDrawable() {
}

int CompositeDrawable::applyGravity(int velocity) {
  mPositionY += velocity;
  if (mPositionY > 490) {
    mPositionY = 490;
    return 1;
  } else {
    return 0;
  }
}

CompositeDrawable::CompositeDrawable(string fileName) {
	ifstream inputStream;
	inputStream.open(fileName.c_str());
	int numberOfComponent;
	inputStream >> numberOfComponent;
	while(numberOfComponent) {
		char typeOfComponent;
		inputStream >> typeOfComponent;
		if (typeOfComponent == '/') {
			string dummy;
			getline(inputStream,dummy);
			continue;
		}
		else if (typeOfComponent == 'L') {
			int x1,y1,x2,y2,red,green,blue;
			inputStream>>x1>>y1>>x2>>y2>>red>>green>>blue;
			Point beginPoint(x1,y1),endPoint(x2,y2);
			Color color(red,green,blue,0);
			this->add(new Line(beginPoint,endPoint,color));
		}
		numberOfComponent--;
	}
	inputStream.close();
}

void CompositeDrawable::add(Drawable *drawable) {
	mDrawables.push_back(drawable);
	int drawableLeftMostX = drawable->getLeftMostX();
	int drawableRightMostX = drawableLeftMostX + drawable->getWidth();
	int drawableTopMostY = drawable->getTopMostY();
	int drawableBottomMostY = drawableTopMostY + drawable->getHeight();
	if (mDrawables.size()==1) {
	  mLeftMostX = drawableLeftMostX;
	  mRightMostX = drawableRightMostX;
	  mTopMostY = drawableTopMostY;
	  mBottomMostY = drawableBottomMostY;
	}
	else {
	  mLeftMostX = (mLeftMostX < drawableLeftMostX) ? mLeftMostX : drawableLeftMostX;
	  mRightMostX = (mRightMostX > drawableRightMostX) ? mRightMostX : drawableRightMostX;
	  mTopMostY = (mTopMostY < drawableTopMostY) ? mTopMostY : drawableTopMostY;
	  mBottomMostY = (mBottomMostY > drawableBottomMostY) ? mBottomMostY : drawableBottomMostY;  
	}
	mWidth = mRightMostX - mLeftMostX + 1;
	mHeight = mBottomMostY - mTopMostY + 1;
}

vector<Pixel> CompositeDrawable::getPixels() const{
	vector<Pixel> pixels;
	for (int i=0;i<mDrawables.size();i++) {
		vector<Pixel> nextPixels = mDrawables[i]->getPixels();
		pixels.insert(pixels.end(),nextPixels.begin(),nextPixels.end());
	}
	
	for (int i=0;i<pixels.size();i++) {
		Point initialPosition = pixels[i].getPosition();
		Point endPosition(initialPosition.x+mPositionX,initialPosition.y+mPositionY);
		pixels[i].setPosition(endPosition);
	}
	return pixels;
}

CompositeDrawable::~CompositeDrawable() {
	for (int i=0;i<mDrawables.size();i++) {
		delete mDrawables[i];
	}
	mDrawables.clear();
}

int CompositeDrawable::getLeftMostX() const{
  return mLeftMostX + mPositionX;
}

int CompositeDrawable::getTopMostY() const{
  return mTopMostY + mPositionY;
}

void CompositeDrawable::rotate(int angle,int x0,int y0){
	for(int i = 0; i < mDrawables.size(); i++){
		mDrawables[i]->rotate(angle,x0,y0);
	}
}
