#ifndef POLYGON3D_H
#define POLYGON3D_H
#include <vector>
#include "Line3D.h"
#include "Drawable.h"

using namespace std;

class Polygon3D : public Drawable {
	vector<Line3D> lines;
	
public:
	Polygon3D();
	Polygon3D(string filename);
	void add(Line3D* line);
	void clear();
	vector<Pixel> getPixels() const;
	~Polygon3D();
	int getLeftMostX() const;
	int getTopMostY() const;
	void rotate(int angle,int x0,int y0);
};

#endif
