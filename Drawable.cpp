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

void Drawable::beforeDraw(){
	printf("fungsi beforeDraw() belum diimplementasikan child\n");
}

void Drawable::afterDraw(){
	printf("fungsi afterDraw() belum diimplementasikan child\n");
}
//fungsi ini harus dioverride oleh child class
//cuman sekedar biar gak compile error
void Drawable::rotate(int angle,int x0,int y0){
	printf("This object does not support rotation\n");
}
