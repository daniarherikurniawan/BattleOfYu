#include "Drawable.h"

void Drawable::setPosition(int positionX,int positionY) {
  mPositionX = positionX;
  mPositionY = positionY;
}

void Drawable::moveBy(int offsetX,int offsetY) {
  mPositionX += offsetX;
  mPositionY += offsetY;
}

Point Drawable::getPosition() const{
  Point position(mPositionX,mPositionY);
  return position;
}

int Drawable::getWidth() const{
  return mWidth;
}

int Drawable::getHeight() const{
  return mHeight;
}

Drawable::~Drawable() {
	
}
