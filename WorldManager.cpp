#include "WorldManager.h"

int WorldManager::getWidth(){ return mWidth;}
int WorldManager::getHeight(){ return mHeight;}

void WorldManager::setWidth(int _width){
	if (_width < MAX_WIDTH){
		mWidth = _width;
	} else {
		mWidth = MAX_WIDTH;
	}
}
void WorldManager::setHeight(int _height){
	if (_height < MAX_HEIGHT){
		mHeight = _height;
	} else {
		mHeight = MAX_HEIGHT;
	}
}

//TBD
void WorldManager::fillBuffer(){
}

//TBD

vector<Pixel> WorldManager::getPixels(){
	fillBuffer();
	
	//create pixel based on buffer
	vector<Pixel> retval;
	for(int w = 0; w < getWidth(); ++w)
	for(int h = 0; h < getHeight(); ++h){
		Point p(w,h);
		Color c = mBuffer[w][h];
		Pixel pixel(p,c);
		retval.push_back(pixel);
	}
	return retval;
}
