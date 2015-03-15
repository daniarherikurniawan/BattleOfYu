//tempat buat nyimpen data-data polygon

#ifndef __WORLD_MANAGER_H
#define __WORLD_MANAGER_H

#include "Polygon3D.h"
#include "CameraService.h"
#include "Pixel.h"
#include <vector>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 768
class WorldManager{
	//resolution
	int mWidth;
	int mHeight;
	Color mBuffer[MAX_WIDTH][MAX_HEIGHT];
	
	
public:
	vector<Polygon3D> mPolygons;
	int getWidth() const;
	int getHeight() const;
	int getPolygonSize() const;
	void setHeight(int _width);
	void setWidth(int _height);
	void fillBuffer();
	vector<Pixel> getPixels() const;
	void readMap3D(const char*);
	WorldManager();
};

#endif
