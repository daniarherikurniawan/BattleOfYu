#include "WorldManager.h"

int WorldManager::getWidth() const { return mWidth;}
int WorldManager::getHeight() const { return mHeight;}

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

int WorldManager::getPolygonSize() const{
	return mPolygons.size();
}

void WorldManager::fillBuffer(){
	for(int i = 0; i < getPolygonSize(); i++){
		Polygon3D &p3d = mPolygons[i];
		Polygon p2d = p3d.convertToPolygon2D();
		vector<Pixel> pixels = p2d.getPixels();
	}
}

//TBD

vector<Pixel> WorldManager::getPixels() const{
	
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
